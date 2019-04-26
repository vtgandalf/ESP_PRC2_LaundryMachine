#include "../lib/HeaterHandler.h"

void HeaterHandler::HeatUp(Temp temperature)
{
    /* to be added:
            the heater shoudl
            only turn on whenever
            the water level is save,
            which the securityManager 
            should indicate */
    while (GetTemperature() <= temperature)
    {
        if (!iheaterPtr->Heater())
        {
            iheaterPtr->SetHeater(true);
        }
    }
}

Temp HeaterHandler::GetTemperature()
{
    return iheaterPtr->GetTemperature();
}

void HeaterHandler::StopHeating()
{
    if (iheaterPtr->Heater())
    {
        iheaterPtr->SetHeater(false);
    }
    
}