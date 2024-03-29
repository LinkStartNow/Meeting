#include "mysock.h"
#include <iostream>

using namespace std;

Mysock::Mysock()
{

}

Mysock::~Mysock()
{

}

bool Mysock::Open()
{
    // 1、加载库
    WORD word = MAKEWORD(2, 2);
    WSADATA wsa;
    int err = WSAStartup(word, &wsa);
    if (err) {
        cout << "WsaStartup failed: " << err << endl;
        return false;
    }
    if (LOBYTE(wsa.wVersion) != 2 || HIBYTE(wsa.wVersion) != 2) {
        cout << "version error" << endl;

        // 卸载库
        WSACleanup();
        return false;
    }
    else {
        cout << "WsaStartup success!" << endl;
    }

    // 2、创建套接字
    m_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (m_sock == INVALID_SOCKET) {
        cout << "socket failed: " << WSAGetLastError() << endl;

        // 卸载库
        WSACleanup();
        return false;
    }
    else {
        cout << "socket success!" << endl;
    }

    return true;
}

void Mysock::Close()
{
    // 关闭套接字
    if (m_sock != INVALID_SOCKET) {
        closesocket(m_sock);
        m_sock = INVALID_SOCKET;
    }

    // 卸载库
    WSACleanup();
}
