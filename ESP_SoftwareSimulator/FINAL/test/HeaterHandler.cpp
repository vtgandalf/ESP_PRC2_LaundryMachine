#include "HeaterHandler.h"

// Method that handles heating up the water
bool HeaterHandler::HeatUp(Temp temperature)
{
    // Var for the response
    bool response = false;
    // If the temp is not high enough
    if (GetTemperature() < temperature)
    {
        // If the heater is off
        if (!iheaterPtr->Heater())
        {
            // Turn it on
            iheaterPtr->SetHeater(true);
        }
    }
    // If the temp is high enough
    if (GetTemperature() == temperature)
    {
        // Set the response to true
        response = true;
        // If the heater is on
        if (iheaterPtr->Heater())
        {
            // Turn it off
            iheaterPtr->SetHeater(false);
        }
    }
    // Return the response (true if the heating process is completed)
    return response;
}

/* Get the temperature from the IHeater interface
and pass through the response */
Temp HeaterHandler::GetTemperature()
{
    return iheaterPtr->GetTemperature();
}

// Method that stops the heating
void HeaterHandler::StopHeating()
{
    // If the heater is on
    if (iheaterPtr->Heater())
    {
        // Turn it off
        iheaterPtr->SetHeater(false);
    }
}