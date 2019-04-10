#ifndef COINHANDLER_H
#define COINHANDLER_H

#include "HardwareControl.h"
#include "InputManager.h"

class CoinHandler
{
    public:
        void IndicateMissingCoins();
        void Change();
        bool AreCoinsEnough();
        void Polling();

    private:
        bool coin10LedHasBeenSet = true;
        bool coin50LedHasBeenSet = true;
        bool coin200LedHasBeenSet = true;
        IO* ioPtr = (IO*)HardwareControl::GetInstance();
        InputManager* ioManager = (InputManager*)InputManager::GetInstance();
        ICoin* icoinPtr = (ICoin*)HardwareControl::GetInstance();
        sharedNamespace::Function function;
        void NewCoin();
        int coin10 = 0;
        int coin50 = 0;
        int coin200 = 0;
        void SetLed();
};

#endif