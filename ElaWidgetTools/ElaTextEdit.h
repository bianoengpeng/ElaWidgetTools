#ifndef ELAWORKSPACE_ELAWIDGETTOOLS_ELATEXTEDIT_H_
#define ELAWORKSPACE_ELAWIDGETTOOLS_ELATEXTEDIT_H_

#include <QTextEdit>

#include "ElaWidgetToolsExport.h"
#include "ElaPropertyMacro.h"

class ElaTextEditPrivate;
class ELA_EXPORT ElaTextEdit : public QTextEdit
{
    Q_OBJECT
    Q_Q_CREATE(ElaTextEdit)
public:
    explicit ElaTextEdit(QWidget* parent = nullptr);
    explicit ElaTextEdit(const QString& text, QWidget* parent = nullptr);
    virtual ~ElaTextEdit();

protected:
    virtual void focusInEvent(QFocusEvent* event) override;
    virtual void focusOutEvent(QFocusEvent* event) override;
    virtual void contextMenuEvent(QContextMenuEvent* event) override;
};

#endif // ELAWORKSPACE_ELAWIDGETTOOLS_ELATEXTEDIT_H_
