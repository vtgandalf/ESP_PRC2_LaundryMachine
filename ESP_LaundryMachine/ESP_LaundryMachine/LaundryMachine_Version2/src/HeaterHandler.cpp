#include "../lib/HeaterHandler.h"

void HeaterHandler::HeatUp(Temp temperature)
{
    Serial.print("Heating up... ");
    while (GetTemperature() <= temperature)
    {
        if (!iheaterPtr->Heater())
        {
            iheaterPtr->SetHeater(true);
        }
    }
    Serial.print("done.");
}

Temp HeaterHandler::GetTemperature()
{
    return iheaterPtr->GetTemperature();
}

void HeaterHandler::StopHeating()
{
    if (iheaterPtr->Heater())
    {
        Serial.println("Heater has been stopped.");
        iheaterPtr->SetHeater(false);
    }
    
}