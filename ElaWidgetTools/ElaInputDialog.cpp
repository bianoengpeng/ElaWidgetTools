#include "ElaInputDialog.h"

#include <QHBoxLayout>
#include <QPainter>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QVBoxLayout>

#include "ElaTheme.h"
#include "private/ElaInputDialogPrivate.h"
#include "ElaText.h"
#include "ElaMaskWidget.h"
#include "ElaPushButton.h"
#include "ElaLineEdit.h"
#include "ElaComboBox.h"
#include "ElaSpinBox.h"
#include "ElaDoubleSpinBox.h"
#include "ElaTextEdit.h"

ElaInputDialog::ElaInputDialog(QWidget* parent)
    : QDialog{parent}, d_ptr(new ElaInputDialogPrivate())
{
    Q_D(ElaInputDialog);
    d->q_ptr = this;

    setMinimumSize(300, 180);
    resize(400, 200);
    setWindowModality(Qt::ApplicationModal);
    setAttribute(Qt::WA_TranslucentBackground);
#ifdef Q_OS_WIN
    createWinId();
#if (QT_VERSION >= QT_VERSION_CHECK(6, 5, 3) && QT_VERSION <= QT_VERSION_CHECK(6, 6, 1))
    window()->setWindowFlags((window()->windowFlags()) | Qt::WindowMinimizeButtonHint | Qt::FramelessWindowHint);
#else
    window()->setWindowFlags((window()->windowFlags()) | Qt::FramelessWindowHint);
#endif
#else
    window()->setWindowFlags((window()->windowFlags()) | Qt::FramelessWindowHint);
#endif

    d->themeMode = eTheme->getThemeMode();
    connect(eTheme, &ElaTheme::themeModeChanged, this, [=](ElaThemeType::ThemeMode mode) {
        d->themeMode = mode;
        update();
    });

    d->setupUi(parent);
}

ElaInputDialog::~ElaInputDialog() = default;

void ElaInputDialog::setInputMode(InputMode mode)
{
    Q_D(ElaInputDialog);
    d->switchInputMode(mode);
}

ElaInputDialog::InputMode ElaInputDialog::inputMode() const
{
    Q_D(const ElaInputDialog);
    return d->inputMode;
}

void ElaInputDialog::setLabelText(const QString& text)
{
    Q_D(ElaInputDialog);
    d->label = text;
    if (d->labelText)
        d->labelText->setText(text);
}

QString ElaInputDialog::labelText() const
{
    Q_D(const ElaInputDialog);
    return d->label;
}

void ElaInputDialog::setTextValue(const QString& text)
{
    Q_D(ElaInputDialog);
    d->textValue = text;
    if (d->lineEdit && d->inputMode == TextInput)
        d->lineEdit->setText(text);
    else if (d->textEdit && d->inputMode == MultiLineTextInput)
        d->textEdit->setPlainText(text);
}

QString ElaInputDialog::textValue() const
{
    Q_D(const ElaInputDialog);
    if (d->inputMode == TextInput && d->lineEdit)
        return d->lineEdit->text();
    else if (d->inputMode == MultiLineTextInput && d->textEdit)
        return d->textEdit->toPlainText();
    else if (d->inputMode == ItemInput && d->comboBox)
        return d->comboBox->currentText();
    return d->textValue;
}

void ElaInputDialog::setTextEchoMode(QLineEdit::EchoMode mode)
{
    Q_D(ElaInputDialog);
    d->echoMode = mode;
    if (d->lineEdit)
        d->lineEdit->setEchoMode(mode);
}

QLineEdit::EchoMode ElaInputDialog::textEchoMode() const
{
    Q_D(const ElaInputDialog);
    return d->echoMode;
}

void ElaInputDialog::setIntValue(int value)
{
    Q_D(ElaInputDialog);
    d->intValue = value;
    if (d->spinBox)
        d->spinBox->setValue(value);
}

