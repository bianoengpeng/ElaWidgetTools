#ifndef ELAINPUTDIALOGPRIVATE_H
#define ELAINPUTDIALOGPRIVATE_H

#include <QObject>
#include <QPointer>
#include <QLineEdit>

#include "ElaDef.h"
#include "ElaProperty.h"
#include "ElaInputDialog.h"

class QVBoxLayout;
class QHBoxLayout;
class QWidget;
class QLabel;
class ElaMaskWidget;
class ElaText;
class ElaPushButton;
class ElaLineEdit;
class ElaComboBox;
class ElaSpinBox;
class ElaDoubleSpinBox;
class ElaTextEdit;
class ElaInputDialog;

class ElaInputDialogPrivate : public QObject
{
    Q_OBJECT
    Q_D_CREATE(ElaInputDialog)
public:
    explicit ElaInputDialogPrivate(QObject* parent = nullptr);
    ~ElaInputDialogPrivate() override;

    void setupUi(QWidget* parentWidget);
    void centerToScreenIfNoParent(QWidget* dialog);
    void doMaskOnShow();
    void switchInputMode(ElaInputDialog::InputMode mode);
    void updateLayout();
    void handleOkClick();
    void handleCancelClick();

public:
    ElaThemeType::ThemeMode themeMode{};
    QPointer<ElaMaskWidget> maskWidget{nullptr};
    QPointer<QWidget> centralWidget{nullptr};
    QPointer<QWidget> buttonBar{nullptr};
    QPointer<QVBoxLayout> mainLayout{nullptr};
    QPointer<QHBoxLayout> buttonLayout{nullptr};
    QPointer<QVBoxLayout> centralLayout{nullptr};

    QPointer<ElaText> titleText{nullptr};
    QPointer<ElaText> labelText{nullptr};
    
    QPointer<ElaLineEdit> lineEdit{nullptr};
    QPointer<ElaComboBox> comboBox{nullptr};
    QPointer<ElaSpinBox> spinBox{nullptr};
    QPointer<ElaDoubleSpinBox> doubleSpinBox{nullptr};
    QPointer<ElaTextEdit> textEdit{nullptr};

    QPointer<ElaPushButton> okButton{nullptr};
    QPointer<ElaPushButton> cancelButton{nullptr};

    ElaInputDialog::InputMode inputMode{ElaInputDialog::TextInput};
    
    QString title{};
    QString label{};
    QString textValue{};
    QString okButtonText{QObject::tr("OK")};
    QString cancelButtonText{QObject::tr("Cancel")};
    QString placeholderText{};
    
    QLineEdit::EchoMode echoMode{QLineEdit::Normal};
    
    int intValue{0};
    int intMin{-2147483647};
    int intMax{2147483647};
    int intStep{1};
    
    double doubleValue{0.0};
    double doubleMin{-2147483647.0};
    double doubleMax{2147483647.0};
    int doubleDecimals{1};
    double doubleStep{1.0};
    
    QStringList comboBoxItems{};
    bool comboBoxEditable{true};
    
    bool isMousePressed{false};
    QPoint mousePressPos{};
    bool canDrag{false};
    
    bool dialogAccepted{false};
};

#endif // ELAINPUTDIALOGPRIVATE_H
