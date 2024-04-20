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
    return a.exec();
//    CJson json;
//    std::vector<int> v {233, 666, 7};
//    json.json_add_value("list", v);
//    std::vector<int>&& ssr = json.json_get_int_list("list");
//    for (int x: ssr) qDebug() << x;
}
