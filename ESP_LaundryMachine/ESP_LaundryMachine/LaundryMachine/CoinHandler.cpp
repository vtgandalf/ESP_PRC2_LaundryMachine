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
    //to be implemented
    function = ioPtr->GetButtonsFunction();
    if(function == COIN10)
    {
        if(coin10 <3) coin10++;
    }
    else if (function == COIN50) 
    {
        if(coin50 <3) coin50++;

    }
    else if (function == COIN200) 
    {
        if(coin200 <3) coin200++;
    }
}

void CoinHandler::SetLed()
{
    icoinPtr->SetCoin10Led(coin10);
    icoinPtr->SetCoin200Led(coin50);
    icoinPtr->SetCoin200Led(coin200);
}

void CoinHandler::Polling()
{
    //to be implemented
    // for now it is only lights the leds nwhen a button is pressed
    NewCoin();
    SetLed(); 
}