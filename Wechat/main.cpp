//#include "wechatdialog.h"
#include "ckernel.h"
#include <QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
//    WeChatDialog w;
//    w.show();
    CKernel::GetKernel();
    qDebug() << "测试push成功！！！";
    return a.exec();
}
