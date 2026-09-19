#ifndef ELAWORKSPACE_ELAWIDGETTOOLS_ELATABBAR_H_
#define ELAWORKSPACE_ELAWIDGETTOOLS_ELATABBAR_H_

#include <QDrag>
#include <QTabBar>

#include "ElaPropertyMacro.h"
#include "ElaWidgetToolsExport.h"
class ElaTabBarPrivate;
class ELA_EXPORT ElaTabBar : public QTabBar
{
    Q_OBJECT
    Q_Q_CREATE(ElaTabBar)
    Q_PROPERTY_CREATE_Q_H(QSize, TabSize)
public:
    explicit ElaTabBar(QWidget* parent = nullptr);
    ~ElaTabBar() override;

    void setTabText(int index, const QString& text);

Q_SIGNALS:
    Q_SIGNAL void tabBarTextChanged(int tabIndex, const QString& tabText);
    Q_SIGNAL void tabDragCreate(QMimeData* mimeData);
    Q_SIGNAL void tabDragEnter(QMimeData* mimeData);
    Q_SIGNAL void tabDragLeave(QMimeData* mimeData);
    Q_SIGNAL void tabDragDrop(QMimeData* mimeData);

protected:
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void tabInserted(int index) override;
    void tabRemoved(int index) override;
    void resizeEvent(QResizeEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void dragEnterEvent(QDragEnterEvent* event) override;
    void dragMoveEvent(QDragMoveEvent* event) override;
    void dragLeaveEvent(QDragLeaveEvent* event) override;
    void dropEvent(QDropEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;
    void paintEvent(QPaintEvent* event) override;
};

#endif // ELAWORKSPACE_ELAWIDGETTOOLS_ELATABBAR_H_
