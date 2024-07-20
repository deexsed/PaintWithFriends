#-------------------------------------------------
#
# Project created by QtCreator 2023-09-27T15:09:33
#
#-------------------------------------------------

QT       += core gui network
QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = paintOnline
TEMPLATE = app


SOURCES += main.cpp\
        paint.cpp \
    paintscene.cpp \

HEADERS  += paint.h \
    paintscene.h \

FORMS    += paint.ui

RC_FILE += appIcon.rc
