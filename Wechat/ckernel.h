#ifndef CKERNEL_H
#define CKERNEL_H

#include <QObject>
#include "wechatdialog.h"
#include "loginwin.h"
#include "tcpsock.h"
#include "Protocol.h"
#include <mutex>
#include <memory>
#include <functional>

class CKernel : public QObject
{
    Q_OBJECT
//    using fun = void(CKernel::*)(char*);
    using fun = std::function<void(char*)>;

    WeChatDialog*                       m_pWeChat;
    LoginWin*                           m_pLogin;
    Tcpsock*                            m_chat;
    QString                             m_serverIP;
    fun                                 m_ProToFun[PRO_CNT];
    static std::once_flag               m_once;
    static std::unique_ptr<CKernel>     self;

    void SetProFun();

    // 处理函数
    void DealLoginRs(char* con);
    void DealRegRs(char* con);

    explicit CKernel(QObject *parent = nullptr);

public:
    static CKernel* GetKernel();
    void InitConfig();

private slots:
    void slot_destroy();

    void slot_Deal(char* buf);

    // 处理的槽
    void slot_LoginRQ(char*);
    void slot_RegisterRQ(char*);
signals:

};

#endif // CKERNEL_H
