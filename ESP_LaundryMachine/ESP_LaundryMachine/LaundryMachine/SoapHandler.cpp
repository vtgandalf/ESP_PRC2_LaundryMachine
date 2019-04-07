#include "SoapHandler.h"

void SoapHandler::IndicateMissingSoap()
{
    //to be implemented iteration 2
}


void SoapHandler::SetLed()
{
    //to be implemented
    /*Serial.print("s1: ");
    Serial.print(soap1);
    Serial.print(" s2: ");
    Serial.println(soap2);*/

    if(soap1 == 2) isoapPtr->SetSoap2Led(true);
    if(soap2 == 3) isoapPtr->SetSoap1Led(true);
}

void SoapHandler::InsertSoap()
{
    if(ioPtr->Keyselect())ioPtr->SetKeyselect(false);
    function = ioPtr->GetButtonsFunction();
    if(function == SOAP1)
    {
        if(soap1 <2)
        {
            Serial.println("soap1+");
            soap1++;
        }
        
    }
    else if (function == SOAP2) 
    {
        if(soap2 <3)
        {
            Serial.println("soap2+");
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