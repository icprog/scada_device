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
    signalsimulator.cpp \
    signalgenerator.cpp \
    simulatedsensor.cpp \
    packet.cpp \
    scadadevice.cpp \
    sensor.cpp \
    deviceclient.cpp

HEADERS += \
    signalsimulator.h \
    signalgenerator.h \
    simulatedsensor.h \
    deviceclient.h \
    packet.h \
    scadadevice.h \
    sensor.h
