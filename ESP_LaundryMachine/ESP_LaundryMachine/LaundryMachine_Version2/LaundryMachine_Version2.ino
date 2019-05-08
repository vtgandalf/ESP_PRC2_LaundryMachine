#include "lib/Program.h"
#include "lib/HardwareControl.h"
#include "lib/InputManager.h"
//Program program;
HardwareControl HC;
CoinHandler CH;
SoapHandler SH;
SecurityManager SM;
InputManager IM;

void setup()
{
    HC.HardwareControlSetup();
}

void loop()
{
 //program.ExecProgram(program.PreProgram());
 IM.Polling();
 CH.Polling();
 SM.Polling();
 SH.Polling();
}
