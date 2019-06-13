#ifndef ISECURITY_H
#define ISECURITY_H

//#include "SharedNamespace.h"

class ISecurity
{
public:
	/* Function to set the internal lock
		input: 
			- true - locked
			- false - unlocked */
	virtual void SetLock(bool) = 0;
	// Returns the lock state
	virtual bool Lock() = 0;
	/* Method that checks if the door switch has been 
    pressed
    output:
        - true - it has been pressed
        - false - it hasnt been pressed */
    virtual bool DoorAction() = 0;
	virtual bool PressureAction() = 0;
};

#endif
