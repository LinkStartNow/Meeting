#include "usershow.h"
#include "ui_usershow.h"
#include <QPainter>

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

// 重绘事件
void UserShow::paintEvent(QPaintEvent *event)
{
    // 创建画手对象
    QPainter p(this);

    // 设置画刷为黑色
    p.setBrush(Qt::black);

    // 画一个黑色矩形背景
    p.drawRect(-1, 0, this->width() + 1, this->height());

    // todo 画视频帧
}
