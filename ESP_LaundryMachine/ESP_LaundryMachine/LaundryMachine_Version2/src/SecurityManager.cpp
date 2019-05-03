#include "../lib/SecurityManager.h"

bool SecurityManager::IsPressureOn()
{
	bool response = false;
	byte temp = ioPtr->GetRawInputByte();
	if (((temp | bitMaskPressure) == temp) && ((temp | bitMaskKeyselect) != temp))
	{
		response = true;
	}
	return response;
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

bool SecurityManager::SafeMode(int program)
{
	// to be implemented
	prevMillis = millis();
	bool trig = false;
	Serial.print("Going in SafeMode(), waiting... ");
	while (!trig)
	{
		if(IsPressureOn())
		{
			Serial.println(" Pressure came back!");
			return true;
		}
		if (((millis() - prevMillis) / (60 * 1000)) > timeIntervalSafeMode)
		{
			Serial.println("Ten monutes have passed and still no pressure!")
			trig = true;
		}
		else
		{
			ioPtr->SetProgramLed(0);
			delay(1000);
			ioPtr->SetProgramLed(program + 1);
			delay(1000);
		}
	}
	return false;
}

// method that handles the polling
// contains everything that has to be checked regularly
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
	bool actionHasBeenTaken = false;
	byte temp = ioPtr->GetGlobalInputByte();
	if (((temp | bitMaskDoorlock) == temp) & ((temp | bitMaskKeyselect) != temp))
	{
		actionHasBeenTaken = true;
		Serial.println("lock the door");
		if (!doorHasBeenLocked)
		{
			isecurityPtr->SetLock(true);
			doorHasBeenLocked = true;
		}
	}

	if (actionHasBeenTaken)
		ioPtr->SetGlobalInputByte(0x00);
}

void SecurityManager::LockDoor()
{
	if (!isecurityPtr->Lock())
	{
		isecurityPtr->SetLock(true);
	}
}