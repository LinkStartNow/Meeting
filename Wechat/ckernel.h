#ifndef CKERNEL_H
#define CKERNEL_H

#include <QObject>
#include "wechatdialog.h"
#include "loginwin.h"
#include "tcpsock.h"
#include "roomdialog.h"
#include "Protocol.h"
#include <functional>
#include <QVector>
#include "cjson.h"

class CKernel : public QObject
{
    Q_OBJECT
//    using fun = void(CKernel::*)(char*);
    using fun = std::function<void(char*)>;

    WeChatDialog*       m_pWeChat;
    LoginWin*           m_pLogin;
    RoomDialog*         m_pRoom;
    Tcpsock*            m_chat;
    QString             m_ip;
    fun                 m_ProToFun[PRO_CNT];
    QVector<int>        m_Member;
    int                 m_RoomId = 0;
    int                 m_UserId;

    void SetProFun();
    void InitConfig();

    // 处理函数
    void DealLoginRs(char* con);
    void DealRegRs(char* con);
    void DealCreateRoomRs(char* con);
    void DealJoinRoomRs(char* con);
    void DealJoinInfo(char* con);
    void DealLeaveInfo(char* con);


public:
    explicit CKernel(QObject *parent = nullptr);
    static CKernel* GetKernel() {
        static CKernel kernel;
        return &kernel;
    }

private slots:
    void slot_destroy();

    // 处理的槽
    void slot_Deal(char* buf);

    // 发送网络信息
    void slot_SendRQ(char*);

    // 创建房间
    void slot_create();

    // 加入房间
    void slot_join();

    // 退出房间
    void slot_QuitRoom();
signals:

};

#endif // CKERNEL_H
