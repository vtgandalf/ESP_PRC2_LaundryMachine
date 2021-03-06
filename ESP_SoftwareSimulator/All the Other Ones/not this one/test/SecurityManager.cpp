#include "SecurityManager.h"

bool SecurityManager::IsPressureOn()
{
	bool response = false;
	//char temp = ioPtr->GetRawInputByte();
	char temp = hwc->GetRawInputByte();
	if (((temp | bitMaskPressure) == temp) && ((temp | bitMaskKeyselect) != temp))
	{
		response = true;
	}
	return response;
}

void SecurityManager::IndicateCompartments()
{
	isecurityPtr->SetLock(true);
	//delay(250);
	isecurityPtr->SetLock(false);
	//delay(250);
	isecurityPtr->SetLock(true);
	//delay(250);
	isecurityPtr->SetLock(false);
	//delay(250);
	isecurityPtr->SetLock(true);
	//delay(250);
	isecurityPtr->SetLock(false);
	//delay(250);
}

bool SecurityManager::IsWaterLevelSafe()
{
	// to be implemented
	return true;
}

bool SecurityManager::IsEverythingClosed()
{
	bool returnVal;
	returnVal = doorHasBeenLocked;
	if (!returnVal)
	{
		IndicateCompartments();
	}
	return returnVal;
}

void SecurityManager::SafeMode()
{
	// to be implemented
}

// method that handles the polling
// contains everything that has to be checked regularly
void SecurityManager::Polling()
{
	//Serial.println(isecurityPtr->Lock());
	// to be implemented
	DoorClosed();
	if (!IsPressureOn())
		SafeMode();
}

void SecurityManager::DoorClosed()
{
	bool actionHasBeenTaken = false;
	//char temp = ioPtr->GetGlobalInputByte();
	char temp = hwc->GetGlobalInputByte();
	if (((temp | bitMaskDoorlock) == temp) & ((temp | bitMaskKeyselect) != temp))
	{
		actionHasBeenTaken = true;
		//Serial.println("lock the door");
		if (!doorHasBeenLocked)
		{
			//isecurityPtr->SetLock(true);
			hwc->SetLock(true);
			doorHasBeenLocked = true;
		}
	}

	if (actionHasBeenTaken)
		//ioPtr->SetGlobalInputByte(0x00);
		hwc->SetGlobalInputByte(0x00);

}

void SecurityManager::setHwc(HardwareControl *hwcont)
{
	hwc = hwcont;
}