#include "ElaDialog.h"

#include "ElaApplication.h"
#include "ElaText.h"
#include "ElaTheme.h"
#include "ElaWinShadowHelper.h"
#include "ElaAppBar.h"
#include "ElaMaskWidget.h"
#include "private/ElaDialogPrivate.h"
#include <QApplication>
#include <QDebug>
#include <QGuiApplication>
#include <QKeyEvent>
#include <QPainter>
#include <QScreen>
#include <QSize>
#include <QTimer>
#include <QVBoxLayout>

Q_TAKEOVER_NATIVEEVENT_CPP(ElaDialog, d_func()->_appBar);

ElaDialog::ElaDialog(QWidget* parent)
    : QDialog{parent}, d_ptr(new ElaDialogPrivate())
{
    Q_D(ElaDialog);
    d->q_ptr = this;

    // 创建遮罩widget
    if (parent) {
        d->_maskWidget = new ElaMaskWidget(parent);
        d->_maskWidget->move(0, 0);
        d->_maskWidget->setFixedSize(parent->size());
        d->_maskWidget->setVisible(false);
    } else {
        d->_maskWidget = nullptr;
    }

    // 设置默认尺寸
    resize(500, 400);
    setWindowModality(Qt::ApplicationModal);

    // 按照Qt标准设置对话框窗口标志
    Qt::WindowFlags dialogFlags = Qt::Dialog | Qt::WindowCloseButtonHint | Qt::WindowTitleHint | Qt::WindowSystemMenuHint;
    // 默认添加最小化和最大化按钮（可以被setFixedSize覆盖）
    dialogFlags |= Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint;
    setWindowFlags(dialogFlags);

#ifdef Q_OS_WIN
    createWinId();
#endif

    // 创建ElaAppBar，按照Qt标准方式配置
    d->_appBar = new ElaAppBar(this);

    // 根据窗口标志更新AppBar按钮
    _updateAppBarButtons();

    // 默认最大化、关闭、最小化直接由ElaAppBar完成
    connect(d->_appBar, &ElaAppBar::minimizeButtonClicked, this, &ElaDialog::minimizeButtonClicked);
    connect(d->_appBar, &ElaAppBar::maximizeButtonClicked, this, &ElaDialog::maximizeButtonClicked);
    connect(d->_appBar, &ElaAppBar::closeButtonClicked, this, &ElaDialog::closeButtonClicked);

    // 创建默认的中央widget
    d->_centralWidget = new QWidget(this);
    QVBoxLayout* centralVLayout = new QVBoxLayout(d->_centralWidget);
    centralVLayout->setContentsMargins(15, 25, 15, 25);

    // 创建主布局（不包含AppBar，让AppBar自己管理位置）
    d->_mainLayout = new QVBoxLayout(this);
    d->_mainLayout->setContentsMargins(0, 0, 0, 0);
    d->_mainLayout->addWidget(d->_centralWidget);

    d->_themeMode = eTheme->getThemeMode();
    connect(eTheme, &ElaTheme::themeModeChanged, this, [=](ElaThemeType::ThemeMode themeMode) {
        d->_themeMode = themeMode;
        update();
    });

    // 添加窗口显示模式支持
    d->_windowDisplayMode = eApp->getWindowDisplayMode();
    connect(eApp, &ElaApplication::pWindowDisplayModeChanged, this, [=]() {
        d->_windowDisplayMode = eApp->getWindowDisplayMode();
        update();
    });
    eApp->syncWindowDisplayMode(this);
}

ElaDialog::~ElaDialog()
{
    Q_D(ElaDialog);
    // 删除遮罩widget
    if (d->_maskWidget) {
        d->_maskWidget->deleteLater();
    }
    // 移除遮罩widget相关处理
    eApp->syncWindowDisplayMode(this, false);
}

void ElaDialog::setCentralWidget(QWidget* centralWidget)
{
    Q_D(ElaDialog);
    d->_mainLayout->takeAt(0);  // 索引0，因为AppBar不在布局中
    delete d->_centralWidget;
    d->_centralWidget = centralWidget;
    d->_mainLayout->addWidget(centralWidget);
}

void ElaDialog::close()
{
    Q_D(ElaDialog);
    d->_doCloseAnimation(true);
}

void ElaDialog::moveToCenter()
{
    if (isMaximized() || isFullScreen())
    {
        return;
    }
#if QT_VERSION >= QT_VERSION_CHECK(5, 14, 0)
    auto geometry = screen()->availableGeometry();
#else
    auto geometry = qApp->screenAt(this->geometry().center())->geometry();
#endif
    setGeometry((geometry.left() + geometry.right() - width()) / 2, (geometry.top() + geometry.bottom() - height()) / 2, width(), height());
}

void ElaDialog::setFixedSize(const QSize& size)
{
    QDialog::setFixedSize(size);
    Q_D(ElaDialog);
    // 按照Qt标准：固定大小的对话框移除最大化按钮标志
    Qt::WindowFlags flags = windowFlags();
    flags &= ~Qt::WindowMaximizeButtonHint;  // 移除最大化按钮
    setWindowFlags(flags);

    // 同时更新AppBar
    d->_appBar->setIsFixedSize(true);
    _updateAppBarButtons();
}

void ElaDialog::setFixedSize(int width, int height)
{
    QDialog::setFixedSize(width, height);
    Q_D(ElaDialog);
    // 按照Qt标准：固定大小的对话框移除最大化按钮标志
    Qt::WindowFlags flags = windowFlags();
    flags &= ~Qt::WindowMaximizeButtonHint;  // 移除最大化按钮
    setWindowFlags(flags);

    // 同时更新AppBar
    d->_appBar->setIsFixedSize(true);
    _updateAppBarButtons();
}

