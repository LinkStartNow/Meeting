#ifndef USERSHOW_H
#define USERSHOW_H

#include <QWidget>
#include <QImage>
#include <QPaintEvent>

namespace Ui {
class UserShow;
}

class UserShow : public QWidget
{
    Q_OBJECT

public:
    explicit UserShow(QWidget *parent = nullptr);
    ~UserShow();

    void SetInfo(QString name, int id);

    QString GetName()
    {
        return m_name;
    }

    void SetImg(QImage& img);

private:
    Ui::UserShow *ui;

    void paintEvent(QPaintEvent *event);

    int     m_id;
    QString m_name;
    QImage  m_image;
};

#endif // USERSHOW_H
