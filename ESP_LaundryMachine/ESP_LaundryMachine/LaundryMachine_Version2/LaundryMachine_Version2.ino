#include "lib/Program.h"
#include "lib/HardwareControl.h"
#include "lib/InputManager.h"
#include "lib/HeaterHandler.h"
#include "lib/Controller.h"

//Program program;
//HardwareControl HC;
//CoinHandler CH;
//SoapHandler SH;
//SecurityManager SM;
//InputManager IM;
//HeaterHandler HH;
Controller ctrl;

void setup()
{
    //HC.HardwareControlSetup();
}

void loop()
{
    //Serial.println(SM.IsPressureOn());
    //Serial.println(HC.PressureAction());
    ctrl.MainStateMachine();
    //program.Testing();
    //program.PreProgram();
    //program.ExecProgram(program.PreProgram());
    //HC.SetHeater(true);
    //Serial.println(HC.GetTemperature());
    //HH.HeatUp(WARM);
    //HC.SetHeater(true);
    //IM.Polling();
    //CH.Polling();
    //SM.Polling();
    //SH.Polling();
}
