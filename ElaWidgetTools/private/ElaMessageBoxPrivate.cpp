#include "ElaMessageBoxPrivate.h"

#include <QApplication>
#include <QDialogButtonBox>
#include <QGuiApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <QScreen>
#include <QStyle>
#include <QVBoxLayout>

#include "ElaMessageBox.h"
#include "ElaMaskWidget.h"
#include "ElaText.h"
#include "ElaTheme.h"
#include "ElaPushButton.h"
#include "Def.h"

ElaMessageBoxPrivate::ElaMessageBoxPrivate(QObject* parent)
    : QObject{parent}
{
}

ElaMessageBoxPrivate::~ElaMessageBoxPrivate() = default;

void ElaMessageBoxPrivate::setupUi(QWidget* parentWidget)
{
    Q_Q(ElaMessageBox);

    if (parentWidget != nullptr)
    {
        maskWidget = new ElaMaskWidget(parentWidget);
        maskWidget->move(0, 0);
        maskWidget->setFixedSize(parentWidget->size());
        maskWidget->setVisible(false);
    }
    else
    {
        maskWidget = nullptr;
    }

    centralWidget = new QWidget(q);
    auto* centralLayout = new QVBoxLayout(centralWidget);
    centralLayout->setContentsMargins(15, 25, 15, 10);

    // 顶部：图标 + 标题（水平）
    auto* topLine = new QWidget(q);
    auto* topLayout = new QHBoxLayout(topLine);
    topLayout->setContentsMargins(0, 0, 0, 0);
    topLayout->setSpacing(8);

    iconLabel = new QLabel(q);
    iconLabel->setFixedSize(20, 20);
    iconLabel->setScaledContents(true);
    titleText = new ElaText(title.isEmpty() ? QString() : title, q);
    titleText->setTextStyle(ElaTextType::Title);
    topLayout->addWidget(iconLabel);
    topLayout->addWidget(titleText, 1);

    bodyText = new ElaText(text.isEmpty() ? QString() : text, q);
    bodyText->setTextStyle(ElaTextType::Body);

    centralLayout->addWidget(topLine);
    centralLayout->addSpacing(6);
    centralLayout->addWidget(bodyText);
    centralLayout->addStretch();

    mainLayout = new QVBoxLayout(q);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    buttonBar = new QWidget(q);
    buttonBar->setFixedHeight(60);
    buttonLayout = new QHBoxLayout(buttonBar);
    mainLayout->addWidget(centralWidget);
    mainLayout->addWidget(buttonBar);

    updateIcon();
}

