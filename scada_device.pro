#-------------------------------------------------
#
# Project created by QtCreator 2015-03-28T23:47:22
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = scada_device
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    scadadevice.cpp \
    packet.cpp

HEADERS += \
    scadadevice.h \
    packet.h
