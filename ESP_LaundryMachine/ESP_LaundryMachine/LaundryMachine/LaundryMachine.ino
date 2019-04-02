#include "SoapHandler.h"
#include "SecurityManager.h"
#include "CoinHandler.h"
#include "HardwareControl.h"
HardwareControl HC;
SoapHandler SH;
SecurityManager SM;
CoinHandler CH;

void setup()
{  
  Serial.begin(9600);
  HC.HardwareControlSetup();
  //CH.HardwareControlSetup();
  //SM.HardwareControlSetup();
}

void loop()
{
  //Serial.write("hello");
  // to be implemented
  //HC.SetDrain(true);
  //HC.SetSink(true);
  //HC.SetHeater(true);
  //HC.SetStrobe(true);
  //HC.SetKeyselect(true);
  //HC.SetSpeed(HIGHSPEED);
  //HC.SetCoin10Led(0);
  //HC.SetCoin50Led(0);
  //HC.SetCoin200Led(0);
  //HC.SetProgramLed(0);
  //HC.SetSoap1Led(false);
  //HC.SetSoap2Led(false);
  //HC.SetSoap2Led();
  //HC.SetLock(true);
  //int test = HC.Keyselect();
  //HC.GetButtonsFunction();
  //Serial.println(HC.GetButtonsFunction(), DEC);
  CH.Polling();
  SM.Polling();
  SH.Polling();
  //delay(500);

}
