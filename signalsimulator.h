#ifndef SIGNALSIMULATOR_H
#define SIGNALSIMULATOR_H
#include "signalgenerator.h"

class SignalSimulator
{
public:
    SignalSimulator();
    ~SignalSimulator();
    SignalGenerator *generator();

private:
    SignalGenerator gener;
};

#endif // SIGNALSIMULATOR_H
