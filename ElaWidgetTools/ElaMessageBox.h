#ifndef ELAMESSAGEBOX_H
#define ELAMESSAGEBOX_H

#include <QDialog>
#include <QMessageBox>
#include <QCheckBox>

#include "ElaProperty.h"

class ElaText;
class ElaPushButton;
class ElaMessageBoxPrivate;
class ELA_EXPORT ElaMessageBox : public QDialog
{
    Q_OBJECT
    Q_Q_CREATE(ElaMessageBox)
public:
    explicit ElaMessageBox(QWidget* parent = nullptr);
    ~ElaMessageBox() override;

    void setTitle(const QString& title);
    void setText(const QString& text);
    void setInformativeText(const QString& text);
    void setDetailedText(const QString& text);
    void setIcon(QMessageBox::Icon icon);
    void setStandardButtons(QMessageBox::StandardButtons buttons);
    void setDefaultButton(QMessageBox::StandardButton button);
    void setButtonText(QMessageBox::StandardButton button, const QString& text);
    void setEscapeButton(QMessageBox::StandardButton button);
    void setWindowIcon(const QIcon& icon);
    void setCheckBox(QCheckBox* checkbox);

    QMessageBox::StandardButton execForResult();

    // 静态便捷方法（签名与 QMessageBox 对齐）
    static QMessageBox::StandardButton information(
        QWidget* parent,
        const QString& title,
        const QString& text,
        QMessageBox::StandardButtons buttons = QMessageBox::Ok,
        QMessageBox::StandardButton defaultButton = QMessageBox::NoButton);

    static QMessageBox::StandardButton question(
        QWidget* parent,
        const QString& title,
        const QString& text,
        QMessageBox::StandardButtons buttons = QMessageBox::StandardButtons(QMessageBox::Yes | QMessageBox::No),
        QMessageBox::StandardButton defaultButton = QMessageBox::NoButton);

    static QMessageBox::StandardButton warning(
        QWidget* parent,
        const QString& title,
        const QString& text,
        QMessageBox::StandardButtons buttons = QMessageBox::Ok,
        QMessageBox::StandardButton defaultButton = QMessageBox::NoButton);

    static QMessageBox::StandardButton critical(
        QWidget* parent,
        const QString& title,
        const QString& text,
        QMessageBox::StandardButtons buttons = QMessageBox::Ok,
        QMessageBox::StandardButton defaultButton = QMessageBox::NoButton);

    static void about(
        QWidget* parent,
        const QString& title,
        const QString& text);

    static void aboutQt(
        QWidget* parent,
        const QString& title = QString());

protected:
    void showEvent(QShowEvent* event) override;
    void paintEvent(QPaintEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
};

#endif // ELAMESSAGEBOX_H
