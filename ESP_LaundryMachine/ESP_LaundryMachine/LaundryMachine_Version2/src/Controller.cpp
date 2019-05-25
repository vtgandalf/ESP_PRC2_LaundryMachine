#include "../lib/Controller.h"

void Controller::MainStateMachine()
{
    while (true)
    {
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
            ProgramStateMachine();
            mainState = PreProgram;
            break;

        default:
            Serial.println("Error in MainStateMachine()");
            break;
        }
    }
}

void Controller::ProgramStateMachine()
{
    bool trig = false;
    programState = PreWash;
    while (!trig)
    {
        switch (programState)
        {
        case PreWash:
            PreWashStateMachine();
            programState = MainWash;
            break;

        case MainWash:
            MainStateMachine();
            programState = Centrifuge;
            break;

        case Centrifuge:
            CentrifugeStateMachine();
            trig = true;
            break;

        case ForceQuit:
            ForceQuitStateMachine();
            trig = true;
            break;

        default:
            break;
        }
    }
}

void Controller::PreWashStateMachine()
{
    Serial.println("--- PRE WASH ---");
    washingState = FillUpTank;
    Temp temp = COLD;
    bool trig = false;
    while (!trig)
    {
        _program.InputPolling();
        _program.HeatUp(temp);
        SecurityCheckUp(&trig);
        switch (washingState)
        {
        case FillUpTank:
            //Serial.println("--- FillUpTank ---");
            if (_program.FillUpWater(ALMOSTFULL))
            {
                washingState = AddSoap1;
            }
            break;

        case AddSoap1:
            //Serial.println("--- AddSoap1 ---");
            _program.AddSoap1();
            washingState = HeatUp;
            break;

        case HeatUp:
            //Serial.println("--- HeatUp ---");
            temp = _washingProgram.PreWashTemp();
            if (_program.HeatUp(_washingProgram.PreWashTemp()))
            {
                _program.SaveTimeMotorManager();
                washingState = RotateClockwise;
            }
            break;

        case RotateClockwise:
            //Serial.println("--- RotateClockwise ---");
            if (_program.Rotate(CLOCKWISE, LOWSPEED, 5))
            {
                _program.SaveTimeMotorManager();
                washingState = RotateCounterclockwise;
            }
            break;

        case RotateCounterclockwise:
            //Serial.println("--- RotateCounterclockwise ---");
            if (_program.Rotate(COUNTERCLOCKWISE, LOWSPEED, 5))
            {
                washingState = Sink;
                temp = COLD;
                _program.StopHeating();
            }
            break;

        case Sink:
            //Serial.println("--- Sink ---");
            if (_program.Sink())
            {
                trig = true;
                //washingState = FillUpTank;
            }
            break;

        case Waiting:
            _program.BlinkProgramLed();
            break;

        default:
            Serial.println("Error in PreWashStateMachine()");
            break;
        }
    }
    Serial.println("--- DONE ---");
}

void Controller::MainWashStateMachine()
{
    Serial.println("--- MAIN WASH ---");
    Temp temp = COLD;
    washingState = FillUpTank;
    bool trig = false;
    int stage = 0;
    int tankReps = 0;
    while (!trig)
    {
        _program.InputPolling();
        _program.HeatUp(temp);
        SecurityCheckUp(&trig);
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
                trig = true;
                if (stage == 1)
                {
                    trig = true;
                    washingState = FillUpTank;
                }
                else
                {
                    stage++;
                    washingState = FillUpTank;
                }
            }
            break;

        case Waiting:
            _program.BlinkProgramLed();
            break;

        default:
            Serial.println("Error in PreWashStateMachine()");
            break;
        }
    }
}

void Controller::CentrifugeStateMachine()
{
    Serial.println("--- CENETRIFUGE ---");
    washingState = Sink;
    bool trig = false;
    int tankReps = 0;
    while (!trig)
    {
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
            Serial.println("Error in PreWashStateMachine()");
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
        _program.InputPolling();
        if (_program.Sink())
        {
            Serial.println("Dirty water has been sinked and the current program has been exited!");
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
            _program.SaveTimeSecurityManager();
            lastWashingState = washingState;
            washingState = Waiting;
        }
        break;

    case 1:
        if (washingState = Waiting)
        {
            washingState = lastWashingState;
        }
        break;

    default:
        Serial.println(" Error checking if in save mode");
        break;
    }
}