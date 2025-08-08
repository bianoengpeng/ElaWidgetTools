#include "ElaMessageBox.h"

#include <QHBoxLayout>
#include <QPainter>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QVBoxLayout>

#include "ElaTheme.h"
#include "private/ElaMessageBoxPrivate.h"
#include "ElaText.h"
#include "ElaMaskWidget.h"
#include "ElaPushButton.h"

ElaMessageBox::ElaMessageBox(QWidget* parent)
    : QDialog{parent}, d_ptr(new ElaMessageBoxPrivate())
{
    Q_D(ElaMessageBox);
    d->q_ptr = this;

    setMinimumSize(300, 180);
    resize(450, 200);
    setWindowModality(Qt::ApplicationModal);
    setAttribute(Qt::WA_TranslucentBackground);
#ifdef Q_OS_WIN
    createWinId();
#if (QT_VERSION >= QT_VERSION_CHECK(6, 5, 3) && QT_VERSION <= QT_VERSION_CHECK(6, 6, 1))
    window()->setWindowFlags((window()->windowFlags()) | Qt::WindowMinimizeButtonHint | Qt::FramelessWindowHint);
#else
    window()->setWindowFlags((window()->windowFlags()) | Qt::FramelessWindowHint);
#endif
#else
    window()->setWindowFlags((window()->windowFlags()) | Qt::FramelessWindowHint);
#endif

    d->themeMode = eTheme->getThemeMode();
    connect(eTheme, &ElaTheme::themeModeChanged, this, [=](ElaThemeType::ThemeMode mode) {
        d->themeMode = mode;
        update();
    });

    d->setupUi(parent);
}

ElaMessageBox::~ElaMessageBox() = default;

void ElaMessageBox::setTitle(const QString& title)
{
    Q_D(ElaMessageBox);
    d->title = title;
    if (d->titleText)
        d->titleText->setText(title);
}

void ElaMessageBox::setText(const QString& text)
{
    Q_D(ElaMessageBox);
    d->text = text;
    if (d->bodyText)
        d->bodyText->setText(text);
}

void ElaMessageBox::setInformativeText(const QString& text)
{
    Q_D(ElaMessageBox);
    d->informativeTextStr = text;
    if (d->informativeText)
    {
        d->informativeText->setText(text);
        d->informativeText->setVisible(!text.isEmpty());
    }
}

void ElaMessageBox::setDetailedText(const QString& text)
{
    Q_D(ElaMessageBox);
    d->detailedTextStr = text;
    // 详细文本需要在 setupUi 中处理
}

void ElaMessageBox::setButtonText(QMessageBox::StandardButton button, const QString& text)
{
    Q_D(ElaMessageBox);
    d->customButtonTexts[button] = text;
    if (d->buttonMap.contains(button) && d->buttonMap[button])
    {
        d->buttonMap[button]->setText(text);
    }
}

void ElaMessageBox::setEscapeButton(QMessageBox::StandardButton button)
{
    Q_D(ElaMessageBox);
    d->escapeButton = button;
}

void ElaMessageBox::setWindowIcon(const QIcon& icon)
{
    QDialog::setWindowIcon(icon);
}

void ElaMessageBox::setCheckBox(QCheckBox* checkbox)
{
    Q_D(ElaMessageBox);
    d->checkBox = checkbox;
    // 复选框需要在 setupUi 中处理
}

void ElaMessageBox::setIcon(QMessageBox::Icon icon)
{
    Q_D(ElaMessageBox);
    d->icon = icon;
    d->updateIcon();
}

void ElaMessageBox::setStandardButtons(QMessageBox::StandardButtons buttons)
{
    Q_D(ElaMessageBox);
    d->buttons = buttons;
    if (d->buttonLayout)
        d->applyButtons();
}

void ElaMessageBox::setDefaultButton(QMessageBox::StandardButton button)
{
    Q_D(ElaMessageBox);
    d->defaultButton = button;
    d->applyDefaultButton();
}

QMessageBox::StandardButton ElaMessageBox::execForResult()
{
    Q_D(ElaMessageBox);
    d->doMaskOnShow();
    show();
    d->centerToScreenIfNoParent(this);
    const int r = QDialog::exec();
    
    // 如果没有点击按钮而是直接关闭了对话框
    if (d->clickedResult == QMessageBox::NoButton)
    {
        // 根据 QDialog 的返回值和可用按钮决定返回值
        if (r == QDialog::Rejected)
        {
            // Esc 或关闭按钮
            if (d->escapeButton != QMessageBox::NoButton)
                return d->escapeButton;
            if (d->buttons & QMessageBox::Cancel)
                return QMessageBox::Cancel;
            if (d->buttons & QMessageBox::No)
                return QMessageBox::No;
        }
        // 默认返回第一个按钮
        if (d->buttons & QMessageBox::Ok)
            return QMessageBox::Ok;
        if (d->buttons & QMessageBox::Yes)
            return QMessageBox::Yes;
    }
    return d->clickedResult;
}

QMessageBox::StandardButton ElaMessageBox::information(
    QWidget* parent,
    const QString& title,
    const QString& text,
    QMessageBox::StandardButtons buttons,
    QMessageBox::StandardButton defaultButton)
{
    ElaMessageBox box(parent);
    box.setTitle(title);
    box.setText(text);
    box.setIcon(QMessageBox::Information);
    box.setStandardButtons(buttons);
    box.setDefaultButton(defaultButton);
    return box.execForResult();
}

QMessageBox::StandardButton ElaMessageBox::question(
    QWidget* parent,
    const QString& title,
    const QString& text,
    QMessageBox::StandardButtons buttons,
    QMessageBox::StandardButton defaultButton)
{
    ElaMessageBox box(parent);
    box.setTitle(title);
    box.setText(text);
    box.setIcon(QMessageBox::Question);
    box.setStandardButtons(buttons);
    box.setDefaultButton(defaultButton);
    return box.execForResult();
}

