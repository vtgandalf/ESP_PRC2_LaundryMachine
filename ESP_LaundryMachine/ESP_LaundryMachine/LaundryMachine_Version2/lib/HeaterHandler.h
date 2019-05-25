#ifndef IHEATERHANDLER_H
#define IHEATERHANDLER_H

#include "HardwareControl.h"
using namespace sharedNamespace;

class HeaterHandler
{
public:
    /* This method will handle the turning 
        on the heater and maintaining the temperature
        in the tank
        input:  sharedNamespace::Temp 
        output:
            - true - Temp has been reached
            - false - Temp hasn't been reached*/
    bool HeatUp(Temp);
    /* This is a method which will return 
        the temperature in the tank
        output: sharedNamespace::Temp */
    Temp GetTemperature();
    /* This is a method that handles
    disabling the heating */
    void StopHeating();

private:
    // accessing the library through this interface
    IHeater *iheaterPtr = (IHeater *)HardwareControl::GetInstance();
};

#endif