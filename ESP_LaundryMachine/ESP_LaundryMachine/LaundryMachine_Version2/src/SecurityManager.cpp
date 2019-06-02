#include "../lib/SecurityManager.h"

/* Checks if the door switch has been closed
and returns its state */
bool SecurityManager::IsPressureOn()
{
	return isecurityPtr->PressureAction();
}

/* Method that checks if the water level is high enough
to add soap or start heating */
bool SecurityManager::IsWaterLevelSafe()
{
	// Var for response
	bool response = false;
	// If the water level is high enough
	if (iwaterPtr->GetWaterLevel() >= ALMOSTEMPTY)
	{
		// Set the response to true
		response = true;
	}
	// Return the response
	return true;
}

/* Method that checks if all the compartments have been closed
and returns an answer. DISCLAIMER: the only compartment that 
can be checked is the door */
bool SecurityManager::IsEverythingClosed()
{
	// Check if the door switch is on and return its state
	return isecurityPtr->DoorAction();
}

/* Method that handles checking for pressure change */
int SecurityManager::SafeMode()
{
	// Var for the response
	int response = 1;
	// If pressure is on
	if (IsPressureOn())
	{
		// Set the response to 1
		response = 1;
	}
	// If not
	else
	{
		// Set the response to 0
		response = 0;
		// If it just dropped
		if (previousSafeModeResponse != response)
		{
			// Save the time
			SaveTime();
		}
		// Check for how long the pressure is down in secconds
		unsigned long timePassed = ((millis() - prevMillis)/1000);
		// If the time passed is more than a set threshold
		if (timePassed > timeIntervalSafeMode * 60)
		{
			Serial.print(timeIntervalSafeMode);
			Serial.println(" minutes have passed and still no pressure!");
			// Set the response to -1
			response = -1;
		}
	}
	// Save the response for next execution of this method
	previousSafeModeResponse = response;
	// Return the response
	return response;
}

// Method that handles locking the door
void SecurityManager::LockDoor()
{
	// If the lock hasnt been set on
	if (!isecurityPtr->Lock())
	{
		// Set it on
		isecurityPtr->SetLock(true);
	}
}

// Method that handles unlocking the door
void SecurityManager::UnlockDoor()
{
	// If the door hasnt been unlocked
	if (isecurityPtr->Lock())
	{
		// Unlock it
		isecurityPtr->SetLock(false);
	}
}

/* Method that saves the current time for further checking */
void SecurityManager::SaveTime()
{
	prevMillis = millis();
}