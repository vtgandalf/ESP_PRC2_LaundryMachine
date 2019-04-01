#ifndef SOAPHANDLER_H
#define SOAPHANDLER_H

#include "HardwareControl.h"

class SoapHandler
{
    public:
        void Polling();
        
    private:
        //ISoap* iptr = (ISoap*)HardwareControl::GetInstance();
        sharedNamespace::Function function;
        int soap1 = 0;
        int soap2 = 0;
        void SetLed();
        void IndicateMissingSoap();
        void InsertSoap();
};

#endif