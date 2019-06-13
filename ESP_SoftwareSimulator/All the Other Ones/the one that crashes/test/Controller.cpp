#include "Controller.h"

void Controller::ProgramStatesCalling()
{
    PreWashStateMachine();
    MainWashStateMachine();
    CentrifugeStateMachine();
}

void Controller::MainStateMachine()
{
   /* while (true)
    {*/
        switch (mainState)
        {
        case Start:
            _program.Setup();
            mainState = PreProgram;
            break;

        case PreProgram:
            _washingProgram = _program.PreProgram();
            mainState = ExecProgram;
            break;

        case ExecProgram:
            programState = PreWash;
            ProgramStateMachine();
            //ProgramStatesCalling();
            mainState = PreProgram;
            break;

        default:
            ////serial.println("Error in MainStateMachine()");
            break;
        }
    //}
}

void Controller::ProgramStateMachine()
{
    bool trig = false;
    while (!trig)
    {
		trig = true;
        switch (programState)
        {
        case PreWash:
            PreWashStateMachine();
            break;

        case MainWash:
            MainWashStateMachine();
            break;

        case Centrifuge:
            CentrifugeStateMachine();
            trig = true;
            _program.UnlockDoor();
            break;

        case ForceQuit:
            ForceQuitStateMachine();
            trig = true;
            _program.UnlockDoor();
            break;

        default:
            ////serial.println("Error in Program State Machine!");
            break;
        }
    }
}

void Controller::PreWashStateMachine()
{
    ////serial.println("--- PRE WASH ---");
    washingState = FillUpTank;
    Temp temp = COLD;
    bool trig = false;
    while (!trig)
    {
		trig = true;
        _program.InputPolling();
        _program.HeatUp(temp);
        if (washingState == FillUpTank || washingState == Waiting)
        {
            SecurityCheckUp(&trig);
        }
        switch (washingState)
        {
        case FillUpTank:
            //////serial.println("--- FillUpTank ---");
            //////serial.println(_program.FillUpWater(ALMOSTFULL));
            if (_program.FillUpWater(ALMOSTFULL))
            {
                washingState = AddSoap1;
            }
            break;

        case AddSoap1:
            //////serial.println("--- AddSoap1 ---");
            _program.AddSoap1();
            washingState = HeatUp;
            break;

        case HeatUp:
            //////serial.println("--- HeatUp ---");
            temp = _washingProgram.PreWashTemp();
            if (_program.HeatUp(_washingProgram.PreWashTemp()))
            {
                _program.SaveTimeMotorManager();
                washingState = RotateClockwise;
            }
            break;

        case RotateClockwise:
            //////serial.println("--- RotateClockwise ---");
            if (_program.Rotate(CLOCKWISE, LOWSPEED, 5))
            {
                _program.SaveTimeMotorManager();
                washingState = RotateCounterclockwise;
            }
            break;

        case RotateCounterclockwise:
            //////serial.println("--- RotateCounterclockwise ---");
            if (_program.Rotate(COUNTERCLOCKWISE, LOWSPEED, 5))
            {
                washingState = Sink;
                temp = COLD;
                _program.StopHeating();
            }
            break;

        case Sink:
            //////serial.println("--- Sink ---");
            if (_program.Sink())
            {
                trig = true;
                programState = MainWash;
                //washingState = FillUpTank;
            }
            break;

        case Waiting:
            _program.BlinkProgramLed();
            break;

        default:
            ////serial.println("Error in PreWashStateMachine()");
            break;
        }
    }
    ////serial.println("--- DONE ---");
}

