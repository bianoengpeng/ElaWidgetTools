#include "ElaDialogPrivate.h"

#include "ElaDialog.h"
#include "ElaMaskWidget.h"
ElaDialogPrivate::ElaDialogPrivate(QObject* parent)
    : QObject{parent}
{
}

ElaDialogPrivate::~ElaDialogPrivate()
{
}

void ElaDialogPrivate::_doCloseAnimation(bool isAccept)
{
    Q_Q(ElaDialog);
    // 执行遮罩关闭动画
    if (_maskWidget) {
        _maskWidget->doMaskAnimation(0);
    }
    // 关闭对话框
    isAccept ? q->accept() : q->reject();
} 