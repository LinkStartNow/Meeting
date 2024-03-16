#ifndef CKERNEL_H
#define CKERNEL_H

#include <QObject>
#include "wechatdialog.h"

class CKernel : public QObject
{
    Q_OBJECT

    WeChatDialog* m_pWeChat;
public:
    explicit CKernel(QObject *parent = nullptr);
    static CKernel* GetKernel() {
        static CKernel kernel;
        return &kernel;
    }

private slots:
    void slot_destroy();

signals:

};

#endif // CKERNEL_H
