#ifndef PACKET_H
#define PACKET_H
#include <QList>
#include <QString>
#include <QStringList>


class Packet
{
public:
    Packet();
    ~Packet();

    QByteArray encode();
    bool decode(QByteArray data);

private:
    enum PacketID_enum{
        SENSOR_INIT,
        SENSOR_DATA,
        REGULATOR_INIT,
        REGULATOR_DATA
    };

    PacketID_enum packetID;
    int deviceID;
    QList<QString>* briefData;
    QList<double>* numericData;

    const char START_CHAR = '!';
    const char SEPARATOR = '|';
    const char END_CHAR = '\n';

};

#endif // PACKET_H
