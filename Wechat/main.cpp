//#include "wechatdialog.h"
#include "ckernel.h"
#include <QDebug>
#include <QApplication>
#include <QClipboard>


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);

    CKernel::GetKernel();
    return a.exec();
}
