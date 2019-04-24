#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "HardwareControl.h"

using namespace sharedNamespace;

class InputManager
{
    public:

        /* Method that handles all the essential
        proccesses for this object that have to 
        be ran during the main loop of the arduino
        program */
        void Polling();


    private:
        /* Method that reads the buttons/switches
        by toggling IO::SetKeyselect(). After that
        the functions for both states of the keyselect
        get recorded into two variables, which later
        get debounced separately. If they were recorded
        on to a single variable the debouncing would be 
        impossible since the the variable would be changing
        states constantly. */
        void GetInput();
        /* This is a method that handles any input debouncing.
        input:
            - previous state - the previous recorded state
            - state - the curent recoded state
            - reading - the raw input
            - lastDebounceTime - the last time and action was recorded 
            - x - keyselect*/
        void Debouncing(byte* previousByteState, byte* byteState, byte reading, unsigned long* lastDebounceTime, int x);

        // vars required for Debouncing()
        
        byte previousByteStateButtons;
        byte byteStateButtons;
        byte previousByteStateSwitches;
        byte byteStateSwitches;
        unsigned long lastDebounceTimeByteButtons;
        unsigned long lastDebounceTimeByteSwitches;
        unsigned long timerTreshold = 20;
        // accessing the library through the IO interface
        IO* ioPtr = (IO*)HardwareControl::GetInstance();


};

#endif