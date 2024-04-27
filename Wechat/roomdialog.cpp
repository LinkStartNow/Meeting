#include "roomdialog.h"
#include "ui_roomdialog.h"
#include <QMessageBox>
#include <QDebug>
#include <QCloseEvent>
#include <QWidget>

RoomDialog::RoomDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RoomDialog)
{
    ui->setupUi(this);

    m_UserList = new QVBoxLayout;
    // 设置外边距
    m_UserList->setContentsMargins(0, 0, 0, 0);
    // 设置内边距
    m_UserList->setSpacing(5);

    ui->wd_list->setLayout(m_UserList);
}

RoomDialog::~RoomDialog()
{
    delete ui;
}

void RoomDialog::SetInfo(QString RoomId)
{
    setWindowTitle(QString("房间号：%1").arg(RoomId));
    ui->lb_room->setText(RoomId);
}

void RoomDialog::AddUser(int id, int icon, QString name)
{
    const auto& t = m_mapIdToUserShow[id] = new UserShow;
    t->SetInfo(name, id);
//    ui->vlo_user_list->addWidget(t);
    m_UserList->addWidget(t);
    t->showNormal();
}

void RoomDialog::Erase(int id)
{
    const auto& t = m_mapIdToUserShow[id];

//    QMessageBox::about(this, "提示", QString("%1悄无声息地离开了").arg(t->GetName()));

    // 去掉窗口
    t->hide();
    m_UserList->removeWidget(t);
    m_mapIdToUserShow.erase(id);

    // todo:删除元素
}

void RoomDialog::ClearUser()
{
    for (const auto& [x, y]: m_mapIdToUserShow) Erase(x);
}

QString RoomDialog::GetNameById(int id)
{
    return  m_mapIdToUserShow[id]->GetName();
}

// 关闭事件
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

void RoomDialog::on_pb_exit_clicked()
{
    // 调用关闭，会触发关闭事件
    this->close();
}

