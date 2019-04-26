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

private:
    IWater* iwaterPtr = (IWater*)HardwareControl::GetInstance();
};

#endif