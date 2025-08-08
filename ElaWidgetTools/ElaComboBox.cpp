#include "ElaComboBox.h"

#include "ElaApplication.h"
#include "ElaComboBoxStyle.h"
#include "ElaScrollBar.h"
#include "ElaTheme.h"
#include "private/ElaComboBoxPrivate.h"
#include <QAbstractItemView>
#include <QApplication>
#include <QLayout>
#include <QLineEdit>
#include <QListView>
#include <QMouseEvent>
#include <QPainter>
#include <QPropertyAnimation>
Q_PROPERTY_CREATE_Q_CPP(ElaComboBox, int, BorderRadius)
ElaComboBox::ElaComboBox(QWidget* parent)
    : QComboBox(parent), d_ptr(new ElaComboBoxPrivate())
{
    Q_D(ElaComboBox);
    d->q_ptr = this;
    d->_pBorderRadius = 3;
    d->_themeMode = eTheme->getThemeMode();
    setObjectName("ElaComboBox");
    setFixedHeight(35);
    d->_comboBoxStyle = new ElaComboBoxStyle(style());
    setStyle(d->_comboBoxStyle);

    //调用view 让container初始化
    setView(new QListView(this));
    QAbstractItemView* comboBoxView = this->view();
    comboBoxView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    ElaScrollBar* scrollBar = new ElaScrollBar(this);
    comboBoxView->setVerticalScrollBar(scrollBar);
    ElaScrollBar* floatVScrollBar = new ElaScrollBar(scrollBar, comboBoxView);
    floatVScrollBar->setIsAnimation(true);
    comboBoxView->setAutoScroll(false);
    comboBoxView->setSelectionMode(QAbstractItemView::NoSelection);
    comboBoxView->setObjectName("ElaComboBoxView");
    comboBoxView->setStyleSheet("#ElaComboBoxView{background-color:transparent;}");
    comboBoxView->setStyle(d->_comboBoxStyle);
    QWidget* container = this->findChild<QFrame*>();
    if (container)
    {
        container->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
        container->setAttribute(Qt::WA_TranslucentBackground);
        container->setObjectName("ElaComboBoxContainer");
        container->setStyle(d->_comboBoxStyle);
        QLayout* layout = container->layout();
        while (layout->count())
        {
            layout->takeAt(0);
        }
        layout->addWidget(view());
        layout->setContentsMargins(6, 0, 6, 6);
#ifndef Q_OS_WIN
        container->setStyleSheet("background-color:transparent;");
#endif
    }
    QComboBox::setMaxVisibleItems(5);
    connect(eTheme, &ElaTheme::themeModeChanged, d, &ElaComboBoxPrivate::onThemeChanged);
}

ElaComboBox::~ElaComboBox()
{
    Q_D(ElaComboBox);
    delete d->_comboBoxStyle;
}

void ElaComboBox::setEditable(bool editable)
{
    Q_D(ElaComboBox);
    QComboBox::setEditable(editable);
    if (editable)
    {
        lineEdit()->setStyle(d->_comboBoxStyle);
        d->onThemeChanged(d->_themeMode);
    }
}

