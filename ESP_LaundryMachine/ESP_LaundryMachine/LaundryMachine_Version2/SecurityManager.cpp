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
	//Serial.println("SecurityManager");
	// to be implemented
	DoorClosed();
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
		Serial.println("lock the door");
		if(!doorHasBeenLocked)
		{
			ioPtr->SetGlobalFunction(NOTHING);
			isecurityPtr->SetLock(true);
			doorHasBeenLocked = true;
		}
	}
}
