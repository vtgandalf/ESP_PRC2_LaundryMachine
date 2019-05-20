#include "../lib/CoinHandler.h"

#define coin10and50maxValue 3
#define coin200maxValue 2

void CoinHandler::IndicateMissingCoins(int value)
{
    int temp = value;
    int coin10counter;
    int coin50counter;
    int coin200counter;
    coin200counter = temp / 200;
    temp = temp - coin200counter * 200;
    coin50counter = temp / 50;
    temp = temp - coin50counter * 50;
    coin10counter = temp / 10;
    temp = temp - coin10counter * 10;
    for (int i = 0; i < 3; i++)
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
    coin10LedHasBeenSet = false;
    coin50LedHasBeenSet = false;
    coin200LedHasBeenSet = false;
    SetLed();
}

void CoinHandler::Change()
{
    //to be implemented
}

bool CoinHandler::AreCoinsEnough(int value)
{
    bool returnVal;
    int temp = coin10 * 10 + coin50 * 50 + coin200 * 200;
    if ((temp - value) < 0)
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
    if ((coin10 < coin10and50maxValue) && icoinPtr->Coin10Action())
    {
        coin10++;
        coin10LedHasBeenSet = false;
        Serial.println("Coin10 has been added.");
    }

    if ((coin50 < coin10and50maxValue) && icoinPtr->Coin50Action())
    {
        coin50++;
        coin50LedHasBeenSet = false;
        Serial.println("Coin50 has been added.");
    }

    if ((coin200 < coin200maxValue) && icoinPtr->Coin200Action())
    {
        coin200++;
        coin200LedHasBeenSet = false;
        Serial.println("Coin200 has been added.");
    }
}

void CoinHandler::Clear()
{
    if (icoinPtr->ClearAction())
    {
        Serial.println("Clear has been pressed.");
        ClearCoins();
    }
}

void CoinHandler::SetLed()
{
    if (!coin10LedHasBeenSet)
    {
        icoinPtr->SetCoin10Led(coin10);
        coin10LedHasBeenSet = true;
    }
    if (!coin50LedHasBeenSet)
    {
        icoinPtr->SetCoin50Led(coin50);
        coin50LedHasBeenSet = true;
    }
    if (!coin200LedHasBeenSet)
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

void CoinHandler::ClearCoins()
{
    coin10LedHasBeenSet = false;
    coin50LedHasBeenSet = false;
    coin200LedHasBeenSet = false;
    coin10 = 0;
    coin50 = 0;
    coin200 = 0;
}