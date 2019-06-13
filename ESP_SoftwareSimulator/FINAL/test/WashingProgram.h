#ifndef WASHINGPROGRAM_H
#define WASHINGPROGRAM_H

#include "SharedNamespace.h"
using namespace sharedNamespace;

class WashingProgram
{
public:
    WashingProgram(Temp _preWashTemp, WaterLevel _mainWashWaterLevel, Temp _mainWashTemp, int _mainWashRotations, int _centrifugeRotations, int _price);
	Temp PreWashTemp();
    WaterLevel MainWashWaterLevel();
    Temp MainWashTemp();
    int MainWashRotations();
    int CentrifugeRotations();
    int Price();

private:
    Temp preWashTemp;
    WaterLevel mainWashWaterLevel;
    Temp mainWashTemp;
    int mainWashRotations;
    int centrifugeRotations;
    int price;
};

#endif