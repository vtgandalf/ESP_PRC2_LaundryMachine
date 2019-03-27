#ifndef COINHANDLER_H
#define COINHANDLER_H

#include "HardwareControl.h"

class CoinHandler
{
    public:
        void IndicateMissingCoins();
        void Change();
        bool AreCoinsEnough();
        void Polling();

    private:
        sharedNamespace::Function function;
        void NewCoin();
        int coin10 = 0;
        int coin50 = 0;
        int coin200 = 0;
        void SetLed();
};

#endif