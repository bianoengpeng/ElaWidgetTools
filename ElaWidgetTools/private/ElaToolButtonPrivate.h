#ifndef ELAWORKSPACE_ELAWIDGETTOOLS_PRIVATE_ELATOOLBUTTONPRIVATE_H_
#define ELAWORKSPACE_ELAWIDGETTOOLS_PRIVATE_ELATOOLBUTTONPRIVATE_H_

#include <QObject>

#include "ElaWidgetToolsDef.h"
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

#endif // ELAWORKSPACE_ELAWIDGETTOOLS_PRIVATE_ELATOOLBUTTONPRIVATE_H_

