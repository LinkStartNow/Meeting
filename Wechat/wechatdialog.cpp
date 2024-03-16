#include "wechatdialog.h"
#include "ui_wechatdialog.h"

WeChatDialog::WeChatDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WeChatDialog)
{
    ui->setupUi(this);
}

WeChatDialog::~WeChatDialog()
{
    delete ui;
}

