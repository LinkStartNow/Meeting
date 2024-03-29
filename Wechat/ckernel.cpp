#include "ckernel.h"
#include <QDebug>
#include "cjson.h"

CKernel::CKernel(QObject *parent) : QObject(parent)
{
    qDebug() << __func__;
    m_pWeChat = new WeChatDialog;
//    m_pWeChat->show();

    connect(m_pWeChat, SIGNAL(sig_destroy()), this, SLOT(slot_destroy()));

    m_chat = new Tcpsock;
    if (!m_chat->Connect(IP, PORT)) {
        qDebug() << "connect error";
        exit(-1);
    }
    connect(m_chat, &Tcpsock::sig_Deal, this, &CKernel::slot_Deal);

    m_pLogin = new LoginWin;
    m_pLogin->show();
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

//    int type = json.json_get_int("type");
    QString content = json.json_get_string("content");

    qDebug() << content;

}
