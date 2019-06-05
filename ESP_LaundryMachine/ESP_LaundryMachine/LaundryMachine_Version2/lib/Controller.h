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
    /* Enum that contains the states neede for the main
    state machine */
    enum MainStates
    {
        Start,
        PreProgram,
        ExecProgram
    };
    /* Enum that contains the states needed for the washing
    program state machine */
    enum ProgramStates
    {
        PreWash,
        MainWash,
        Centrifuge,
        ForceQuit
    };
    /* Enum that contains the states needed for each of the
    program states. Those are sub states of the previous ones.
    Those Get executed in preWash, mainWash and Centrifuge
    state machines */
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
    /* Var containing the current state of the main state machie */
    MainStates mainState = Start;
    /* Var containing the current state of the program state machine */
    ProgramStates programState = PreWash;
    /* Var containing the current state of the washing state machines */
    WashingStates washingState = FillUpTank;
    /* Var containing the previous state of the washing state machines.
    It is needed to store since if the washing machine has to stop
    due to lack of pressure and later it comes back the machine
    should start from the state it last stopped */
    WashingStates lastWashingState = FillUpTank;
    /* Reference of the Program class */
    Program _program;
    //WashingProgram = delete;
    WashingProgram _washingProgram = WashingProgram(WARMER, FULL, HOT, 3, 2, 510);
    /* Method that handles handles the securty checkup routine 
    Input: pointer the trigger bool so the current state machine
    could be exited after 10 mins of waiting. For further explanation
    read the comments in the .cpp file!*/
    void SecurityCheckUp(bool *);
};

#endif