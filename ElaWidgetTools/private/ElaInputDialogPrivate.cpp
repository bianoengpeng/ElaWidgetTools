#include "ElaInputDialogPrivate.h"

#include <QApplication>
#include <QGuiApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <QScreen>
#include <QVBoxLayout>

#include "ElaInputDialog.h"
#include "ElaMaskWidget.h"
#include "ElaText.h"
#include "ElaTheme.h"
#include "ElaPushButton.h"
#include "ElaLineEdit.h"
#include "ElaComboBox.h"
#include "ElaSpinBox.h"
#include "ElaDoubleSpinBox.h"
#include "ElaTextEdit.h"
#include "Def.h"

ElaInputDialogPrivate::ElaInputDialogPrivate(QObject* parent)
    : QObject{parent}
{
}

ElaInputDialogPrivate::~ElaInputDialogPrivate() = default;

void ElaInputDialogPrivate::setupUi(QWidget* parentWidget)
{
    Q_Q(ElaInputDialog);

    if (parentWidget != nullptr)
    {
        maskWidget = new ElaMaskWidget(parentWidget);
        maskWidget->move(0, 0);
        maskWidget->setFixedSize(parentWidget->size());
        maskWidget->setVisible(false);
    }
    else
    {
        maskWidget = nullptr;
    }

    centralWidget = new QWidget(q);
    centralLayout = new QVBoxLayout(centralWidget);
    centralLayout->setContentsMargins(20, 25, 20, 15);
    centralLayout->setSpacing(12);

    titleText = new ElaText(title.isEmpty() ? QString() : title, q);
    titleText->setTextStyle(ElaTextType::Title);
    
    labelText = new ElaText(label.isEmpty() ? QString() : label, q);
    labelText->setTextStyle(ElaTextType::Body);

    centralLayout->addWidget(titleText);
    centralLayout->addWidget(labelText);

    lineEdit = new ElaLineEdit(q);
    lineEdit->setText(textValue);
    lineEdit->setEchoMode(echoMode);
    if (!placeholderText.isEmpty())
    {
        lineEdit->setPlaceholderText(placeholderText);
    }
    centralLayout->addWidget(lineEdit);

    comboBox = new ElaComboBox(q);
    comboBox->addItems(comboBoxItems);
    comboBox->setEditable(comboBoxEditable);
    comboBox->setVisible(false);
    centralLayout->addWidget(comboBox);

    spinBox = new ElaSpinBox(q);
    spinBox->setValue(intValue);
    spinBox->setMinimum(intMin);
    spinBox->setMaximum(intMax);
    spinBox->setSingleStep(intStep);
    spinBox->setVisible(false);
    centralLayout->addWidget(spinBox);

    doubleSpinBox = new ElaDoubleSpinBox(q);
    doubleSpinBox->setValue(doubleValue);
    doubleSpinBox->setMinimum(doubleMin);
    doubleSpinBox->setMaximum(doubleMax);
    doubleSpinBox->setDecimals(doubleDecimals);
    doubleSpinBox->setSingleStep(doubleStep);
    doubleSpinBox->setVisible(false);
    centralLayout->addWidget(doubleSpinBox);

    textEdit = new ElaTextEdit(q);
    textEdit->setPlainText(textValue);
    textEdit->setMaximumHeight(150);
    textEdit->setVisible(false);
    centralLayout->addWidget(textEdit);

    centralLayout->addStretch();

    mainLayout = new QVBoxLayout(q);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    
    buttonBar = new QWidget(q);
    buttonBar->setFixedHeight(60);
    buttonLayout = new QHBoxLayout(buttonBar);
    buttonLayout->setContentsMargins(20, 0, 20, 0);
    buttonLayout->setSpacing(10);

    buttonLayout->addStretch();

    cancelButton = new ElaPushButton(cancelButtonText, q);
    cancelButton->setMinimumSize(0, 0);
    cancelButton->setMaximumSize(QSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX));
    cancelButton->setFixedHeight(38);
    cancelButton->setBorderRadius(6);
    QObject::connect(cancelButton, &ElaPushButton::clicked, q, [this]() {
        handleCancelClick();
    });
    buttonLayout->addWidget(cancelButton);

    okButton = new ElaPushButton(okButtonText, q);
    okButton->setMinimumSize(0, 0);
    okButton->setMaximumSize(QSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX));
    okButton->setFixedHeight(38);
    okButton->setBorderRadius(6);
    okButton->setLightDefaultColor(ElaThemeColor(ElaThemeType::Light, PrimaryNormal));
    okButton->setLightHoverColor(ElaThemeColor(ElaThemeType::Light, PrimaryHover));
    okButton->setLightPressColor(ElaThemeColor(ElaThemeType::Light, PrimaryPress));
    okButton->setLightTextColor(Qt::white);
    okButton->setDarkDefaultColor(ElaThemeColor(ElaThemeType::Dark, PrimaryNormal));
    okButton->setDarkHoverColor(ElaThemeColor(ElaThemeType::Dark, PrimaryHover));
    okButton->setDarkPressColor(ElaThemeColor(ElaThemeType::Dark, PrimaryPress));
    okButton->setDarkTextColor(Qt::black);
    QObject::connect(okButton, &ElaPushButton::clicked, q, [this]() {
        handleOkClick();
    });
    buttonLayout->addWidget(okButton);

    mainLayout->addWidget(centralWidget);
    mainLayout->addWidget(buttonBar);

    switchInputMode(inputMode);
}

