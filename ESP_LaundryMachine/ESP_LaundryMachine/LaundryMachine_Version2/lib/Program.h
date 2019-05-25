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
#include "WashingProgram.h"

using namespace sharedNamespace;

/*struct WashingProgram
{
    Temp preWashTemp;
    WaterLevel mainWashWaterLevel;
    Temp mainWashTemp;
    int mainWashRotations;
    int centrifugeRotations;
    int price;
};*/

class Program
{
public:
    /* Method that handles the setup of the HardwareControl lib */
    void Setup();
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

    // NEW
    /* Method that is responsible for calling the objects
    that handle filling up the water tank 
    output:
        - true - tank has been filled
        - false - tank is not yet filled */
    bool FillUpWater(WaterLevel);
    /* Method that is responsible for calling the objects
    that handle adding soap1 */
    void AddSoap1();
    /* Method that is responsible for calling the objects
    that handle adding soap2 */
    void AddSoap2();
    /* Method that is responsible for calling the objects
    that handle heating up */
    bool HeatUp(Temp);
    /* Method that is responsible for calling the objects
    that handle stopping the heating */
    void StopHeating();
    /* Method that is responsible for calling the objects
    that handle rotating the tank */
    bool Rotate(Rotation, Speed, int);
    /* Method that is responsible for calling the objects
    that handle sinking the water
    output:
        - false - tank is not yet empty
        - true - tank is empty */
    bool Sink();
    /* Method that is responsible for calling the objects
    responsible for the input */
    void InputPolling();
    /* This method handles saving the current time, which
    needed for the motor manager */
    void SaveTimeMotorManager();
    /* This is a method that calls the SecurityManager
    to check the pressure and possibly fall into 
    save mode */
    int SecurityFallBack();
    /* This is a method that calls the security manager
    in order to save the current time for further checking */
    void SaveTimeSecurityManager();
    /* This is a method that handles blinking the program
    led in case in save mode */
    void BlinkProgramLed();

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
    WashingProgram programs[3] = {WashingProgram(COLD, ALMOSTFULL, WARMER, 1, 1, 360), WashingProgram(WARMER, ALMOSTFULL, WARMER, 1, 1, 480), WashingProgram(WARMER, FULL, HOT, 3, 2, 510)};
    //WashingProgram programs[3] = {{COLD, ALMOSTFULL, WARMER, 1, 1, 360},{WARMER, ALMOSTFULL, WARMER, 1, 1, 480}, {WARMER, FULL, HOT, 3, 2, 510}};
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
    IProgram *iprogramPtr = (IProgram *)HardwareControl::GetInstance();
    // var indicating the selected program
    int program = -1;
};

#endif