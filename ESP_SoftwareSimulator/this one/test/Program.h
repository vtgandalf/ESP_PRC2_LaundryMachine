#ifndef PROGRAM_H
#define PROGRAM_H

#include "HardwareControl.h"
#include "WaterManager.h"
#include "HeaterHandler.h"
#include "SecurityManager.h"
#include "SoapHandler.h"
#include "CoinHandler.h"
#include "MotorManager.h"
#include "InputManager.h"

using namespace sharedNamespace;

struct WashingProgram
{
    Temp preWashTemp;
    WaterLevel mainWashWaterLevel;
    Temp mainWashTemp;
    int mainWashRotations;
    int centrifugeRotations;
    int price;
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

	void setHwc(HardwareControl *hwcont);


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
    /* Method that handles reading the program button*/
    void ReadProgramButton();
    /* Method that handles reading the start button 
    output: 
        - true - if the button has been pressed
        - false - if it hasnt*/
    bool ReadStartButton();
    /* Method that sets the leds for the programs 
    input: {1,2,3} the number of the program */
    void SetLeds(int);
    /* Vars which store the wahsing programs 
    input: int, defines how many times the tank should
        repeat a cicle of rotating clockwise and 
        anticlockwise */
    WashingProgram programs[3] = {{COLD, ALMOSTFULL, WARMER, 1, 1, 360},{WARMER, ALMOSTFULL, WARMER, 1, 1, 480}, {WARMER, FULL, HOT, 3, 2, 510}};
    /* Vars for the managers/handlers and the library */
    HardwareControl _hardwareControl;
    SecurityManager _securityManager;
    SoapHandler _soapHandler;
    CoinHandler _coinHandler;
    HeaterHandler _heaterHandler;
    WaterManager _waterManager;
    MotorManager _motorManager;
    InputManager _inputManager;
    // access the library through the io interface
	HardwareControl *hwc;
    //IProgram *iprogramPtr = (IProgram *)HardwareControl::GetInstance();
    // var indicating the selected program
    int program = -1;
};

#endif