#include "wechatdialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WeChatDialog w;
    w.show();
    return a.exec();
}
