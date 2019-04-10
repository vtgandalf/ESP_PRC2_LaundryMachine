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
        //Serial.println(functionGlobal);
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
  Debouncing(&previousStateButtons, &stateButtons, functionButtons, &lastDebounceTimeButtons); 
  ioPtr->SetKeyselect(false);
  functionSwitches = ioPtr->GetButtonsFunction();
  Debouncing(&previousStateSwitches, &stateSwitches, functionSwitches, &lastDebounceTimeSwitches);
}

void InputManager::Polling()
{
    //to be implemented
    // for now it is only lights the leds nwhen a button is pressed
    GetInput();
}