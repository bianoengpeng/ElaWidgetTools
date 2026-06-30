#ifndef ELAICON_H
#define ELAICON_H
#include <QIcon>

#include "ElaDef.h"
#include "ElaProperty.h"
#include "ElaSingleton.h"
class ELA_EXPORT ElaIcon
{
    Q_SINGLETON_CREATE_H(ElaIcon)
private:
    explicit ElaIcon();
    ~ElaIcon();

public:
    QIcon getElaIcon(ElaIconType::IconName awesome);
    QIcon getElaIcon(ElaIconType::IconName awesome, const QColor& iconColor);
    QIcon getElaIcon(ElaIconType::IconName awesome, int pixelSize);
    QIcon getElaIcon(ElaIconType::IconName awesome, int pixelSize, const QColor& iconColor);
    QIcon getElaIcon(ElaIconType::IconName awesome, int pixelSize, int fixedWidth, int fixedHeight);
    QIcon getElaIcon(ElaIconType::IconName awesome, int pixelSize, int fixedWidth, int fixedHeight, const QColor& iconColor);
};

#endif // ELAICON_H
