#ifndef SOAPHANDLER_H
#define SOAPHANDLER_H

#include "HardwareControl.h"
#include "InputManager.h"

class SoapHandler
{
    public:
        void Polling();
        
    private:
        bool soap1LedHasBeenSetUp = true;
        bool soap2LedHasBeenSetUp = true;
        IO* ioPtr = (IO*)HardwareControl::GetInstance();
        InputManager* ioManager = (InputManager*)InputManager::GetInstance();
        ISoap* isoapPtr = (ISoap*)HardwareControl::GetInstance();
        sharedNamespace::Function function;
        int soap1 = 0;
        int soap2 = 0;
        void SetLed();
        void IndicateMissingSoap();
        void InsertSoap();
};

#endif