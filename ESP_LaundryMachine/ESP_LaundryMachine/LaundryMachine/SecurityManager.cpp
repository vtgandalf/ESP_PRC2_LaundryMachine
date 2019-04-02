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
	// to be implemented
	DoorClosed();
	if(IsPressureOn()) SafeMode();
}

void SecurityManager::DoorClosed()
{
	if(ioPtr->Keyselect())ioPtr->SetKeyselect(false);
	function = ioPtr->GetButtonsFunction();
	if(function == DOORLOCK) 
	{
		Serial.println("Lock");
		isecurityPtr->SetLock(true);
	}
	if(function != DOORLOCK) 
	{
		isecurityPtr->SetLock(false);
	}
}