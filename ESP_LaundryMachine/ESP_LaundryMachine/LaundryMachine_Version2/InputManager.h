#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "HardwareControl.h"

using namespace sharedNamespace;

class InputManager
{
    public:
        // bytes and bitmasks
        
        byte bitMaskClear = 0x1E;
        byte bitMaskProgram = 0x19;
        byte bitMaskStart = 0x11;
        byte bitMaskPressure = 0x01;
        byte bitMaskKeyselect = 0x10;
        byte previousByteState;
        byte byteState;
        unsigned long lastDebounceTime;

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
            - lastDebounceTime - the last time and action was recorded */
        void Debouncing(Function* previousState, Function* state, Function reading, unsigned long* lastDebounceTime);
        void DebouncingByte(byte* previousByteState, byte* byteState, byte reading, unsigned long* lastDebounceTime);

        // vars required for Debouncing()
        Function previousStateButtons;
        Function previousStateSwitches;
        Function stateButtons;
        Function stateSwitches;
        Function functionSwitches;
        Function functionButtons;
        unsigned long lastDebounceTimeButtons;
        unsigned long lastDebounceTimeSwitches;
        unsigned long timerTreshold = 20;
        // accessing the library through the IO interface
        IO* ioPtr = (IO*)HardwareControl::GetInstance();
};

#endif