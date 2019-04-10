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
void InputManager::GetInput()
{
  ioPtr->SetKeyselect(true);
  functionButtons = ioPtr->GetButtonsFunction();
  Debouncing(&previousStateButtons, &stateButtons, functionButtons, &lastDebounceTimeButtons); 
  ioPtr->SetKeyselect(false);
  functionSwitches = ioPtr->GetButtonsFunction();
  Debouncing(&previousStateSwitches, &stateSwitches, functionSwitches, &lastDebounceTimeSwitches);
}

void InputManager::Polling()
{
    GetInput();
}