//#include "wechatdialog.h"
#include "ckernel.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    WeChatDialog w;
//    w.show();
    CKernel::GetKernel();
    return a.exec();
}
