#ifndef LOGINWIN_H
#define LOGINWIN_H

#include <QDialog>

namespace Ui {
class LoginWin;
}

class LoginWin : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWin(QWidget *parent = nullptr);
    ~LoginWin();

private slots:


    void on_pb_login_clicked();

    void on_pb_clear_clicked();

    void on_pb_clear_r_clicked();

    void on_pb_register_clicked();

signals:
    void sig_SendRQ(char*);
    void sig_destroy();

private:
    Ui::LoginWin *ui;

    void closeEvent(QCloseEvent *);
};

#endif // LOGINWIN_H
