#include "../lib/WaterManager.h"

void WaterManager::FillUpWater(WaterLevel level)
{
    while (iwaterPtr->GetWaterLevel() < level)
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
}

void WaterManager::EmptyWaterTank()
{
    while (iwaterPtr->GetWaterLevel() > EMPTY)
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
}

bool WaterManager::Drain()
{
    return iwaterPtr->Drain();
}

void WaterManager::SetDrain(bool request)
{
    iwaterPtr->SetDrain(request);
}