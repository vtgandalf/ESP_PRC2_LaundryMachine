#include "../lib/Controller.h"

#define ROTATETIME 5

/* Method that handles the main state machine */
void Controller::MainStateMachine()
{
    // Stays in the loop forever
    while (true)
    {
        // Read the current state
        switch (mainState)
        {
        /* This state handles the initial initialization 
        of the centipede library on boot. This state gets
        executed only once on boot. */
        case Start:
            // Call the setup method from class Program
            _program.Setup();
            /* After that is done change the state to
            PreProgram */
            mainState = PreProgram;
            break;

        /* This is the state that handles inserting the coins,
        soap, checking the pressure, choosing a program and etc */
        case PreProgram:
            /* Execute the PreProgram method that handles all that
            and store the washing program that had been chosen */
            _washingProgram = _program.PreProgram();
            /* Change the state to ExecProgram, which is the 
            program itself*/
            mainState = ExecProgram;
            break;

        /* This state handles the washing program itself */
        case ExecProgram:
            // Set the washing state to PreWash
            programState = PreWash;
            // Go to the program state machine
            ProgramStateMachine();
            /* After the program has finished change the state 
            to preProgram so the machine could wait for more
            coins, soap and etc. in order to start the next program */
            mainState = PreProgram;
            break;

        default:
            Serial.println("Error in MainStateMachine()");
            break;
        }
    }
}

// Method that handles the program state machine
void Controller::ProgramStateMachine()
{
    /* This bool keeps the while loop running until
    the program has finished. */
    bool trig = false;
    while (!trig)
    {
        // Read the current program state
        switch (programState)
        {
        /* This state handles the preWash part of any
        washing program */
        case PreWash:
            // Go to PreWash state machine
            PreWashStateMachine();
            break;

        /* This state handles the mainWash part of any
        washing program */
        case MainWash:
            // Go to MainWash state machine
            MainWashStateMachine();
            break;

        /* This state handles the centrifuge part of any
        washing program */
        case Centrifuge:
            // Go to Centrifuge state machine
            CentrifugeStateMachine();
            /* Since this is the end of the program the trig
            gets set to true so the the while loop can be 
            exited */
            trig = true;
            /* Again since this is the end of the washing program
            we can safely unlock the door so the user can take
            their clothes off */
            _program.UnlockDoor();
            break;

        /* This state handles the situation where the pressure has
        stopped and it is gone for more than 10 minutes. Then we sink
        the dirty water and end the program */
        case ForceQuit:
            // Go to ForceQuit state machine
            ForceQuitStateMachine();
            /* Since this is the end of the program the trig
            gets set to true so the the while loop can be 
            exited */
            trig = true;
            /* Again since this is the end of the washing program
            we can safely unlock the door so the user can take
            their clothes off */
            _program.UnlockDoor();
            break;

        default:
            Serial.println("Error in Program State Machine!");
            break;
        }
    }
}

/* This state machine handles the pre wash part of any washing
program */
void Controller::PreWashStateMachine()
{
    Serial.println("--- PRE WASH ---");
    // Set the washing state the state machine should start from
    washingState = FillUpTank;
    // Set initial temperature to be maintained from the heater
    Temp temp = COLD;
    // This bool keeps the while running until the proccess is done
    bool trig = false;
    while (!trig)
    {
        // Read the buttons on every while cycle
        _program.InputPolling();
        // Maintain the set temperature on every cycle
        _program.HeatUp(temp);
        /* Check for pressure change during filling up and waiting 
        states*/
        if (washingState == FillUpTank || washingState == Waiting)
        {
            SecurityCheckUp(&trig);
        }
        // Read the current washing state
        switch (washingState)
        {
        // This state handles filling up the water
        case FillUpTank:
            /* Go to state AddSoap1 if the water tank is 
            full enough */
            if (_program.FillUpWater(ALMOSTFULL))
            {
                washingState = AddSoap1;
            }
            break;

        // This state handles adding soap1
        case AddSoap1:
            // Add Soap1
            _program.AddSoap1();
            // Change the state to HeatUp
            washingState = HeatUp;
            break;

        // This state handles heating up the water
        case HeatUp:
            // Set the heat to be maintained
            temp = _washingProgram.PreWashTemp();
            /* If the desired temperature has been reached */
            if (_program.HeatUp(_washingProgram.PreWashTemp()))
            {
                /* Save the current time which gets used by the
                motor handler in order to keep rotating the tank
                for specific time period */
                _program.SaveTimeMotorManager();
                /* Set the state to RotateClockwise */
                washingState = RotateClockwise;
            }
            break;

        // This state handles rotating the tank clockwise
        case RotateClockwise:
            /* If the tank had been rotate for long enough */
            if (_program.Rotate(CLOCKWISE, LOWSPEED, ROTATETIME))
            {
                /* Save the current time which gets used by the
                motor handler in order to keep rotating the tank
                for specific time period */
                _program.SaveTimeMotorManager();
                // Set the state to RotateCounterclockwise
                washingState = RotateCounterclockwise;
            }
            break;

        // This state handles rotating the tank counterclockwise
        case RotateCounterclockwise:
            /* If the tank had been rotate for long enough */
            if (_program.Rotate(COUNTERCLOCKWISE, LOWSPEED, ROTATETIME))
            {
                // Set the state to sink
                washingState = Sink;
                /* Set the temperature to maintain to cold,
                since we do not need to heat any more */
                temp = COLD;
                // Stop the heating
                _program.StopHeating();
            }
            break;

        // This state handles sinking the water
        case Sink:
            /* If the water tank has been emptied */
            if (_program.Sink())
            {
                /* Set trig to true so we could step out of
                the while */
                trig = true;
                // Set the program state to mainWash
                programState = MainWash;
            }
            break;

        /* This state handles the behaviour of the machine 
        if the pressure has dropped */
        case Waiting:
            // Blink the led indicating which program had been selected
            _program.BlinkProgramLed();
            break;

        default:
            Serial.println("Error in PreWashStateMachine()");
            break;
        }
    }
    Serial.println("--- DONE ---");
}

