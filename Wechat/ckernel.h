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
#include "AudioApi/audio_read.h"
#include "AudioApi/audio_write.h"
#include "VideoApi/videoread.h"
#include "VideoApi/screenreader.h"

class CKernel : public QObject
{
    Q_OBJECT
//    using fun = void(CKernel::*)(char*);
    using fun = std::function<void(char*)>;

    WeChatDialog*                       m_pWeChat;
    LoginWin*                           m_pLogin;
    RoomDialog*                         m_pRoom;
    Tcpsock*                            m_chat;
    QString                             m_ip;
    fun                                 m_ProToFun[PRO_CNT];
    QVector<int>                        m_Member;
    int                                 m_RoomId = 0;
    int                                 m_UserId;
    Audio_Write*                        m_pAudio_out;
    Audio_Read*                         m_pAudio_in;
    VideoRead*                          m_pVideo_in;
    ScreenReader*                       m_pScreen_in;

    void SetProFun();
    void InitConfig();

    // 处理函数
    void DealLoginRs(char* con);
    void DealRegRs(char* con);
    void DealCreateRoomRs(char* con);
    void DealJoinRoomRs(char* con);
    void DealJoinInfo(char* con);
    void DealLeaveInfo(char* con);
    void DealVedioClose(char* con);

#if USE_NO_JSON_AUDIO
    void DealAudio(char*, int);
    void DealVedio(char*, int);
#else
    void DealAudio(char* con);
#endif


public:
    explicit CKernel(QObject *parent = nullptr);
    static CKernel* GetKernel() {
        static CKernel kernel;
        return &kernel;
    }

private slots:
    void slot_destroy();

    // 处理的槽
    void slot_Deal(char* buf, int len);

#if USE_NO_JSON_AUDIO
    // 发送音频信息
    void slot_SendRQ(char*, int);
#endif
    // 发送网络信息
    void slot_SendRQ(char*);


    // 创建房间
    void slot_create();

    // 加入房间
    void slot_join();

    // 退出房间
    void slot_QuitRoom();

    // 操作做了音频选项
    void slot_AudioEnabled();
    void slot_AudioUnabled();

    // 关闭音频
    void slot_VedioUnabled();

    // 关闭桌面
    void slot_ScreenUnabled();

    // 发送音频
    void slot_AudioSend(QByteArray buf);

    // 处理视频图像
    void slot_sendVideoFrame(QImage img);
signals:
    void sig_Write(char*, int);
};

#endif // CKERNEL_H
