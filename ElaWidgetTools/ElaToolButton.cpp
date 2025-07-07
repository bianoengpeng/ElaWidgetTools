#include "ElaToolButton.h"

#include <QApplication>
#include <QDebug>
#include <QEvent>
#include <QMouseEvent>
#include <QPropertyAnimation>

#include "DeveloperComponents/ElaToolButtonStyle.h"
#include "ElaIcon.h"
#include "ElaMenu.h"
#include "ElaToolButtonPrivate.h"
ElaToolButton::ElaToolButton(QWidget* parent)
    : QToolButton(parent), d_ptr(new ElaToolButtonPrivate())
{
    Q_D(ElaToolButton);
    d->q_ptr = this;
    setIconSize(QSize(22, 22));
    setPopupMode(QToolButton::InstantPopup);
    d->_toolButtonStyle = new ElaToolButtonStyle(style());
    setStyle(d->_toolButtonStyle);
    // 默认外观
    d->_pButtonAppearance = ElaPushButtonType::Appearance::Default;
    d->_toolButtonStyle->setButtonAppearance(d->_pButtonAppearance);
    // Default 外观为非透明
    setIsTransparent(false);
}

ElaToolButton::~ElaToolButton()
{
}

void ElaToolButton::setBorderRadius(int borderRadius)
{
    Q_D(ElaToolButton);
    d->_toolButtonStyle->setBorderRadius(borderRadius);
    Q_EMIT pBorderRadiusChanged();
}

int ElaToolButton::getBorderRadius() const
{
    Q_D(const ElaToolButton);
    return d->_toolButtonStyle->getBorderRadius();
}

void ElaToolButton::setIsSelected(bool isSelected)
{
    Q_D(ElaToolButton);
    d->_toolButtonStyle->setIsSelected(isSelected);
    Q_EMIT pIsSelectedChanged();
}

bool ElaToolButton::getIsSelected() const
{
    Q_D(const ElaToolButton);
    return d->_toolButtonStyle->getIsSelected();
}

void ElaToolButton::setIsTransparent(bool isTransparent)
{
    Q_D(ElaToolButton);
    d->_toolButtonStyle->setIsTransparent(isTransparent);
    update();
}

bool ElaToolButton::getIsTransparent() const
{
    Q_D(const ElaToolButton);
    return d->_toolButtonStyle->getIsTransparent();
}

void ElaToolButton::setMenu(ElaMenu* menu)
{
    if (!menu || menu == this->menu())
    {
        return;
    }
    menu->setMenuItemHeight(27);
    QToolButton::setMenu(menu);
    menu->installEventFilter(this);
}

void ElaToolButton::setElaIcon(ElaIconType::IconName icon)
{
    setProperty("ElaIconType", QChar((unsigned short)icon));
    setIcon(ElaIcon::getInstance()->getElaIcon(ElaIconType::Broom, 1));
}

bool ElaToolButton::eventFilter(QObject* watched, QEvent* event)
{
    Q_D(ElaToolButton);
    if (watched == menu())
    {
        switch (event->type())
        {
        case QEvent::Show:
        {
            //指示器动画
            QPropertyAnimation* rotateAnimation = new QPropertyAnimation(d->_toolButtonStyle, "pExpandIconRotate");
            connect(rotateAnimation, &QPropertyAnimation::valueChanged, this, [=](const QVariant& value) {
                update();
            });
            rotateAnimation->setDuration(300);
            rotateAnimation->setEasingCurve(QEasingCurve::InOutSine);
            rotateAnimation->setStartValue(d->_toolButtonStyle->getExpandIconRotate());
            rotateAnimation->setEndValue(-180);
            rotateAnimation->start(QAbstractAnimation::DeleteWhenStopped);
            break;
        }
        case QEvent::Hide:
        {
            //指示器动画
            QPropertyAnimation* rotateAnimation = new QPropertyAnimation(d->_toolButtonStyle, "pExpandIconRotate");
            connect(rotateAnimation, &QPropertyAnimation::valueChanged, this, [=](const QVariant& value) {
                update();
            });
            rotateAnimation->setDuration(300);
            rotateAnimation->setEasingCurve(QEasingCurve::InOutSine);
            rotateAnimation->setStartValue(d->_toolButtonStyle->getExpandIconRotate());
            rotateAnimation->setEndValue(0);
            rotateAnimation->start(QAbstractAnimation::DeleteWhenStopped);
            QMouseEvent focusEvent(QEvent::MouseButtonPress, QPoint(-1, -1), QPoint(-1, -1), Qt::NoButton, Qt::NoButton, Qt::NoModifier);
            QApplication::sendEvent(parentWidget(), &focusEvent);
            break;
        }
        default:
        {
            break;
        }
        }
    }
    return QObject::eventFilter(watched, event);
}

// ButtonAppearance property implementation
void ElaToolButton::setButtonAppearance(ElaPushButtonType::Appearance appearance)
{
    Q_D(ElaToolButton);
    if (d->_pButtonAppearance == appearance)
        return;

    d->_pButtonAppearance = appearance;

    // 同步到 style
    d->_toolButtonStyle->setButtonAppearance(appearance);

    // 根据不同外观设置透明背景
    bool transparent = false;
    switch (appearance) {
    case ElaPushButtonType::Appearance::Default:
    case ElaPushButtonType::Appearance::Primary:
        transparent = false;
        break;
    case ElaPushButtonType::Appearance::Outline:
    case ElaPushButtonType::Appearance::Subtle:
    case ElaPushButtonType::Appearance::Transparent:
        transparent = true;
        break;
    }

    d->_toolButtonStyle->setIsTransparent(transparent);

    Q_EMIT pButtonAppearanceChanged();
    update();
}

ElaPushButtonType::Appearance ElaToolButton::getButtonAppearance() const
{
    Q_D(const ElaToolButton);
    return d->_pButtonAppearance;
}
