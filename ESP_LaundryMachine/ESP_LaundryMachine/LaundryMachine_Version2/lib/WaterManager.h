#ifndef WATERMANAGER_H
#define WATERMANAGER_H

#include "HardwareControl.h"

using namespace sharedNamespace;

class WaterManager
{
public:
    /* This is a method that handles filling
    up the tank with water up to a desired
    point
    input: sharedNamespace::WaterLevel */
    void FillUpWater(WaterLevel);
    /* This is a method that handles emptying
    the tank fully. It will halt every other
    process until that is done */
    void EmptyWaterTank();
    /* Method that returns the current status
    of the drain. That is needed for adding the
    soap, since it should be for that action to 
    execute
    output: 
        - true - drain is open
        - false - drain is closed*/
    bool Drain();
    /* Method that sets the drain on or off. This
    is meant to be called from outside this class 
    again for adding the soap
    input:
        - true - turn it on
        - false - turn it off */
    void SetDrain(bool);

private:
    IWater* iwaterPtr = (IWater*)HardwareControl::GetInstance();
};

#endif