void Controller::MainWashStateMachine()
{
    ////serial.println("--- MAIN WASH ---");
    Temp temp = COLD;
    washingState = FillUpTank;
    bool trig = false;
    int stage = 0;
    int tankReps = 0;
    while (!trig)
    {
		trig = true;
        _program.InputPolling();
        _program.HeatUp(temp);
        if (washingState == FillUpTank || washingState == Waiting)
        {
            SecurityCheckUp(&trig);
        }
        switch (washingState)
        {
        case FillUpTank:
            if (_program.FillUpWater(_washingProgram.MainWashWaterLevel()))
            {
                if (stage == 0)
                {
                    washingState = AddSoap2;
                }
                if (stage == 1)
                {
                    washingState = StopHeating;
                }
            }
            break;

        case AddSoap2:
            _program.AddSoap2();
            washingState = HeatUp;
            break;

        case HeatUp:
            temp = _washingProgram.PreWashTemp();
            if (_program.HeatUp(_washingProgram.PreWashTemp()))
            {
                _program.SaveTimeMotorManager();
                washingState = RotateClockwise;
            }
            break;

        case StopHeating:
            temp = COLD;
            _program.StopHeating();
            _program.SaveTimeMotorManager();
            washingState = RotateClockwise;
            break;

        case RotateClockwise:
            if (_program.Rotate(CLOCKWISE, MEDIUMSPEED, 5))
            {
                _program.SaveTimeMotorManager();
                washingState = RotateCounterclockwise;
            }
            break;

        case RotateCounterclockwise:
            if (_program.Rotate(COUNTERCLOCKWISE, MEDIUMSPEED, 5))
            {
                tankReps++;
                if (tankReps < _washingProgram.MainWashRotations())
                {
                    _program.SaveTimeMotorManager();
                    washingState = RotateClockwise;
                }
                if (tankReps == _washingProgram.MainWashRotations())
                {
                    washingState = Sink;
                    temp = COLD;
                    _program.StopHeating();
                }
            }
            break;

        case Sink:
            temp = COLD;
            if (_program.Sink())
            {
                //trig = true;
                if (stage == 1)
                {
                    trig = true;
                    programState = Centrifuge;
                    // washingState = FillUpTank;
                }
                if (stage == 0)
                {
                    stage++;
                    tankReps = 0;
                    washingState = FillUpTank;
                }
            }
            break;

        case Waiting:
            _program.BlinkProgramLed();
            break;

        default:
            ////serial.println("Error in PreWashStateMachine()");
            break;
        }
    }
}

void Controller::CentrifugeStateMachine()
{
    ////serial.println("--- CENETRIFUGE ---");
    washingState = Sink;
    bool trig = false;
    int tankReps = 0;
    while (!trig)
    {
		trig = true;
        _program.InputPolling();
        switch (washingState)
        {
        case RotateClockwise:
            _program.Sink();
            if (_program.Rotate(CLOCKWISE, MEDIUMSPEED, 5))
            {
                washingState = RotateCounterclockwise;
                _program.SaveTimeMotorManager();
            }
            break;

        case RotateCounterclockwise:
            _program.Sink();
            if (_program.Rotate(COUNTERCLOCKWISE, MEDIUMSPEED, 5))
            {
                tankReps++;
                if (tankReps < _washingProgram.CentrifugeRotations())
                {
                    washingState = RotateClockwise;
                }
                if (tankReps == _washingProgram.CentrifugeRotations())
                {
                    washingState = Sink;
                }
            }
            break;

        case Sink:
            if (_program.Sink())
            {
                _program.SaveTimeMotorManager();
                washingState = RotateClockwise;
                if (tankReps == _washingProgram.CentrifugeRotations())
                {
                    trig = true;
                }
            }
            break;

        default:
            ////serial.println("Error in PreWashStateMachine()");
            break;
        }
    }
}

void Controller::ForceQuitStateMachine()
{
    bool trig = false;
    washingState = Sink;
    while (!trig)
    {
		trig = true;
        _program.InputPolling();
        if (_program.Sink())
        {
            ////serial.println("Dirty water has been sinked and the current program has been exited!");
            trig = true;
        }
    }
}

void Controller::SecurityCheckUp(bool *trig)
{
    switch (_program.SecurityFallBack())
    {
    case -1:
        *trig = true;
        programState = ForceQuit;
        break;

    case 0:
        // in save mode
        if (washingState != Waiting)
        {
            ////serial.println("Pressure dropped! Entering Waiting state.");
            //_program.SaveTimeSecurityManager();
            _program.StopDrain(true);
            lastWashingState = washingState;
            washingState = Waiting;
        }
        break;

    case 1:
        if (washingState == Waiting)
        {
            ////serial.println("Pressure came back!");
            washingState = lastWashingState;
        }
        break;

    default:
        ////serial.println(" Error checking if in save mode");
        break;
    }
}