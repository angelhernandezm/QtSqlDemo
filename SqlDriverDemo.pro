#-------------------------------------------------
#
# Project created by QtCreator 2015-11-27T13:38:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SqlDriverDemo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    employeedto.cpp \
    employeedal.cpp

HEADERS  += mainwindow.h \
    employeedto.h \
    employeedal.h \
    definitions.h \
    utils.h

FORMS    += mainwindow.ui

CONFIG   += C++11

QT += sql