int ElaInputDialog::intValue() const
{
    Q_D(const ElaInputDialog);
    if (d->spinBox && d->inputMode == IntInput)
        return d->spinBox->value();
    return d->intValue;
}

void ElaInputDialog::setIntMinimum(int min)
{
    Q_D(ElaInputDialog);
    d->intMin = min;
    if (d->spinBox)
        d->spinBox->setMinimum(min);
}

int ElaInputDialog::intMinimum() const
{
    Q_D(const ElaInputDialog);
    return d->intMin;
}

void ElaInputDialog::setIntMaximum(int max)
{
    Q_D(ElaInputDialog);
    d->intMax = max;
    if (d->spinBox)
        d->spinBox->setMaximum(max);
}

int ElaInputDialog::intMaximum() const
{
    Q_D(const ElaInputDialog);
    return d->intMax;
}

void ElaInputDialog::setIntRange(int min, int max)
{
    setIntMinimum(min);
    setIntMaximum(max);
}

void ElaInputDialog::setIntStep(int step)
{
    Q_D(ElaInputDialog);
    d->intStep = step;
    if (d->spinBox)
        d->spinBox->setSingleStep(step);
}

int ElaInputDialog::intStep() const
{
    Q_D(const ElaInputDialog);
    return d->intStep;
}

void ElaInputDialog::setDoubleValue(double value)
{
    Q_D(ElaInputDialog);
    d->doubleValue = value;
    if (d->doubleSpinBox)
        d->doubleSpinBox->setValue(value);
}

double ElaInputDialog::doubleValue() const
{
    Q_D(const ElaInputDialog);
    if (d->doubleSpinBox && d->inputMode == DoubleInput)
        return d->doubleSpinBox->value();
    return d->doubleValue;
}

void ElaInputDialog::setDoubleMinimum(double min)
{
    Q_D(ElaInputDialog);
    d->doubleMin = min;
    if (d->doubleSpinBox)
        d->doubleSpinBox->setMinimum(min);
}

double ElaInputDialog::doubleMinimum() const
{
    Q_D(const ElaInputDialog);
    return d->doubleMin;
}

void ElaInputDialog::setDoubleMaximum(double max)
{
    Q_D(ElaInputDialog);
    d->doubleMax = max;
    if (d->doubleSpinBox)
        d->doubleSpinBox->setMaximum(max);
}

double ElaInputDialog::doubleMaximum() const
{
    Q_D(const ElaInputDialog);
    return d->doubleMax;
}

void ElaInputDialog::setDoubleRange(double min, double max)
{
    setDoubleMinimum(min);
    setDoubleMaximum(max);
}

void ElaInputDialog::setDoubleDecimals(int decimals)
{
    Q_D(ElaInputDialog);
    d->doubleDecimals = decimals;
    if (d->doubleSpinBox)
        d->doubleSpinBox->setDecimals(decimals);
}

int ElaInputDialog::doubleDecimals() const
{
    Q_D(const ElaInputDialog);
    return d->doubleDecimals;
}

void ElaInputDialog::setDoubleStep(double step)
{
    Q_D(ElaInputDialog);
    d->doubleStep = step;
    if (d->doubleSpinBox)
        d->doubleSpinBox->setSingleStep(step);
}

double ElaInputDialog::doubleStep() const
{
    Q_D(const ElaInputDialog);
    return d->doubleStep;
}

void ElaInputDialog::setComboBoxItems(const QStringList& items)
{
    Q_D(ElaInputDialog);
    d->comboBoxItems = items;
    if (d->comboBox)
    {
        d->comboBox->clear();
        d->comboBox->addItems(items);
    }
}

QStringList ElaInputDialog::comboBoxItems() const
{
    Q_D(const ElaInputDialog);
    return d->comboBoxItems;
}

