#ifndef SIMULATEDSENSOR_H
#define SIMULATEDSENSOR_H

#include "common/sensor.h"
#include "signalgenerator.h"

class SimulatedSensor : public Sensor, public SignalGenerator
{

public:
    SimulatedSensor();
    SimulatedSensor(int uuid, QString name, QString factoryData, QString measurandName, QString measureUnit, double rangeMin, double rangeMax, double samplingPeriod);
    ~SimulatedSensor();



};

#endif // SIMULATEDSENSOR_H
