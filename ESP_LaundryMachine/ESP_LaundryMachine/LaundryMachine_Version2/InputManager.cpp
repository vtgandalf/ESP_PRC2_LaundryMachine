#include "InputManager.h"

InputManager* InputManager::instance = 0;

InputManager* InputManager::GetInstance()
{
  if (instance == 0)
    {
      instance = new InputManager();
    }
    return instance;
}

void InputManager::Debouncing(Function* previousState, Function* state, Function reading, unsigned long* lastDebounceTime, functiontype method)
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
        method;
        Serial.println(reading);
      }
    }
  }
  *previousState = reading;
}

void InputManager::ReadButtons()
{
  Serial.println(functionButtons);
}

void InputManager::ReadSwitches()
{
  Serial.println(functionSwitches);
}

void InputManager::GetInput()
{
  ioPtr->SetKeyselect(true);
  functionButtons = ioPtr->GetButtonsFunction();
  functiontype x = &InputManager::ReadButtons;
  Debouncing(&previousStateButtons, &stateButtons, functionButtons, &lastDebounceTimeButtons, x); 
  ioPtr->SetKeyselect(false);
  functionSwitches = ioPtr->GetButtonsFunction();
  functiontype y = &InputManager::ReadSwitches;
  Debouncing(&previousStateSwitches, &stateSwitches, functionSwitches, &lastDebounceTimeSwitches, y);
}

void InputManager::Polling()
{
    //to be implemented
    // for now it is only lights the leds nwhen a button is pressed
    GetInput();
}