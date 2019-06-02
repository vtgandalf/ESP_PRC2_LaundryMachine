#include "../lib/InputManager.h"

// Macros for the states of the keyselect
#define emptyBitmask 0x00
#define keyselectBitmask 0x10

// Method that handles deouncing the input
// I will not explain that since it is fairly standart and common technique
void InputManager::Debouncing(byte *previousByteState, byte *byteState, byte reading, unsigned long *lastDebounceTime, int x)
{
  if (reading != *previousByteState)
  {
    *lastDebounceTime = millis();
  }
  if ((millis() - *lastDebounceTime) > timerTreshold)
  {
    if (reading != *byteState)
    {
      *byteState = reading;
      if (x == 0)
      {
        if (*byteState != emptyBitmask)
        {
          ioPtr->SetGlobalInputByte(reading);
        }
      }
      if (x == 1)
      {
        if (*byteState != keyselectBitmask) // 0x10 is the bitmask for keyselect
        {
          ioPtr->SetGlobalInputByte(reading);
        }
      }
    }
  }
  *previousByteState = reading;
}

// Method that handles toggling the keyselect, getting the input and debouncing it
void InputManager::GetInput()
{
  ioPtr->SetKeyselect(true);
  Debouncing(&previousByteStateButtons, &byteStateButtons, ioPtr->GetRawInputByte(), &lastDebounceTimeByteButtons, ioPtr->Keyselect());
  ioPtr->SetKeyselect(false);
  Debouncing(&previousByteStateSwitches, &byteStateSwitches, ioPtr->GetRawInputByte(), &lastDebounceTimeByteSwitches, ioPtr->Keyselect());
}

// Method that handles all the methods that need to be polled
void InputManager::Polling()
{
  GetInput();
}