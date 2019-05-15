#include "../lib/InputManager.h"

#define emptyBitmask 0x00
#define keyselectBitmask 0x10

void InputManager::Debouncing(byte *previousByteState, byte *byteState, byte reading, unsigned long *lastDebounceTime, int x)
{
  if (reading != *previousByteState)
  {
    *lastDebounceTime = millis();
  }

  if ((millis() - *lastDebounceTime) > timerTreshold)
  {
    //if((reading != *byteState)&((*byteState | *previousByteState) != *byteState))
    if (reading != *byteState)
    {
      *byteState = reading;
      if (x == 0)
      {
        if (*byteState != emptyBitmask)
        {
          //Serial.println(reading, BIN);
          ioPtr->SetGlobalInputByte(reading);
        }
      }
      if (x == 1)
      {
        if (*byteState != keyselectBitmask) // 0x10 is the bitmask for keyselect
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
  ioPtr->SetKeyselect(true);
  Debouncing(&previousByteStateButtons, &byteStateButtons, ioPtr->GetRawInputByte(), &lastDebounceTimeByteButtons, ioPtr->Keyselect());
  ioPtr->SetKeyselect(false);
  Debouncing(&previousByteStateSwitches, &byteStateSwitches, ioPtr->GetRawInputByte(), &lastDebounceTimeByteSwitches, ioPtr->Keyselect());
}

void InputManager::Polling()
{
  GetInput();
}