void ElaDialog::setIsStayTop(bool isStayTop)
{
    Q_D(ElaDialog);
    d->_appBar->setIsStayTop(isStayTop);
    Q_EMIT pIsStayTopChanged();
}

bool ElaDialog::getIsStayTop() const
{
    return d_ptr->_appBar->getIsStayTop();
}

void ElaDialog::setIsFixedSize(bool isFixedSize)
{
    Q_D(ElaDialog);
    d->_appBar->setIsFixedSize(isFixedSize);
    Q_EMIT pIsFixedSizeChanged();
}

bool ElaDialog::getIsFixedSize() const
{
    return d_ptr->_appBar->getIsFixedSize();
}

void ElaDialog::setIsDefaultClosed(bool isDefaultClosed)
{
    Q_D(ElaDialog);
    d->_appBar->setIsDefaultClosed(isDefaultClosed);
    Q_EMIT pIsDefaultClosedChanged();
}

bool ElaDialog::getIsDefaultClosed() const
{
    Q_D(const ElaDialog);
    return d->_appBar->getIsDefaultClosed();
}

void ElaDialog::setIsDefaultMinimized(bool isDefaultMinimized)
{
    Q_D(ElaDialog);
    d->_appBar->setIsDefaultMinimized(isDefaultMinimized);
    Q_EMIT pIsDefaultMinimizedChanged();
}

bool ElaDialog::getIsDefaultMinimized() const
{
    Q_D(const ElaDialog);
    return d->_appBar->getIsDefaultMinimized();
}

void ElaDialog::setIsDefaultMaximized(bool isDefaultMaximized)
{
    Q_D(ElaDialog);
    d->_appBar->setIsDefaultMaximized(isDefaultMaximized);
    Q_EMIT pIsDefaultMaximizedChanged();
}

bool ElaDialog::getIsDefaultMaximized() const
{
    Q_D(const ElaDialog);
    return d->_appBar->getIsDefaultMaximized();
}

void ElaDialog::setAppBarHeight(int appBarHeight)
{
    Q_D(ElaDialog);
    d->_appBar->setAppBarHeight(appBarHeight);
    Q_EMIT pAppBarHeightChanged();
}

int ElaDialog::getAppBarHeight() const
{
    Q_D(const ElaDialog);
    return d->_appBar->getAppBarHeight();
}

void ElaDialog::setWindowButtonFlag(ElaAppBarType::ButtonType buttonFlag, bool isEnable)
{
    Q_D(ElaDialog);
    d->_appBar->setWindowButtonFlag(buttonFlag, isEnable);
}

void ElaDialog::setWindowButtonFlags(ElaAppBarType::ButtonFlags buttonFlags)
{
    Q_D(ElaDialog);
    d->_appBar->setWindowButtonFlags(buttonFlags);
}

ElaAppBarType::ButtonFlags ElaDialog::getWindowButtonFlags() const
{
    return d_ptr->_appBar->getWindowButtonFlags();
}

void ElaDialog::showEvent(QShowEvent* event)
{
    Q_D(ElaDialog);
    // 显示遮罩并执行动画
    if (d->_maskWidget && parentWidget()) {
        d->_maskWidget->setVisible(true);
        d->_maskWidget->raise();
        d->_maskWidget->setFixedSize(parentWidget()->size());
        d->_maskWidget->doMaskAnimation(90);
    }
    // 移除遮罩相关处理，参考ElaColorDialog
#ifdef Q_OS_WIN
#if (QT_VERSION >= QT_VERSION_CHECK(6, 5, 3) && QT_VERSION <= QT_VERSION_CHECK(6, 6, 1))
    HWND hwnd = (HWND)d->_currentWinID;
    ElaWinShadowHelper::getInstance()->setWindowShadow(d->_currentWinID);
    DWORD style = ::GetWindowLongPtr(hwnd, GWL_STYLE);
    bool hasCaption = (style & WS_CAPTION) == WS_CAPTION;
    if (!hasCaption)
    {
        ::SetWindowLongPtr(hwnd, GWL_STYLE, style | WS_CAPTION);
    }
#endif
#endif
    QDialog::showEvent(event);
}

void ElaDialog::paintEvent(QPaintEvent* event)
{
    Q_D(ElaDialog);
#if (QT_VERSION >= QT_VERSION_CHECK(6, 5, 3) && QT_VERSION <= QT_VERSION_CHECK(6, 6, 1))
    if (d->_windowDisplayMode != ElaApplicationType::WindowDisplayMode::ElaMica)
#else
    if (d->_windowDisplayMode == ElaApplicationType::WindowDisplayMode::Normal)
#endif
    {
        QPainter painter(this);
        painter.save();
        painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
        painter.setPen(Qt::NoPen);
        painter.setBrush(ElaThemeColor(d->_themeMode, WindowBase));
        painter.drawRect(rect());
        painter.restore();
    }
    QDialog::paintEvent(event);
}



void ElaDialog::_updateAppBarButtons()
{
    Q_D(ElaDialog);
    Qt::WindowFlags flags = windowFlags();
    ElaAppBarType::ButtonFlags appBarFlags;

    // 根据Qt窗口标志设置AppBar按钮
    if (flags & Qt::WindowMinimizeButtonHint)
        appBarFlags |= ElaAppBarType::MinimizeButtonHint;
    if (flags & Qt::WindowMaximizeButtonHint)
        appBarFlags |= ElaAppBarType::MaximizeButtonHint;
    if (flags & Qt::WindowCloseButtonHint)
        appBarFlags |= ElaAppBarType::CloseButtonHint;

    d->_appBar->setWindowButtonFlags(appBarFlags);
}
