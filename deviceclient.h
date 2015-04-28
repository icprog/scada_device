#ifndef DEVICECLIENT_H
#define DEVICECLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QTimer>
#include "common/scadadevice.h"


class DeviceClient : public QObject
{
    Q_OBJECT
public:
    explicit DeviceClient(QObject *parent = 0);
    ~DeviceClient();
    bool connectToHost(QString hostName, int portNumber);
    bool disconnect();

    void setDevice(ScadaDevice* dev);


signals:

private slots:
    void onSamplingPeriod();
    void onConnected();
    void onDisconnected();
    void onBytesReceived();


private:
    QTcpSocket* socket;
    QTimer* timer;
    ScadaDevice* device;

};

#endif // DEVICECLIENT_H
