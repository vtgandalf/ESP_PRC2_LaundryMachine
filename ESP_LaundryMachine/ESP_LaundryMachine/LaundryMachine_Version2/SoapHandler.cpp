#include "SoapHandler.h"

void SoapHandler::IndicateMissingSoap()
{
    //to be implemented iteration 2
}

bool SoapHandler::IsSoapEnough(int soap1Required, int soap2Required)
{
    bool returnVal;
    if((soap1 < soap1Required)|(soap2 < soap2Required))
    {
        returnVal = false;
        IndicateMissingSoap();
    }
    else
    {
        returnVal = true;
    }
    return returnVal;
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
    bool actionHasBeenTaken = false;
    byte temp = ioPtr->GetGlobalInputByte();

    if(((temp | bitMaskSoap1) == temp)&((temp | bitMaskKeyselect) != temp))
    {
        Serial.println((temp | bitMaskSoap1), BIN);        
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
    else if (((temp | bitMaskSoap2) == temp)&((temp | bitMaskKeyselect) != temp)) 
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
    InsertSoap();
    SetLed();
}