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

private:
    Ui::LoginWin *ui;
};

#endif // LOGINWIN_H