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

