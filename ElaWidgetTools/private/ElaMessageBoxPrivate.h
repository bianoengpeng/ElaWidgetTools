#ifndef ELAMESSAGEBOXPRIVATE_H
#define ELAMESSAGEBOXPRIVATE_H

#include <QObject>
#include <QMap>
#include <QMessageBox>
#include <QPointer>

#include "ElaDef.h"
#include "ElaProperty.h"

class QVBoxLayout;
class QHBoxLayout;
class QLabel;
class QWidget;
class QCheckBox;
class ElaMaskWidget;
class ElaText;
class ElaPushButton;
class ElaMessageBox;

class ElaMessageBoxPrivate : public QObject
{
    Q_OBJECT
    Q_D_CREATE(ElaMessageBox)
public:
    explicit ElaMessageBoxPrivate(QObject* parent = nullptr);
    ~ElaMessageBoxPrivate() override;

    void setupUi(QWidget* parentWidget);
    void applyButtons();
    void applyDefaultButton();
    void centerToScreenIfNoParent(QWidget* dialog);
    void doMaskOnShow();

public:
    ElaThemeType::ThemeMode themeMode{};
    QPointer<ElaMaskWidget> maskWidget{nullptr};
    QPointer<QWidget> centralWidget{nullptr};
    QPointer<QWidget> buttonBar{nullptr};
    QPointer<QVBoxLayout> mainLayout{nullptr};
    QPointer<QHBoxLayout> buttonLayout{nullptr};
    QPointer<QLabel> iconLabel{nullptr};

    QPointer<ElaText> titleText{nullptr};
    QPointer<ElaText> bodyText{nullptr};
    QPointer<ElaText> informativeText{nullptr};
    QPointer<ElaText> detailedText{nullptr};
    QPointer<ElaPushButton> detailsButton{nullptr};
    QPointer<QCheckBox> checkBox{nullptr};

    QMessageBox::Icon icon{QMessageBox::NoIcon};
    QString title{};
    QString text{};
    QString informativeTextStr{};
    QString detailedTextStr{};
    QMessageBox::StandardButtons buttons{QMessageBox::Ok};
    QMessageBox::StandardButton defaultButton{QMessageBox::NoButton};
    QMessageBox::StandardButton escapeButton{QMessageBox::NoButton};
    QMap<QMessageBox::StandardButton, QString> customButtonTexts{};

    // 运行时结果
    QMessageBox::StandardButton clickedResult{QMessageBox::NoButton};

    QMap<QMessageBox::StandardButton, ElaPushButton*> buttonMap{};
    
    // 拖动支持
    bool isMousePressed{false};
    QPoint mousePressPos{};
    bool canDrag{false};

    void updateIcon();
};

#endif // ELAMESSAGEBOXPRIVATE_H


