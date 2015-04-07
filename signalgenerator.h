#ifndef SIGNALGENERATOR_H
#define SIGNALGENERATOR_H

#include <QObject>
#include <QTimer>
#include <QtMath>

class SignalGenerator : public QObject
{
    Q_OBJECT
public:
    explicit SignalGenerator(QObject *parent = 0);
    ~SignalGenerator();
    void setTimeBase(double time);
    void setParameters(double amplitude, double phase, double stdDeviation);
    QTimer* getTimer();
private:
    QTimer timer;
    double amplitude;
    double phase;
    double interval;
    double timeBase;
    double stdDeviation;

    double currentValue;
    int currentTime;

public slots:
    void onTimerTimeout();
};

#endif // SIGNALGENERATOR_H
