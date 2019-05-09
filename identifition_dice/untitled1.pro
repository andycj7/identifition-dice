#-------------------------------------------------
#
# Project created by QtCreator 2018-08-09T17:52:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = identification
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    identification.cpp \
    readfilethread.cpp \
    algorithmthread.cpp \
    form2.cpp \
    form1.cpp \
    form3.cpp

HEADERS += \
        mainwindow.h \
    identification.h \
    form2.h \
    readfilethread.h \
    algorithmthread.h \
    form1.h \
    form3.h

FORMS += \
        mainwindow.ui \
    form2.ui \
    form1.ui \
    form3.ui

INCLUDEPATH+=E:\third_party_library\opencv3.4.1\MinGW-Build\include
             E:\third_party_library\opencv-3.4.1\MinGW-Build\include\opencv
             E:\third_party_library\opencv-3.4.1\MinGW-Build\include\opencv2
LIBS += E:\third_party_library\opencv-3.4.1\MinGW-Build\x64\mingw\lib\libopencv_*.a

RESOURCES += \
    icon.qrc

RC_FILE += app.rc