// This state machine handles the mainWash state of any wahsing program
void Controller::MainWashStateMachine()
{
    Serial.println("--- MAIN WASH ---");
    // Set the temp to be maintained
    Temp temp = COLD;
    // Set the initial washing state
    washingState = FillUpTank;
    /* By now this trigger boolean should be familliar,
    if not read the description for the previous state machine */
    bool trig = false;
    /* How many times the water had been sinked, for the mainWash
    we actually need to sink the water twice*/
    int stage = 0;
    /* How many times the tank has executed the rotating clockwise +
    counterclockwise routine */
    int tankReps = 0;
    while (!trig)
    {
        // Read the buttons every loop cycle
        _program.InputPolling();
        // Maintain the heat of the tank every loop cycle
        _program.HeatUp(temp);
        /* Check for pressure change during filling up and waiting 
        states*/
        if (washingState == FillUpTank || washingState == Waiting)
        {
            SecurityCheckUp(&trig);
        }
        switch (washingState)
        {
        // This state handles filling up the water
        case FillUpTank:
            /* Go to state AddSoap2 if the water tank is 
            full enough (for before the water had been first sinked)
            or go to StopHeating (after the water had been sinked once) */
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

        // This state handles adding soap2
        case AddSoap2:
            // Add Soap2
            _program.AddSoap2();
            // Change the state to HeatUp
            washingState = HeatUp;
            break;

        // This state handles heating up the water
        case HeatUp:
            // Set the heat to be maintained
            temp = _washingProgram.PreWashTemp();
            /* If the desired temperature has been reached */
            if (_program.HeatUp(_washingProgram.PreWashTemp()))
            {
                /* Save the current time which gets used by the
                motor handler in order to keep rotating the tank
                for specific time period */
                _program.SaveTimeMotorManager();
                /* Set the state to RotateClockwise */
                washingState = RotateClockwise;
            }
            break;

        // This state handles stopping the heat
        case StopHeating:
            // Set temp to be maintained
            temp = COLD;
            // Stop the heating
            _program.StopHeating();
            /* Save the current time which gets used by the
                motor handler in order to keep rotating the tank
                for specific time period */
            _program.SaveTimeMotorManager();
            /* Set the state to RotateClockwise */
            washingState = RotateClockwise;
            break;

        // This state handles rotating the tank counterclockwise
        case RotateClockwise:
            /* If the tank had been rotate for long enough */
            if (_program.Rotate(CLOCKWISE, MEDIUMSPEED, ROTATETIME))
            {
                /* Save the current time which gets used by the
                motor handler in order to keep rotating the tank
                for specific time period */
                _program.SaveTimeMotorManager();
                // Set the state to RotateCounterclockwise
                washingState = RotateCounterclockwise;
            }
            break;

        // This state handles rotating the tank counterclockwise
        case RotateCounterclockwise:
            /* If the tank had been rotate for long enough */
            if (_program.Rotate(COUNTERCLOCKWISE, MEDIUMSPEED, ROTATETIME))
            {
                /* Increment the counter. Its use had been explained
                in the beginning of the state machine */
                tankReps++;
                // If the motor routine hadn't been executed enough times
                if (tankReps < _washingProgram.MainWashRotations())
                {
                    /* Save the current time which gets used by the
                    motor handler in order to keep rotating the tank
                    for specific time period */
                    _program.SaveTimeMotorManager();
                    // Set the state to RotateClockwise
                    washingState = RotateClockwise;
                }
                // If the motor routine had been executed enough times
                if (tankReps == _washingProgram.MainWashRotations())
                {
                    /* Set the state to sinking */
                    washingState = Sink;
                    // Set temperature to be maintained
                    temp = COLD;
                    // Stop the heating
                    _program.StopHeating();
                }
            }
            break;

        // This state handles sinking the water
        case Sink:
            // Set temperature to be maintained
            temp = COLD;
            // If the water tank had been emptied
            if (_program.Sink())
            {
                // If this is the second time sinking the water
                if (stage == 1)
                {
                    /* Set this bool to true so we can step out
                    of the loop */
                    trig = true;
                    // Set the program state to Centrifuge
                    programState = Centrifuge;
                }
                // If this is the first time sinking the water
                if (stage == 0)
                {
                    /* Increment this counter. It has been explained
                    in the beginning of this stte machine */
                    stage++;
                    /* Reset this counter for further use */
                    tankReps = 0;
                    // Set the state to FillUpTank
                    washingState = FillUpTank;
                }
            }
            break;

        /* This state handles the behaviour of the machine 
        if the pressure has dropped */
        case Waiting:
            // Blink the led indicating which program had been selected
            _program.BlinkProgramLed();
            break;

        default:
            Serial.println("Error in PreWashStateMachine()");
            break;
        }
    }
}

