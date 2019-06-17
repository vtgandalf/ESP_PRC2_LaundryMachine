#ifndef COINHANDLER_H
#define COINHANDLER_H

#include "HardwareControl.h"
using namespace sharedNamespace;

class CoinHandler
{
public:
    // Method that handles the change
    void Change();

    /* Method that shows wether or not the coins are
        enoug
        input:
            - the required amount
        output: 
            - true - coins are enough
            - false - coins are not enough */
    bool AreCoinsEnough(int);

    /* Method that handles all the essential
        proccesses for this object that have to 
        be ran during the main loop of the arduino
        program */
    void Polling();

	void setHwc(HardwareControl *hwcont);


private:
    // IN DEV
    void Clear();
    // END

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
    //IO *ioPtr = (IO *)HardwareControl::GetInstance();
    ICoin *icoinPtr = (ICoin *)HardwareControl::GetInstance();
	HardwareControl *hwc;
    // Method for incrementing the coin counters
    void NewCoin();
    // Coin counters
    int coin10 = 0;
    int coin50 = 0;
    int coin200 = 0;
    /* This method sets the leds according
        to the local coin variables */
    void SetLed();
    /* Method that controlls the coin leds
        showing that some amount of them is missing */
    void IndicateMissingCoins(int);
};

#endif