#include "SecurityManager.h"

bool SecurityManager::IsPressureOn()
{
	// to be implemented
	return true;
}

void SecurityManager::IndicateCompartments()
{
	// to be implemented
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
	if(!returnVal)
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
	Serial.println(isecurityPtr->Lock());
	// to be implemented
	DoorClosed();
	if(!IsPressureOn()) SafeMode();
}

void SecurityManager::DoorClosed()
{
	bool actionHasBeenTaken = false;
	byte temp = ioPtr->GetGlobalInputByte();
	if((temp | bitMaskDoorlock) == temp) 
	{
		actionHasBeenTaken = true;
		Serial.println("lock the door");
		if(!doorHasBeenLocked)
		{
			isecurityPtr->SetLock(true);
			doorHasBeenLocked = true;
		}
	}

	if(actionHasBeenTaken) ioPtr->SetGlobalInputByte(0x00);
}
