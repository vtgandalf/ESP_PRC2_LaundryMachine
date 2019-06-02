#include "../lib/WaterManager.h"

// This method handles filling up the water
bool WaterManager::FillUpWater(WaterLevel level)
{
    // variable for the response
    bool response = false;
    // If the current water level isnt high enough
    if (iwaterPtr->GetWaterLevel() < level)
    {
        // If the drain is off
        if (!iwaterPtr->Drain())
        {
            // Make sure it is on
            iwaterPtr->SetDrain(true);
        }
        // If the sink is on
        if (iwaterPtr->Sink())
        {
            // Make sure it is off
            iwaterPtr->SetSink(false);
        }
    }
    // If the water level is high enough
    if(iwaterPtr->GetWaterLevel() == level)
    {
        // Set the response to true
        response = true;
        // If the drain is on
        if (iwaterPtr->Drain())
        {
            // Make sure its off
            iwaterPtr->SetDrain(false);
        }
    }
    // Return the response
    return response;
}

// Method that handles emptying the tank
bool WaterManager::EmptyWaterTank()
{
    // Var for the response
    bool response = false;
    // If there is still water in the tank
    if (iwaterPtr->GetWaterLevel() > EMPTY)
    {
        // If the drain is on
        if (iwaterPtr->Drain())
        {
            // Set it off
            iwaterPtr->SetDrain(false);
        }
        // If the sink is off
        if (!iwaterPtr->Sink())
        {
            // Make sure its on
            iwaterPtr->SetSink(true);
        }
    }
    // If the Water tank is empty
    if (iwaterPtr->GetWaterLevel() == EMPTY)
    {
        // Set the response to true
        response = true;
        // Set the sink to off
        iwaterPtr->SetSink(false);
    }
    // Return the response
    return response;
}

/* Call the Drain method from the IWater interface
and pass through the response */
bool WaterManager::Drain()
{
    return iwaterPtr->Drain();
}

// Method to turn on/off the drain
void WaterManager::SetDrain(bool request)
{
    iwaterPtr->SetDrain(request);
}