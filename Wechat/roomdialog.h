#ifndef ROOMDIALOG_H
#define ROOMDIALOG_H

#include <QDialog>
#include <unordered_map>
#include <QVBoxLayout>
#include "usershow.h"

namespace Ui {
class RoomDialog;
}

class RoomDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RoomDialog(QWidget *parent = nullptr);
    ~RoomDialog();
    void SetInfo(QString RoomId, int UserId);
    void AddUser(int id, int icon, QString name);
    void Erase(int id);
    void ClearUser();
    void SetImgById(int id, QImage& img);
    QString GetNameById(int id);
    void Close_AudioAndVedio();
    void ClearCheck();

signals:
    void sig_QuitRoom();

    // 音频打开、关闭
    void sig_AudioEnabled();
    void sig_AudioUnabled();

    // 视频打开、关闭
    void sig_VideoEnabled();
    void sig_VideoUnabled();

    // 桌面打开、关闭
    void sig_ScreenEnabled();
    void sig_ScreenUnabled();

private slots:
    void on_pb_exit_clicked();

    void on_cb_audio_stateChanged(int arg1);

    void on_lb_copy_clicked();

    void on_cb_video_stateChanged(int arg1);

    void on_cb_desk_stateChanged(int arg1);

    void slot_UserClicked(int id, QString name);

private:
    Ui::RoomDialog *ui;
    std::unordered_map<int, UserShow*>  m_mapIdToUserShow;
    QVBoxLayout* m_UserList;
    int          m_Userid;
    void closeEvent(QCloseEvent *);
};

#endif // ROOMDIALOG_H
