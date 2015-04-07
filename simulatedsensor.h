#ifndef SIMULATEDSENSOR_H
#define SIMULATEDSENSOR_H

#include "sensor.h"
#include "signalsimulator.h"

class SimulatedSensor : public Sensor, SignalSimulator
{

public:
    SimulatedSensor();
    ~SimulatedSensor();

};

#endif // SIMULATEDSENSOR_H
