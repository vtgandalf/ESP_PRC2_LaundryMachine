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
	/* Method that handles all the essential
        proccesses for this object that have to 
        be ran during the main loop of the arduino
        program 
		output:
			- 1 - pressure is on
			- 0 - pressure is off and is save mode
			- -1 - time interal has passed and the
					that is running should force
					exit! */
	void Polling();
	/* This is a method that locks the door */
	void LockDoor();
	/* This is a method that saves the time
	at which the pressure dropped and the save
	mode was activated */
	void SaveTime();

private:
	/* Variable containing the time which the
	safe mode should wait the pressure to come back.
	Please, note that it is in minutes */
	long timeIntervalSafeMode = 10;
	/* Var which is a holder for the last millis value
	from the cpu at which the pressure dropped. It is
	used to calculate the time passed since the beginning
	of the SafeMode() */
	long prevMillis;
	/* Boolean that indicated wheter or not the door has
        been locked after the last command. This is
        neccessary since without it we do keep locking the 
		door that is already locked, which only
        wastes cpu cycles.*/
	bool doorHasBeenLocked = false;
	// accessing the library through the interfaces
	IProgram *iprogramPtr = (IProgram *)HardwareControl::GetInstance();
	//IO *ioPtr = (IO *)HardwareControl::GetInstance();
	ISecurity *isecurityPtr = (ISecurity *)HardwareControl::GetInstance();
	IWater *iwaterPtr = (IWater *)HardwareControl::GetInstance();
	/* Checks if the door has been closed
		disclamer: for now it just locks it */
	void DoorClosed();
	/* This method indicates which compartments
		are not yet closed through the corresponding
		leds */
	void IndicateCompartments();
};

#endif