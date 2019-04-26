#include "../lib/SoapHandler.h"

void SoapHandler::IndicateMissingSoap(int soap1Required, int soap2Required)
{
    for (int i = 0; i < (soap1Required - soap1); i++)
    {
        isoapPtr->SetSoap1Led(true);
        delay(250);
        isoapPtr->SetSoap1Led(false);
        delay(250);
    }
    for (int i = 0; i < (soap2Required - soap2); i++)
    {
        isoapPtr->SetSoap2Led(true);
        delay(250);
        isoapPtr->SetSoap2Led(false);
        delay(250);
    }
}

bool SoapHandler::IsSoapEnough(int soap1Required, int soap2Required)
{
    bool returnVal;
    if ((soap1 < soap1Required) | (soap2 < soap2Required))
    {
        returnVal = false;
        IndicateMissingSoap(soap1Required, soap2Required);
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
    if (soap1 == 2)
    {
        if (!soap1LedHasBeenSetUp)
        {
            isoapPtr->SetSoap1Led(true);
            soap1LedHasBeenSetUp = true;
            Serial.println("SetSoap1Led");
        }
    }
    if (soap2 == 3)
    {
        if (!soap2LedHasBeenSetUp)
        {
            isoapPtr->SetSoap2Led(true);
            soap2LedHasBeenSetUp = true;
            Serial.println("SetSoap2Led");
        }
    }
}

void SoapHandler::InsertSoap()
{
    bool actionHasBeenTaken = false;
    byte temp = ioPtr->GetGlobalInputByte();
    /*if (temp != 0x00)
    {
        Serial.println(lastByte, BIN);
        Serial.println(temp, BIN);
        Serial.println(" ");
    }*/
    if (((temp | bitMaskSoap1) == temp) & ((temp | bitMaskKeyselect) != temp))
    {

        actionHasBeenTaken = true;
        if (soap1 < 2)
        {
            //Serial.println("soap1++");
            //Serial.print("soap1: ");
            //Serial.println(soap1);
            soap1++;
            soap1LedHasBeenSetUp = false;
            Serial.print("soap1: ");
            Serial.println(soap1);
            lastByte = 0x00;
        }
    }
    else if (((temp | bitMaskSoap2) == temp) & ((temp | bitMaskKeyselect) != temp))
    {
        actionHasBeenTaken = true;
        if (soap2 < 3)
        {
            //Serial.println("soap2++");
            //Serial.print("soap2: ");
            //Serial.println(soap2);
            soap2++;
            soap2LedHasBeenSetUp = false;
            Serial.print("soap2: ");
            Serial.println(soap2);
            lastByte = 0x00;
        }
    }

    if (actionHasBeenTaken)
    {
        lastByte = temp;
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