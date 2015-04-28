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
    signalgenerator.cpp \
    simulatedsensor.cpp \
    deviceclient.cpp \
    common/humanmachineinterface.cpp \
    common/packet.cpp \
    common/scadadevice.cpp \
    common/sensor.cpp

HEADERS += \
    signalgenerator.h \
    simulatedsensor.h \
    deviceclient.h \
    common/humanmachineinterface.h \
    common/packet.h \
    common/scadadevice.h \
    common/sensor.h
