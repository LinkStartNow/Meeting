#include "wechatdialog.h"
#include "ui_wechatdialog.h"
#include <QMessageBox>
#include <QDebug>

WeChatDialog::WeChatDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WeChatDialog)
{
    ui->setupUi(this);
}

WeChatDialog::~WeChatDialog()
{
    qDebug() << __func__;
    delete ui;
}

void WeChatDialog::SetInfo(QString name, int icon)
{
    ui->lb_name->setText(name);

}

void WeChatDialog::closeEvent(QCloseEvent *event)
{
    qDebug() << __func__;
    if (QMessageBox::question(this, "提示", "是否退出？") == QMessageBox::Yes) {
        Q_EMIT sig_destroy();
        // 执行
        event->accept();
    }
    else {
        // 忽略
        event->ignore();
    }
}


void WeChatDialog::on_pb_create_clicked()
{
    qDebug() << __func__;
    Q_EMIT sig_create();
}


void WeChatDialog::on_pb_join_clicked()
{
    qDebug() << __func__;
    Q_EMIT sig_join();
}

