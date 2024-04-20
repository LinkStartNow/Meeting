#ifndef ROOMDIALOG_H
#define ROOMDIALOG_H

#include <QDialog>

namespace Ui {
class RoomDialog;
}

class RoomDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RoomDialog(QWidget *parent = nullptr);
    ~RoomDialog();

signals:
    void sig_QuitRoom();

private:
    Ui::RoomDialog *ui;

    void closeEvent(QCloseEvent *);
};

#endif // ROOMDIALOG_H
