#include "../lib/Program.h"

WashingProgram Program::PreProgram()
{
    _hardwareControl.HardwareControlSetup();
    // to be implemented
    Serial.println("Waiting for coins, soap, program selection and etc...");
    bool trig = false;
    while (trig != true)
    {
        //Serial.println("PreProgram loop");
        // update input
        _inputManager.Polling();

        // get coins
        _coinHandler.Polling();

        // get soap
        _soapHandler.Polling();

        // lock door
        _securityManager.Polling();

        // get program
        ReadProgramButton();

        // PRESS START BUTTONS
        if (ReadStartButton())
        {
            if (_coinHandler.AreCoinsEnough(programs[program].price) && _soapHandler.IsSoapEnough(2, 3) && _securityManager.IsEverythingClosed())
            {
                trig = true;
                Serial.print("Program ");
                Serial.print(program);
                Serial.println(" is about to start!");
            }
            else
            {
                Serial.println("You cant start the program yet!");
            }
        }
    }
    return programs[program];
}

void Program::ExecProgram(WashingProgram program)
{
    Serial.println("Program has been started.");
    // to be implemented
    PreWash(program.preWashTemp);
    MainWash(program.mainWashWaterLevel, program.mainWashTemp, program.mainWashRotations);
    Centrifuge(program.centrifugeRotations);
}

void Program::PreWash(Temp temperature)
{
    // to be implemented

    // fill water at least 50%
    if (!_waterManager.FillUpWater(ALMOSTFULL, program, &_securityManager))
    {
        Serial.println("Program exiting due to lack of pressure");
        _waterManager.EmptyWaterTank();
        return;
    }

    // add soap1
    if (_waterManager.Drain())
    {
        if (_securityManager.IsWaterLevelSafe())
        {
            if (!_soapHandler.UseSoap1(2))
            {
                Serial.println("Error: soap 1 out of range, something went wrong!");
            }
        }
    }
    else
    {
        _waterManager.SetDrain(true);
        if (_securityManager.IsWaterLevelSafe())
        {
            if (!_soapHandler.UseSoap1(2))
            {
                Serial.println("Error: soap 1 out of range, something went wrong!");
            }
        }
    }
    _waterManager.SetDrain(false);

    // heatup until temp >= temperature
    bool trig = false;
    while (trig != true)
    {
        if (_securityManager.IsWaterLevelSafe())
        {
            _heaterHandler.HeatUp(temperature);
            trig = true;
        }
        else
        {
            Serial.println("Error: the tank does not have enough water");
            Serial.println("Action: Fill up the tank");
            if (!_waterManager.FillUpWater(ALMOSTFULL, program, &_securityManager))
            {
                Serial.println("Program exiting due to lack of pressure");
                _waterManager.EmptyWaterTank();
                return;
            }
        }
    }

    // rotate clockwise, lowspeed, 60s
    _motorManager.Rotate(CLOCKWISE, LOWSPEED, 60);

    // rotate anticlockwise, lowspeed, 60s
    _motorManager.Rotate(COUNTERCLOCKWISE, LOWSPEED, 60);

    // sink
    _waterManager.EmptyWaterTank();
}

void Program::MainWash(WaterLevel waterLevel, Temp temperature, int numberOfRepetitions)
{
    // to be implemented

    // fill water until >= waterLevel
    if (!_waterManager.FillUpWater(waterLevel, program, &_securityManager))
    {
        Serial.println("Program exiting due to lack of pressure");
        _waterManager.EmptyWaterTank();
        return;
    }
    // add soap2
    if (_waterManager.Drain())
    {
        if (_securityManager.IsWaterLevelSafe())
        {
            if (!_soapHandler.UseSoap2(3))
            {
                Serial.println("Error: soap 2 out of range, something went wrong!");
            }
        }
    }
    else
    {
        _waterManager.SetDrain(true);
        if (_securityManager.IsWaterLevelSafe())
        {
            if (!_soapHandler.UseSoap2(3))
            {
                Serial.println("Error: soap 2 out of range, something went wrong!");
            }
        }
    }
    _waterManager.SetDrain(false);

    // heatup until >= temperature
    bool trig = false;
    while (trig != true)
    {
        if (_securityManager.IsWaterLevelSafe())
        {
            _heaterHandler.HeatUp(temperature);
            trig = true;
        }
        else
        {
            Serial.println("Error: the tank does not have enough water");
            Serial.println("Actio: Fill up the tank");
            if (!_waterManager.FillUpWater(ALMOSTFULL, program, &_securityManager))
            {
                Serial.println("Program exiting due to lack of pressure");
                _waterManager.EmptyWaterTank();
                return;
            }
        }
    }

    // REPEAT the following *numberOfRepetitions
    for(int i=0; i<numberOfRepetitions; i++)
    {
        // rotate clockwise, medspeed, 60s
        _motorManager.Rotate(CLOCKWISE, MEDIUMSPEED, 60);
        // rotate anticlockwise, medspeed, 60s
        _motorManager.Rotate(COUNTERCLOCKWISE, MEDIUMSPEED, 60);
    }
    
    // no heating
    _heaterHandler.StopHeating();

    // sink water until empty
    _waterManager.EmptyWaterTank();

    ///////////////////////////////////////////////

    // fill water until >= 50%
    if (!_waterManager.FillUpWater(ALMOSTEMPTY, program, &_securityManager))
    {
        Serial.println("Program exiting due to lack of pressure");
        _waterManager.EmptyWaterTank();
        return;
    }

    // no heating
    _heaterHandler.StopHeating();

    // REPEAT the following *numberOfRepetitions
    for(int i=0; i<numberOfRepetitions; i++)
    {
        // rotate clockwise, medspeed, 60s
        _motorManager.Rotate(CLOCKWISE, MEDIUMSPEED, 60);
        // rotate anticlockwise, medspeed, 60s
        _motorManager.Rotate(COUNTERCLOCKWISE, MEDIUMSPEED, 60);
    }

    // sink water until empty
    _waterManager.EmptyWaterTank();
}

void Program::Centrifuge(int numberOfRepetitions)
{
    // to be implemented

    // sink
    _waterManager.EmptyWaterTank();
    // REPEAT the following *numberOfRepetitions
    for(int i=0; i<numberOfRepetitions; i++)
    {
        // rotate clockwise, highspeed, 30s
        _motorManager.Rotate(CLOCKWISE, HIGHSPEED, 30);
        // rotate anticlockwise, highspeed, 30s
        _motorManager.Rotate(COUNTERCLOCKWISE, HIGHSPEED, 30);
    }
}

void Program::ReadProgramButton()
{
    if(iprogramPtr->ProgramAction())
    {
        if (program <= 1)
        {
            program++;
        }
        else
        {
            program = 0;
        }
        Serial.println(program);
    }
}

bool Program::ReadStartButton()
{
    return iprogramPtr->StartAction();
}

void Program::SetLeds(int prog)
{
    if ((prog >= 0) && (prog <= 2))
    {
        iprogramPtr->SetProgramLed(prog);
    }
}