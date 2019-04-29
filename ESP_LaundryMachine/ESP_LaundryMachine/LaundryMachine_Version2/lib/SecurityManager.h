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
		to be taken upon pressure outage */
	void SafeMode();
	/* Method that handles all the essential
        proccesses for this object that have to 
        be ran during the main loop of the arduino
        program */
	void Polling();

private:
	/* Boolean that indicated wheter or not the door has
        been locked after the last command. This is
        neccessary since without it we do keep locking the 
		door that is already locked, which only
        wastes cpu cycles.*/
	bool doorHasBeenLocked = false;
	// accessing the library through the interfaces
	IO *ioPtr = (IO *)HardwareControl::GetInstance();
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