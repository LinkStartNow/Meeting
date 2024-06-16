#include "ckernel.h"
#include <QDebug>
#include "cjson.h"
#include <QMessageBox>
#include "usershow.h"

#define FUNMAP(a) m_ProToFun[a - PRO_BASE]

void CKernel::SetProFun()
{

    memset(m_ProToFun, 0, sizeof (m_ProToFun));

    FUNMAP(LOG_RS)           = std::bind(&CKernel::DealLoginRs, this, std::placeholders::_1);
    FUNMAP(REG_RS)           = std::bind(&CKernel::DealRegRs, this, std::placeholders::_1);
    FUNMAP(CREATE_ROOM_RS)   = std::bind(&CKernel::DealCreateRoomRs, this, std::placeholders::_1);
    FUNMAP(JOIN_ROOM_RS)     = std::bind(&CKernel::DealJoinRoomRs, this, std::placeholders::_1);
    FUNMAP(JOIN_INFO)        = std::bind(&CKernel::DealJoinInfo, this, std::placeholders::_1);
    FUNMAP(LEAVE_INFO)       = std::bind(&CKernel::DealLeaveInfo, this, std::placeholders::_1);
    FUNMAP(CLOSE_VEDIO)      = std::bind(&CKernel::DealVedioClose, this, std::placeholders::_1);

#if !USE_NO_JSON_AUDIO
    FUNMAP(AUDIO)            = std::bind(&CKernel::DealAudio, this, std::placeholders::_1);
#endif
}

#include <QFileInfo>
#include <QApplication>
#include <QSettings>
void CKernel::InitConfig()
{
    qDebug() << __func__;
    m_ip = IP;
    // 获取路径
    QString path = QApplication::applicationDirPath() + "/config.ini";

    QFileInfo test(path);
    QSettings set(path, QSettings::IniFormat, nullptr);
    if (test.exists()) {
        // 存在，则读取IP
        // 打开组
        set.beginGroup("Net");

        // 读取值
        m_ip = set.value("ip").toString();

        // 关闭组
        set.endGroup();
    }
    else {
        // 不存在，写入IP
        // 打开组
        set.beginGroup("Net");

        // 写入值
        set.setValue("ip", m_ip);

        // 关闭组
        set.endGroup();
    }
}

void CKernel::DealLoginRs(char *con)
{
    qDebug() << __func__;

    CJson json(con);
    delete [] con, con = nullptr;

    int result = json.json_get_int("result");
    switch (result) {
    case LOG_SUCCESS: {
        QString name = json.json_get_string("name");
        QMessageBox::information(nullptr, "提示", QString("用户名:%1, 个性签名:%2, id:%3")
                                 .arg(name)
                                 .arg(json.json_get_string("feeling"))
                                 .arg(json.json_get_int("id")));
        m_UserId = json.json_get_int("id");
        m_pWeChat->SetInfo(name);
        m_pLogin->hide();
        m_pWeChat->showNormal();
        break;
    }
    case USER_MISS: {
        QMessageBox::information(nullptr, "提示", "用户不存在，请检查手机号！");
        break;
    }
    case PASS_ERROR: {
        QMessageBox::information(nullptr, "提示", "密码错误，请重新输入！");
        break;
    }
    }
}

void CKernel::DealRegRs(char *con)
{
    qDebug() << __func__;

    CJson json(con);
    delete [] con, con = nullptr;

    int result = json.json_get_int("result");
    switch (result) {
    case REG_SUCCESS: {
        QMessageBox::information(nullptr, "提示", "注册成功！");
        break;
    }
    case NAME_USED: {
        QMessageBox::information(nullptr, "提示", "用户名已被使用！");
        break;
    }
    case TEL_USED: {
        QMessageBox::information(nullptr, "提示", "此手机号已经注册过用户！");
        break;
    }
    }
}

void CKernel::DealCreateRoomRs(char *con)
{
    qDebug() << __func__;

    CJson json(con);
    delete [] con, con = nullptr;

    m_RoomId = json.json_get_int("RoomId");
//    m_pRoom = new RoomDialog;
    m_pRoom->SetInfo(QString::number(m_RoomId), m_UserId);
//    connect(m_pRoom, &RoomDialog::sig_QuitRoom, this, &CKernel::slot_QuitRoom);
    m_pRoom->showNormal();
    qDebug() << "room:" << m_RoomId;
    m_pWeChat->hide();

    // 测试item添加
//    for (int i = 0; i < 10; ++i) {
//        UserShow* item = new UserShow;
//        item->SetInfo(QString("测试用户%1").arg(i), 233);
//        m_pRoom->AddUser(item);
//    }
}

