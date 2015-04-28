#include "signalgenerator.h"

SignalGenerator::SignalGenerator(QObject *parent) : QObject(parent)
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(onTimerTimeout()));
    currentTime =0;
    currentValuePtr = 0;


}

SignalGenerator::SignalGenerator(QObject *parent, double* generatedSignalPointer) : QObject(parent)
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(onTimerTimeout()));
    currentTime =0;
    currentValuePtr = 0;
    currentValuePtr = generatedSignalPointer;
}

SignalGenerator::~SignalGenerator()
{

}

void SignalGenerator::setTimeBase(double time)
{
    this->timeBase = time;
    this->interval = time/50;
    timer.setInterval(interval);
    timer.start();
}

void SignalGenerator::setParameters(double amplitude, double phase, double stdDeviation)
{
    this->amplitude = amplitude;
    this->phase = phase;
    this->stdDeviation = stdDeviation;
}

void SignalGenerator::setGeneratedValuePointer(double* genVal)
{
    this->currentValuePtr = genVal;
}

//QTimer* SignalGenerator::getTimer()
//{
//    return &timer;
//}

void SignalGenerator::onTimerTimeout()
{
    currentTime++;
    *currentValuePtr = amplitude * sin((2*M_PI/interval)*currentTime + phase * (2 * M_PI /360));
    double a = -10;
    double b = 10;
//    *currentValue += a+rand()*(b-a);
    if(currentTime>50)
        currentTime = 0;
}
