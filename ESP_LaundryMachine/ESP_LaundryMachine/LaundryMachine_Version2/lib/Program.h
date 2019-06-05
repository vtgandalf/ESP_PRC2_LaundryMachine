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

class Program
{
public:
    /* Method that handles the setup of the HardwareControl lib */
    void Setup();
    /* A method that handles the stage
    prior to any washing program. It includes
    waiting for coins, soap, doorlock,
    program selection and etc.
    Output: The chose washing program */
    WashingProgram PreProgram();
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
    /* This is a method that handles the drain through
    the water manager */
    void StopDrain(bool);
    /* This method handles unlocking the door through
    the security manager */
    void UnlockDoor();

private:
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
    WashingProgram programs[3] = {WashingProgram(COLD, ALMOSTFULL, WARMER, 2, 1, 360), WashingProgram(WARMER, ALMOSTFULL, WARMER, 2, 1, 480), WashingProgram(WARMER, FULL, HOT, 4, 2, 510)};
    //WashingProgram programs[3] = {{COLD, ALMOSTFULL, WARMER, 1, 1, 360},{WARMER, ALMOSTFULL, WARMER, 1, 1, 480}, {WARMER, FULL, HOT, 3, 2, 510}};
    /* Vars for the managers/handlers and the library */
    HardwareControl *_hardwareControl = (HardwareControl *)HardwareControl::GetInstance();
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