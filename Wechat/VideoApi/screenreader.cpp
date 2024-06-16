#include "screenreader.h"

ScreenReader::ScreenReader(QObject *parent) : QObject(parent)
{
    m_timer = new QTimer;
    connect(m_timer, &QTimer::timeout, this, &ScreenReader::slot_GetScreen);
}

void ScreenReader::slot_GetScreen()
{
    QScreen *src = QApplication::primaryScreen();
    // QRect deskRect = QApplication::desktop()->screenGeometry();
     QPixmap map = src->grabWindow( QApplication::desktop()->winId()/* ,0,0 , deskRect.width() ,
    deskRect.height()*/);

     QImage image = map.toImage();
//     image = image.scaled( 1600, 900, Qt::KeepAspectRatio, Qt::SmoothTransformation );
     image = image.scaled(IMAGE_WIDTH, IMAGE_HEIGHT, Qt::KeepAspectRatio, Qt::SmoothTransformation);
     Q_EMIT sig_ScreenFrame(image);
//    //压缩图片从 RGB24 格式压缩到 JPEG 格式, 发送出去
//    QByteArray ba;
//    QBuffer qbuf(&ba); // QBuffer 与 QByteArray 字节数组联立联系
//    image.save( &qbuf , "JPEG" , 60 ); //将图片的数据写入 ba
//    Q_EMIT sig_ScreenFrame( ba );
}

void ScreenReader::slot_stop()
{
    if (m_timer) m_timer->stop();
}

void ScreenReader::slot_start()
{
    if (m_timer) m_timer->start(1000 / FRAME_RATE - 10);
}
