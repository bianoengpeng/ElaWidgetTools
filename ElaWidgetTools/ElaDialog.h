#ifndef ELADIALOG_H
#define ELADIALOG_H
#include <QAbstractNativeEventFilter>
#include <QDialog>

#include "ElaDef.h"
#include "ElaAppBar.h"

class ElaDialogPrivate;
class ELA_EXPORT ElaDialog : public QDialog
{
    Q_OBJECT
    Q_Q_CREATE(ElaDialog)
    Q_PROPERTY_CREATE_Q_H(bool, IsStayTop)
    Q_PROPERTY_CREATE_Q_H(bool, IsFixedSize)
    Q_PROPERTY_CREATE_Q_H(bool, IsDefaultClosed)
    Q_PROPERTY_CREATE_Q_H(bool, IsDefaultMinimized)
    Q_PROPERTY_CREATE_Q_H(bool, IsDefaultMaximized)
    Q_PROPERTY_CREATE_Q_H(int, AppBarHeight)
    Q_TAKEOVER_NATIVEEVENT_H
public:
    explicit ElaDialog(QWidget* parent);
    ~ElaDialog() override;
    
    void setCentralWidget(QWidget* centralWidget);
    void close();
    void moveToCenter();
    
    void setFixedSize(const QSize& size);
    void setFixedSize(int width, int height);
    
    void setWindowButtonFlag(ElaAppBarType::ButtonType buttonFlag, bool isEnable = true);
    void setWindowButtonFlags(ElaAppBarType::ButtonFlags buttonFlags);
    ElaAppBarType::ButtonFlags getWindowButtonFlags() const;

Q_SIGNALS:
    Q_SIGNAL void minimizeButtonClicked();
    Q_SIGNAL void maximizeButtonClicked();
    Q_SIGNAL void closeButtonClicked();

protected:
    virtual void showEvent(QShowEvent* event) override;
    virtual void paintEvent(QPaintEvent* event) override;

private:
    void _updateAppBarButtons();
};

#endif // ELADIALOG_H 
