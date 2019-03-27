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

int CoinHandler::NewCoin()
{
    //to be implemented
    function = ioPtr->GetButtonsFunction();
    if(function == COIN10)
    {
        if(coin10 <3)
        {
            coin10++;
            return 10;
        }
    }
    else if (function == COIN50) 
    {
        if(coin50 <3)
        {
            coin50++;
            return 50;
        }
    }
    else if (function == COIN200) 
    {
        if(coin200 <3)
        {
            coin200++;
            return 200;
        }
    }
    return 0;
}

void CoinHandler::SetLed(int coinNominal)
{
    //to be implemented
    if(coinNomila == 10)
    {
        if(coin10 == 1)
        {
            //to be implemented
        }
        else if(coin10 == 2)
        {
            //to be implemented
        }
        else if(coin10 == 3)
        {
            //to be implemented
        }
    }
    else if(coinNominal == 50)
    {
        if(coin50 == 1)
        {
            //to be implemented
        }
        else if(coin50 == 2)
        {
            //to be implemented
        }
        else if(coin50 == 3)
        {
            //to be implemented
        }
    }
    else if(coinNominal == 200)
    {
        if(coin200 == 1)
        {
            //to be implemented
        }
        else if(coin200 == 2)
        {
            //to be implemented
        }
        else if(coin200 == 3)
        {
            //to be implemented
        }
    }
}

void CoinHandler::Polling()
{
    //to be implemented
    // for now it is only lights the leds nwhen a button is pressed
    SetLed( NewCoin()); 
}