// This state mahine handles the Centrifuge state of any washing proccess
void Controller::CentrifugeStateMachine()
{
    Serial.println("--- CENETRIFUGE ---");
    // Set the inital state to Sink
    washingState = Sink;
    /* By now this trigger boolean should be familliar,
    if not read the description for the previous state machine */
    bool trig = false;
    /* How many times the tank has executed the rotating clockwise +
    counterclockwise routine */
    int tankReps = 0;
    while (!trig)
    {
        // Read the buttons every loop cycle
        _program.InputPolling();
        switch (washingState)
        {
        // This state handles rotating the tank clockwise
        case RotateClockwise:
            // Keeping the sink turned on
            _program.Sink();
            /* If the tank had been rotate for long enough */
            if (_program.Rotate(CLOCKWISE, MEDIUMSPEED, ROTATETIME))
            {
                // Set the state to RotateCounterclockwise
                washingState = RotateCounterclockwise;
                /* Save the current time which gets used by the
                motor handler in order to keep rotating the tank
                for specific time period */
                _program.SaveTimeMotorManager();
            }
            break;

        // This state handles rotating the tank counterclockwise
        case RotateCounterclockwise:
            // Keeping the sink turned on
            _program.Sink();
            /* If the tank had been rotate for long enough */
            if (_program.Rotate(COUNTERCLOCKWISE, MEDIUMSPEED, ROTATETIME))
            {
                /* Increment the counter. Its use had been explained
                in the beginning of the state machine */
                tankReps++;
                // If the motor routine hadn't been executed enough times
                if (tankReps < _washingProgram.CentrifugeRotations())
                {
                     /* Save the current time which gets used by the
                    motor handler in order to keep rotating the tank
                    for specific time period */
                    _program.SaveTimeMotorManager();
                    // Set the state to RotateClockwise
                    washingState = RotateClockwise;
                }
                // If the motor routine had been executed enough times
                if (tankReps == _washingProgram.CentrifugeRotations())
                {
                    /* Set the state to sinking */
                    washingState = Sink;
                }
            }
            break;

        // This state handles sinking the water
        case Sink:
            // If the water tank had been emptied
            if (_program.Sink())
            {
                /* Save the current time which gets used by the
                motor handler in order to keep rotating the tank
                for specific time period */
                _program.SaveTimeMotorManager();
                // Set the state to RotateClockwise
                washingState = RotateClockwise;
                // If the motor routine had been executed enough times
                if (tankReps == _washingProgram.CentrifugeRotations())
                {
                    /* Set the trig to true so we can step out
                    of the loop */
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

/* State machine to handle force quitting the current program 
if the pressure has dropped and 10 minutes have passed*/
void Controller::ForceQuitStateMachine()
{
    // Very familiar bool?
    bool trig = false;
    // Set the initial state to sinking
    washingState = Sink;
    while (!trig)
    {
        // Read the buttons every loop cycle
        _program.InputPolling();
        // If the tank had is empty
        if (_program.Sink())
        {
            Serial.println("Dirty water has been sinked and the current program has been exited!");
            /* Set the trig to true so we can step out of the loop*/
            trig = true;
        }
    }
}

/* This method handles chenking change in the pressure*/
void Controller::SecurityCheckUp(bool *trig)
{
    // read the pressure
    switch (_program.SecurityFallBack())
    {
    // if te pressure hasnt come back after 10 mins
    case -1:
        /* Set this trig to true so the loop that called
        this method can be stepped out of*/
        *trig = true;
        // Set the program state to ForceQuit
        programState = ForceQuit;
        break;

    /* If the pressure has dropped and 10 minutes havent 
    yet passed */
    case 0:
        // If this it just dropped
        if (washingState != Waiting)
        {
            Serial.println("Pressure dropped! Entering Waiting state.");
            //_program.SaveTimeSecurityManager();
            // Stop the drain
            _program.StopDrain(true);
            // Save the current washing state
            lastWashingState = washingState;
            // Set the washing state to Waiting
            washingState = Waiting;
        }
        break;
    /* If the pressure is one */
    case 1:
        // If it just came back
        if (washingState == Waiting)
        {
            Serial.println("Pressure came back!");
            /* Set the washing state to the one before the 
            pressure dropped, so the washing process can resume
            where it laststopped */
            washingState = lastWashingState;
        }
        break;

    default:
        Serial.println(" Error checking if in save mode");
        break;
    }
}