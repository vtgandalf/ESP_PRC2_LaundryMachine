#include "WaterManager.h"

bool WaterManager::FillUpWater(WaterLevel level, int program, SecurityManager *sec)
{

	bool response = false;
	// Serial.print("Filling up tank... ");
	while (hwc->GetWaterLevel() < level)
		//while (iwaterPtr->GetWaterLevel() < level)
	{
		if (!sec->IsPressureOn())
		{
			//response = sec->SafeMode(program);
		}
		else
		{
			if (!response)
			{
				response = true;
			}
		}
		//if (!iwaterPtr->Drain())
		if (!hwc->Drain())
		{
			//iwaterPtr->SetDrain(true);
		}
		//if (iwaterPtr->Sink())
		if (hwc->Sink())
		{
			hwc->SetSink(false);
			//iwaterPtr->SetSink(false);
		}
	}
	// Serial.println("done.");
	return response;

}

void WaterManager::EmptyWaterTank()
{
	//Serial.print("Emptying tank... ");
	//while (iwaterPtr->GetWaterLevel() > EMPTY)
	while (hwc->GetWaterLevel() > EMPTY)
	{
		if (hwc->Drain())
			//if (iwaterPtr->Drain())
		{
			hwc->SetDrain(false);
			//iwaterPtr->SetDrain(false);
		}
		//if (!iwaterPtr->Sink())
		if (!hwc->Sink())
		{
			hwc->SetSink(true);
			//iwaterPtr->SetSink(true);
		}
	}
	// Serial.println("done.");
}

bool WaterManager::Drain()
{
	return hwc->Drain();
	//return iwaterPtr->Drain();
}

void WaterManager::SetDrain(bool request)
{
	// Serial.print("Drain set to: ");
	 //Serial.print(request);
	 //Serial.println(".");
	 //iwaterPtr->SetDrain(request);
	hwc->SetDrain(request);
}

void WaterManager::setHwc(HardwareControl *hwcont)
{
	hwc = hwcont;
}

void WaterManager::Polling()
{
	if (hwc->PressureAction() == true)
	{
		if (hwc->Drain() == true) {
			SetDrain(false);
		}
		else
		{
			SetDrain(true);
		}
	}

}
