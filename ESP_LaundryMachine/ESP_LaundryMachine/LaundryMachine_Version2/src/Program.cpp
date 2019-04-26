#include "../lib/Program.h"

WashingProgram Program::PreProgram(){
    // to be implemented
    return progA;
}

void Program::ExecProgram(WashingProgram program){
    // to be implemented
    PreWash(program.preWashTemp);
    MainWash(program.mainWashWaterLevel, program.mainWashTemp, program.mainWashRotations);
    Centrifuge(program.centrifugeRotations);
}

void Program::PreWash(Temp temperature){
    // to be implemented

    // fill water at least 50%
    _waterManager.FillUpWater(ALMOSTFULL);
    // add soap1
    if(!_soapHandler.UseSoap1(2))
    {
        Serial.println("Error: soap 1 out of range");
    }
    // heatup until temp >= temperature
    _heaterHandler.HeatUp(temperature);
    // rotate clockwise, lowspeed, 60s

    // rotate anticlockwise, lowspeed, 60s

    // sink
    _waterManager.EmptyWaterTank();
}

void Program::MainWash(WaterLevel waterLevel, Temp temperature, int numberOfRotations){
    // to be implemented

    // fill water until >= waterLevel
    _waterManager.FillUpWater(waterLevel);
    // add soap2
    if(!_soapHandler.UseSoap2(3))
    {
        Serial.println("Error: soap 2 out of range");
    }
    // heatup until >= temperature
    _heaterHandler.HeatUp(temperature);
    // REPEAT the following *numberOfRotations
    // rotate clockwise, medspeed, 60s
    // rotate anticlockwise, medspeed, 60s

    // no heating
    _heaterHandler.StopHeating();
    // sink water until empty
    _waterManager.EmptyWaterTank();
    ///////////////////////////////////////////////

    // fill water until >= 50%
    _waterManager.FillUpWater(ALMOSTEMPTY);
    // no heating
    _heaterHandler.StopHeating();
    // REPEAT the following *numberOfRotations
    // rotate clockwise, medspeed, 60s
    // rotate anticlockwise, medspeed, 60s

    // sink water until empty
    _waterManager.EmptyWaterTank();
}

void Program::Centrifuge(int numberOfRotations){
    // to be implemented

    // sink
    _waterManager.EmptyWaterTank();
    // REPEAT the following *numberOfRotations
    // rotate clockwise, highspeed, 30s
    // rotate anticlockwise, highspeed, 30s
}