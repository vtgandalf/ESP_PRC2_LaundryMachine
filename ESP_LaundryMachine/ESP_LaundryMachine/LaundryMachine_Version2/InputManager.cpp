#include "InputManager.h"

void InputManager::Debouncing(Function* previousState, Function* state, Function reading, unsigned long* lastDebounceTime)
{
  if(reading != *previousState)
  {
    *lastDebounceTime = millis();
  }

  if((millis() - *lastDebounceTime) > timerTreshold)
  {
    if(reading != *state)
    {
      *state = reading;
      if(*state != NOTHING)
      {
        ioPtr->SetGlobalFunction(reading);
      }
    }
  }
  *previousState = reading;
}

void InputManager::DebouncingByte(byte* previousByteState, byte* byteState, byte reading, unsigned long* lastDebounceTime, int x)
{
  if(reading != *previousByteState)
  {
    *lastDebounceTime = millis();
  }

  if((millis() - *lastDebounceTime) > timerTreshold)
  {
    //if((reading != *byteState)&((*byteState | *previousByteState) != *byteState))
    if(reading != *byteState)
    {
      *byteState = reading;
      if(x == 0)
      {
        if(*byteState != 0x00)
        {
          //Serial.println(reading, BIN);
          ioPtr->SetGlobalInputByte(reading);
        }
      }
      if(x == 1)
      {
        if(*byteState != bitMaskKeyselect)
        {
          //Serial.println(reading, BIN);
          ioPtr->SetGlobalInputByte(reading);
        }
      }
      
    }
  }
  *previousByteState = reading;
}

void InputManager::GetInput()
{
  /*ioPtr->SetKeyselect(true);
  functionButtons = ioPtr->GetButtonsFunction();
  Debouncing(&previousStateButtons, &stateButtons, functionButtons, &lastDebounceTimeButtons); 
  ioPtr->SetKeyselect(false);
  functionSwitches = ioPtr->GetButtonsFunction();
  Debouncing(&previousStateSwitches, &stateSwitches, functionSwitches, &lastDebounceTimeSwitches);*/
  // byte
  ioPtr->SetKeyselect(true);
  DebouncingByte(&previousByteStateButtons, &byteStateButtons, ioPtr->GetRawInputByte(), &lastDebounceTimeByteButtons, 1);
  ioPtr->SetKeyselect(false);
  DebouncingByte(&previousByteStateSwitches, &byteStateSwitches, ioPtr->GetRawInputByte(), &lastDebounceTimeByteSwitches, 0);
}

void InputManager::Polling()
{
    GetInput();
}