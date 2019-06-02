#ifndef SECURITYMANAGER_H
#define SECURITYMANAGER_H

#include "HardwareControl.h"
using namespace sharedNamespace;

class SecurityManager
{
public:
	/* Method that checkes wheter or not
		the laundry machine is connected
		to the water system 
		output:
			- true - there is pressure
			- false - there is no pressure */
	bool IsPressureOn();
	/* Method that checks if the water level
		is big enough so the heater could turned on
		safely
		output:
			- true - the water level is enough
			- false - the water lavel is too low */
	bool IsWaterLevelSafe();
	/* Method that checks if all the
		compartments have been closed 
		output:
			- true - everything has been closed
			- false - there are some open compartments */
	bool IsEverythingClosed();
	/* Method that contains the set of actions 
		to be taken upon pressure outage
		input:
			- 0 - current program is the first one
			- 1 - current program is the second one
			- 2 - current program is the third one 
		output:
			- true - the pressure is back
			- false - there is no pressure 
						even after waiting*/
	int SafeMode();
	/* This is a method that locks the door */
	void LockDoor();
	/* This is a method that saves the time
	at which the pressure dropped and the save
	mode was activated */
	void SaveTime();
	// Method that unlocks the door
	void UnlockDoor();

private:
	/* Variable containing the time which the
	safe mode should wait the pressure to come back.
	Please, note that it is in minutes */
	unsigned long timeIntervalSafeMode = 1; // should be 10
	/* Var which is a holder for the last millis value
	from the cpu at which the pressure dropped. It is
	used to calculate the time passed since the beginning
	of the SafeMode() */
	unsigned long prevMillis;
	/* Boolean that indicated wheter or not the door has
        been locked after the last command. This is
        neccessary since without it we do keep locking the 
		door that is already locked, which only
        wastes cpu cycles.*/
	bool doorHasBeenLocked = false;
	// accessing the library through the interfaces
	ISecurity *isecurityPtr = (ISecurity *)HardwareControl::GetInstance();
	IWater *iwaterPtr = (IWater *)HardwareControl::GetInstance();
	// Ver to contain the previous response of SafeMode()
	int previousSafeModeResponse = 1;
};

#endif