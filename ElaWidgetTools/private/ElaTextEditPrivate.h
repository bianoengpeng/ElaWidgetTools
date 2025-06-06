#ifndef ELATEXTEDITPRIVATE_H
#define ELATEXTEDITPRIVATE_H

#include <QObject>

#include "Def.h"
class ElaEvent;
class ElaTextEdit;
class ElaTextEditStyle;
class ElaTextEditPrivate : public QObject
{
    Q_OBJECT
    Q_D_CREATE(ElaTextEdit)

public:
    explicit ElaTextEditPrivate(QObject* parent = nullptr);
    ~ElaTextEditPrivate();
    Q_INVOKABLE void onWMWindowClickedEvent(QVariantMap data);
    Q_SLOT void onThemeChanged(ElaThemeType::ThemeMode themeMode);

private:
    ElaThemeType::ThemeMode _themeMode;
    ElaTextEditStyle* _style{nullptr};
    ElaEvent* _focusEvent{nullptr};
    void _changeTheme();
};

#endif // ELATEXTEDITPRIVATE_H