void ElaInputDialogPrivate::centerToScreenIfNoParent(QWidget* dialog)
{
    if (!dialog || dialog->parentWidget())
    {
        return;
    }
    auto* screen = QGuiApplication::primaryScreen();
    if (!screen)
    {
        return;
    }
    const QRect scr = screen->geometry();
    const QSize sz = dialog->size();
    const int x = scr.x() + (scr.width() - sz.width()) / 2;
    const int y = scr.y() + (scr.height() - sz.height()) / 2;
    dialog->move(x, y);
}

void ElaInputDialogPrivate::doMaskOnShow()
{
    if (maskWidget && maskWidget->parentWidget())
    {
        maskWidget->setVisible(true);
        maskWidget->raise();
        maskWidget->setFixedSize(maskWidget->parentWidget()->size());
        maskWidget->doMaskAnimation(90);
    }
}

void ElaInputDialogPrivate::switchInputMode(ElaInputDialog::InputMode mode)
{
    Q_Q(ElaInputDialog);
    inputMode = mode;
    
    if (!lineEdit || !comboBox || !spinBox || !doubleSpinBox || !textEdit)
        return;

    lineEdit->setVisible(mode == ElaInputDialog::TextInput);
    comboBox->setVisible(mode == ElaInputDialog::ItemInput);
    spinBox->setVisible(mode == ElaInputDialog::IntInput);
    doubleSpinBox->setVisible(mode == ElaInputDialog::DoubleInput);
    textEdit->setVisible(mode == ElaInputDialog::MultiLineTextInput);

    switch (mode)
    {
    case ElaInputDialog::TextInput:
        lineEdit->setFocus();
        break;
    case ElaInputDialog::IntInput:
        spinBox->setFocus();
        break;
    case ElaInputDialog::DoubleInput:
        doubleSpinBox->setFocus();
        break;
    case ElaInputDialog::ItemInput:
        comboBox->setFocus();
        break;
    case ElaInputDialog::MultiLineTextInput:
        textEdit->setFocus();
        break;
    }

    updateLayout();
}

void ElaInputDialogPrivate::updateLayout()
{
    Q_Q(ElaInputDialog);
    
    switch (inputMode)
    {
    case ElaInputDialog::MultiLineTextInput:
        q->resize(450, 300);
        break;
    default:
        q->resize(400, 200);
        break;
    }
}

void ElaInputDialogPrivate::handleOkClick()
{
    Q_Q(ElaInputDialog);
    dialogAccepted = true;
    
    switch (inputMode)
    {
    case ElaInputDialog::TextInput:
        textValue = lineEdit->text();
        break;
    case ElaInputDialog::IntInput:
        intValue = spinBox->value();
        break;
    case ElaInputDialog::DoubleInput:
        doubleValue = doubleSpinBox->value();
        break;
    case ElaInputDialog::ItemInput:
        textValue = comboBox->currentText();
        break;
    case ElaInputDialog::MultiLineTextInput:
        textValue = textEdit->toPlainText();
        break;
    }
    
    if (maskWidget)
    {
        maskWidget->doMaskAnimation(0);
    }
    q->accept();
}

void ElaInputDialogPrivate::handleCancelClick()
{
    Q_Q(ElaInputDialog);
    dialogAccepted = false;
    
    if (maskWidget)
    {
        maskWidget->doMaskAnimation(0);
    }
    q->reject();
}