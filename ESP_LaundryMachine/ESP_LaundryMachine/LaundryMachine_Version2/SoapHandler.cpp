#include "SoapHandler.h"

void SoapHandler::IndicateMissingSoap()
{
    //to be implemented iteration 2
}


void SoapHandler::SetLed()
{
    //Serial.println("SoapHandler::SetLed");
    //to be implemented
    if(soap1 == 2) 
    {
        if(!soap1LedHasBeenSetUp)
        {
            isoapPtr->SetSoap1Led(true);
            soap1LedHasBeenSetUp = true;
            Serial.println("SetSoap2Led");
        }
    }
    if(soap2 == 3) 
    {
        if(!soap2LedHasBeenSetUp)
        {
            isoapPtr->SetSoap2Led(true);
            soap2LedHasBeenSetUp = true;
            Serial.println("SetSoap1Led");
        }
    }
}

void SoapHandler::InsertSoap()
{
    //Serial.println("SoapHandler::InsertSoap");
    /*ioPtr->SetKeyselect(false);
    function = ioPtr->GetButtonsFunction();
    if(functionGlobal!=NOTHING) 
    {
        Serial.print("SoapHandler::GetButtonsFunctionDebounced::");
	    Serial.println(function);
    }*/
    function = ioPtr->GetGlobalFunction();

    if(function == SOAP1)
    {
        if(soap1 <2)
        {
            //Serial.println("soap1++");
            //Serial.print("soap1: ");
            //Serial.println(soap1);
            soap1++;
            soap1LedHasBeenSetUp = false;
            ioPtr->SetGlobalFunction(NOTHING);
            Serial.print("soap1: ");
            Serial.println(soap1);
        }
    }
    else if (function == SOAP2) 
    {
        if(soap2 <3)
        {
            //Serial.println("soap2++");
            //Serial.print("soap2: ");
            //Serial.println(soap2);
            soap2++;
            soap2LedHasBeenSetUp = false;            
            ioPtr->SetGlobalFunction(NOTHING);
            Serial.print("soap2: ");
            Serial.println(soap2);
        }
    }
}

void SoapHandler::InsertSoapByte()
{
    //Serial.println("SoapHandler::InsertSoap");
    /*ioPtr->SetKeyselect(false);
    function = ioPtr->GetButtonsFunction();
    if(functionGlobal!=NOTHING) 
    {
        Serial.print("SoapHandler::GetButtonsFunctionDebounced::");
	    Serial.println(function);
    }*/
    bool actionHasBeenTaken = false;
    byte temp = ioPtr->GetGlobalInputByte();

    if((temp | bitMaskSoap1) == temp)
    {
        actionHasBeenTaken = true;
        if(soap1 <2)
        {
            //Serial.println("soap1++");
            //Serial.print("soap1: ");
            //Serial.println(soap1);
            soap1++;
            soap1LedHasBeenSetUp = false;
            Serial.print("soap1: ");
            Serial.println(soap1);
        }
    }
    else if ((temp | bitMaskSoap2) == temp) 
    {
        actionHasBeenTaken = true;
        if(soap2 <3)
        {
            //Serial.println("soap2++");
            //Serial.print("soap2: ");
            //Serial.println(soap2);
            soap2++;
            soap2LedHasBeenSetUp = false;            
            Serial.print("soap2: ");
            Serial.println(soap2);
        }
    }
    if (actionHasBeenTaken)
    {
        ioPtr->SetGlobalInputByte(0x00);
    }
}

void SoapHandler::Polling()
{
    //Serial.println("SoapHandler");
    //to be implemented
    //InsertSoap();
    InsertSoapByte();
    SetLed();
}