#include "tcpsock.h"
#include <iostream>
#include <QDebug>

bool Tcpsock::IsRecving = true;

Tcpsock::Tcpsock()
{

}

Tcpsock::~Tcpsock()
{
    if (m_rthread) {
        if (!m_rthread->isFinished()) {
            m_rthread->quit();
            m_rthread->wait(100);
            if (!m_rthread->isFinished()) {
                m_rthread->terminate();
                m_rthread->wait(100);
            }
        }
        delete m_rthread; m_rthread = nullptr;
    }

    Close();
}

bool Tcpsock::Connect(const char* ip, const int port)
{
    if (!Open()) {
        qDebug() << "net start failed";
        return false;
    }

    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.S_un.S_addr = inet_addr(ip);

    int err = ::connect(m_sock, (sockaddr*)&addr, sizeof(addr));
    if (err == SOCKET_ERROR) {
        qDebug() << "connect fail:" << WSAGetLastError();

        closesocket(m_sock);

        WSACleanup();
        return false;
    }
    else qDebug() << "connect success!";

    m_rthread = new RecvThread(this);
    m_rthread->start();

    return true;
}

bool Tcpsock::Write(char *buf, int size)
{
    int num;
    if ((num = send(m_sock, (char*)&size, sizeof(size), 0)) == SOCKET_ERROR) {
        qDebug() << "send size error:" << WSAGetLastError();
        return false;
    }
    qDebug() << "send num:" << num;

    if (send(m_sock, buf, size, 0) == SOCKET_ERROR) {
        qDebug() << "send buf error:" << WSAGetLastError();
        return false;
    }
    return true;
}

bool Tcpsock::Read()
{
    static int num = 0; // 成功读取的字节数
    static int size = 0; // 获取buf大小
    if ((num = recv(m_sock, (char*)&size, sizeof(int), 0)) == SOCKET_ERROR) {
        qDebug() << "recv size error:" << WSAGetLastError();
        return false;
    }

    if (num <= 0) {
        qDebug() << "recv size failed" << WSAGetLastError();
        return false;
    }

    char* buf = new char[size];

//    if (num > size) {
//        qDebug() << "buf size is so small";
//        return false;
//    }

    if ((num = recv(m_sock, buf, size, 0)) == SOCKET_ERROR) {
        qDebug() << "recv buf error:" << WSAGetLastError();
        return false;
    }

    if (num <= 0) {
        qDebug() << "recv content failed" << WSAGetLastError();
        return false;
    }

    Q_EMIT sig_Deal(buf);

    return true;
}

void Tcpsock::EndRecv()
{
    IsRecving = false;
}

void Tcpsock::Close()
{
    IsRecving = false;

    // 调用父类的Close
    Mysock::Close();
}

void Tcpsock::RecvThread::run()
{
    while (IsRecving && m_chat->Read());
    qDebug() << "something wrong with recv";
}
