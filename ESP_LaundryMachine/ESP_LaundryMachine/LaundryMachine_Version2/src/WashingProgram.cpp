#include "../lib/WashingProgram.h"

WashingProgram::WashingProgram(Temp _preWashTemp, WaterLevel _mainWashWaterLevel, Temp _mainWashTemp, int _mainWashRotations, int _centrifugeRotations, int _price)
{
    preWashTemp = _preWashTemp;
    mainWashWaterLevel = _mainWashWaterLevel;
    mainWashTemp = _mainWashTemp;
    mainWashRotations = _mainWashRotations;
    centrifugeRotations = _centrifugeRotations;
    price = _price;
}

Temp WashingProgram::PreWashTemp()
{
    return preWashTemp;
}

WaterLevel WashingProgram::MainWashWaterLevel()
{
    return mainWashWaterLevel;
}

Temp WashingProgram::MainWashTemp()
{
    return mainWashTemp;
}

int WashingProgram::MainWashRotations()
{
    return mainWashRotations;
}

int WashingProgram::CentrifugeRotations()
{
    return centrifugeRotations;
}

int WashingProgram::Price()
{
    return price;
}