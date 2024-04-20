#include "roomdialog.h"
#include "ui_roomdialog.h"
#include <QMessageBox>
#include <QDebug>
#include <QCloseEvent>

RoomDialog::RoomDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RoomDialog)
{
    ui->setupUi(this);
}

RoomDialog::~RoomDialog()
{
    delete ui;
}

void RoomDialog::closeEvent(QCloseEvent *event)
{
    qDebug() << __func__;
    if (QMessageBox::question(this, "提示", "是否退出？") == QMessageBox::Yes) {
        Q_EMIT sig_QuitRoom();
        // 执行
        event->accept();
    }
    else {
        // 忽略
        event->ignore();
    }
}
