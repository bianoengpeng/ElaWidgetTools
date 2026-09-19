#ifndef ELAWORKSPACE_ELAWIDGETTOOLS_ELATABWIDGET_H_
#define ELAWORKSPACE_ELAWIDGETTOOLS_ELATABWIDGET_H_

#include <QTabWidget>

#include "ElaPropertyMacro.h"
#include "ElaWidgetToolsExport.h"

class ElaTabWidgetPrivate;
class ELA_EXPORT ElaTabWidget : public QTabWidget
{
    Q_OBJECT
    Q_Q_CREATE(ElaTabWidget)
    Q_PROPERTY_CREATE_Q_H(bool, IsTabTransparent);
    Q_PROPERTY_CREATE_Q_H(bool, IsContainerAcceptDrops);
    Q_PROPERTY_CREATE_Q_H(QSize, TabSize)
    Q_PROPERTY_CREATE_Q_H(QSize, FloatWidgetSize)
public:
    explicit ElaTabWidget(QWidget* parent = nullptr);
    ~ElaTabWidget() override;
    void setTabPosition(TabPosition position);

Q_SIGNALS:
    Q_SIGNAL void currentWidgetChanged(QWidget* widget);

protected:
    void paintEvent(QPaintEvent* event) override;
    void dragEnterEvent(QDragEnterEvent* event) override;
    void dropEvent(QDropEvent* event) override;
    void tabInserted(int index) override;

private:
    friend class ElaCustomTabWidget;
};

#endif // ELAWORKSPACE_ELAWIDGETTOOLS_ELATABWIDGET_H_
