#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "HardwareControl.h"

using namespace sharedNamespace;

class InputManager
{
    public:
        void Polling();

    private:
        void GetInput();
        void ReadButtons();
        void ReadSwitches();
        void Debouncing(Function* previousState, Function* state, Function reading, unsigned long* lastDebounceTime);
        Function previousStateButtons;
        Function previousStateSwitches;
        Function stateButtons;
        Function stateSwitches;
        unsigned long lastDebounceTimeButtons;
        unsigned long lastDebounceTimeSwitches;
        unsigned long timerTreshold = 20;
        IO* ioPtr = (IO*)HardwareControl::GetInstance();
        Function functionButtons;
        Function functionSwitches;
};

#endif