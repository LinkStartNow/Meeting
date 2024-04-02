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
        qDebug() << 123;
        // 打开组
        set.beginGroup("Net");

        // 读取值
        m_ip = set.value("ip").toString();
        qDebug() << m_ip;

        // 关闭组
        set.endGroup();
    }
    else {
        // 不存在，写入IP
        qDebug() << 666;
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
    if (result == LOG_SUCCESS) {
        QMessageBox::information(nullptr, "提示", "登录成功！");
    }
}

void CKernel::DealRegRs(char *con)
{
    qDebug() << __func__;

    CJson json(con);
    delete [] con, con = nullptr;

    int result = json.json_get_int("result");
    if (result == REG_SUCCESS) {
        QMessageBox::information(nullptr, "提示", "注册成功！");
    }
}

CKernel::CKernel(QObject *parent) : QObject(parent)
{

    qDebug() << __func__;


    // 加载配置文件
    InitConfig();

    qDebug() << QString("Ip:%1").arg(m_ip);

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
    connect(m_pLogin, &LoginWin::sig_SendRQ, this, &CKernel::slot_SendRQ);
}

void CKernel::slot_destroy()
{
    qDebug() << __func__;
    if (m_pWeChat) {
        m_pWeChat->hide();
        delete m_pWeChat;
        m_pWeChat = nullptr;
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
