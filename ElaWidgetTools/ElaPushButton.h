#ifndef ELAPUSHBUTTON_H
#define ELAPUSHBUTTON_H

#include <QPushButton>
#include "ElaDef.h"
#include "ElaProperty.h"
class ElaPushButtonPrivate;
class ELA_EXPORT ElaPushButton : public QPushButton
{
    Q_OBJECT
    Q_Q_CREATE(ElaPushButton)
    Q_PROPERTY_CREATE_Q_H(int, BorderRadius)
    Q_PROPERTY_REF_CREATE_Q_H(QColor, LightDefaultColor)
    Q_PROPERTY_REF_CREATE_Q_H(QColor, DarkDefaultColor)
    Q_PROPERTY_REF_CREATE_Q_H(QColor, LightHoverColor)
    Q_PROPERTY_REF_CREATE_Q_H(QColor, DarkHoverColor)
    Q_PROPERTY_REF_CREATE_Q_H(QColor, LightPressColor)
    Q_PROPERTY_REF_CREATE_Q_H(QColor, DarkPressColor)
    Q_PROPERTY_CREATE_Q_H(ElaPushButtonType::Appearance, ButtonAppearance)
    Q_PROPERTY_CREATE_Q_H(ElaPushButtonType::Shape, ButtonShape)
public:
    explicit ElaPushButton(QWidget* parent = nullptr);
    explicit ElaPushButton(const QString& text, QWidget* parent = nullptr);
    ~ElaPushButton();

    void setLightTextColor(const QColor& color);
    const QColor& getLightTextColor() const;

    void setDarkTextColor(const QColor& color);
    const QColor& getDarkTextColor() const;

protected:
    virtual void mousePressEvent(QMouseEvent* event) override;
    virtual void mouseReleaseEvent(QMouseEvent* event) override;
    virtual void paintEvent(QPaintEvent* event) override;
};

#endif // ELAPUSHBUTTON_H
