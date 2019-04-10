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
        Serial.println(reading);
      }
    }
  }
  *previousState = reading;
}

void InputManager::ReadButtons()
{
  ioPtr->SetKeyselect(true);
  functionButtons = ioPtr->GetButtonsFunction();
}

void InputManager::ReadSwitches()
{
  ioPtr->SetKeyselect(false);
  functionSwitches = ioPtr->GetButtonsFunction();
}

void InputManager::GetInput()
{
  ReadButtons();
  Debouncing(&previousStateButtons, &stateButtons, functionButtons, &lastDebounceTimeButtons);
  ReadSwitches();
  Debouncing(&previousStateSwitches, &stateSwitches, functionSwitches, &lastDebounceTimeSwitches);
}

void InputManager::Polling()
{
    //to be implemented
    // for now it is only lights the leds nwhen a button is pressed
    GetInput();
}