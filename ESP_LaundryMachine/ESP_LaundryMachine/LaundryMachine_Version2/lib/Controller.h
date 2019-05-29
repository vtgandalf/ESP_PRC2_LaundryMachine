#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../lib/Program.h"
#include "../lib/WashingProgram.h"

class Controller
{
public:
    /* A method that handles the main state machine
    of the general process, which includes pre program state
    and program state */
    void MainStateMachine();

private:
    void ProgramStatesCalling();
    /* A method that handles the program state machine */
    void ProgramStateMachine();
    /* This method handles the preWash state machine */
    void PreWashStateMachine();
    /* This method handles the mainWash state machine */
    void MainWashStateMachine();
    /* This method handles the centrifuge state machine */
    void CentrifugeStateMachine();
    /* This method handles the state machine to be executed
    if the laundry machine is in save mode, 10 minutes have
    passed and the pressure hasnt came back. It handles
    sinking the water and quiting the washing program */
    void ForceQuitStateMachine();
    enum MainStates
    {
        Start,
        PreProgram,
        ExecProgram
    };
    enum ProgramStates
    {
        PreWash,
        MainWash,
        Centrifuge,
        ForceQuit
    };
    enum WashingStates
    {
        FillUpTank,
        AddSoap1,
        AddSoap2,
        HeatUp,
        StopHeating,
        RotateClockwise,
        RotateCounterclockwise,
        Sink,
        Waiting
    };
    MainStates mainState = Start;
    ProgramStates programState = PreWash;
    WashingStates washingState = FillUpTank;
    WashingStates lastWashingState = FillUpTank;
    Program _program;
    //WashingProgram = delete;
    WashingProgram _washingProgram = WashingProgram(WARMER, FULL, HOT, 3, 2, 510);
    void SecurityCheckUp(bool *);
    bool trigProgramStateMachine = false;
    bool trigExecProgramStateMachine = false;
};

#endif