#ifndef SCREENREADER_H
#define SCREENREADER_H

#include <QObject>
#include<QTimer>
#include<QApplication>
#include<QDesktopWidget>
#include<QBuffer>
#include<QScreen>
#include<QImage>
#include "common.h"

class ScreenReader : public QObject
{
    Q_OBJECT
public:
    explicit ScreenReader(QObject *parent = nullptr);

signals:
    void sig_ScreenFrame(QImage);

public slots:
    void slot_GetScreen();
    void slot_stop();
    void slot_start();

private:
    QTimer*      m_timer;



};

#endif // SCREENREADER_H
