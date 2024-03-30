#include "loginwin.h"
#include "ui_loginwin.h"
#include <cjson.h>
#include "Protocol.h"

LoginWin::LoginWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWin)
{
    ui->setupUi(this);
}

LoginWin::~LoginWin()
{
    delete ui;
}

void LoginWin::on_pb_login_clicked()
{
    CJson json;
    QString phone = ui->le_phone->text();
    QString pass = ui->le_pass->text();

    json.json_add_value("type", LOG_RQ);
    json.json_add_value("phone", phone.toStdString().c_str());
    json.json_add_value("pass", pass.toStdString().c_str());

    QByteArray con = json.json_to_string();
    Q_EMIT sig_LoginRQ(con.data());
}

