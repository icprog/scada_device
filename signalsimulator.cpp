#include "signalsimulator.h"

SignalSimulator::SignalSimulator()
{

}

SignalSimulator::~SignalSimulator()
{

}

SignalGenerator* SignalSimulator::generator()
{
    return &gener;
}
