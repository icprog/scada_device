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

void SignalGenerator::setParameters(double amplitude, double constant, double stdDeviation)
{
    this->amplitude = amplitude;
    this->constant = constant;
    this->stdDeviation = stdDeviation;
}

void SignalGenerator::setGeneratedValuePointer(double* genVal)
{
    this->currentValuePtr = genVal;
}


void SignalGenerator::onTimerTimeout()
{
    currentTime++;
    *currentValuePtr = amplitude * sin(((2*M_PI/interval)*currentTime)* (2 * M_PI /360));
    *currentValuePtr += constant;
    double rnd = (-1 *stdDeviation) + (double(rand())/RAND_MAX) * (2*stdDeviation);
    *currentValuePtr += rnd;
//    if(currentTime>50)
//        currentTime = 0;
}
