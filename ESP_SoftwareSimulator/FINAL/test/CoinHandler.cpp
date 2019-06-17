#include "CoinHandler.h"
#include <windows.h>

// Macros for the max values we can input as coins
#define coin10and50maxValue 3
#define coin200maxValue 2

/* Method that indicates which and how many coins are missing 
through the approprate leds */
void CoinHandler::IndicateMissingCoins(int value)
{
    int temp = value;
    int coin10counter;
    int coin50counter;
    int coin200counter;
    // Check how we can devide the value between the types of coins
    coin200counter = temp / 200;
    temp = temp - coin200counter * 200;
    coin50counter = temp / 50;
    temp = temp - coin50counter * 50;
    coin10counter = temp / 10;
    temp = temp - coin10counter * 10;
    // Blink the leds to show how many more coins to add
    for (int i = 0; i < 3; i++)
    {
        icoinPtr->SetCoin10Led(coin10counter);
        icoinPtr->SetCoin50Led(coin50counter);
        icoinPtr->SetCoin200Led(coin200counter);
		Sleep(250);
		icoinPtr->SetCoin10Led(0);
        icoinPtr->SetCoin50Led(0);
        icoinPtr->SetCoin200Led(0);
		Sleep(250);
	}
    // Update the leds
    coin10LedHasBeenSet = false;
    coin50LedHasBeenSet = false;
    coin200LedHasBeenSet = false;
    SetLed();
}

void CoinHandler::Change()
{
    //to be implemented
}

// Method that checks if we have enough coins to start the program
bool CoinHandler::AreCoinsEnough(int value)
{
    // Var for the response
    bool returnVal;
    // Calculate whats the value of the coins we have
    int temp = coin10 * 10 + coin50 * 50 + coin200 * 200;
    // If we dont have enough
    if ((temp - value) < 0)
    {
        // Set the response to false
        returnVal = false;
        // Indicate how many coins are missing
        IndicateMissingCoins(value);
    }
    // If we have enough coins
    else
    {
        // Set the response to true
        returnVal = true;
    }
    // return the response
    return returnVal;
}

// Method that handles adding a new coin on button press
void CoinHandler::NewCoin()
{
    /* If the we can add more coins to the slot and there is a button press */
    if ((coin10 < coin10and50maxValue) && icoinPtr->Coin10Action())
    {
        // Increment the counter for the coin
        coin10++;
        // Indicate the leds have to update
        coin10LedHasBeenSet = false;
        //Serial.println("Coin10 has been added.");
    }
    /* If the we can add more coins to the slot and there is a button press */
    if ((coin50 < coin10and50maxValue) && icoinPtr->Coin50Action())
    {
        // Increment the counter for the coin
        coin50++;
        // Indicate the leds have to update
        coin50LedHasBeenSet = false;
        //Serial.println("Coin50 has been added.");
    }
    /* If the we can add more coins to the slot and there is a button press */
    if ((coin200 < coin200maxValue) && icoinPtr->Coin200Action())
    {
        // Increment the counter for the coin
        coin200++;
        // Indicate the leds have to update
        coin200LedHasBeenSet = false;
        //Serial.println("Coin200 has been added.");
    }
}

// Handle the clear button press
void CoinHandler::Clear()
{
    // If the button was pressed
    if (icoinPtr->ClearAction())
    {
        //Serial.println("Clear has been pressed.");
        // Clear the coins
        ClearCoins();
    }
}

// Method that handles updating the leds
void CoinHandler::SetLed()
{
    // If the leds need to be updated
    if (!coin10LedHasBeenSet)
    {
        // Update the led
        icoinPtr->SetCoin10Led(coin10);
        // Indicate it has been updated
        coin10LedHasBeenSet = true;
    }
    // If the leds need to be updated
    if (!coin50LedHasBeenSet)
    {
        // Update the led
        icoinPtr->SetCoin50Led(coin50);
        // Indicate it has been updated
        coin50LedHasBeenSet = true;
    }
    // If the leds need to be updated 
    if (!coin200LedHasBeenSet)
    {
        // Update the led
        icoinPtr->SetCoin200Led(coin200);
        // Indicate it has been updated
        coin200LedHasBeenSet = true;
    }
}

// Method that handles the polling
void CoinHandler::Polling()
{
    // Check for Clear button
    Clear();
    // Check for coin button
    NewCoin();
    // Update the leds
    SetLed();
}

// Method that handles clearing the coins
void CoinHandler::ClearCoins()
{
    // Indicate that the leds should update
    coin10LedHasBeenSet = false;
    coin50LedHasBeenSet = false;
    coin200LedHasBeenSet = false;
    // Reset the counters to 0
    coin10 = 0;
    coin50 = 0;
    coin200 = 0;
}

// Method that handles Using an x amount of money from the added coins
void CoinHandler::UseCoins(int value)
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
    coin10 -= coin10counter;
    coin50 -= coin50counter;
    coin200 -= coin200counter;
    coin10LedHasBeenSet = false;
    coin50LedHasBeenSet = false;
    coin200LedHasBeenSet = false;
    SetLed();
}