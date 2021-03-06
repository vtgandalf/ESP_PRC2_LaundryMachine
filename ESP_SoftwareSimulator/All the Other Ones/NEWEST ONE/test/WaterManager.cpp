#include "WaterManager.h"

bool WaterManager::FillUpWater(WaterLevel level)
{
    bool response = false;
    if (iwaterPtr->GetWaterLevel() < level)
    {
        if (!iwaterPtr->Drain())
        {
            iwaterPtr->SetDrain(true);
        }
        if (iwaterPtr->Sink())
        {
            iwaterPtr->SetSink(false);
        }
    }
    if(iwaterPtr->GetWaterLevel() == level)
    {
        response = true;
    }
    return response;
}

bool WaterManager::EmptyWaterTank()
{
    bool response = false;
    if (iwaterPtr->GetWaterLevel() > EMPTY)
    {
        if (iwaterPtr->Drain())
        {
            iwaterPtr->SetDrain(false);
        }
        if (!iwaterPtr->Sink())
        {
            iwaterPtr->SetSink(true);
        }
    }
    if (iwaterPtr->GetWaterLevel() == EMPTY)
    {
        response = true;
        iwaterPtr->SetSink(false);
    }
    return response;
}

bool WaterManager::Drain()
{
    return iwaterPtr->Drain();
}

void WaterManager::SetDrain(bool request)
{
    iwaterPtr->SetDrain(request);
}