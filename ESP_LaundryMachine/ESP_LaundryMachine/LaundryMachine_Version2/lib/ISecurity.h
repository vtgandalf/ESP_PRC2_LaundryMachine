#ifndef ISECURITY_H
#define ISECURITY_H

#include "SharedNamespace.h"

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
};

#endif
