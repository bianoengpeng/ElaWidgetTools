#include "ElaPushButton.h"

#include <QPainter>
#include <QPainterPath>

#include "ElaTheme.h"
#include "private/ElaPushButtonPrivate.h"
Q_PROPERTY_CREATE_Q_CPP(ElaPushButton, int, BorderRadius)
Q_PROPERTY_CREATE_Q_CPP(ElaPushButton, QColor, LightDefaultColor)
Q_PROPERTY_CREATE_Q_CPP(ElaPushButton, QColor, DarkDefaultColor)
Q_PROPERTY_CREATE_Q_CPP(ElaPushButton, QColor, LightHoverColor)
Q_PROPERTY_CREATE_Q_CPP(ElaPushButton, QColor, DarkHoverColor)
Q_PROPERTY_CREATE_Q_CPP(ElaPushButton, QColor, LightPressColor)
Q_PROPERTY_CREATE_Q_CPP(ElaPushButton, QColor, DarkPressColor)
Q_PROPERTY_CREATE_Q_CPP(ElaPushButton, ElaPushButtonType::Appearance, ButtonAppearance)
Q_PROPERTY_CREATE_Q_CPP(ElaPushButton, ElaPushButtonType::Shape, ButtonShape)
ElaPushButton::ElaPushButton(QWidget* parent)
    : QPushButton(parent), d_ptr(new ElaPushButtonPrivate())
{
    Q_D(ElaPushButton);
    d->q_ptr = this;
    d->_pBorderRadius = 3;
    d->_themeMode = eTheme->getThemeMode();
    d->_pLightDefaultColor = ElaThemeColor(ElaThemeType::Light, BasicBase);
    d->_pDarkDefaultColor = ElaThemeColor(ElaThemeType::Dark, BasicBase);
    d->_pLightHoverColor = ElaThemeColor(ElaThemeType::Light, BasicHover);
    d->_pDarkHoverColor = ElaThemeColor(ElaThemeType::Dark, BasicHover);
    d->_pLightPressColor = ElaThemeColor(ElaThemeType::Light, BasicPress);
    d->_pDarkPressColor = ElaThemeColor(ElaThemeType::Dark, BasicPress);
    d->_lightTextColor = ElaThemeColor(ElaThemeType::Light, BasicText);
    d->_darkTextColor = ElaThemeColor(ElaThemeType::Dark, BasicText);
    d->_pButtonAppearance = ElaPushButtonType::Appearance::Default;
	d->_pButtonShape = ElaPushButtonType::Shape::Rounded;
    setMouseTracking(true);
    setFixedHeight(38);
    QFont font = this->font();
    font.setPixelSize(15);
    setFont(font);
    setObjectName("ElaPushButton");
    setStyleSheet("#ElaPushButton{background-color:transparent;}");
    connect(eTheme, &ElaTheme::themeModeChanged, this, [=](ElaThemeType::ThemeMode themeMode) {
        d->_themeMode = themeMode;
    });
}

ElaPushButton::ElaPushButton(QString text, QWidget* parent)
    : ElaPushButton(parent)
{
    setText(text);
}

ElaPushButton::~ElaPushButton()
{
}

void ElaPushButton::setLightTextColor(QColor color)
{
    Q_D(ElaPushButton);
    d->_lightTextColor = color;
}

QColor ElaPushButton::getLightTextColor() const
{
    Q_D(const ElaPushButton);
    return d->_lightTextColor;
}

void ElaPushButton::setDarkTextColor(QColor color)
{
    Q_D(ElaPushButton);
    d->_darkTextColor = color;
}

QColor ElaPushButton::getDarkTextColor() const
{
    Q_D(const ElaPushButton);
    return d->_darkTextColor;
}

void ElaPushButton::mousePressEvent(QMouseEvent* event)
{
    Q_D(ElaPushButton);
    d->_isPressed = true;
    QPushButton::mousePressEvent(event);
}

void ElaPushButton::mouseReleaseEvent(QMouseEvent* event)
{
    Q_D(ElaPushButton);
    d->_isPressed = false;
    QPushButton::mouseReleaseEvent(event);
}

void ElaPushButton::paintEvent(QPaintEvent* event)
{
    Q_D(ElaPushButton);
    QPainter painter(this);
    painter.setRenderHints(QPainter::SmoothPixmapTransform | QPainter::Antialiasing | QPainter::TextAntialiasing);

    // 形状处理
    int radius = d->_pBorderRadius;
    if (d->_pButtonShape == ElaPushButtonType::Shape::Square) {
        radius = 0;
    } else if (d->_pButtonShape == ElaPushButtonType::Shape::Circular) {
        radius = height() / 2;
    }

    // 阴影
    eTheme->drawEffectShadow(&painter, rect(), d->_shadowBorderWidth, radius);

    // 背景与边框
    painter.save();
    QRect foregroundRect(d->_shadowBorderWidth, d->_shadowBorderWidth, width() - 2 * d->_shadowBorderWidth, height() - 2 * d->_shadowBorderWidth);

    QColor bgColor, borderColor, textColor;
    borderColor = Qt::transparent;
    textColor = isEnabled() ? (d->_themeMode == ElaThemeType::Light ? d->_lightTextColor : d->_darkTextColor) : ElaThemeColor(d->_themeMode, BasicTextDisable);

    // Appearance 处理
    switch (d->_pButtonAppearance) {
    case ElaPushButtonType::Appearance::Primary:
        bgColor = isEnabled() ? (d->_isPressed ? ElaThemeColor(d->_themeMode, colorCompoundBrandBackgroundPressed)
                                               : (underMouse() ? ElaThemeColor(d->_themeMode, colorCompoundBrandBackgroundHover)
                                                               : ElaThemeColor(d->_themeMode, colorCompoundBrandBackground)))
                              : ElaThemeColor(d->_themeMode, BasicDisable);
        borderColor = bgColor;
        textColor = Qt::white;
        break;
    case ElaPushButtonType::Appearance::Default:
        bgColor = isEnabled() ? (d->_isPressed ? d->_pLightPressColor : (underMouse() ? d->_pLightHoverColor : d->_pLightDefaultColor))
                              : ElaThemeColor(d->_themeMode, BasicDisable);
        if (d->_themeMode == ElaThemeType::Dark)
            bgColor = isEnabled() ? (d->_isPressed ? d->_pDarkPressColor : (underMouse() ? d->_pDarkHoverColor : d->_pDarkDefaultColor))
                                  : ElaThemeColor(d->_themeMode, BasicDisable);
        borderColor = ElaThemeColor(d->_themeMode, BasicBorder);
        break;
    case ElaPushButtonType::Appearance::Outline:
        bgColor = Qt::transparent;
        borderColor = ElaThemeColor(d->_themeMode, BasicBorder);
        break;
    case ElaPushButtonType::Appearance::Subtle:
        bgColor = Qt::transparent;
        if (isEnabled()) {
            if (d->_isPressed)
                bgColor = ElaThemeColor(d->_themeMode, colorSubtleBackgroundPressed);
            else if (underMouse())
                bgColor = ElaThemeColor(d->_themeMode, colorSubtleBackgroundHover);
        }
        break;
    case ElaPushButtonType::Appearance::Transparent:
        bgColor = Qt::transparent;
        break;
    }

    painter.setPen(QPen(borderColor, 1));
    painter.setBrush(bgColor);
    painter.drawRoundedRect(foregroundRect, radius, radius);

    // 文字
    painter.setPen(textColor);
    painter.drawText(foregroundRect, Qt::AlignCenter, text());
    painter.restore();
}
