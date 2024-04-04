#include "ckernel.h"
#include <QDebug>
#include "cjson.h"
#include <QMessageBox>

#define FUNMAP(a) m_ProToFun[a - PRO_BASE]

void CKernel::SetProFun()
{

    memset(m_ProToFun, 0, sizeof (m_ProToFun));

    FUNMAP(LOG_RS) = std::bind(&CKernel::DealLoginRs, this, std::placeholders::_1);
    FUNMAP(REG_RS) = std::bind(&CKernel::DealRegRs, this, std::placeholders::_1);
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
        QMessageBox::information(nullptr, "提示", QString("用户名:%1, 个性签名:%2, id:%3")
                                 .arg(json.json_get_string("name"))
                                 .arg(json.json_get_string("feeling"))
                                 .arg(json.json_get_string("id")));
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

CKernel::CKernel(QObject *parent) : QObject(parent)
{

    qDebug() << __func__;


    // 加载配置文件
    InitConfig();

    // 绑定函数
    SetProFun();

    m_pWeChat = new WeChatDialog;
//    m_pWeChat->show();

    connect(m_pWeChat, SIGNAL(sig_destroy()), this, SLOT(slot_destroy()));

    m_chat = new Tcpsock;
    if (!m_chat->Connect(m_ip.toStdString().c_str(), PORT)) {
        qDebug() << "connect error";
        exit(-1);
    }
    connect(m_chat, &Tcpsock::sig_Deal, this, &CKernel::slot_Deal);

    m_pLogin = new LoginWin;
    m_pLogin->show();
    connect(m_pLogin, &LoginWin::sig_destroy, this, &CKernel::slot_destroy);
    connect(m_pLogin, &LoginWin::sig_SendRQ, this, &CKernel::slot_SendRQ);
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

void CKernel::slot_Deal(char *buf)
{
    qDebug() << __func__;
    CJson json(buf);
    delete [] buf;

    int type = json.json_get_int("type");

    if (type < PRO_BASE || type >= PRO_BASE + PRO_CNT) {
        qDebug() << "type is wrong!";
        return;
    }

    FUNMAP(type)(buf);
}

void CKernel::slot_SendRQ(char * buf)
{
    m_chat->Write(buf, strlen(buf) + 1);
}
