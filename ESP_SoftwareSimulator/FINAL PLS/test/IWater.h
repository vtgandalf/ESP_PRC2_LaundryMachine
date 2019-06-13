#ifndef IWATER_H
#define IWATER_H

#include "SharedNamespace.h"
using namespace sharedNamespace;

class IWater
{
public:
    /* GETTERS */
    /* Method that reads the waters
		level of the tank */
	virtual WaterLevel GetWaterLevel() = 0;
	/* Function to set the Drain
		input: 
			- true - turns it on
			- false - turns it off */
	virtual void SetDrain(bool) = 0;
	/* Function to set the Sink
		input: 
			- true - turns it on
			- false - turns it off */
	virtual void SetSink(bool) = 0;

    /* Fields */
	virtual bool Drain() = 0;			   // Returns the drain state
	virtual bool Sink() = 0;			   // Returns the sink state
};

#endif