#include "loginwin.h"
#include "ui_loginwin.h"
#include <cjson.h>
#include "Protocol.h"
#include <QMessageBox>

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

#include <QRegExp>
// 提交登录请求
void LoginWin::on_pb_login_clicked()
{
    QString phone = ui->le_phone->text();
    QString pass = ui->le_pass->text();

    // 校验
    // 非空校验 清掉空格后不能是空字符串
    QString ph = phone, pa = pass;
    if (ph.remove(" ").isEmpty() || pa.remove(" ").isEmpty()) {
        QMessageBox::information(this, "提示", "手机号和密码不能为空");
        return;
    }

    // 1. 校验手机号
    QRegExp reg("^1[3-8][0-9]{6,9}$");
    if (!reg.exactMatch(ph)) {
        QMessageBox::information(this, "提示", "请检查手机号是否输入错误！");
        return;
    }

    // 2. 校验密码 长度不超过20
    if (pa.length() > 20) {
        QMessageBox::information(this, "提示", "密码过长，长度不超过20");
        return;
    }

    CJson json;
    json.json_add_value("type", LOG_RQ);
    json.json_add_value("phone", phone.toStdString().c_str());
    json.json_add_value("pass", pass.toStdString().c_str());

    QByteArray con = json.json_to_string();
    Q_EMIT sig_LoginRQ(con.data());
}


// 清空登录信息
void LoginWin::on_pb_clear_clicked()
{
    ui->le_phone->clear();
    ui->le_pass->clear();
}

// 清空注册信息
void LoginWin::on_pb_clear_r_clicked()
{
    ui->le_name_r->clear();
    ui->le_pass_rp->clear();
    ui->le_pass_r->clear();
    ui->le_phone_r->clear();
}

// 发送注册请求
void LoginWin::on_pb_register_clicked()
{
    QString phone = ui->le_phone_r->text();
    QString pass = ui->le_pass_r->text();
    QString pass_rp = ui->le_pass_rp->text();
    QString name = ui->le_name_r->text();

    // 校验
    // 非空校验 清掉空格后不能是空字符串
    QString ph = phone, pa = pass, rp = pass_rp, nt = name;
    if (ph.remove(" ").isEmpty() || pa.remove(" ").isEmpty() || rp.remove(" ").isEmpty() || nt.remove(" ").isEmpty()) {
        QMessageBox::information(this, "提示", "信息不能为空");
        return;
    }

    // 1. 校验手机号
    QRegExp reg("^1[3-8][0-9]{6,9}$");
    if (!reg.exactMatch(ph)) {
        QMessageBox::information(this, "提示", "请检查手机号是否输入错误！");
        return;
    }

    // 2. 校验密码 长度不超过20
    if (pa.length() > 20) {
        QMessageBox::information(this, "提示", "密码过长，长度不超过20");
        return;
    }

    // 3. 校验用户名
    if (name.length() > 10) {
        QMessageBox::information(this, "提示", "用户名过长，长度不超过10");
        return;
    }

    // 4. 检查密码是否相等
    if (pass != pass_rp) {
        QMessageBox::information(this, "提示", "密码不相同，请注意输入");
        return;
    }

    CJson json;
    json.json_add_value("type", REG_RQ);
    json.json_add_value("phone", phone.toStdString().c_str());
    json.json_add_value("pass", pass.toStdString().c_str());
    json.json_add_value("name", name.toStdString().c_str());

    QByteArray con = json.json_to_string();
    Q_EMIT sig_LoginRQ(con.data());
}

