#ifndef IHEATER_H
#define IHEATER_H

#include "SharedNamespace.h"
using namespace sharedNamespace;

class IHeater
{
public:
	/* Method that returns the Temperature 
		of the water in the laundry machine
		output: of type sharedNamespace::Temp */
	virtual Temp GetTemperature() = 0;
	/* Function to set the Heater
		input: 
			- true - turns it on
			- false - turns it off */
	virtual void SetHeater(bool) = 0;
	// Returns the heater state
	virtual bool Heater() = 0;
};

#endif