#ifndef SIMULATEDSENSOR_H
#define SIMULATEDSENSOR_H

#include "sensor.h"
#include "signalgenerator.h"

class SimulatedSensor : public Sensor
{

public:
    SimulatedSensor();
    SimulatedSensor(int uuid, QString name, QString factoryData, QString measurandName, QString measureUnit, double rangeMin, double rangeMax, double samplingPeriod);
    ~SimulatedSensor();
    SignalGenerator* getGenerator() const;

private:
    SignalGenerator *generator;


};

#endif // SIMULATEDSENSOR_H
