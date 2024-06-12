#ifndef AUDIO_COMMON_H
#define AUDIO_COMMON_H

//获取声音和播放声音的组件是 Qt 自带的 QAudioInput 和 QAudioOutput ,
#include<QAudioInput>
#include<QAudioOutput>
#include<QAudioFormat>
#include<QAudioDeviceInfo>
#include<QMessageBox>
#include<qDebug>


#define USE_SPEEX 1

#if USE_SPEEX
////使用speex
#include "speex/include/speex.h"

////设置压缩质量
#define SPEEX_QUALITY (8)

#endif

#endif // AUDIO_COMMON_H
