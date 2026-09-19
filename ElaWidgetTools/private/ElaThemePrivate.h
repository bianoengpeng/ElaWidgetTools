#ifndef ELAWORKSPACE_ELAWIDGETTOOLS_PRIVATE_ELATHEMEPRIVATE_H_
#define ELAWORKSPACE_ELAWIDGETTOOLS_PRIVATE_ELATHEMEPRIVATE_H_

#include <QColor>
#include <QMap>
#include <QObject>

#include "ElaWidgetToolsDef.h"
class ElaTheme;
class ElaThemePrivate : public QObject
{
    Q_OBJECT
    Q_D_CREATE(ElaTheme)
public:
    explicit ElaThemePrivate(QObject* parent = nullptr);
    ~ElaThemePrivate();

private:
    ElaThemeType::ThemeMode _themeMode{ElaThemeType::Light};
    QColor _lightThemeColorList[403];
    QColor _darkThemeColorList[403];
    void _initThemeColor();
};

#endif // ELAWORKSPACE_ELAWIDGETTOOLS_PRIVATE_ELATHEMEPRIVATE_H_

