#include "ElaTabBarPrivate.h"

#include "ElaTabBar.h"
#include "ElaTabBarStyle.h"

#include <QPropertyAnimation>
#include <private/qtabbar_p.h>

ElaTabBarPrivate::ElaTabBarPrivate(QObject* parent)
    : QObject{parent}
{
    _scrollAnimation = new QPropertyAnimation(this, "pScrollOffset");
    _scrollAnimation->setDuration(200);
    _scrollAnimation->setEasingCurve(QEasingCurve::OutCubic);
}

ElaTabBarPrivate::~ElaTabBarPrivate()
{
}

void ElaTabBarPrivate::startScrollAnimation()
{
    if (qFuzzyCompare(_pScrollOffset, _pTargetScrollOffset))
    {
        return;
    }
    _scrollAnimation->stop();
    _scrollAnimation->setStartValue(_pScrollOffset);
    _scrollAnimation->setEndValue(_pTargetScrollOffset);
    _scrollAnimation->start();
}

void ElaTabBarPrivate::restoreScrollOffset(qreal offset)
{
    Q_Q(ElaTabBar);
    // 不超过当前最大偏移
    int maxOffset = qMax(0, _tabBarPrivate->tabList.size() * _style->getTabSize().width() - q->width());
    offset = qBound(0.0, offset, static_cast<qreal>(maxOffset));
    setTargetScrollOffset(offset);
    setScrollOffset(offset);
    _tabBarPrivate->scrollOffset = qRound(offset);
    q->update();
}
