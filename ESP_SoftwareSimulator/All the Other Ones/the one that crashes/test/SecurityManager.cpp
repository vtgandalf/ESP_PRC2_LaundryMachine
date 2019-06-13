#include "SecurityManager.h"

bool SecurityManager::IsPressureOn()
{
	return isecurityPtr->PressureAction();
	//return true;
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
	bool response = false;
	if (iwaterPtr->GetWaterLevel() >= ALMOSTEMPTY)
	{
		response = true;
	}
	return true;
}

bool SecurityManager::IsEverythingClosed()
{
	/*bool returnVal;
	returnVal = doorHasBeenLocked;
	if (!returnVal)
	{
		IndicateCompartments();
	}
	return returnVal;*/
	return isecurityPtr->DoorAction();
}

int SecurityManager::SafeMode()
{
	// to be implemented
	int response = 1;
	//bool trig = false;
	////////serial.print("Going in SafeMode(), waiting... ");
	if (IsPressureOn())
	{
		////////serial.println(" Pressure came back!");
		response = 1;
	}
	else
	{
		response = 0;
		if (previousSafeModeResponse != response)
		{
			SaveTime();
		}
		//unsigned long timePassed = ((millis() - prevMillis)/1000);
		/*if (timePassed > timeIntervalSafeMode * 60)
		{
			////////serial.print(timeIntervalSafeMode);
			////////serial.println(" minutes have passed and still no pressure!");
			response = -1;
		}*/
	}
	previousSafeModeResponse = response;
	return response;
}

// method that handles the polling
// contains everything that has to be checked regularly 60
void SecurityManager::Polling()
{
	////////serial.println(isecurityPtr->Lock());
	// to be implemented
	DoorClosed();
	if (!IsPressureOn())
	{
		//SafeMode();
	}
}

void SecurityManager::DoorClosed()
{
	if (isecurityPtr->DoorAction())
	{
		////////serial.println("lock the door");
		/*if (!doorHasBeenLocked)
		{
			isecurityPtr->SetLock(true);
			doorHasBeenLocked = true;
		}*/
	}
}

void SecurityManager::LockDoor()
{
	if (!isecurityPtr->Lock())
	{
		isecurityPtr->SetLock(true);
	}
}

void SecurityManager::UnlockDoor()
{
	if (isecurityPtr->Lock())
	{
		isecurityPtr->SetLock(false);
	}
}

void SecurityManager::SaveTime()
{
	//prevMillis = millis();
}