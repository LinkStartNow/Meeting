HEADERS += \
    $$PWD/cjson.h \
    $$PWD/mysock.h \
    $$PWD/tcpsock.h

SOURCES += \
    $$PWD/mysock.cpp \
    $$PWD/tcpsock.cpp

LIBS += -lws2_32

INCLUDEPATH += mynet
