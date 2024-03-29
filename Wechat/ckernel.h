#ifndef CKERNEL_H
#define CKERNEL_H

#include <QObject>
#include "wechatdialog.h"
#include "loginwin.h"
#include "tcpsock.h"
#include "Protocol.h"

class CKernel : public QObject
{
    Q_OBJECT

    WeChatDialog* m_pWeChat;
    LoginWin* m_pLogin;
    Tcpsock* m_chat;
public:
    explicit CKernel(QObject *parent = nullptr);
    static CKernel* GetKernel() {
        static CKernel kernel;
        return &kernel;
    }

private slots:
    void slot_destroy();

    void slot_Deal(char* buf);
signals:

};

#endif // CKERNEL_H
