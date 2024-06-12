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
    void SetInfo(QString RoomId);
    void AddUser(int id, int icon, QString name);
    void Erase(int id);
    void ClearUser();
    QString GetNameById(int id);

signals:
    void sig_QuitRoom();
    void sig_AudioEnabled();
    void sig_AudioUnabled();

private slots:
    void on_pb_exit_clicked();

    void on_cb_audio_stateChanged(int arg1);

private:
    Ui::RoomDialog *ui;
    std::unordered_map<int, UserShow*>  m_mapIdToUserShow;
    QVBoxLayout* m_UserList;

    void closeEvent(QCloseEvent *);
};

#endif // ROOMDIALOG_H
