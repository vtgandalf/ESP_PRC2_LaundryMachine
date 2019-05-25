#include "../lib/SecurityManager.h"

bool SecurityManager::IsPressureOn()
{
	//return isecurityPtr->PressureAction();
	return true;
}

void SecurityManager::IndicateCompartments()
{
	isecurityPtr->SetLock(true);
	delay(250);
	isecurityPtr->SetLock(false);
	delay(250);
	isecurityPtr->SetLock(true);
	delay(250);
	isecurityPtr->SetLock(false);
	delay(250);
	isecurityPtr->SetLock(true);
	delay(250);
	isecurityPtr->SetLock(false);
	delay(250);
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
	return true;
}

int SecurityManager::SafeMode()
{
	// to be implemented
	int response = 1;
	//bool trig = false;
	//Serial.print("Going in SafeMode(), waiting... ");
	if (IsPressureOn())
	{
		Serial.println(" Pressure came back!");
		response = 1;
	}
	else
	{
		response = 0;
		if (((millis() - prevMillis) / (60 * 1000)) > timeIntervalSafeMode)
		{
			Serial.println("Ten minutes have passed and still no pressure!");
			response = -1;
		}
	}
	return response;
}

// method that handles the polling
// contains everything that has to be checked regularly 60
void SecurityManager::Polling()
{
	//Serial.println(isecurityPtr->Lock());
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
		Serial.println("lock the door");
		if (!doorHasBeenLocked)
		{
			isecurityPtr->SetLock(true);
			doorHasBeenLocked = true;
		}
	}
}

void SecurityManager::LockDoor()
{
	if (!isecurityPtr->Lock())
	{
		isecurityPtr->SetLock(true);
	}
}

void SecurityManager::SaveTime()
{
	prevMillis = millis();
}