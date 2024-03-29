#ifndef MYSOCK_H
#define MYSOCK_H

#pragma comment(lib, "ws2_32.lib")

#include <WinSock2.h>
#include <QObject>

class Mysock: public QObject
{
    Q_OBJECT
protected:
    SOCKET m_sock = INVALID_SOCKET;

public:
    Mysock();
    ~Mysock();

    bool Open();

    void Close();
};

#endif // MYSOCK_H
