#ifndef ISECURITY_H
#define ISECURITY_H

#include "SharedNamespace.h"
using namespace sharedNamespace;

class ISecurity
{
	public:
		virtual WaterLevel GetWaterLevel()=0;
		virtual void SetHeater(bool)=0;
		virtual void SetLock(bool)=0;
		virtual bool Lock()=0;
};

#endif
