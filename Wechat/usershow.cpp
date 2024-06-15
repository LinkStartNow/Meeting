#include "usershow.h"
#include "ui_usershow.h"
#include <QPainter>
#include <QPixmap>

UserShow::UserShow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserShow)
{
    ui->setupUi(this);
}

UserShow::~UserShow()
{
    delete ui;
}

void UserShow::SetInfo(QString name, int id)
{
    m_name  = name;
    m_id    = id;
    ui->lb_name->setText(m_name);
    repaint();
}

void UserShow::SetImg(QImage &img)
{
    m_image = img;

    // 启动刷新事件
    update();
}

// 重绘事件
void UserShow::paintEvent(QPaintEvent *event)
{
    // 创建画手对象
    QPainter p(this);

    // 设置画刷为黑色
    p.setBrush(Qt::black);

    // 画一个黑色矩形背景
    p.drawRect(-1, 0, this->width() + 1, this->height());

    // 画视频帧
    // 等比例缩放
    m_image = m_image.scaled(this->width(), this->height(), Qt::KeepAspectRatio);

    QPixmap pix = QPixmap::fromImage(m_image);

    int x = this->width() - pix.width() >> 1;
    int y = (this->height() - ui->lb_name->height() - pix.height() >> 1) + ui->lb_name->height();
//    int y = 0;
    p.drawPixmap(QPoint(x, y), pix);

    p.end();
}
