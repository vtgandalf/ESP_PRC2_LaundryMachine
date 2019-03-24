#ifndef SECURITYMANAGER_H
#define SECURITYMANAGER_H

#include "HardwareControl.h"

class SecurityManager
{
	public:
		bool IsPressureOn();
		bool IsWaterLevelSafe();
		bool IsEverythingClosed();
		void SafeMode();
		void Polling();
		

	private:
		//sharedNamespace::ioPtr = new HardwareControl();
		//sharedNamespace::isecurityPtr = new HardwareControl();
		sharedNamespace::Function function;
		void DoorClosed();
};

#endif