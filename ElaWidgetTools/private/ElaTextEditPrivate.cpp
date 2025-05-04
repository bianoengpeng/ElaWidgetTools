#include "ElaTextEditPrivate.h"
#include "ElaApplication.h"
#include "ElaTextEdit.h"
#include <QTimer>
ElaTextEditPrivate::ElaTextEditPrivate(QObject* parent)
    : QObject{parent}
{
}

ElaTextEditPrivate::~ElaTextEditPrivate()
{
}

void ElaTextEditPrivate::onWMWindowClickedEvent(QVariantMap data)
{
    Q_Q(ElaTextEdit);
    ElaAppBarType::WMMouseActionType actionType = data.value("WMClickType").value<ElaAppBarType::WMMouseActionType>();
    if (actionType == ElaAppBarType::WMLBUTTONDOWN)
    {
        if (!q->toPlainText().isEmpty() && q->hasFocus())
        {
            q->clearFocus();
        }
    }
    else if (actionType == ElaAppBarType::WMLBUTTONUP || actionType == ElaAppBarType::WMNCLBUTTONDOWN)
    {
        if (ElaApplication::containsCursorToItem(q) || (actionType == ElaAppBarType::WMLBUTTONUP && !q->toPlainText().isEmpty()))
        {
            return;
        }
        if (q->hasFocus())
        {
            q->clearFocus();
        }
    }
}

void ElaTextEditPrivate::onThemeChanged(ElaThemeType::ThemeMode themeMode)
{
    Q_Q(ElaTextEdit);
    _themeMode = themeMode;
    if (q->isVisible())
    {
        _changeTheme();
    }
    else
    {
        QTimer::singleShot(1, this, [=] {
            _changeTheme();
        });
    }
}

void ElaTextEditPrivate::_changeTheme()
{
    Q_Q(ElaTextEdit);
    if (_themeMode == ElaThemeType::Light)
    {
        QPalette palette;
        palette.setColor(QPalette::Text, Qt::black);
        palette.setColor(QPalette::PlaceholderText, QColor(0x00, 0x00, 0x00, 128));
        q->setPalette(palette);
    }
    else
    {
        QPalette palette;
        palette.setColor(QPalette::Text, Qt::white);
        palette.setColor(QPalette::PlaceholderText, QColor(0xBA, 0xBA, 0xBA));
        q->setPalette(palette);
    }
}
