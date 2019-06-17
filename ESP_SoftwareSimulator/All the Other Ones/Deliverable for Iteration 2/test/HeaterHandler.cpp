#include "HeaterHandler.h"

void HeaterHandler::HeatUp(Temp temperature)
{
	if (hwc->GetTemperature() != temperature)
	{
		SetHeater(true);
	}
	else
	{
		SetHeater(false);
	}
}

Temp HeaterHandler::GetTemperature()
{
	return hwc->GetTemperature();
    //return iheaterPtr->GetTemperature();
}

void HeaterHandler::StopHeating()
{
	if (hwc->Heater())
    {
		hwc->SetHeater(false);
    }
    
}

bool HeaterHandler::Heater()
{
	return hwc->Heater();
}

void HeaterHandler::SetHeater(bool request)
{
	hwc->SetHeater(request);
}

void HeaterHandler::setHwc(HardwareControl *hwcont) 
{
	hwc = hwcont;
}

void HeaterHandler::Polling()
{
	if (hwc->HeaterAction() == true)
	{
		if (hwc->Heater() == true) {
			SetHeater(false);
		}
		else
		{
			SetHeater(true);
		}
	}
}