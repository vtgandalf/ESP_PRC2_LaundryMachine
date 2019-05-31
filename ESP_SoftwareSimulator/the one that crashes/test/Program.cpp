#include "Program.h"

void Program::Setup()
{
	_hardwareControl.HardwareControlSetup();
	program = 0;
	SetLeds(program);
}

WashingProgram Program::PreProgram()
{
	// to be implemented
	//serial.println("Waiting for coins, soap, program selection and etc...");
	bool trig = false;
	while (trig != true)
	{
		 

		////serial.println("PreProgram loop");
		// update input
		//_inputManager.Polling();

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
			if (_coinHandler.AreCoinsEnough(programs[program].Price()) & _soapHandler.IsSoapEnough(2, 3) & _securityManager.IsEverythingClosed() & _securityManager.IsPressureOn() & program != -1)
			{
				trig = true;
				_coinHandler.UseCoins(programs[program].Price());
				_securityManager.LockDoor();
				//serial.print("Program ");
				//serial.print(program);
				//serial.println(" is about to start!");
			}
			else
			{
				//serial.println("You cant start the program yet!");
			}
		}
	}
	return programs[program];
}

void Program::ExecProgram(WashingProgram program)
{
	//serial.println("Program has been started.");
	// to be implemented
	PreWash(program.PreWashTemp());
	MainWash(program.MainWashWaterLevel(), program.MainWashTemp(), program.MainWashRotations());
	Centrifuge(program.CentrifugeRotations());
}

void Program::PreWash(Temp temperature)
{
	// to be implemented
	// fill water at least 50%
	//if (!_waterManager.FillUpWater(ALMOSTFULL, program, &_securityManager))
	if (!_waterManager.FillUpWater(ALMOSTFULL))
	{
		//serial.println("Program exiting due to lack of pressure");
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
				//serial.println("Error: soap 1 out of range, something went wrong!");
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
				//serial.println("Error: soap 1 out of range, something went wrong!");
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
			//serial.println("Error: the tank does not have enough water");
			//serial.println("Action: Fill up the tank");
			//if (!_waterManager.FillUpWater(ALMOSTFULL, program, &_securityManager))
			if (!_waterManager.FillUpWater(ALMOSTFULL))
			{
				//serial.println("Program exiting due to lack of pressure");
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
	//if (!_waterManager.FillUpWater(waterLevel, program, &_securityManager))
	if (!_waterManager.FillUpWater(waterLevel))
	{
		//serial.println("Program exiting due to lack of pressure");
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
				//serial.println("Error: soap 2 out of range, something went wrong!");
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
				//serial.println("Error: soap 2 out of range, something went wrong!");
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
			//serial.println("Error: the tank does not have enough water");
			//serial.println("Actio: Fill up the tank");
			//if (!_waterManager.FillUpWater(ALMOSTFULL, program, &_securityManager))
			if (!_waterManager.FillUpWater(ALMOSTFULL))
			{
				//serial.println("Program exiting due to lack of pressure");
				_waterManager.EmptyWaterTank();
				return;
			}
		}
	}
	// REPEAT the following *numberOfRepetitions
	for (int i = 0; i < numberOfRepetitions; i++)
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
	//if (!_waterManager.FillUpWater(ALMOSTEMPTY, program, &_securityManager))
	if (!_waterManager.FillUpWater(ALMOSTEMPTY))
	{
		//serial.println("Program exiting due to lack of pressure");
		_waterManager.EmptyWaterTank();
		return;
	}
	// no heating
	_heaterHandler.StopHeating();
	// REPEAT the following *numberOfRepetitions
	for (int i = 0; i < numberOfRepetitions; i++)
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
	for (int i = 0; i < numberOfRepetitions; i++)
	{
		// rotate clockwise, highspeed, 30s
		_motorManager.Rotate(CLOCKWISE, HIGHSPEED, 30);
		// rotate anticlockwise, highspeed, 30s
		_motorManager.Rotate(COUNTERCLOCKWISE, HIGHSPEED, 30);
	}
}

void Program::ReadProgramButton()
{
	if (iprogramPtr->ProgramAction())
	{
		if (program <= 1)
		{
			program++;
		}
		else
		{
			program = 0;
		}
		SetLeds(program);
		//serial.println(program);
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
		iprogramPtr->SetProgramLed(prog + 1);
	}
}

bool Program::FillUpWater(WaterLevel waterLevel)
{
	return _waterManager.FillUpWater(waterLevel);
}

void Program::AddSoap1()
{
	// add soap1
	if (_waterManager.Drain())
	{
		if (_securityManager.IsWaterLevelSafe())
		{
			if (!_soapHandler.UseSoap1(2))
			{
				//serial.println("Error: soap 1 out of range, something went wrong!");
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
				//serial.println("Error: soap 1 out of range, something went wrong!");
			}
		}
	}
	_waterManager.SetDrain(false);
}

void Program::AddSoap2()
{
	// add soap2
	if (_waterManager.Drain())
	{
		if (_securityManager.IsWaterLevelSafe())
		{
			if (!_soapHandler.UseSoap2(3))
			{
				//serial.println("Error: soap 2 out of range, something went wrong!");
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
				//serial.println("Error: soap 2 out of range, something went wrong!");
			}
		}
	}
	_waterManager.SetDrain(false);
}

bool Program::HeatUp(Temp temp)
{
	return _heaterHandler.HeatUp(temp);
}

void Program::StopHeating()
{
	// no heating
	_heaterHandler.StopHeating();
}

bool Program::Rotate(Rotation direction, Speed speed, int seconds)
{
	return _motorManager.Rotate(direction, speed, seconds);
}

bool Program::Sink()
{
	// sink
	return _waterManager.EmptyWaterTank();
}

void Program::InputPolling()
{
	// update input
	//_inputManager.Polling();

	// get coins
	_coinHandler.Polling();

	// get soap
	_soapHandler.Polling();
}

void Program::SaveTimeMotorManager()
{
	_motorManager.SaveTime();
}

int Program::SecurityFallBack()
{
	return _securityManager.SafeMode();
}

void Program::SaveTimeSecurityManager()
{
	_securityManager.SaveTime();
}

void Program::BlinkProgramLed()
{
	iprogramPtr->SetProgramLed(0);
	//delay(500);
	iprogramPtr->SetProgramLed(program + 1);
	//delay(500);
}

void Program::StopDrain(bool boolean)
{
	_waterManager.SetDrain(!boolean);
}

void Program::UnlockDoor()
{
	_securityManager.UnlockDoor();
}