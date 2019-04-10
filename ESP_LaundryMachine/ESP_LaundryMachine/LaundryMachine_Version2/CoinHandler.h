#ifndef COINHANDLER_H
#define COINHANDLER_H

#include "HardwareControl.h"

class CoinHandler
{
    public:
        /* Method that controlls the coin leds
        showing that some amount of them is missing */
        void IndicateMissingCoins();

        // Method that handles the change
        void Change();

        /* Method that shows wether or not the coins are
        enoug
        output: 
            - true - coins are enough
            - false - coins are not enough */
        bool AreCoinsEnough();

        /* Method that handles all the essential
        proccesses for this object that have to 
        be ran during the main loop of the arduino
        program */
        void Polling();

    private:
        /* Booleans that indicate wheter or not an led has
        been already lit up after the last command. Those
        are neccessary since without them we do keep turning
        on leds that have already been turned on, which only
        wastes cpu cycles.*/
        bool coin10LedHasBeenSet = true;
        bool coin50LedHasBeenSet = true;
        bool coin200LedHasBeenSet = true;
        /* Getting a pointer to the library through the interface
        allows us to only have access to the functions we need */
        IO* ioPtr = (IO*)HardwareControl::GetInstance();
        ICoin* icoinPtr = (ICoin*)HardwareControl::GetInstance();
        /* This is a function(enum from sharedNamespace) 
        container for storing the last function which has
        been reccorded of the buttons*/
        sharedNamespace::Function function;
        // Method for incrementing the coin counters
        void NewCoin();
        // Coin counters
        int coin10 = 0;
        int coin50 = 0;
        int coin200 = 0;
        /* This method sets the leds according
        to the local coin variables */
        void SetLed();
};

#endif