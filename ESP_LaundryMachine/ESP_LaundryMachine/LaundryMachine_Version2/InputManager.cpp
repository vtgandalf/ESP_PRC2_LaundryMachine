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

void InputManager::DebouncingByte(byte* previousByteState, byte* byteState, byte reading, unsigned long* lastDebounceTime)
{
  if(reading != *previousByteState)
  {
    *lastDebounceTime = millis();
  }

  if((millis() - *lastDebounceTime) > timerTreshold)
  {
    if(reading != *byteState)
    {
      *byteState = reading;
      if((*byteState != 0x00)&(*byteState != bitMaskKeyselect))
      {
        ioPtr->SetGlobalInputByte(reading);
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
  DebouncingByte(&previousByteState, &byteState, ioPtr->GetRawInputByte(), &lastDebounceTime);
  ioPtr->SetKeyselect(false);
  DebouncingByte(&previousByteState, &byteState, ioPtr->GetRawInputByte(), &lastDebounceTime);
}

void InputManager::Polling()
{
    GetInput();
}