#include "ckernel.h"
#include <QDebug>
#include "cjson.h"
#include <QMessageBox>

#define FUNMAP(a) m_ProToFun[a - PRO_BASE]

std::once_flag CKernel::m_once;
std::unique_ptr<CKernel> CKernel::self;

void CKernel::SetProFun()
{

    memset(m_ProToFun, 0, sizeof (m_ProToFun));

    FUNMAP(LOG_RS) = std::bind(&CKernel::DealLoginRs, this, std::placeholders::_1);
    FUNMAP(REG_RS) = std::bind(&CKernel::DealRegRs, this, std::placeholders::_1);
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

    // 绑定函数
    SetProFun();

    // 加载配置文件
    InitConfig();

    m_pWeChat = new WeChatDialog;
//    m_pWeChat->show();

    connect(m_pWeChat, SIGNAL(sig_destroy()), this, SLOT(slot_destroy()));

    m_chat = new Tcpsock;
    if (!m_chat->Connect(m_serverIP.toStdString().c_str(), PORT)) {
        qDebug() << "connect error";
        exit(-1);
    }
    connect(m_chat, &Tcpsock::sig_Deal, this, &CKernel::slot_Deal);

    m_pLogin = new LoginWin;
    m_pLogin->show();
    connect(m_pLogin, &LoginWin::sig_LoginRQ, this, &CKernel::slot_LoginRQ);
    connect(m_pLogin, &LoginWin::sig_RegisterRQ, this, &CKernel::slot_RegisterRQ);
}

CKernel *CKernel::GetKernel()
{
    std::call_once(m_once, []() {
       self.reset(new CKernel);
    });
    return self.get();
}

#include <QSettings>
#include <QApplication>
#include <QFileInfo>

void CKernel::InitConfig()
{
    m_serverIP = IP;

    // 路径设置在exe同级下 config.ini
    QString path = QApplication::applicationDirPath() + "/config.ini";
    qDebug() << path;

    // 判断是否存在
    QFileInfo info(path);
    QSettings setting(path, QSettings::IniFormat, nullptr);
    if (info.exists()) {
        // 加载配置文件，设置为配置文件中的ip

        // 打开组
        setting.beginGroup("Net");

        m_serverIP = setting.value("ip").toString();

        // 关闭组
        setting.endGroup();
    }
    else {
        // 没有配置文件，写入默认的ip

        // 打开组
        setting.beginGroup("Net");

        setting.setValue("ip", m_serverIP);

        // 关闭组
        setting.endGroup();
    }

    qDebug() << m_serverIP;
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

void CKernel::slot_LoginRQ(char * buf)
{
    m_chat->Write(buf, strlen(buf) + 1);
}

void CKernel::slot_RegisterRQ(char *)
{

}
