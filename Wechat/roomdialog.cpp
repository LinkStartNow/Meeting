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

void RoomDialog::SetInfo(QString RoomId, int UserId)
{
    setWindowTitle(QString("房间号：%1").arg(RoomId));
    ui->lb_room_id->setText(RoomId);
    m_Userid = UserId;
}

void RoomDialog::AddUser(int id, int icon, QString name)
{
    UserShow*& t = m_mapIdToUserShow[id] = new UserShow;
    t->SetInfo(name, id);
//    ui->vlo_user_list->addWidget(t);
    m_UserList->addWidget(t);
    t->showNormal();
    connect(t, &UserShow::sig_UserClicked, this, &RoomDialog::slot_UserClicked);
}

void RoomDialog::Erase(int id)
{
    const auto& t = m_mapIdToUserShow[id];

//    QMessageBox::about(this, "提示", QString("%1悄无声息地离开了").arg(t->GetName()));

    // 去掉窗口
    t->hide();
    m_UserList->removeWidget(t);
    m_mapIdToUserShow.erase(id);

    if (id == ui->wd_user_show->m_id) ui->wd_user_show->Clear();

    // todo:删除元素
}

void RoomDialog::ClearUser()
{
    for (const auto& [x, y]: m_mapIdToUserShow) Erase(x);
}

void RoomDialog::SetImgById(int id, QImage &img)
{
    if (id == ui->wd_user_show->m_id) {
        ui->wd_user_show->SetImg(img);
    }
    if (m_mapIdToUserShow.count(id)) {
        UserShow* t = m_mapIdToUserShow[id];
        t->SetImg(img);
    }
}

QString RoomDialog::GetNameById(int id)
{
    return  m_mapIdToUserShow[id]->GetName();
}

void RoomDialog::ClearCheck()
{
    ui->cb_audio->setCheckState(Qt::Unchecked);
    ui->cb_video->setCheckState(Qt::Unchecked);
    ui->cb_desk->setCheckState(Qt::Unchecked);
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


void RoomDialog::on_cb_audio_stateChanged(int arg1)
{
    if (ui->cb_audio->isChecked()) {
        Q_EMIT sig_AudioEnabled();
        qDebug() << "音频已经打开";
    }
    else {
        Q_EMIT sig_AudioUnabled();
        qDebug() << "音频已经关闭";
    }
}

#include <QClipboard>
void RoomDialog::on_lb_copy_clicked()
{
    QClipboard* ssr = QApplication::clipboard();
    ssr->setText(ui->lb_room_id->text());
    QMessageBox::about(this, "提示", "房间号复制成功！");
}


void RoomDialog::on_cb_video_stateChanged(int arg1)
{
    if (ui->cb_video->isChecked()) {
        ui->cb_desk->setCheckState(Qt::Unchecked);
        Q_EMIT sig_VideoEnabled();
        qDebug() << "视频已经打开";
    }
    else {
        Q_EMIT sig_VideoUnabled();
        qDebug() << "视频已经关闭";
    }
}


void RoomDialog::on_cb_desk_stateChanged(int arg1)
{
    if (ui->cb_desk->isChecked()) {
        ui->cb_video->setCheckState(Qt::Unchecked);
        Q_EMIT sig_ScreenEnabled();
        qDebug() << "录屏已经打开";
    }
    else {
        Q_EMIT sig_ScreenUnabled();
        qDebug() << "录屏已经关闭";
    }
}

void RoomDialog::slot_UserClicked(int id, QString name)
{
    qDebug() << __func__;
    ui->wd_user_show->SetInfo(name, id);
}

