#include "SoapHandler.h"

void SoapHandler::IndicateMissingSoap()
{
    //to be implemented iteration 2
}


void SoapHandler::SetLed()
{
    //to be implemented
    if(soap1 == 2) isoapPtr->SetSoap2Led(true);
    if(soap2 == 3) isoapPtr->SetSoap1Led(true);
}

void SoapHandler::InsertSoap()
{
    function = ioPtr->GetButtonsFunctionDebounced();
    if(function == SOAP1)
    {
        if(soap1 <1)
        {
            soap1++;
        }
    }
    else if (function == SOAP2) 
    {
        if(soap2 <2)
        {
            soap2++;
        }
    } 
}

void SoapHandler::Polling()
{
    //to be implemented
    InsertSoap();
    SetLed();
}