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
    int num = 0;
    int max = sizeof(int);
    char* ssr = (char*)&size;
    while (num < max) {
        int t;
        if ((t = send(m_sock, ssr + num, max - num, 0)) == SOCKET_ERROR) {
            qDebug() << "send size error:" << WSAGetLastError();
            return false;
        }
        num += t;
    }

    qDebug() << "send num:" << num;

    num = 0;
    max = size;
    while (num < max) {
        int t;
        if ((t = send(m_sock, buf + num, max - num, 0)) == SOCKET_ERROR) {
            qDebug() << "send size error:" << WSAGetLastError();
            return false;
        }
        num += t;
    }
//    if (send(m_sock, buf, size, 0) == SOCKET_ERROR) {
//        qDebug() << "send buf error:" << WSAGetLastError();
//        return false;
//    }
    return true;
}

bool Tcpsock::Read()
{
    int num = 0; // 成功读取的字节数
    int size = 0; // 获取buf大小
    int max = sizeof(int);
    char sz[4];
    while (num < max) {
        int t;
        if ((t = recv(m_sock, sz + num, max - num, 0)) == SOCKET_ERROR) {
            qDebug() << "recv size error:" << WSAGetLastError();
            return false;
        }
        num += t;
    }

    max = *(int*)sz;

    if (max <= 0) {
        qDebug() << "recv size failed" << WSAGetLastError();
        return false;
    }

    char* buf = new char[max];
    num = 0;

//    if (num > size) {
//        qDebug() << "buf size is so small";
//        return false;
//    }

    while (num < max) {
        int t;
        if ((t = recv(m_sock, buf + num, max - num, 0)) == SOCKET_ERROR) {
            qDebug() << "recv size error:" << WSAGetLastError();
            return false;
        }
        num += t;
    }

//    if ((num = recv(m_sock, buf, size, 0)) == SOCKET_ERROR) {
//        qDebug() << "recv buf error:" << WSAGetLastError();
//        return false;
//    }

//    if (num <= 0) {
//        qDebug() << "recv content failed" << WSAGetLastError();
//        return false;
//    }

    Q_EMIT sig_Deal(buf, max);

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
