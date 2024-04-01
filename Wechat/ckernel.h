#ifndef CKERNEL_H
#define CKERNEL_H

#include <QObject>
#include "wechatdialog.h"
#include "loginwin.h"
#include "tcpsock.h"
#include "Protocol.h"
#include <functional>

class CKernel : public QObject
{
    Q_OBJECT
//    using fun = void(CKernel::*)(char*);
    using fun = std::function<void(char*)>;

    WeChatDialog* m_pWeChat;
    LoginWin* m_pLogin;
    Tcpsock* m_chat;

    fun m_ProToFun[PRO_CNT];

    void SetProFun();

    // 处理函数
    void DealLoginRs(char* con);
    void DealRegRs(char* con);

public:
    explicit CKernel(QObject *parent = nullptr);
    static CKernel* GetKernel() {
        static CKernel kernel;
        return &kernel;
    }

private slots:
    void slot_destroy();

    void slot_Deal(char* buf);

    // 处理的槽
    void slot_LoginRQ(char*);
    void slot_RegisterRQ(char*);
signals:

};

#endif // CKERNEL_H
