QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ckernel.cpp \
    loginwin.cpp \
    main.cpp \
    roomdialog.cpp \
    usershow.cpp \
    wechatdialog.cpp

HEADERS += \
    Protocol.h \
    ckernel.h \
    loginwin.h \
    roomdialog.h \
    usershow.h \
    wechatdialog.h

FORMS += \
    loginwin.ui \
    roomdialog.ui \
    usershow.ui \
    wechatdialog.ui

include(mynet/mynet.pri)
include(md5/md5.pri)
include(AudioApi/audioapi.pri)

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES +=
