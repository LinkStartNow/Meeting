#ifndef TCPSOCK_H
#define TCPSOCK_H

#include "mysock.h"
#include <QThread>

class Tcpsock : public Mysock
{
    Q_OBJECT

    class RecvThread: public QThread
    {
        Tcpsock* m_chat;

        void run();

    public:
        RecvThread(Tcpsock* chat = nullptr): m_chat(chat) {}
    };

    static bool IsRecving;
    RecvThread* m_rthread;
    QThread*    m_self;

public:
    Tcpsock();

    ~Tcpsock();

    bool Connect(const char* ip, const int port);

    bool Read();

    void EndRecv();

    void Close();

public slots:
    bool Write(char* buf, int size);

signals:
    void sig_Deal(char* buf, int len);
};

#endif // TCPSOCK_H
