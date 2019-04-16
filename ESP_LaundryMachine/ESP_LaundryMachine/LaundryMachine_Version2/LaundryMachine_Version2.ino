#include "SoapHandler.h"
#include "SecurityManager.h"
#include "CoinHandler.h"
#include "InputManager.h"
HardwareControl HC;
SoapHandler SH;
SecurityManager SM;
CoinHandler CH;
InputManager IM;

void setup()
{
  //Serial.begin(9600);
  HC.HardwareControlSetup();
}

void loop()
{
  //HC.SetKeyselect(false);
  //Serial.println(HC.GetGlobalInputByte(), BIN);
  IM.Polling();
  //SH.Polling();
  CH.Polling();
  SM.Polling();
}
