#include "CoinHandler.h"

void CoinHandler::IndicateMissingCoins(int value)
{
    int temp = value;
    int coin10counter;
    int coin50counter;
    int coin200counter;
    coin200counter = temp/200;
    temp = temp - coin200counter*200;
    coin50counter = temp/50;
    temp = temp - coin50counter*50;
    coin10counter = temp/10;
    temp = temp - coin10counter*10;
    for(int i = 0; i < 3; i++)
    {
        icoinPtr->SetCoin10Led(coin10counter);
        icoinPtr->SetCoin50Led(coin50counter);
        icoinPtr->SetCoin200Led(coin200counter);
        delay(250);
        icoinPtr->SetCoin10Led(0);
        icoinPtr->SetCoin50Led(0);
        icoinPtr->SetCoin200Led(0);
        delay(300);
    }
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
        IndicateMissingCoins(value);
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
    if(((temp | bitMaskCoin10) == temp) && ((temp | bitMaskProgram) != temp))
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
        Serial.println("Clear");
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