#include <vector>
void CKernel::DealJoinRoomRs(char *con)
{
    qDebug() << __func__;

    CJson json(con);
    delete [] con, con = nullptr;

    int result = json.json_get_int("result");
    switch (result) {
    case JOIN_SUCCESS: {
        m_RoomId = json.json_get_int("RoomId");
        m_Member = json.json_get_int_list("MemberList");

        // 创建并初始化房间
        m_pRoom->SetInfo(QString::number(m_RoomId), m_UserId);
        qDebug() << "room:" << m_RoomId;
        m_pRoom->showNormal();
        m_pWeChat->hide();

        QMessageBox::about(m_pWeChat, "提示", "加入房间成功，欢迎！");
//        QString tmp;
//        for (int x: m_Member) tmp += QString(" %1").arg(x);
//        QMessageBox::about(m_pWeChat, "提示", "房间内有：" + tmp);
//        QMessageBox::about(m_pWeChat, "提示", "加入成功，正在进入房间...");
        break;
    }
    case JOIN_FAILED: {
        QMessageBox::information(m_pWeChat, "提示", "加入房间失败！");
        return;
    }
    case ROOM_NOTEXIST: {
        QMessageBox::information(m_pWeChat, "提示", "房间号不存在，请确认后重新输入！");
        break;
    }
    }
}

void CKernel::DealJoinInfo(char *con)
{
    qDebug() << __func__;

    CJson json(con);
    delete [] con, con = nullptr;

    int id          = json.json_get_int("id");
    int icon        = json.json_get_int("icon");
    QString name    = json.json_get_string("name");
    int flag        = json.json_get_int("flag");

    m_pRoom->AddUser(id, icon, name);

    if (flag != NEW_IN && id != m_UserId)
        QMessageBox::about(m_pRoom, "提示", QString("欢迎%1加入房间！").arg(name));
}

void CKernel::DealLeaveInfo(char *con)
{
    qDebug() << __func__;

    CJson json(con);
    delete [] con, con = nullptr;

    int id = json.json_get_int("UserId");
//    int roomid = json.json_get_int("room_id");

    QMessageBox::about(m_pRoom, "提示", QString("%1悄无声息地离开了……").arg(m_pRoom->GetNameById(id)));

    // 从显示列表中去掉用户
    m_pRoom->Erase(id);

//    auto& t = m_mapIdToUserShow[id];
//    t->hide();
//    delete t; t = nullptr;
    //    m_mapIdToUserShow.erase(id);
}

void CKernel::DealVedioClose(char *con)
{
    CJson json(con);
    delete [] con, con = nullptr;

    int id = json.json_get_int("UserId");

    QImage img;
    m_pRoom->SetImgById(id, img);
}

#if USE_NO_JSON_AUDIO
void CKernel::DealAudio(char *buf, int len)
{
    len -= 3 * sizeof(int);
    buf += 3 * sizeof(int);

    QByteArray res;
    res.append(buf, len);

    m_pAudio_out->slot_net_rx(res);

    delete[] buf;
}

void CKernel::DealVedio(char *buf, int len)
{
    // 跳过type
    buf += sizeof(int);

    // 获得用户id
    int UserId = *(int*)buf;
    buf += sizeof(int);

    // 跳过roomid
    buf += sizeof(int);

    QByteArray ba( buf, len);
    QImage img;
    img.loadFromData( ba );

    m_pRoom->SetImgById(UserId, img);

    delete[] buf;
}


#else
void CKernel::DealAudio(char *con)
{
    CJson json(con);
    delete [] con, con = nullptr;

    QByteArray buf = QByteArray::fromBase64( json.json_get_byte_array("audio"));

    m_pAudio_out->slot_net_rx(buf);
}
#endif

