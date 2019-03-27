#ifndef SOAPHANDLER_H
#define SOAPHANDLER_H

#include "ISoap.h"

class SoapHandler
{
    public:
        bool IsSoapEnough(int soapNr);
        void Polling();
        
    private:
        sharedNamespace::Function function;
        int soap1 = 0;
        int soap2 = 0;
        void SetLed();
        void IndicateMissingSoap();
        int InsertSoap(int soapNr);
};

#endif