void ElaMessageBoxPrivate::applyButtons()
{
    Q_Q(ElaMessageBox);
    // 清空已有按钮
    while (auto* item = buttonLayout->takeAt(0))
    {
        if (item->widget())
        {
            item->widget()->deleteLater();
        }
        delete item;
    }

    buttonMap.clear();

    auto addButton = [&](QMessageBox::StandardButton sb, const QString& text) {
        auto* btn = new ElaPushButton(text, q);
        btn->setMinimumSize(0, 0);
        btn->setMaximumSize(QSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX));
        btn->setFixedHeight(38);
        btn->setBorderRadius(6);
        
        // 为特定按钮设置主题色（如 Ok, Yes 等肯定按钮）
        if (sb == QMessageBox::Ok || sb == QMessageBox::Yes || sb == QMessageBox::Apply || sb == QMessageBox::Save) {
            btn->setLightDefaultColor(ElaThemeColor(ElaThemeType::Light, PrimaryNormal));
            btn->setLightHoverColor(ElaThemeColor(ElaThemeType::Light, PrimaryHover));
            btn->setLightPressColor(ElaThemeColor(ElaThemeType::Light, PrimaryPress));
            btn->setLightTextColor(Qt::white);
            btn->setDarkDefaultColor(ElaThemeColor(ElaThemeType::Dark, PrimaryNormal));
            btn->setDarkHoverColor(ElaThemeColor(ElaThemeType::Dark, PrimaryHover));
            btn->setDarkPressColor(ElaThemeColor(ElaThemeType::Dark, PrimaryPress));
            btn->setDarkTextColor(Qt::black);
        }
        
        QObject::connect(btn, &ElaPushButton::clicked, q, [this, sb, q]() {
            clickedResult = sb;
            if (maskWidget)
            {
                maskWidget->doMaskAnimation(0);
            }
            q->accept();
        });
        buttonLayout->addWidget(btn);
        buttonMap.insert(sb, btn);
        return btn;
    };

    auto tryAdd = [&](QMessageBox::StandardButton sb, const QString& defaultText) {
        if (buttons.testFlag(sb))
        {
            // 优先使用自定义文本，否则使用默认文本
            QString text = customButtonTexts.contains(sb) ? customButtonTexts[sb] : defaultText;
            addButton(sb, text);
        }
    };

    // 按照标准顺序添加按钮
    // 左侧按钮（消极/否定）
    tryAdd(QMessageBox::Cancel, QDialogButtonBox::tr("Cancel"));
    tryAdd(QMessageBox::No, QDialogButtonBox::tr("&No"));
    tryAdd(QMessageBox::Abort, QDialogButtonBox::tr("Abort"));
    tryAdd(QMessageBox::Close, QDialogButtonBox::tr("Close"));
    tryAdd(QMessageBox::Discard, QDialogButtonBox::tr("&Discard"));
    
    // 中间按钮（中性）
    tryAdd(QMessageBox::Ignore, QDialogButtonBox::tr("Ignore"));
    tryAdd(QMessageBox::Help, QDialogButtonBox::tr("Help"));
    tryAdd(QMessageBox::Retry, QDialogButtonBox::tr("&Retry"));
    
    // 右侧按钮（积极/肯定）- 这些会被高亮
    tryAdd(QMessageBox::Apply, QDialogButtonBox::tr("Apply"));
    tryAdd(QMessageBox::Save, QDialogButtonBox::tr("&Save"));
    tryAdd(QMessageBox::Yes, QDialogButtonBox::tr("&Yes"));
    tryAdd(QMessageBox::Ok, QDialogButtonBox::tr("OK"));
    
    // 如果没有按钮，至少添加一个 Ok 按钮
    if (buttonMap.isEmpty() && buttons == QMessageBox::NoButton) {
        addButton(QMessageBox::Ok, QDialogButtonBox::tr("OK"));
    }
}

void ElaMessageBoxPrivate::applyDefaultButton()
{
    if (defaultButton == QMessageBox::NoButton)
        return;
    if (buttonMap.contains(defaultButton) && buttonMap[defaultButton])
    {
        buttonMap[defaultButton]->setFocus();
        return;
    }
    // 回退：存在 Ok/Yes 时优先
    for (auto candidate : {QMessageBox::Ok, QMessageBox::Yes})
    {
        if (buttonMap.contains(candidate) && buttonMap[candidate])
        {
            buttonMap[candidate]->setFocus();
            return;
        }
    }
}

void ElaMessageBoxPrivate::centerToScreenIfNoParent(QWidget* dialog)
{
    if (!dialog || dialog->parentWidget())
    {
        return;
    }
    auto* screen = QGuiApplication::primaryScreen();
    if (!screen)
    {
        return;
    }
    const QRect scr = screen->geometry();
    const QSize sz = dialog->size();
    const int x = scr.x() + (scr.width() - sz.width()) / 2;
    const int y = scr.y() + (scr.height() - sz.height()) / 2;
    dialog->move(x, y);
}

void ElaMessageBoxPrivate::doMaskOnShow()
{
    if (maskWidget && maskWidget->parentWidget())
    {
        maskWidget->setVisible(true);
        maskWidget->raise();
        maskWidget->setFixedSize(maskWidget->parentWidget()->size());
        maskWidget->doMaskAnimation(90);
    }
}

void ElaMessageBoxPrivate::updateIcon()
{
    if (!iconLabel)
        return;
    // 简易映射：用系统标准图标或占位
    QStyle::StandardPixmap sp = QStyle::SP_MessageBoxInformation;
    switch (icon)
    {
    case QMessageBox::Warning: sp = QStyle::SP_MessageBoxWarning; break;
    case QMessageBox::Critical: sp = QStyle::SP_MessageBoxCritical; break;
    case QMessageBox::Question: sp = QStyle::SP_MessageBoxQuestion; break;
    case QMessageBox::Information: sp = QStyle::SP_MessageBoxInformation; break;
    default: break;
    }
    const QIcon ic = QApplication::style()->standardIcon(sp);
    iconLabel->setPixmap(ic.pixmap(20, 20));
}


