#-------------------------------------------------
#
# Project created by QtCreator 2016-06-27T17:16:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Wordie
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    correctwords.cpp

HEADERS  += mainwindow.h \
    correctwords.h

FORMS    += mainwindow.ui

DISTFILES += \
    ../wordsEn.txt
