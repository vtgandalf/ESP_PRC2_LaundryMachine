#include "SoapHandler.h"

#define soap1max 2
#define soap2max 3

void SoapHandler::IndicateMissingSoap(int soap1Required, int soap2Required)
{
    for (int i = 0; i < (soap1Required - soap1); i++)
    {
        isoapPtr->SetSoap1Led(true);
        //delay(250);
        isoapPtr->SetSoap1Led(false);
        //delay(250);
    }
    for (int i = 0; i < (soap2Required - soap2); i++)
    {
        isoapPtr->SetSoap2Led(true);
        //delay(250);
        isoapPtr->SetSoap2Led(false);
        //delay(250);
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
    ////////serial.println("SoapHandler::SetLed");
    //to be implemented
    if (soap1 == soap1max)
    {
        if (!soap1LedHasBeenSetUp)
        {
            isoapPtr->SetSoap1Led(true);
            soap1LedHasBeenSetUp = true;
            ////////serial.println("SetSoap1Led has been set.");
        }
    }
    if (soap2 == soap2max)
    {
        if (!soap2LedHasBeenSetUp)
        {
            isoapPtr->SetSoap2Led(true);
            soap2LedHasBeenSetUp = true;
            ////////serial.println("SetSoap2Led has been set.");
        }
    }
}

void SoapHandler::InsertSoap()
{
    if ((soap1 < soap1max) && isoapPtr->Soap1Action())
    {
        soap1++;
        soap1LedHasBeenSetUp = false;
        ////////serial.print("Soap1 has been added.");
        ////////serial.println(soap1);
    }
    if ((soap2 < soap2max) && isoapPtr->Soap2Action())
    {
        soap2++;
        soap2LedHasBeenSetUp = false;
        ////////serial.print("Soap2 has been added.");
        ////////serial.println(soap2);
    }
}

void SoapHandler::Polling()
{
    ////////serial.println("SoapHandler");
    //to be implemented
    InsertSoap();
    SetLed();
}

bool SoapHandler::UseSoap1(int x)
{
    if (soap1 - x >= 0)
    {
        ////////serial.println("Soap 1 added!");
        soap1 -= x;
        isoapPtr->SetSoap1Led(false);
        return true;
    }
    else
    {
        return false;
    }
}

bool SoapHandler::UseSoap2(int x)
{
    ////////serial.println("Soap 2 added!");
    if (soap2 - x >= 0)
    {
        soap2 -= x;
        isoapPtr->SetSoap2Led(false);
        return true;
    }
    else
    {
        return false;
    }
}