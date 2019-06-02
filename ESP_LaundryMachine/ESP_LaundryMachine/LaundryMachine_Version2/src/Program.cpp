#include "../lib/Program.h"

// This method handles setting up the class instance
void Program::Setup()
{
    // Initialize the Centipede library
    _hardwareControl.HardwareControlSetup();
    // Set the chosen program to the first one
    program = 0;
    // Manage the leds according to the chosen program
    SetLeds(program);
}

// This mehtod handles reading the coins, soap, and etc.
WashingProgram Program::PreProgram()
{
    Serial.println("Waiting for coinsw, soap, program selection and etc...");
    // On this bool depends how long we are going to stay in the loop
    bool trig = false;
    while (trig != true)
    {
        // update input
        _inputManager.Polling();

        // get coins
        _coinHandler.Polling();

        // get soap
        _soapHandler.Polling();

        // get program
        ReadProgramButton();

        // PRESS START BUTTONS
        if (ReadStartButton())
        {
            /* IF:
                - Enough coins have been inserted
                - Enough soap had been inserted
                - Is everything closed
                - Is the pressure on
                - If a program had been chosen */
            if (_coinHandler.AreCoinsEnough(programs[program].Price()) & _soapHandler.IsSoapEnough(2, 3) & _securityManager.IsEverythingClosed() & _securityManager.IsPressureOn() & program != -1)
            {
                /* Set the trig to bool so we can step out of the loop*/
                trig = true;
                // Take what we need from the coins
                _coinHandler.UseCoins(programs[program].Price());
                // Lock the door
                _securityManager.LockDoor();
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
    // return the chosen program
    return programs[program];
}

// Method for handling the program button action
void Program::ReadProgramButton()
{
    // If the program button had been pressed
    if (iprogramPtr->ProgramAction())
    {
        // If this the previously chosen program is 0 or 1
        if (program <= 1)
        {
            // change it to the next one
            program++;
        }
        // If the previously chosenprogram is 2
        else
        {
            // chenge it to 0 (the first one)
            program = 0;
        }
        // Update the leds
        SetLeds(program);
        Serial.print("Chosen program: ");
        Serial.println(program);
    }
}

// Show if the start button had been pressed
bool Program::ReadStartButton()
{
    return iprogramPtr->StartAction();
}

// Method to update the program leds
void Program::SetLeds(int prog)
{
    // if program in range
    if ((prog >= 0) && (prog <= 2))
    {
        iprogramPtr->SetProgramLed(prog + 1);
    }
}

// Pass through the FillingUpWaterMethod
bool Program::FillUpWater(WaterLevel waterLevel)
{
    return _waterManager.FillUpWater(waterLevel);
}

// Method that handles adding Soap1 to water
void Program::AddSoap1()
{
    // If water is running
    if (_waterManager.Drain())
    {
        // If the water level high enough
        if (_securityManager.IsWaterLevelSafe())
        {
            // Add the soap and if it fails throw an error message
            if (!_soapHandler.UseSoap1(2))
            {
                Serial.println("Error: soap 1 out of range, something went wrong!");
            }
        }
    }
    // If water is not running
    else
    {
        // Make sure it is
        _waterManager.SetDrain(true);
        // If the water level is hoigh enough
        if (_securityManager.IsWaterLevelSafe())
        {
            // Add the soap and if it fails throuw an erro message
            if (!_soapHandler.UseSoap1(2))
            {
                Serial.println("Error: soap 1 out of range, something went wrong!");
            }
        }
    }
    // Stop the drain
    _waterManager.SetDrain(false);
}

// Method that handles adding Soap1 to water
void Program::AddSoap2()
{
    // If water is running
    if (_waterManager.Drain())
    {
        // If the water level high enough
        if (_securityManager.IsWaterLevelSafe())
        {
            // Add the soap and if it fails throw an error message
            if (!_soapHandler.UseSoap2(3))
            {
                Serial.println("Error: soap 2 out of range, something went wrong!");
            }
        }
    }
    // If water is not running
    else
    {
        // Make sure it is
        _waterManager.SetDrain(true);
        // If the water level is hoigh enough
        if (_securityManager.IsWaterLevelSafe())
        {
            // Add the soap and if it fails throuw an erro message
            if (!_soapHandler.UseSoap2(3))
            {
                Serial.println("Error: soap 2 out of range, something went wrong!");
            }
        }
    }
    // Stop the drain
    _waterManager.SetDrain(false);
}

/* Call the HeatUp method from the heater handler and 
pass through the response */
bool Program::HeatUp(Temp temp)
{
    return _heaterHandler.HeatUp(temp);
}

/* Call the StopHeating method from the heater handler */
void Program::StopHeating()
{
    _heaterHandler.StopHeating();
}

/* Call the Rotate method from the motor manager and
pass through the response */
bool Program::Rotate(Rotation direction, Speed speed, int seconds)
{
    return _motorManager.Rotate(direction, speed, seconds);
}

/* Call the Sink method from the water manager and pass through
the response */
bool Program::Sink()
{
    return _waterManager.EmptyWaterTank();
}

/* Call the Polling methods from the input manager and
the coin handler */
void Program::InputPolling()
{
    // update input
    _inputManager.Polling();

    // get coins
    _coinHandler.Polling();
}

/* Call the SaveTime method from the motor manager */
void Program::SaveTimeMotorManager()
{
    _motorManager.SaveTime();
}

/* Call the SaveMode method from the security manager
and pass through the response */
int Program::SecurityFallBack()
{
    return _securityManager.SafeMode();
}

/* Call the SaveTime method from the security manager */
void Program::SaveTimeSecurityManager()
{
    _securityManager.SaveTime();
}

/* Method that handles blinking the program led */
void Program::BlinkProgramLed()
{
    iprogramPtr->SetProgramLed(0);
    delay(500);
    iprogramPtr->SetProgramLed(program+1);
    delay(500);
}

/* Call the SetDrain method from the water manager
and pass htrough the response */
void Program::StopDrain(bool boolean)
{
    _waterManager.SetDrain(!boolean);
}

/* Call the UnlcokDoor method from the security manager
and pass through the response */
void Program::UnlockDoor()
{
    _securityManager.UnlockDoor();
}