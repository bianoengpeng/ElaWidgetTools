#include "ElaTableView.h"

#include <QHeaderView>
#include <QMouseEvent>

#include "DeveloperComponents/ElaTableViewStyle.h"
#include "ElaScrollBar.h"
#include "ElaTableViewPrivate.h"
ElaTableView::ElaTableView(QWidget* parent)
    : QTableView(parent), d_ptr(new ElaTableViewPrivate())
{
    Q_D(ElaTableView);
    d->q_ptr = this;
    setMouseTracking(true);
    setObjectName("ElaTableView");
    setStyleSheet(
        "QTableView{background-color:transparent;}"
        "QHeaderView{background-color:transparent;border:0px;}");
    setShowGrid(false);
    setVerticalScrollBar(new ElaScrollBar(this));
    setHorizontalScrollBar(new ElaScrollBar(this));
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    d->_tableViewStyle = new ElaTableViewStyle(style());
    setStyle(d->_tableViewStyle);
}

ElaTableView::~ElaTableView()
{
}

void ElaTableView::setHeaderMargin(int headerMargin)
{
    Q_D(ElaTableView);
    if (headerMargin >= 0)
    {
        d->_tableViewStyle->setHeaderMargin(headerMargin);
        doItemsLayout();
    }
}

int ElaTableView::getHeaderMargin() const
{
    Q_D(const ElaTableView);
    return d->_tableViewStyle->getHeaderMargin();
}

void ElaTableView::showEvent(QShowEvent* event)
{
    Q_EMIT tableViewShow();
    QTableView::showEvent(event);
}

void ElaTableView::hideEvent(QHideEvent* event)
{
    Q_EMIT tableViewHide();
    QTableView::hideEvent(event);
}

void ElaTableView::mouseMoveEvent(QMouseEvent* event)
{
    Q_D(ElaTableView);
    if (selectionBehavior() == QAbstractItemView::SelectRows)
    {
        d->_tableViewStyle->setCurrentHoverRow(indexAt(event->pos()).row());
        update();
    }
    QTableView::mouseMoveEvent(event);
}

void ElaTableView::leaveEvent(QEvent* event)
{
    Q_D(ElaTableView);
    if (selectionBehavior() == QAbstractItemView::SelectRows)
    {
        d->_tableViewStyle->setCurrentHoverRow(-1);
        update();
    }
    QTableView::leaveEvent(event);
}

void ElaTableView::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        QModelIndex index = indexAt(event->pos());
        if (index.isValid() && index.column() == 0)
        {
            // 获取单元格的样式选项
            QStyleOptionViewItem option;
            option.rect = visualRect(index);
            option.features = QStyleOptionViewItem::HasCheckIndicator;
            
            // 获取 checkbox 的精确区域
            QRect checkRect = style()->subElementRect(QStyle::SE_ItemViewItemCheckIndicator, &option, this);
            
            // 检查点击是否在 checkbox 区域内
            if (checkRect.contains(event->pos()))
            {
                QVariant state = model()->data(index, Qt::CheckStateRole);
                Qt::CheckState newState = (state.toInt() == Qt::Checked) ? Qt::Unchecked : Qt::Checked;
                model()->setData(index, newState, Qt::CheckStateRole);
                return; // 已处理
            }
        }
    }

    QTableView::mousePressEvent(event);
}

void ElaTableView::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        QModelIndex index = indexAt(event->pos());
        if (index.isValid() && index.column() == 0)
        {
            // 与 mousePressEvent 中已处理，阻止默认委托再次切换
            // 直接吃掉事件，避免二次切换
            event->accept();
            return;
        }
    }

    QTableView::mouseReleaseEvent(event);
}
