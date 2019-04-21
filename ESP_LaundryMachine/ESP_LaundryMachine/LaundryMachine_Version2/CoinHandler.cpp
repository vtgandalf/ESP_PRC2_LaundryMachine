#include "CoinHandler.h"

void CoinHandler::IndicateMissingCoins()
{
    //to be implemented iteration 2
}

void CoinHandler::Change()
{
    //to be implemented
}

bool CoinHandler::AreCoinsEnough(int value)
{
    bool returnVal;
    int temp = coin10*10 + coin50*50 + coin200*200;
    if((temp-value)<0)
    {
        returnVal = false;
        IndicateMissingCoins();
    }
    else
    {
        returnVal = true;
    }
    
    //to be implemented iteration 2
    return returnVal;
}

void CoinHandler::NewCoin()
{
    bool actionHasBeenTaken = false;
    byte temp = ioPtr->GetGlobalInputByte();
    if((temp | bitMaskCoin10) == temp)
    {
        if(coin10 <3) 
        {
            coin10++;
            coin10LedHasBeenSet = false;
            actionHasBeenTaken = true;
            Serial.println("coin10++");
        }
    }
    else if ((temp | bitMaskCoin50) == temp) 
    {
        if(coin50 <3) 
        {
            coin50++;
            coin50LedHasBeenSet = false;
            actionHasBeenTaken = true;
            Serial.println("coin50++");
        }
    }
    else if ((temp | bitMaskCoin200) == temp) 
    {
        if(coin200 <2) 
        {
            coin200++;
            coin200LedHasBeenSet = false;
            actionHasBeenTaken = true;
            Serial.println("coin200++");
        }
    }
    if(actionHasBeenTaken)
    {
        ioPtr->SetGlobalInputByte(0x00);
    } 
}

void CoinHandler::Clear()
{
    bool actionHasBeenTaken = false;
    byte temp = ioPtr->GetGlobalInputByte();
    if((temp | bitMaskClear) == temp)
    {
        coin10LedHasBeenSet = false;
        coin50LedHasBeenSet = false;
        coin200LedHasBeenSet = false;
        coin10 = 0;
        coin50 = 0;
        coin200 = 0;
        actionHasBeenTaken = true;
    }
    if(actionHasBeenTaken)
    {
        ioPtr->SetGlobalInputByte(0x00);
    }
}

void CoinHandler::SetLed()
{
    if(!coin10LedHasBeenSet)
    {
        icoinPtr->SetCoin10Led(coin10);
        coin10LedHasBeenSet = true;
    }
    if(!coin50LedHasBeenSet)
    {
        icoinPtr->SetCoin50Led(coin50);
        coin50LedHasBeenSet = true;
    }
    if(!coin200LedHasBeenSet)
    {
        icoinPtr->SetCoin200Led(coin200);
        coin200LedHasBeenSet = true;
    }
}

void CoinHandler::Polling()
{
    //to be implemented
    // for now it is only lights the leds nwhen a button is pressed
    Clear();
    NewCoin();
    SetLed(); 
}