#include "SoapHandler.h"
#include "SecurityManager.h"
#include "CoinHandler.h"
HardwareControl HC;
SoapHandler SH;
SecurityManager SM;
CoinHandler CH;

void setup()
{
  //Serial.begin(9600);
  HC.HardwareControlSetup();
  }

void loop()
{
  //Serial.write("hello");
  // to be implemented
  //HC.SetDrain(true);
  //HC.SetSink(true);
  //HC.SetHeater(true);
  //HC.SetStrobe(true);
  //HC.SetKeyselect(false);
  //HC.SetSpeed(HIGHSPEED);
  //HC.SetCoin10Led(1);
  //HC.SetCoin50Led(1);
  //HC.SetCoin200Led(1);
  //HC.SetProgramLed(2);
  //HC.SetSoap1Led(true);
  //HC.SetSoap2Led(true);
  //HC.SetLock(true);
  //int test = HC.Keyselect();
  //HC.GetButtonsFunction();
  //Serial.println(HC.Keyselect());
  //Serial.println(HC.GetButtonsFunctionDebounced(),DEC);
  //HC.SetKeyselect(true);
  //CH.Polling();
  //delay(100);
  //HC.SetKeyselect(false);
  SM.Polling();
  delay(100);
  SH.Polling();
  delay(100);
}
