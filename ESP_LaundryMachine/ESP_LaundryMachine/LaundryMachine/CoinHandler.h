#ifndef COINHANDLER_H
#define COINHANDLER_H

#include "ICoin.h"

class CoinHandler
{
    public:
        void IndicateMissingCoins();
        void Change();
        bool AreCoinsEnough();
        void NewCoin();
        void Polling();

    private:
        sharedNmaespace::Function newCoin();
        int coin10 = 0;
        int coin50 = 0;
        int coin200 = 0;
        void SetLed(int coinNominal);
};

#endif