CKernel::CKernel(QObject *parent) : QObject(parent)
{

    qDebug() << __func__;


    // 加载配置文件
    InitConfig();

    // 绑定函数
    SetProFun();

    // 创建主交互窗口
    m_pWeChat = new WeChatDialog;
    connect(m_pWeChat, &WeChatDialog::sig_create, this, &CKernel::slot_create);
    connect(m_pWeChat, &WeChatDialog::sig_join, this, &CKernel::slot_join);
//    m_pWeChat->show();
    connect(m_pWeChat, SIGNAL(sig_destroy()), this, SLOT(slot_destroy()));


    // 创建通信tcp对象
    m_chat = new Tcpsock;
    if (!m_chat->Connect(m_ip.toStdString().c_str(), PORT)) {
        qDebug() << "connect error";
        exit(-1);
    }
    connect(m_chat, &Tcpsock::sig_Deal, this, &CKernel::slot_Deal);
    connect(this, SIGNAL(sig_Write(char*,int)), m_chat, SLOT(Write(char*,int)));


    // 创建登录窗口
    m_pLogin = new LoginWin;
    m_pLogin->show();
    connect(m_pLogin, &LoginWin::sig_destroy, this, &CKernel::slot_destroy);
    connect(m_pLogin, SIGNAL(sig_SendRQ(char*)), this, SLOT(slot_SendRQ(char*)));

    // 创建屏幕录制
    m_pScreen_in = new ScreenReader;
    connect(m_pScreen_in, &ScreenReader::sig_ScreenFrame, this, &CKernel::slot_sendVideoFrame);

    // 创建播放音频和采集音频对象
    m_pAudio_out = new Audio_Write;
    m_pAudio_in = new Audio_Read;

    connect(m_pAudio_in, &Audio_Read::SIG_audioFrame, this, &CKernel::slot_AudioSend);

    // 创建视频采集对象
    m_pVideo_in = new VideoRead;
    connect(m_pVideo_in, &VideoRead::SIG_sendVideoFrame, this, &CKernel::slot_sendVideoFrame);

    // 创建房间
    m_pRoom = new RoomDialog;
    connect(m_pRoom, &RoomDialog::sig_QuitRoom, this, &CKernel::slot_QuitRoom);
    connect(m_pRoom, &RoomDialog::sig_AudioEnabled, this, &CKernel::slot_AudioEnabled);
    connect(m_pRoom, &RoomDialog::sig_AudioUnabled, this, &CKernel::slot_AudioUnabled);
    connect(m_pRoom, &RoomDialog::sig_VideoEnabled, m_pVideo_in, &VideoRead::slot_openVideo);
    connect(m_pRoom, &RoomDialog::sig_VideoUnabled, this, &CKernel::slot_VedioUnabled);
    connect(m_pRoom, &RoomDialog::sig_ScreenEnabled, m_pScreen_in, &ScreenReader::slot_start);
    connect(m_pRoom, &RoomDialog::sig_ScreenUnabled, this, &CKernel::slot_ScreenUnabled);
}


void CKernel::slot_destroy()
{
    qDebug() << __func__;
    if (m_pWeChat) {
        m_pWeChat->hide();
        delete m_pWeChat; m_pWeChat = nullptr;
    }
    if (m_pLogin) {
        m_pLogin->hide();
        delete m_pLogin; m_pLogin = nullptr;
    }
    if (m_chat) {
        m_chat->Close();
        delete m_chat; m_chat = nullptr;
    }
}

void CKernel::slot_Deal(char *buf, int len)
{
    qDebug() << __func__;

#if USE_NO_JSON_AUDIO
    if (*(int*)buf == AUDIO) {
        DealAudio(buf, len);
        return;
    }
    else if (*(int*)buf == VEDIO) {
        DealVedio(buf, len);
        return;
    }
#endif
    CJson json(buf);
//    delete [] buf;

    int type = json.json_get_int("type");

    if (type < PRO_BASE || type >= PRO_BASE + PRO_CNT) {
        qDebug() << "type is wrong!";
        return;
    }

    FUNMAP(type)(buf);
}

#if USE_NO_JSON_AUDIO
void CKernel::slot_SendRQ(char *buf, int len)
{
    qDebug() << QString("发送了：%1").arg(len);
    m_chat->Write(buf, len);
}
#endif

void CKernel::slot_SendRQ(char * buf)
{
//    m_chat->Write(buf, strlen(buf) + 1);
    Q_EMIT sig_Write(buf, strlen(buf) + 1);
}

void CKernel::slot_create()
{
    qDebug() << __func__;

    // 判断是否在房间内
    if (m_RoomId) {
        QMessageBox::about(m_pWeChat, "提示", "在房间内，无法加入，请先退出");
        return;
    }

    // 发命令创建房间
    CJson json;
    json.json_add_value("type", CREATE_ROOM_RQ);
    json.json_add_value("id", m_UserId);

    QByteArray con = json.json_to_string();
    slot_SendRQ(con.data());
}

#include <QInputDialog>
#include <QRegExp>
void CKernel::slot_join()
{
    qDebug() << __func__;

    // 判断是否在房间内
    if (m_RoomId) {
        QMessageBox::about(m_pWeChat, "提示", "在房间内，无法加入，请先退出");
        return;
    }

    // 输入房间号
    QString RoomId = QInputDialog::getText(m_pWeChat, "加入房间", "请输入房间号：");

    // 判断房间号是否有效
    QRegExp exp("^[0-9]{1,8}$");
    if (!exp.exactMatch(RoomId)) {
        // 无效则提示
        QMessageBox::information(m_pWeChat, "提示", "请输入正确的房间号！(1-8位数字)");
        return;
    }
    qDebug() << RoomId;

    // 发命令加入房间
    CJson json;
    json.json_add_value("type", JOIN_ROOM_RQ);
    json.json_add_value("id", m_UserId);
    json.json_add_value("room_id", RoomId.toInt());

    QByteArray con = json.json_to_string();
    slot_SendRQ(con.data());
}

