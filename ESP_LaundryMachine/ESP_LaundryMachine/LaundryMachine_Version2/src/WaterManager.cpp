#include "../lib/WaterManager.h"

bool WaterManager::FillUpWater(WaterLevel level, int program, SecurityManager *sec)
{
    bool response = false;
    Serial.print("Filling up tank... ");
    while (iwaterPtr->GetWaterLevel() < level)
    {
        if (!sec->IsPressureOn())
        {
            response = sec->SafeMode(program);
        }
        else
        {
            if (!response)
            {
                response = true;
            }
        }
        if (!iwaterPtr->Drain())
        {
            iwaterPtr->SetDrain(true);
        }
        if (iwaterPtr->Sink())
        {
            iwaterPtr->SetSink(false);
        }
    }
    Serial.println("done.");
    return response;
}

void WaterManager::EmptyWaterTank()
{
    Serial.print("Emptying tank... ");
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
    Serial.println("done.");
}

bool WaterManager::Drain()
{
    return iwaterPtr->Drain();
}

void WaterManager::SetDrain(bool request)
{
    Serial.print("Drain set to: ");
    Serial.print(request);
    Serial.println(".");
    iwaterPtr->SetDrain(request);
}