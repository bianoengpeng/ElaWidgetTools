#ifndef ELADIALOGPRIVATE_H
#define ELADIALOGPRIVATE_H

#include <QObject>

#include "ElaDef.h"
#include "ElaProperty.h"
class QVBoxLayout;
class ElaDialog;
class ElaAppBar;
class ElaMaskWidget;
class ElaDialogPrivate : public QObject
{
    Q_OBJECT
    Q_D_CREATE(ElaDialog)
public:
    explicit ElaDialogPrivate(QObject* parent = nullptr);
    ~ElaDialogPrivate() override;

private:
    qint64 _currentWinID{0};
    ElaThemeType::ThemeMode _themeMode;
    ElaApplicationType::WindowDisplayMode _windowDisplayMode;
    ElaMaskWidget* _maskWidget{nullptr};
    QWidget* _centralWidget{nullptr};
    QVBoxLayout* _mainLayout{nullptr};
    ElaAppBar* _appBar{nullptr};
    void _doCloseAnimation(bool isAccept);
};

#endif // ELADIALOGPRIVATE_H 
