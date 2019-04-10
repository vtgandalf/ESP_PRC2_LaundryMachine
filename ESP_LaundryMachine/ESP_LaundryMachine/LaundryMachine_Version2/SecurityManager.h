#ifndef SECURITYMANAGER_H
#define SECURITYMANAGER_H

#include "HardwareControl.h"
#include "InputManager.h"

class SecurityManager
{
	public:
		bool IsPressureOn();
		bool IsWaterLevelSafe();
		bool IsEverythingClosed();
		void SafeMode();
		void Polling();
		

	private:
		bool doorHasBeenLocked = false;
		IO* ioPtr = (IO*)HardwareControl::GetInstance();
        InputManager* ioManager = (InputManager*)InputManager::GetInstance();
		ISecurity* isecurityPtr = (ISecurity*)HardwareControl::GetInstance();
		sharedNamespace::Function function;
		void DoorClosed();
};

#endif