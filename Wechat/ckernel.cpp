#include "ckernel.h"
#include <QDebug>

CKernel::CKernel(QObject *parent) : QObject(parent)
{
    qDebug() << __func__;
    m_pWeChat = new WeChatDialog;
    m_pWeChat->show();

    connect(m_pWeChat, SIGNAL(sig_destroy()), this, SLOT(slot_destroy()));
}

void CKernel::slot_destroy()
{
    qDebug() << __func__;
    if (m_pWeChat) {
        delete m_pWeChat;
        m_pWeChat = nullptr;
    }
}
