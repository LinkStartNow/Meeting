#ifndef USERSHOW_H
#define USERSHOW_H

#include <QWidget>
#include <QImage>
#include <QPaintEvent>
#include <QMouseEvent>
//#include "roomdialog.h"

namespace Ui {
class UserShow;
}

class RoomDialog;

class UserShow : public QWidget
{
    Q_OBJECT

signals:
    void sig_UserClicked(int id, QString name);

public:
    explicit UserShow(QWidget *parent = nullptr);
    ~UserShow();

    void SetInfo(QString name, int id);

    QString GetName()
    {
        return m_name;
    }

    void SetImg(QImage& img);

    void Clear();

private:
    Ui::UserShow *ui;

    void paintEvent(QPaintEvent *event);

    int     m_id;
    QString m_name;
    QImage  m_image;

    void mousePressEvent(QMouseEvent* e);

    friend class RoomDialog;
};

#endif // USERSHOW_H
