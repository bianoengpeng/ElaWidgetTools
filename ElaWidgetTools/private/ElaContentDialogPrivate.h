#ifndef ELACONTENTDIALOGPRIVATE_H
#define ELACONTENTDIALOGPRIVATE_H

#include <QObject>

#include "ElaDef.h"
class QVBoxLayout;
class ElaPushButton;
class ElaContentDialog;
class ElaMaskWidget;
class ElaContentDialogPrivate : public QObject
{
    Q_OBJECT
    Q_D_CREATE(ElaContentDialog)
public:
    explicit ElaContentDialogPrivate(QObject* parent = nullptr);
    ~ElaContentDialogPrivate() override;

private:
    qint64 _currentWinID{0};
    ElaThemeType::ThemeMode _themeMode;
    ElaMaskWidget* _maskWidget{nullptr};
    QWidget* _centralWidget{nullptr};
    QWidget* _buttonWidget{nullptr};
    QVBoxLayout* _mainLayout{nullptr};
    QString _leftButtonText{u8"取消"};
    QString _middleButtonText{u8"最小化"};
    QString _rightButtonText{u8"退出"};
    ElaPushButton* _leftButton{nullptr};
    ElaPushButton* _middleButton{nullptr};
    ElaPushButton* _rightButton{nullptr};
    void _doCloseAnimation(bool isAccept);
};

#endif // ELACONTENTDIALOGPRIVATE_H
