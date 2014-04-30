#-------------------------------------------------
#
# Project created by QtCreator 2014-04-26T15:52:24
#
#-------------------------------------------------

QT       += core gui\
            network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PanelBoeing
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    panel.cpp \
    ../../Qtraspberrylib/display7seg.cpp \
    ../../Qtraspberrylib/ht16k33.cpp \
    ../../Qtraspberrylib/mcp23017_isr.cpp \
    ../../Qtraspberrylib/mcp23017.cpp \
    b777.cpp \
    ../../Qtraspberrylib/rotaryencoder.cpp \
    ../../Qtraspberrylib/pbutton.cpp \
    ../../Qtraspberrylib/qttelnet.cpp

LIBS += -lwiringPi

HEADERS  += mainwindow.h \
    panel.h \
    ../../Qtraspberrylib/display7seg.h \
    ../../Qtraspberrylib/ht16k33.h \
    ../../Qtraspberrylib/mcp23017.h \
    ../../Qtraspberrylib/mcp23017_isr.h \
    hardware_conf.h \
    b777.h \
    ../../Qtraspberrylib/rotaryencoder.h \
    ../../Qtraspberrylib/pbutton.h \
    ../../Qtraspberrylib/qttelnet.h

FORMS    += mainwindow.ui
