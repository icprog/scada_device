#include "signalsimulator.h"

SignalSimulator::SignalSimulator()
{
    gener = new SignalGenerator();
}

SignalSimulator::~SignalSimulator()
{
    delete gener;
}

SignalGenerator* SignalSimulator::generator()
{
    return gener;
}
