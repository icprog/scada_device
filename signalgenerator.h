#ifndef SIGNALGENERATOR_H
#define SIGNALGENERATOR_H

#include <QObject>
#include <QTimer>
#include <QtMath>

class SignalGenerator : public QObject
{
    Q_OBJECT
public:
    SignalGenerator(QObject *parent = 0);
    SignalGenerator(QObject *parent, double* generatedSignalPointer);
    ~SignalGenerator();
    void setTimeBase(double time);
    void setParameters(double amplitude, double phase, double stdDeviation);
    void setGeneratedValuePointer(double* genVal);
//    QTimer* getTimer();
private:
    QTimer timer;
    double amplitude;
    double phase;
    double interval;
    double timeBase;
    double stdDeviation;
protected:
    double *currentValuePtr;
    int currentTime;

public slots:
    void onTimerTimeout();
};

#endif // SIGNALGENERATOR_H
