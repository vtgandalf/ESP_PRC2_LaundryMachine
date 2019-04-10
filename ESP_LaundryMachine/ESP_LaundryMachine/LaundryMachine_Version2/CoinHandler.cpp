#include "CoinHandler.h"

void CoinHandler::IndicateMissingCoins()
{
    //to be implemented iteration 2
}

void CoinHandler::Change()
{
    //to be implemented
}

bool CoinHandler::AreCoinsEnough()
{
    //to be implemented iteration 2
    return true;
}

void CoinHandler::NewCoin()
{
    /*ioPtr->SetKeyselect(true);
    function = ioPtr->GetButtonsFunction();
    if(function!= NOTHING) 
    {
        Serial.print("CoinHandler::GetButtonsFunctionDebounced::");
        Serial.println(function);
    }
    if(function == COIN10)
    {
        if(coin10 <3) 
        {
            coin10++;
            coin10LedHasBeenSet = false;
            Serial.println("coin10++");
        }
    }
    else if (function == COIN50) 
    {
        if(coin50 <3) 
        {
            coin50++;
            coin50LedHasBeenSet = false;
            Serial.println("coin50++");
        }
    }
    else if (function == COIN200) 
    {
        if(coin200 <2) 
        {
            coin200++;
            coin200LedHasBeenSet = false;
            Serial.println("coin200++");
        }
    }*/
}

void CoinHandler::SetLed()
{
    /*if(!coin10LedHasBeenSet)
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
    }*/
}

void CoinHandler::Polling()
{
    //to be implemented
    // for now it is only lights the leds nwhen a button is pressed
    NewCoin();
    SetLed(); 
}