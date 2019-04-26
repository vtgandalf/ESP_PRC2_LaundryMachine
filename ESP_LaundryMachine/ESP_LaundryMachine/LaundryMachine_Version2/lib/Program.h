#ifndef PROGRAM_H
#define PROGRAM_H

#include "HardwareControl.h"
#include "WaterManager.h"
#include "HeaterHandler.h"
#include "SecurityManager.h"
#include "SoapHandler.h"
#include "CoinHandler.h"

using namespace sharedNamespace;

struct WashingProgram
{
    Temp preWashTemp;
    WaterLevel mainWashWaterLevel;
    Temp mainWashTemp;
    int mainWashRotations;
    int centrifugeRotations;
};

class Program
{
public:
    /* A method that handles the stage
    prior to any washing program. It includes
    waiting for coins, soap, doorlock,
    program selection and etc. It is meant
    to pass on the washing program that the 
    void ExecProgram(WashingProgram) should use */
    WashingProgram PreProgram();
    /* This method handles all the stages of 
    a woshing program accordingly to the program
    that has been passed on from the PreProgram() */
    void ExecProgram(WashingProgram);

private:
    /* Method that handles the prewash stage
    input: sharedNamespace::Temp, defines what
        should the heating during that stage be */
    void PreWash(Temp);
    /* Method that handles the main wash stage
    input: 
        - sharedNamespace::WaterLevel, defines how
        full the tank should be before the soap is added
        - sharedNamespace::Temp, defines the level of 
        heating 
        - int, defines how many times the tank should
        repeat a cicle of rotating clockwise and 
        anticlockwise */
    void MainWash(WaterLevel, Temp, int);
    /* Method that handles the centrifuge stage */
    void Centrifuge(int);
    /* Vars which store the wahsing programs 
    input: int, defines how many times the tank should
        repeat a cicle of rotating clockwise and 
        anticlockwise */
    WashingProgram progA = {COLD, ALMOSTFULL, WARMER, 1, 1};
    WashingProgram progB = {WARMER, ALMOSTFULL, WARMER, 1, 1};
    WashingProgram progC = {WARMER, FULL, HOT, 3, 2};
    /* Vars for the managers/handlers and the library */
    HardwareControl _hardwareControl;
    SecurityManager _securityManager;
    SoapHandler _soapHandler;
    CoinHandler _coinHandler;
    HeaterHandler _heaterHandler;
    WaterManager _waterManager;
};

#endif