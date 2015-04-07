#-------------------------------------------------
#
# Project created by QtCreator 2015-03-28T23:47:22
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = scada_device
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    scadadevice.cpp \
    packet.cpp \
    signalsimulator.cpp \
    signalgenerator.cpp \
    sensor.cpp \
    simulatedsensor.cpp \
    deviceclient.cpp

HEADERS += \
    scadadevice.h \
    packet.h \
    signalsimulator.h \
    signalgenerator.h \
    sensor.h \
    simulatedsensor.h \
    deviceclient.h
