#ifndef ELATOOLBUTTONPRIVATE_H
#define ELATOOLBUTTONPRIVATE_H

#include <QObject>

#include "stdafx.h"
#include "Def.h"

class ElaToolButton;
class ElaToolButtonStyle;
class ElaToolButtonPrivate : public QObject
{
    Q_OBJECT
    Q_D_CREATE(ElaToolButton)
public:
    explicit ElaToolButtonPrivate(QObject* parent = nullptr);
    ~ElaToolButtonPrivate();

private:
    Q_PROPERTY_CREATE_D(ElaPushButtonType::Appearance, ButtonAppearance)
    ElaToolButtonStyle* _toolButtonStyle{nullptr};
};

#endif // ELATOOLBUTTONPRIVATE_H