void ElaComboBox::paintEvent(QPaintEvent* e)
{
    Q_D(ElaComboBox);
    QPainter painter(this);
    painter.save();
    painter.setRenderHints(QPainter::SmoothPixmapTransform | QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.setPen(ElaThemeColor(d->_themeMode, BasicBorder));
    painter.setBrush(isEnabled() ? underMouse() ? ElaThemeColor(d->_themeMode, BasicHover) : ElaThemeColor(d->_themeMode, BasicBase) : Qt::transparent);
    QRect foregroundRect = rect();
    foregroundRect.adjust(6, 1, -6, -1);
    painter.drawRoundedRect(foregroundRect, d->_pBorderRadius, d->_pBorderRadius);
    // 底边线绘制
    painter.setPen(ElaThemeColor(d->_themeMode, BasicBaseLine));
    painter.drawLine(foregroundRect.x() + 3, foregroundRect.y() + foregroundRect.height(), foregroundRect.x() + foregroundRect.width() - 3, foregroundRect.y() + foregroundRect.height());
    //文字绘制
    painter.setPen(isEnabled() ? ElaThemeColor(d->_themeMode, BasicText) : ElaThemeColor(d->_themeMode, BasicTextDisable));
    QString currentText = painter.fontMetrics().elidedText(this->currentText(), Qt::ElideRight, foregroundRect.width() - 27 - width() * 0.05);
    painter.drawText(15, height() / 2 + painter.fontMetrics().ascent() / 2 - 1, currentText);
    //展开指示器绘制
    painter.setPen(Qt::NoPen);
    painter.setBrush(d->_themeMode == ElaThemeType::Light ? QColor(0x0E, 0x6F, 0xC3) : QColor(0x4C, 0xA0, 0xE0));
    painter.drawRoundedRect(QRectF(foregroundRect.center().x() - d->_comboBoxStyle->getExpandMarkWidth(), foregroundRect.y() + foregroundRect.height() - 3, d->_comboBoxStyle->getExpandMarkWidth() * 2, 3), 2, 2);

    // 展开图标绘制
    if (count() > 0)
    {
        QFont iconFont = QFont("ElaAwesome");
        iconFont.setPixelSize(17);
        painter.setFont(iconFont);
        painter.setPen(isEnabled() ? ElaThemeColor(d->_themeMode, BasicText) : ElaThemeColor(d->_themeMode, BasicTextDisable));
        QRectF expandIconRect(width() - 25, 0, 20, height());
        painter.translate(expandIconRect.x() + (qreal)expandIconRect.width() / 2 - 2, expandIconRect.y() + (qreal)expandIconRect.height() / 2);
        painter.rotate(d->_comboBoxStyle->getExpandIconRotate());
        painter.translate(-expandIconRect.x() - (qreal)expandIconRect.width() / 2 + 2, -expandIconRect.y() - (qreal)expandIconRect.height() / 2);
        painter.drawText(expandIconRect, Qt::AlignVCenter, QChar((unsigned short)ElaIconType::AngleDown));
        painter.restore();
    }
}

void ElaComboBox::showPopup()
{
    Q_D(ElaComboBox);
    bool oldAnimationEffects = qApp->isEffectEnabled(Qt::UI_AnimateCombo);
    qApp->setEffectEnabled(Qt::UI_AnimateCombo, false);
    QComboBox::showPopup();
    qApp->setEffectEnabled(Qt::UI_AnimateCombo, oldAnimationEffects);
    if (count() > 0)
    {
        QWidget* container = this->findChild<QFrame*>();
        if (container)
        {
            int containerHeight = 0;
            if (count() >= maxVisibleItems())
            {
                containerHeight = maxVisibleItems() * 35 + 8;
            }
            else
            {
                containerHeight = count() * 35 + 8;
            }
            view()->resize(view()->width(), containerHeight - 8);
            container->move(container->x(), container->y() + 3);
            QLayout* layout = container->layout();
            while (layout->count())
            {
                layout->takeAt(0);
            }
            QPropertyAnimation* fixedSizeAnimation = new QPropertyAnimation(container, "maximumHeight");
            connect(fixedSizeAnimation, &QPropertyAnimation::valueChanged, this, [=](const QVariant& value) {
                container->setFixedHeight(value.toUInt());
            });
            fixedSizeAnimation->setStartValue(1);
            fixedSizeAnimation->setEndValue(containerHeight);
            fixedSizeAnimation->setEasingCurve(QEasingCurve::OutCubic);
            fixedSizeAnimation->setDuration(400);
            fixedSizeAnimation->start(QAbstractAnimation::DeleteWhenStopped);

            QPropertyAnimation* viewPosAnimation = new QPropertyAnimation(view(), "pos");
            connect(viewPosAnimation, &QPropertyAnimation::finished, this, [=]() {
                d->_isAllowHidePopup = true;
                layout->addWidget(view());
            });
            QPoint viewPos = view()->pos();
            viewPosAnimation->setStartValue(QPoint(viewPos.x(), viewPos.y() - view()->height()));
            viewPosAnimation->setEndValue(viewPos);
            viewPosAnimation->setEasingCurve(QEasingCurve::OutCubic);
            viewPosAnimation->setDuration(400);
            viewPosAnimation->start(QAbstractAnimation::DeleteWhenStopped);
        }
        //指示器动画
        QPropertyAnimation* rotateAnimation = new QPropertyAnimation(d->_comboBoxStyle, "pExpandIconRotate");
        connect(rotateAnimation, &QPropertyAnimation::valueChanged, this, [=](const QVariant& value) {
            update();
        });
        rotateAnimation->setDuration(300);
        rotateAnimation->setEasingCurve(QEasingCurve::InOutSine);
        rotateAnimation->setStartValue(d->_comboBoxStyle->getExpandIconRotate());
        rotateAnimation->setEndValue(-180);
        rotateAnimation->start(QAbstractAnimation::DeleteWhenStopped);
        QPropertyAnimation* markAnimation = new QPropertyAnimation(d->_comboBoxStyle, "pExpandMarkWidth");
        markAnimation->setDuration(300);
        markAnimation->setEasingCurve(QEasingCurve::InOutSine);
        markAnimation->setStartValue(d->_comboBoxStyle->getExpandMarkWidth());
        markAnimation->setEndValue(width() / 2 - d->_pBorderRadius - 6);
        markAnimation->start(QAbstractAnimation::DeleteWhenStopped);
    }
}

void ElaComboBox::hidePopup()
{
    Q_D(ElaComboBox);
    if (d->_isFirstPopup && !this->view()->underMouse())
    {
        d->_isFirstPopup = false;
        return;
    }
    if (eApp->containsCursorToItem(this->view()))
    {
        return;
    }
    else
    {
    if (d->_isAllowHidePopup)
    {
        QWidget* container = this->findChild<QFrame*>();
        int containerHeight = container->height();
        if (container)
        {
            QLayout* layout = container->layout();
            while (layout->count())
            {
                layout->takeAt(0);
            }
            QPropertyAnimation* viewPosAnimation = new QPropertyAnimation(view(), "pos");
            connect(viewPosAnimation, &QPropertyAnimation::finished, this, [=]() {
                layout->addWidget(view());
                QMouseEvent focusEvent(QEvent::MouseButtonPress, QPoint(-1, -1), QPoint(-1, -1), Qt::NoButton, Qt::NoButton, Qt::NoModifier);
                QApplication::sendEvent(parentWidget(), &focusEvent);
                QComboBox::hidePopup();
                container->setFixedHeight(containerHeight);
            });
            QPoint viewPos = view()->pos();
            connect(viewPosAnimation, &QPropertyAnimation::finished, this, [=]() {
                view()->move(viewPos);
            });
            viewPosAnimation->setStartValue(viewPos);
            viewPosAnimation->setEndValue(QPoint(viewPos.x(), viewPos.y() - view()->height()));
            viewPosAnimation->setEasingCurve(QEasingCurve::InCubic);
            viewPosAnimation->start(QAbstractAnimation::DeleteWhenStopped);

            QPropertyAnimation* fixedSizeAnimation = new QPropertyAnimation(container, "maximumHeight");
            connect(fixedSizeAnimation, &QPropertyAnimation::valueChanged, this, [=](const QVariant& value) {
                container->setFixedHeight(value.toUInt());
            });
            fixedSizeAnimation->setStartValue(container->height());
            fixedSizeAnimation->setEndValue(1);
            fixedSizeAnimation->setEasingCurve(QEasingCurve::InCubic);
            fixedSizeAnimation->start(QAbstractAnimation::DeleteWhenStopped);
            d->_isAllowHidePopup = false;
        }
        //指示器动画
        QPropertyAnimation* rotateAnimation = new QPropertyAnimation(d->_comboBoxStyle, "pExpandIconRotate");
        connect(rotateAnimation, &QPropertyAnimation::valueChanged, this, [=](const QVariant& value) {
            update();
        });
        rotateAnimation->setDuration(300);
        rotateAnimation->setEasingCurve(QEasingCurve::InOutSine);
        rotateAnimation->setStartValue(d->_comboBoxStyle->getExpandIconRotate());
        rotateAnimation->setEndValue(0);
        rotateAnimation->start(QAbstractAnimation::DeleteWhenStopped);
        QPropertyAnimation* markAnimation = new QPropertyAnimation(d->_comboBoxStyle, "pExpandMarkWidth");
        markAnimation->setDuration(300);
        markAnimation->setEasingCurve(QEasingCurve::InOutSine);
        markAnimation->setStartValue(d->_comboBoxStyle->getExpandMarkWidth());
        markAnimation->setEndValue(0);
        markAnimation->start(QAbstractAnimation::DeleteWhenStopped);
	    }
	}
}
