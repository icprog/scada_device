#include "deviceclient.h"

DeviceClient::DeviceClient(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    connect(this->timer, SIGNAL(timeout()),this, SLOT(onSamplingPeriod()));
    timer->setInterval(500);
    timer->start();

}

DeviceClient::~DeviceClient()
{

}

bool DeviceClient::connectToHost(QString hostName, int portNumber)
{
    socket = new QTcpSocket(this);
    socket->connectToHost(hostName, portNumber); //Connect to gived server
    connect(this->socket, SIGNAL(connected()), this, SLOT(onConnected()));
    connect(this->socket, SIGNAL(readyRead()), this, SLOT(onBytesReceived()));
    connect(this->socket, SIGNAL(disconnected()), this, SLOT(onDisconnected()));

    qDebug()<<"Connecting...";
    if(!socket->waitForConnected()) //Function above is non-blocking so we need to wait manually (30sec by default)
    {
        qDebug()<<"Connection failed. ";
        qDebug()<<"Error: "<<socket->errorString();
        return false;
    }
    else return true;
}

bool DeviceClient::disconnect()
{
    socket->disconnectFromHost();
    if(!socket->waitForDisconnected())
    {
        qDebug()<<"Disconnection error: "<<socket->errorString();
        return false;
    }
    else return true;
}

void DeviceClient::setDevice(ScadaDevice *dev)
{
    this->device = dev;
}

void DeviceClient::onSamplingPeriod()
{
    socket->write((device->getDataPacket()).encode());
}

void DeviceClient::onConnected()
{
    qDebug()<<"Connected. Sending init message.";
    socket->write((device->getInitPacket()).encode());
}

void DeviceClient::onDisconnected()
{
    qDebug()<<"Disconnected";
}

void DeviceClient::onBytesReceived()
{
    qDebug() << "Data received";
    QByteArray rxData = socket->readAll();
    Packet packet;
    QList<Packet> packetList;
    while(packet.decode(&rxData)) //there can be more packets which came together
    {
        packetList.append(packet); //we will separate them and put into list
    }
    foreach(Packet element, packetList)
    {
        if(element.getPacketType()==Packet::SETTINGS)
        {
            qDebug() << "SETTINGS received";
            SimulatedSensor* sensor = dynamic_cast<SimulatedSensor*>(device);
            if(sensor)
            {
                sensor->settingsReceived(&element);
            }
            else device->settingsReceived(&element);
        }
    }
}
