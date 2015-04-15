#include <QCoreApplication>
#include <QTextStream>
#include <QByteArray>
#include "packet.h"
#include "deviceclient.h"
#include "simulatedsensor.h"

int main(int argc, char *argv[])
{

  /*  QTextStream qCout(stdout);
    QTextStream qCin(stdin);
    if(argc != 2)
    {
        qCout<<"Usage: scada_device [type] [server addres] [portnumber]\n";
        return -1;
    }
    switch(argv[0])
    {
    case "sensor":
        {
            QString name, factoryData, measurandName, measureUnit;
            double rangeMin, rangeMax, samplingPeriod;
            qCout<<"Device name: ";
            name = qCin.readLine();
            qCout<<"Factory data: ";
            factoryData = qCin.readLine();
            qCout<<"Measurand name: ";
            measurandName = qCin.readLine();
            qCout<<"Measure unit: ";
            measureUnit = qCin.readLine();
            qCout<<"Range: minimum: ";
            rangeMin = (qCin.readLine()).toDouble();
            qCout<<"Range: maximum: ";
            rangeMax = (qCin.readLine()).toDouble();
            qCout<<"Sampling period: ";
            samplingPeriod = (qCin.readLine()).toDouble();

            device = new Sensor(name, factoryData, measurandName, measureUnit, rangeMin, rangeMax, samplingPeriod);
        }break;
    case "regulator":
        {
        QString name, factoryData;
        double Kp, Ki, Kd, setpoint, samplingPeriod;
            qCout<<"Device name: ";
            name = qCin.readLine();
            qCout<<"Factory data: ";
            factoryData = qCin.readLine();
            qCout<<"Set PID settings: \n";
            Kp = (qCin.readLine()).toDouble();
            Ki = (qCin.readLine()).toDouble();
            Kd = (qCin.readLine()).toDouble();
            qCout<<"Setpoint: \n";
            setpoint = (qCin.readLine()).toDouble();
            qCout<<"Sampling period: ";
            samplingPeriod = (qCin.readLine()).toDouble();

            device = new Regulator(name, factoryData, Kp, Ki, Kd, setpoint, samplingPeriod);
        }break;
    default:
        qCout<<"This program has no Super Cow power. Usage: scada_device [type] [server addres] [portnumber]\n";
        return -1;
    }

    qCout<<"Device created. Signal simulator parameters: \n Amplitude:";
    amplitude = (qCin.readLine()).toDouble();
    qCout<<"Period: ";
    period = (qCin.readLine()).toDouble();
    qCout<<"Phase: ";
    phase = (qCin.readLine()).toDouble();
    qCout<<"Standard Deviation: ";
    stdDev = (qCin.readLine()).toDouble();
    device->generator().setParameters(amplitude, phase, stdDev);

*/
    QCoreApplication a(argc, argv);
    SimulatedSensor simulatedSensor(112, "sensor", "really good one", "pressure", "kPa", 0, 100, 0.1);
    simulatedSensor.generator()->setParameters(10,0,1);
    simulatedSensor.generator()->setTimeBase(1000);
    ScadaDevice* device = &simulatedSensor;
//    SimulatedSensor* sensor = dynamic_cast<SimulatedSensor*>(&device);


    DeviceClient deviceClient;
    deviceClient.setDevice(device);
    deviceClient.connectToHost("localhost", 8888);


//    delete device, deviceClient;
    return a.exec();
}
