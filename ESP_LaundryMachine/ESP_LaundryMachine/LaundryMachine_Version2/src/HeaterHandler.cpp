#include "../lib/HeaterHandler.h"

void HeaterHandler::HeatUp(Temp temperature)
{
    Serial.print("Heating up... ");
    while (GetTemperature() < temperature)
    {
        if (!iheaterPtr->Heater())
        {
            iheaterPtr->SetHeater(true);
        }
    }
    if (iheaterPtr->Heater())
    {
        iheaterPtr->SetHeater(false);
    }
    //iheaterPtr->SetHeater(true);
    //Serial.print(" ");
    //Serial.println(iheaterPtr->GetTemperature());
    //Serial.print(" ");
    Serial.println("done.");
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