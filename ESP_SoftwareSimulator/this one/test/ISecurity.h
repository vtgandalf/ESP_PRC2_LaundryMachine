#ifndef ISECURITY_H
#define ISECURITY_H

#include "SharedNamespace.h"
using namespace sharedNamespace;

class ISecurity
{
public:
	/* Method that reads the water
		level of the tank */
	virtual WaterLevel GetWaterLevel(bool waterlvl1, bool waterlvl2, bool waterlvl3) = 0;
	/* Function to set the internal lock
		input: 
			- true - locked
			- false - unlocked */
	virtual void SetLock(bool) = 0;
	// Returns the lock state
	virtual bool Lock() = 0;
};

#endif