QMessageBox::StandardButton ElaMessageBox::warning(
    QWidget* parent,
    const QString& title,
    const QString& text,
    QMessageBox::StandardButtons buttons,
    QMessageBox::StandardButton defaultButton)
{
    ElaMessageBox box(parent);
    box.setTitle(title);
    box.setText(text);
    box.setIcon(QMessageBox::Warning);
    box.setStandardButtons(buttons);
    box.setDefaultButton(defaultButton);
    return box.execForResult();
}

QMessageBox::StandardButton ElaMessageBox::critical(
    QWidget* parent,
    const QString& title,
    const QString& text,
    QMessageBox::StandardButtons buttons,
    QMessageBox::StandardButton defaultButton)
{
    ElaMessageBox box(parent);
    box.setTitle(title);
    box.setText(text);
    box.setIcon(QMessageBox::Critical);
    box.setStandardButtons(buttons);
    box.setDefaultButton(defaultButton);
    return box.execForResult();
}

void ElaMessageBox::about(
    QWidget* parent,
    const QString& title,
    const QString& text)
{
    // 使用信息框语义
    information(parent, title, text, QMessageBox::Ok, QMessageBox::Ok);
}

void ElaMessageBox::aboutQt(
    QWidget* parent,
    const QString& title)
{
    const QString t = title.isEmpty() ? QObject::tr("About Qt") : title;
    information(parent, t, QStringLiteral("Qt"));
}

void ElaMessageBox::showEvent(QShowEvent* event)
{
    Q_D(ElaMessageBox);
    d->doMaskOnShow();
    QDialog::showEvent(event);
}

void ElaMessageBox::paintEvent(QPaintEvent* event)
{
    Q_D(ElaMessageBox);
    Q_UNUSED(event);
    QPainter painter(this);
    painter.save();
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.setPen(Qt::NoPen);
    painter.setBrush(ElaThemeColor(d->themeMode, DialogBase));
    
    // 绘制圆角窗体背景
    painter.drawRoundedRect(rect(), 8, 8);
    
    // 按钮栏背景绘制
    painter.setBrush(ElaThemeColor(d->themeMode, DialogLayoutArea));
    painter.drawRoundedRect(QRectF(0, height() - 60, width(), 60), 8, 8);
    
    painter.restore();
}

void ElaMessageBox::keyPressEvent(QKeyEvent* event)
{
    Q_D(ElaMessageBox);
    // Enter/Return 触发默认按钮；Esc 触发 Cancel/No；否则交由基类
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
    {
        if (d->defaultButton != QMessageBox::NoButton)
        {
            d->clickedResult = d->defaultButton;
            if (d->maskWidget)
                d->maskWidget->doMaskAnimation(0);
            accept();
            return;
        }
        // 无默认则优先 Ok/Yes
        if (d->buttonMap.contains(QMessageBox::Ok))
        {
            d->clickedResult = QMessageBox::Ok;
            if (d->maskWidget)
                d->maskWidget->doMaskAnimation(0);
            accept();
            return;
        }
        if (d->buttonMap.contains(QMessageBox::Yes))
        {
            d->clickedResult = QMessageBox::Yes;
            if (d->maskWidget)
                d->maskWidget->doMaskAnimation(0);
            accept();
            return;
        }
    }
    else if (event->key() == Qt::Key_Escape)
    {
        // 优先使用用户设置的 escape button
        if (d->escapeButton != QMessageBox::NoButton && d->buttonMap.contains(d->escapeButton))
        {
            d->clickedResult = d->escapeButton;
            if (d->maskWidget)
                d->maskWidget->doMaskAnimation(0);
            reject();
            return;
        }
        // 默认顺序：Cancel > No > 关闭对话框
        if (d->buttonMap.contains(QMessageBox::Cancel))
        {
            d->clickedResult = QMessageBox::Cancel;
            if (d->maskWidget)
                d->maskWidget->doMaskAnimation(0);
            reject();
            return;
        }
        if (d->buttonMap.contains(QMessageBox::No))
        {
            d->clickedResult = QMessageBox::No;
            if (d->maskWidget)
                d->maskWidget->doMaskAnimation(0);
            reject();
            return;
        }
        // 如果没有合适的按钮，直接关闭
        if (d->maskWidget)
            d->maskWidget->doMaskAnimation(0);
        reject();
        return;
    }
    QDialog::keyPressEvent(event);
}

void ElaMessageBox::mousePressEvent(QMouseEvent* event)
{
    Q_D(ElaMessageBox);
    if (event->button() == Qt::LeftButton)
    {
        d->isMousePressed = true;
        d->mousePressPos = event->globalPos() - this->frameGeometry().topLeft();
        
        // 判断是否在可拖动区域（排除按钮栏区域）
        if (event->y() < height() - 60)
        {
            d->canDrag = true;
        }
        else
        {
            d->canDrag = false;
        }
    }
    QDialog::mousePressEvent(event);
}

void ElaMessageBox::mouseReleaseEvent(QMouseEvent* event)
{
    Q_D(ElaMessageBox);
    d->isMousePressed = false;
    d->canDrag = false;
    QDialog::mouseReleaseEvent(event);
}

void ElaMessageBox::mouseMoveEvent(QMouseEvent* event)
{
    Q_D(ElaMessageBox);
    if (d->isMousePressed && d->canDrag && (event->buttons() & Qt::LeftButton))
    {
        // 移动窗口
        move(event->globalPos() - d->mousePressPos);
    }
    QDialog::mouseMoveEvent(event);
}
