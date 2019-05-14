#ifndef MOTORMANAGER_H
#define MOTORMANAGER_H

#include "HardwareControl.h"

using namespace sharedNamespace;

class MotorManager
{
    public:
    /* This is a method that handles rotation of
    the tank during the washing
    input: 
        - sharedNamespace::Rotation (giving the direction for rotating)
        - sharedNamespace::Speed (giving the speed for rotation)
        - long - gives the suration of the rotation in seconds
    */
    void Rotate(Rotation, Speed, long);

    private:
    // accessing the library through the interfaces
    IMotor* imotorPtr = (IMotor*)HardwareControl::GetInstance();
    /* Var which is a holder for the last millis value
	from the cpu at which the rotation started. It is
	used to calculate the time passed since the rotation 
    started */
    long prevMillis;
};

#endif