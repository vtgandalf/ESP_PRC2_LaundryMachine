#ifndef MOTORMANAGER_H
#define MOTORMANAGER_H

#include "HardwareControl.h"

using namespace sharedNamespace;

class MotorManager
{
    public:
    void Rotate(Rotation, Speed, long);

    private:
    IMotor* imotorPtr = (IMotor*)HardwareControl::GetInstance();
    long prevMillis;
};

#endif