void ElaInputDialog::setComboBoxEditable(bool editable)
{
    Q_D(ElaInputDialog);
    d->comboBoxEditable = editable;
    if (d->comboBox)
        d->comboBox->setEditable(editable);
}

bool ElaInputDialog::isComboBoxEditable() const
{
    Q_D(const ElaInputDialog);
    return d->comboBoxEditable;
}

void ElaInputDialog::setTextInputPlaceholderText(const QString& placeholderText)
{
    Q_D(ElaInputDialog);
    d->placeholderText = placeholderText;
    if (d->lineEdit)
        d->lineEdit->setPlaceholderText(placeholderText);
}

QString ElaInputDialog::textInputPlaceholderText() const
{
    Q_D(const ElaInputDialog);
    return d->placeholderText;
}

void ElaInputDialog::setOkButtonText(const QString& text)
{
    Q_D(ElaInputDialog);
    d->okButtonText = text;
    if (d->okButton)
        d->okButton->setText(text);
}

QString ElaInputDialog::okButtonText() const
{
    Q_D(const ElaInputDialog);
    return d->okButtonText;
}

void ElaInputDialog::setCancelButtonText(const QString& text)
{
    Q_D(ElaInputDialog);
    d->cancelButtonText = text;
    if (d->cancelButton)
        d->cancelButton->setText(text);
}

QString ElaInputDialog::cancelButtonText() const
{
    Q_D(const ElaInputDialog);
    return d->cancelButtonText;
}

void ElaInputDialog::setTitle(const QString& title)
{
    Q_D(ElaInputDialog);
    d->title = title;
    if (d->titleText)
        d->titleText->setText(title);
}

QString ElaInputDialog::title() const
{
    Q_D(const ElaInputDialog);
    return d->title;
}

QString ElaInputDialog::getText(QWidget* parent, const QString& title, const QString& label,
                               QLineEdit::EchoMode echo, const QString& text, bool* ok,
                               Qt::WindowFlags flags)
{
    ElaInputDialog dialog(parent);
    dialog.setWindowFlags(dialog.windowFlags() | flags);
    dialog.setInputMode(TextInput);
    dialog.setTitle(title);
    dialog.setLabelText(label);
    dialog.setTextValue(text);
    dialog.setTextEchoMode(echo);
    
    const int ret = dialog.exec();
    if (ok)
        *ok = (ret == QDialog::Accepted);
    
    if (ret == QDialog::Accepted)
        return dialog.textValue();
    return QString();
}

QString ElaInputDialog::getMultiLineText(QWidget* parent, const QString& title, const QString& label,
                                        const QString& text, bool* ok, Qt::WindowFlags flags)
{
    ElaInputDialog dialog(parent);
    dialog.setWindowFlags(dialog.windowFlags() | flags);
    dialog.setInputMode(MultiLineTextInput);
    dialog.setTitle(title);
    dialog.setLabelText(label);
    dialog.setTextValue(text);
    
    const int ret = dialog.exec();
    if (ok)
        *ok = (ret == QDialog::Accepted);
    
    if (ret == QDialog::Accepted)
        return dialog.textValue();
    return QString();
}

int ElaInputDialog::getInt(QWidget* parent, const QString& title, const QString& label, int value,
                          int minValue, int maxValue, int step, bool* ok, Qt::WindowFlags flags)
{
    ElaInputDialog dialog(parent);
    dialog.setWindowFlags(dialog.windowFlags() | flags);
    dialog.setInputMode(IntInput);
    dialog.setTitle(title);
    dialog.setLabelText(label);
    dialog.setIntValue(value);
    dialog.setIntRange(minValue, maxValue);
    dialog.setIntStep(step);
    
    const int ret = dialog.exec();
    if (ok)
        *ok = (ret == QDialog::Accepted);
    
    if (ret == QDialog::Accepted)
        return dialog.intValue();
    return value;
}