void CKernel::slot_QuitRoom()
{
    qDebug() << __func__;

    CJson json;
    json.json_add_value("type", LEAVE_INFO);
    json.json_add_value("UserId", m_UserId);
    json.json_add_value("RoomId", m_RoomId);

    QByteArray con = json.json_to_string();
    slot_SendRQ(con.data());

    // 赋值房间号为无房间状态
    m_RoomId = 0;

    // 清空房间
    m_pRoom->ClearUser();

    // 再次打开界面
    m_pWeChat->showNormal();

    // 关闭音频视频
    m_pAudio_in->pause();
    m_pVideo_in->slot_closeVideo();
    m_pRoom->ClearCheck();

    //    m_pRoom->showNormal();
}

void CKernel::slot_AudioEnabled()
{
    m_pAudio_in->start();
}

void CKernel::slot_AudioUnabled()
{
    m_pAudio_in->pause();
}

// 关闭视频播放
void CKernel::slot_VedioUnabled()
{
    // 关闭视频采集
    m_pVideo_in->slot_closeVideo();


    // 本地视频显示黑屏
    QImage img;
    m_pRoom->SetImgById(m_UserId, img);

    CJson json;
    json.json_add_value("type", CLOSE_VEDIO);
    json.json_add_value("UserId", m_UserId);
    json.json_add_value("RoomId", m_RoomId);

    QByteArray con = json.json_to_string();
    slot_SendRQ(con.data());
}

void CKernel::slot_ScreenUnabled()
{
    // 关闭桌面采集
    m_pScreen_in->slot_stop();


    // 本地视频显示黑屏
    QImage img;
    m_pRoom->SetImgById(m_UserId, img);

    CJson json;
    json.json_add_value("type", CLOSE_VEDIO);
    json.json_add_value("UserId", m_UserId);
    json.json_add_value("RoomId", m_RoomId);

    QByteArray con = json.json_to_string();
    slot_SendRQ(con.data());
}

void CKernel::slot_AudioSend(QByteArray buf)
{
    qDebug() << __func__;
//    qDebug() << QString("要发送的音频大小为%1").arg(buf.size());
#if USE_NO_JSON_AUDIO
    // 序列化
    int num = buf.size() + 3 * sizeof(int);
    char* tmp = new char[num];
    char* ssr = tmp;

    // 写入类型
    *(int*)ssr = AUDIO;
    ssr += sizeof(int);

    *(int*)ssr = m_UserId;
    ssr += sizeof(int);

    *(int*)ssr = m_RoomId;
    ssr += sizeof(int);

    memcpy(ssr, buf.data(), buf.size());

    qDebug() << QString("size of new = %1").arg(strlen(tmp));

    slot_SendRQ(tmp, num);
    delete[] tmp;
#else
    CJson json;
    json.json_add_value("type", AUDIO);

    json.json_add_value("UserId", m_UserId);
    json.json_add_value("RoomId", m_RoomId);
    json.json_add_value("audio", buf.toBase64().data());

    QByteArray con = json.json_to_string();

    qDebug() << QString("buf = %1").arg(buf.size());
    qDebug() << QString("json %1").arg(con.size());
    slot_SendRQ(con.data());
#endif
}

#include <QBuffer>
void CKernel::slot_sendVideoFrame(QImage img)
{
    qDebug() << __func__;
    // 显示图像
    m_pRoom->SetImgById(m_UserId, img);

    // 压缩图片
    QByteArray ba;
    QBuffer qbuf(&ba); // QBuffer 与 QByteArray 字节数组联立联系
    img.save( &qbuf , "JPEG" , 80 ); //将图片的数据写入 ba

    // 发送图片
    // 序列化
    int num = ba.size() + 3 * sizeof(int);
    char* tmp = new char[num];
    char* ssr = tmp;

    // 写入类型
    *(int*)ssr = VEDIO;
    ssr += sizeof(int);

    *(int*)ssr = m_UserId;
    ssr += sizeof(int);

    *(int*)ssr = m_RoomId;
    ssr += sizeof(int);

    memcpy(ssr, ba.data(), ba.size());

    slot_SendRQ(tmp, num);
    delete[] tmp;
}
