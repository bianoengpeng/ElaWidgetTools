#ifndef ELAINPUTDIALOG_H
#define ELAINPUTDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QStringList>

#include "stdafx.h"

class ElaLineEdit;
class ElaComboBox;
class ElaSpinBox;
class ElaDoubleSpinBox;
class ElaTextEdit;
class ElaInputDialogPrivate;

class ELA_EXPORT ElaInputDialog : public QDialog
{
    Q_OBJECT
    Q_Q_CREATE(ElaInputDialog)
public:
    enum InputMode {
        TextInput,
        IntInput,
        DoubleInput,
        ItemInput,
        MultiLineTextInput
    };
    Q_ENUM(InputMode)

    explicit ElaInputDialog(QWidget* parent = nullptr);
    ~ElaInputDialog() override;

    void setInputMode(InputMode mode);
    InputMode inputMode() const;

    void setLabelText(const QString& text);
    QString labelText() const;

    void setTextValue(const QString& text);
    QString textValue() const;

    void setTextEchoMode(QLineEdit::EchoMode mode);
    QLineEdit::EchoMode textEchoMode() const;

    void setIntValue(int value);
    int intValue() const;

    void setIntMinimum(int min);
    int intMinimum() const;

    void setIntMaximum(int max);
    int intMaximum() const;

    void setIntRange(int min, int max);
    void setIntStep(int step);
    int intStep() const;

    void setDoubleValue(double value);
    double doubleValue() const;

    void setDoubleMinimum(double min);
    double doubleMinimum() const;

    void setDoubleMaximum(double max);
    double doubleMaximum() const;

    void setDoubleRange(double min, double max);
    void setDoubleDecimals(int decimals);
    int doubleDecimals() const;
    void setDoubleStep(double step);
    double doubleStep() const;

    void setComboBoxItems(const QStringList& items);
    QStringList comboBoxItems() const;

    void setComboBoxEditable(bool editable);
    bool isComboBoxEditable() const;

    void setTextInputPlaceholderText(const QString& placeholderText);
    QString textInputPlaceholderText() const;

    void setOkButtonText(const QString& text);
    QString okButtonText() const;

    void setCancelButtonText(const QString& text);
    QString cancelButtonText() const;

    void setTitle(const QString& title);
    QString title() const;

    static QString getText(QWidget* parent, const QString& title, const QString& label,
                          QLineEdit::EchoMode echo = QLineEdit::Normal,
                          const QString& text = QString(), bool* ok = nullptr,
                          Qt::WindowFlags flags = Qt::WindowFlags());

    static QString getMultiLineText(QWidget* parent, const QString& title, const QString& label,
                                   const QString& text = QString(), bool* ok = nullptr,
                                   Qt::WindowFlags flags = Qt::WindowFlags());

    static int getInt(QWidget* parent, const QString& title, const QString& label, int value = 0,
                     int minValue = -2147483647, int maxValue = 2147483647,
                     int step = 1, bool* ok = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());

    static double getDouble(QWidget* parent, const QString& title, const QString& label, double value = 0,
                          double minValue = -2147483647, double maxValue = 2147483647,
                          int decimals = 1, bool* ok = nullptr, Qt::WindowFlags flags = Qt::WindowFlags(),
                          double step = 1);

    static QString getItem(QWidget* parent, const QString& title, const QString& label,
                          const QStringList& items, int current = 0, bool editable = true,
                          bool* ok = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());

protected:
    void showEvent(QShowEvent* event) override;
    void paintEvent(QPaintEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
};

#endif // ELAINPUTDIALOG_H