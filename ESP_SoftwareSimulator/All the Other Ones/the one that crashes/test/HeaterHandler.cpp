#include "HeaterHandler.h"

bool HeaterHandler::HeatUp(Temp temperature)
{
    bool response = false;
    if (GetTemperature() < temperature)
    {
        if (!iheaterPtr->Heater())
        {
            iheaterPtr->SetHeater(true);
        }
    }
    if (GetTemperature() == temperature)
    {
        response = true;
        if (iheaterPtr->Heater())
        {
            iheaterPtr->SetHeater(false);
        }
    }
    return response;
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