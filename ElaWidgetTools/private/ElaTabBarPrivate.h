#ifndef ELAWORKSPACE_ELAWIDGETTOOLS_PRIVATE_ELATABBARPRIVATE_H_
#define ELAWORKSPACE_ELAWIDGETTOOLS_PRIVATE_ELATABBARPRIVATE_H_

#include "ElaPropertyMacro.h"
#include "ElaWidgetToolsExport.h"
#include <QMimeData>
#include <QObject>
#include <QPixmap>
class ElaTabBar;
class ElaTabBarStyle;
class QTabBarPrivate;
class QPropertyAnimation;
class ElaTabBarPrivate : public QObject
{
    Q_OBJECT
    Q_D_CREATE(ElaTabBar)
    Q_PROPERTY_CREATE(qreal, ScrollOffset)
    Q_PROPERTY_CREATE(qreal, TargetScrollOffset)
public:
    explicit ElaTabBarPrivate(QObject* parent = nullptr);
    ~ElaTabBarPrivate() override;

    void startScrollAnimation();
    void restoreScrollOffset(qreal offset);

private:
    QMimeData* _mimeData{nullptr};
    ElaTabBarStyle* _style{nullptr};
    QTabBarPrivate* _tabBarPrivate{nullptr};
    QPropertyAnimation* _scrollAnimation{nullptr};
};

#endif // ELAWORKSPACE_ELAWIDGETTOOLS_PRIVATE_ELATABBARPRIVATE_H_
