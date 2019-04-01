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
		IO* ioPtr = (IO*)HardwareControl::GetInstance();
		ISecurity* isecurityPtr = (ISecurity*)HardwareControl::GetInstance();
		sharedNamespace::Function function;
		void DoorClosed();
};

#endif