double ElaInputDialog::getDouble(QWidget* parent, const QString& title, const QString& label, double value,
                                double minValue, double maxValue, int decimals, bool* ok,
                                Qt::WindowFlags flags, double step)
{
    ElaInputDialog dialog(parent);
    dialog.setWindowFlags(dialog.windowFlags() | flags);
    dialog.setInputMode(DoubleInput);
    dialog.setTitle(title);
    dialog.setLabelText(label);
    dialog.setDoubleValue(value);
    dialog.setDoubleRange(minValue, maxValue);
    dialog.setDoubleDecimals(decimals);
    dialog.setDoubleStep(step);
    
    const int ret = dialog.exec();
    if (ok)
        *ok = (ret == QDialog::Accepted);
    
    if (ret == QDialog::Accepted)
        return dialog.doubleValue();
    return value;
}

QString ElaInputDialog::getItem(QWidget* parent, const QString& title, const QString& label,
                              const QStringList& items, int current, bool editable,
                              bool* ok, Qt::WindowFlags flags)
{
    ElaInputDialog dialog(parent);
    dialog.setWindowFlags(dialog.windowFlags() | flags);
    dialog.setInputMode(ItemInput);
    dialog.setTitle(title);
    dialog.setLabelText(label);
    dialog.setComboBoxItems(items);
    dialog.setComboBoxEditable(editable);
    
    ElaInputDialogPrivate* d = dialog.d_ptr.data();
    if (d && d->comboBox && current >= 0 && current < items.count())
        d->comboBox->setCurrentIndex(current);
    
    const int ret = dialog.exec();
    if (ok)
        *ok = (ret == QDialog::Accepted);
    
    if (ret == QDialog::Accepted)
        return dialog.textValue();
    return QString();
}

void ElaInputDialog::showEvent(QShowEvent* event)
{
    Q_D(ElaInputDialog);
    d->doMaskOnShow();
    d->centerToScreenIfNoParent(this);
    QDialog::showEvent(event);
}

void ElaInputDialog::paintEvent(QPaintEvent* event)
{
    Q_D(ElaInputDialog);
    Q_UNUSED(event);
    QPainter painter(this);
    painter.save();
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.setPen(Qt::NoPen);
    painter.setBrush(ElaThemeColor(d->themeMode, DialogBase));
    
    painter.drawRoundedRect(rect(), 8, 8);
    
    painter.setBrush(ElaThemeColor(d->themeMode, DialogLayoutArea));
    painter.drawRoundedRect(QRectF(0, height() - 60, width(), 60), 8, 8);
    
    painter.restore();
}

void ElaInputDialog::keyPressEvent(QKeyEvent* event)
{
    Q_D(ElaInputDialog);
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
    {
        d->handleOkClick();
        return;
    }
    else if (event->key() == Qt::Key_Escape)
    {
        d->handleCancelClick();
        return;
    }
    QDialog::keyPressEvent(event);
}

void ElaInputDialog::mousePressEvent(QMouseEvent* event)
{
    Q_D(ElaInputDialog);
    if (event->button() == Qt::LeftButton)
    {
        d->isMousePressed = true;
        d->mousePressPos = event->globalPos() - this->frameGeometry().topLeft();
        
        if (event->y() < height() - 60)
        {
            d->canDrag = true;
        }
        else
        {
            d->canDrag = false;
        }
    }
    QDialog::mousePressEvent(event);
}

void ElaInputDialog::mouseReleaseEvent(QMouseEvent* event)
{
    Q_D(ElaInputDialog);
    d->isMousePressed = false;
    d->canDrag = false;
    QDialog::mouseReleaseEvent(event);
}

void ElaInputDialog::mouseMoveEvent(QMouseEvent* event)
{
    Q_D(ElaInputDialog);
    if (d->isMousePressed && d->canDrag && (event->buttons() & Qt::LeftButton))
    {
        move(event->globalPos() - d->mousePressPos);
    }
    QDialog::mouseMoveEvent(event);
}