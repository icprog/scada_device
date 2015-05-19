#include <QCoreApplication>
#include <QTextStream>
#include <QByteArray>
#include "common/packet.h"
#include "deviceclient.h"
#include "simulatedsensor.h"

int main(int argc, char *argv[])
{

    QTextStream qCout(stdout, QIODevice::WriteOnly);
    QTextStream qCin(stdin);
    if(argc != 3)
    {
        qCout<<"Usage: scada_device [server addres] [portnumber]\n";
        return -1;
    }
    QString hostAddress = QString(argv[1]);
    int portNumber = QString(argv[2]).toInt();


    QString name, factoryData, measurandName, measureUnit;
    double rangeMin, rangeMax, samplingPeriod, amplitude, phase, stdDev, period;
    int uuid;
    qCout<<"Type: \" default\" to use default sensor settings or press ENTER to set new settings."<<endl;
    if(qCin.readLine()=="default")
    {
        uuid = 111;
        name = "Sensor";
        factoryData = "Really good one";
        measurandName = "Pressure";
        measureUnit = "kPa";
        rangeMin = 0;
        rangeMax = 10;
        samplingPeriod = 0.1;
        period = 1000;
        amplitude = 1;
    }
    else
    {
        qCout<<"Device name: "<<endl;
        name = qCin.readLine();

        qCout<<"Device UUID: "<<endl;
        uuid = qCin.readLine().toInt();
        qCout<<"Factory data: "<<endl;
        factoryData = qCin.readLine();
        qCout<<"Measurand name: "<<endl;
        measurandName = qCin.readLine();
        qCout<<"Measure unit: "<<endl;
        measureUnit = qCin.readLine();
        qCout<<"Range: minimum: "<<endl;
        rangeMin = (qCin.readLine()).toDouble();
        qCout<<"Range: maximum: "<<endl;
        rangeMax = (qCin.readLine()).toDouble();
        qCout<<"Sampling period: "<<endl;
        samplingPeriod = (qCin.readLine()).toDouble();
        qCout<<"Signal simulator parameters: \n Amplitude:"<<endl;
        amplitude = (qCin.readLine()).toDouble();
        qCout<<"Period: "<<endl;
        period = (qCin.readLine()).toDouble();
        qCout<<"Phase: "<<endl;
        phase = (qCin.readLine()).toDouble();
        qCout<<"Standard Deviation: "<<endl;
        stdDev = (qCin.readLine()).toDouble();
    }


    QCoreApplication a(argc, argv);
    SimulatedSensor simulatedSensor(uuid, name, factoryData, measurandName, measureUnit, rangeMin, rangeMax, samplingPeriod);
    simulatedSensor.setParameters(amplitude,0, 0.1);
    simulatedSensor.setTimeBase(period);
    ScadaDevice* device = &simulatedSensor;


    DeviceClient deviceClient;
    deviceClient.setDevice(device);
    deviceClient.connectToHost(hostAddress, portNumber);

    return a.exec();
}
