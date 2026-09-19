#ifndef ELAWORKSPACE_ELAWIDGETTOOLS_PRIVATE_ELATEXTEDITPRIVATE_H_
#define ELAWORKSPACE_ELAWIDGETTOOLS_PRIVATE_ELATEXTEDITPRIVATE_H_

#include <QObject>

#include "ElaWidgetToolsDef.h"
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

#endif // ELAWORKSPACE_ELAWIDGETTOOLS_PRIVATE_ELATEXTEDITPRIVATE_H_
