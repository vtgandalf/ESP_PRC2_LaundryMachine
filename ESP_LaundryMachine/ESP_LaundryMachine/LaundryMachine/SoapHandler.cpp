#include "SoapHandler.h"

bool SoapHandler::IsSoapEnough(int soapNr)
{
    //to be implemented
    if(soapNr == 1)
    {
        if(soap1 == 2)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
    else if(soapNr == 2)
    {
        if(soap2 == 3)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
}

void SoapHandler::IndicateMissingSoap()
{
    //to be implemented iteration 2
}


void SoapHandler::SetLed(int soapNr)
{
    //to be implemented
    if(soapNr == 1)
    {
        //to be implemented
    }
    else if(soapNr == 2)
    {
        //to be implemented
    }
}

void SoapHandler::InsertSoap()
{
    function = ioPtr->GetButtonsFunction();
    if(function == SOAP1)
    {
        if(soap1 <2)
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
    if(IsSoapEnough(1)) SetLed(1);
    if(IsSoapEnough(2)) SetLed(2);
}