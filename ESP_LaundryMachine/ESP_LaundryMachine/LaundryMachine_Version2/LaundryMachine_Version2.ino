#include "SoapHandler.h"
#include "SecurityManager.h"
#include "CoinHandler.h"
#include "InputManager.h"
HardwareControl HC;
//SoapHandler SH;
//SecurityManager SM;
//CoinHandler CH;
InputManager IM;

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
  
  /*sharedNamespace::Function function = HC.GetButtonsFunctionDebounced();
  if(function != NOTHING)
  {
    Serial.println(function);
  
  }*/

  //HC.SetKeyselect(true);
  //CH.Polling();
  //delay(100);
  //HC.SetKeyselect(false);
  //SM.Polling();
  //delay(100);
  //SH.Polling();
  //delay(100);
  IM.Polling();
  /*int x = 100;
  for(int i = 0; i < x; i++)
  {
    CH.Polling();
  }
    
  for(int i = 0; i < x; i++)
  {
    SH.Polling();
  }
  
  for(int i = 0; i < x; i++)
  {
    SM.Polling();
  }*/
    
}
