#include "lib/SoapHandler.h"
#include "lib/SecurityManager.h"
#include "lib/CoinHandler.h"
#include "lib/InputManager.h"
HardwareControl HC;
SoapHandler SH;
SecurityManager SM;
CoinHandler CH;
InputManager IM;

void setup()
{
  //Serial.begin(9600);
  HC.HardwareControlSetup();
  //HC.SetCoin10Led(0);
  //HC.SetCoin200Led(0);
  //HC.SetCoin50Led(0);
  //SM.IsEverythingClosed();
  //SH.IsSoapEnough(2,3);
  //CH.AreCoinsEnough(530);
}

void loop()
{
  //HC.SetKeyselect(false);
  //Serial.println(HC.GetGlobalInputByte(), BIN);
  IM.Polling();
  SH.Polling();
  CH.Polling();
  SM.Polling();
}
