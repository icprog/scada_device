#include "simulatedsensor.h"

SimulatedSensor::SimulatedSensor()
{

}

SimulatedSensor::SimulatedSensor(int uuid, QString name, QString factoryData, QString measurandName, QString measureUnit, double rangeMin, double rangeMax, double samplingPeriod)
{
    this->uuid = uuid;
    this->name = name;
    this->factoryData =factoryData;
    this->measurandName = measurandName;
    this->measurandUnit = measureUnit;
    this->rangeMax = rangeMax;
    this->rangeMin = rangeMin;
    this->samplingPeriod = samplingPeriod;
    this->generator = new SignalGenerator(NULL, &currentValue);

}

SignalGenerator* SimulatedSensor::getGenerator() const
{
    return generator;
}

SimulatedSensor::~SimulatedSensor()
{
    delete generator;
}

