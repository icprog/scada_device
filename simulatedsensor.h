#ifndef SIMULATEDSENSOR_H
#define SIMULATEDSENSOR_H

#include "sensor.h"
#include "signalsimulator.h"

class SimulatedSensor : public Sensor, public SignalSimulator
{

public:
    SimulatedSensor();
    SimulatedSensor(int uuid, QString name, QString factoryData, QString measurandName, QString measureUnit, double rangeMin, double rangeMax, double samplingPeriod);
    ~SimulatedSensor();

};

#endif // SIMULATEDSENSOR_H
