#ifndef PROGRAM_H
#define PROGRAM_H

#include "HardwareControl.h"

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
    /* Method that handles the prewash stage */
    void PreWash(int);
    /* Method that handles the main wash stage */
    void MainWash(WaterLevel, Temp, int);
    /* Method that handles the centrifuge stage */
    void Centrifuge(int);
    /* Vars which store the wahsing programs */
    WashingProgram progA;
    WashingProgram progB;
    WashingProgram progC;
};

#endif