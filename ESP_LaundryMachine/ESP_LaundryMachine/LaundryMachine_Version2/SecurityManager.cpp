#include "SecurityManager.h"

bool SecurityManager::IsPressureOn()
{
	// to be implemented
	return true;
}

bool SecurityManager::IsWaterLevelSafe()
{
	// to be implemented
	return true;
}

bool SecurityManager::IsEverythingClosed()
{
	// to be implemented
	return true;
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
	//DoorClosed();
	DoorClosedByte();
	if(!IsPressureOn()) SafeMode();
}

void SecurityManager::DoorClosed()
{
	//Serial.println("SecurityManager::DoorClosed");
	/*ioPtr->SetKeyselect(false);
	function = ioPtr->GetButtonsFunction();
	if(function!=NOTHING) 
	{
		Serial.print("SecurityManager::GetButtonsFunctionDebounced::");
		Serial.println(function);
	}*/
	if(ioPtr->GetGlobalFunction() == DOORLOCK) 
	{
		if(!doorHasBeenLocked)
		{
			Serial.println("lock the door");
			ioPtr->SetGlobalFunction(NOTHING);
			isecurityPtr->SetLock(true);
			doorHasBeenLocked = true;
		}
	}
}

void SecurityManager::DoorClosedByte()
{
	//Serial.println("SecurityManager::DoorClosed");
	/*ioPtr->SetKeyselect(false);
	function = ioPtr->GetButtonsFunction();
	if(function!=NOTHING) 
	{
		Serial.print("SecurityManager::GetButtonsFunctionDebounced::");
		Serial.println(function);
	}*/

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
