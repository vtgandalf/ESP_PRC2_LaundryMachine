#include "HardwareControl.h"

#define BitMaskEmpty 0x00
#define BitMaskClear 0x1E
#define BitMaskCoin10 0x18
#define BitMaskProgram 0x19
#define BitMaskCoin50 0x14
#define BitMaskCoin200 0x12
#define BitMaskStart 0x11
#define BitMaskDoorlock 0x08
#define BitMaskSoap2 0x04
#define BitMaskSoap1 0x02
#define BitMaskPressure 0x01
#define BitMaskKeyselect 0x10

#define BitMaskTempCold 0x00
#define BitMaskTempWarm 0x01
#define BitMaskTempWarmer 0x02
#define BitMaskTempHot 0x03

void HardwareControl::HardwareControlSetup()
{
	SetStrobe(false);
	SetKeyselect(true);
	SetBuzzer(false);
	SetHeater(false);
	SetSpeed(OFF);
	SetSoap1Led(false);
	SetSoap2Led(false);
	SetRotation(CLOCKWISE);
	SetSink(false);
	SetDrain(false);
	SetLock(false);
	SetCoin10Led(0);
	SetCoin50Led(0);
	SetCoin200Led(0);
}

HardwareControl *HardwareControl::instance = 0;

HardwareControl *HardwareControl::GetInstance()
{
	if (instance == 0)
	{
		instance = new HardwareControl();
	}
	return instance;
}

bool HardwareControl::Buzzer()
{
	return buzzer;
}

bool HardwareControl::Drain()
{
	return drain;
}

bool HardwareControl::Heater()
{
	return heater;
}

bool HardwareControl::Lock()
{
	return lock;
}

bool HardwareControl::Sink()
{
	return sink;
}

bool HardwareControl::Keyselect()
{
	return keyselect;
}

bool HardwareControl::Strobe()
{
	return strobe;
}

Rotation HardwareControl::CurentRotation()
{
	return rotation;
}

Speed HardwareControl::CurentSpeed()
{
	return speed;
}

bool HardwareControl::Soap1()
{
	return soap1;
}

bool HardwareControl::Soap2()
{
	return soap2;
}

char HardwareControl::Coin10()
{
	char temp = 0;
	if (coins10LedsArray[0] == true) {
		temp = temp | 0b001;
	}
	if (coins10LedsArray[1] == true) {
		temp = temp | 0b010;
	}
	if (coins10LedsArray[2] == true) {
		temp = temp | 0b100;
	}
	return temp;
}

char HardwareControl::Coin50()
{
	char temp = 0;
	if (coins50LedsArray[0] == true) {
		temp = temp | 0b001;
	}
	if (coins50LedsArray[1] == true) {
		temp = temp | 0b010;
	}
	if (coins50LedsArray[2] == true) {
		temp = temp | 0b100;
	}
	return temp;
}

char HardwareControl::Coin200()
{
	char temp = 0;
	if (coins200LedsArray[0] == true) {
		temp = temp | 0b01;
	}
	if (coins200LedsArray[1] == true) {
		temp = temp | 0b10;
	}
	return temp;
}

char HardwareControl::Program()
{
	char temp = 0;
	if (programLedsArray[0] == true) {
		temp = temp | 0b001;
	}
	if (programLedsArray[1] == true) {
		temp = temp | 0b010;
	}
	if (programLedsArray[2] == true) {
		temp = temp | 0b100;
	}
	return temp;
}

void HardwareControl::SetStrobe(bool boolean)
{
	strobe = boolean;
}

void HardwareControl::SetHeater(bool boolean)
{
	heater = boolean;
}

void HardwareControl::SetBuzzer(bool boolean)
{
	buzzer = boolean;
}

void HardwareControl::SetSpeed(Speed motorSpeed)
{
	switch (motorSpeed)
	{
	case HIGHSPEED:
		OUT_SPEED2 = false;
		OUT_SPEED1 = false;
		break;

	case MEDIUMSPEED:
		OUT_SPEED2 = false;
		OUT_SPEED1 = true;
		break;

	case LOWSPEED:
		OUT_SPEED2 = true;
		OUT_SPEED1 = false;
		break;

	case OFF:
		OUT_SPEED2 = true;
		OUT_SPEED1 = true;
		break;

	default:
		break;
	}
	speed = motorSpeed;
}

void HardwareControl::SetLock(bool boolean)
{
	lock = boolean;
}

void HardwareControl::SetDrain(bool boolean)
{
	drain = boolean;
}

void HardwareControl::SetSink(bool boolean)
{
	sink = boolean;
}

void HardwareControl::SetRotation(Rotation tankRotation)
{
	switch (tankRotation)
	{
	case CLOCKWISE:
		OUT_MOTOR_RL = false;
		break;

	case COUNTERCLOCKWISE:
		OUT_MOTOR_RL = true;
		break;

	default:
		break;
	}
	rotation = tankRotation;
}

void HardwareControl::SetKeyselect(bool boolean)
{
	keyselect = boolean;
}

void HardwareControl::SetCoin10Led(int x)
{
	switch (x)
	{
	case 0:
		coins10LedsArray[0] = false;
		coins10LedsArray[1] = false;
		coins10LedsArray[2] = false;
		break;

	case 1:
		coins10LedsArray[0] = true;
		coins10LedsArray[1] = false;
		coins10LedsArray[2] = false;
		break;

	case 2:
		coins10LedsArray[0] = true;
		coins10LedsArray[1] = true;
		coins10LedsArray[2] = false;
		break;

	case 3:
		coins10LedsArray[0] = true;
		coins10LedsArray[1] = true;
		coins10LedsArray[2] = true;
		break;

	default:
		break;
	}
}

void HardwareControl::SetCoin50Led(int x)
{
	switch (x)
	{
	case 0:
		coins50LedsArray[0] = false;
		coins50LedsArray[1] = false;
		coins50LedsArray[2] = false;
		break;

	case 1:
		coins50LedsArray[0] = true;
		coins50LedsArray[1] = false;
		coins50LedsArray[2] = false;
		break;

	case 2:
		coins50LedsArray[0] = true;
		coins50LedsArray[1] = true;
		coins50LedsArray[2] = false;

		break;

	case 3:
		coins50LedsArray[0] = true;
		coins50LedsArray[1] = true;
		coins50LedsArray[2] = true;
		break;

	default:
		break;
	}
}

void HardwareControl::SetCoin200Led(int x)
{
	switch (x)
	{
	case 0:
		coins200LedsArray[0] = false;
		coins200LedsArray[1] = false;
		break;

	case 1:
		coins200LedsArray[0] = true;
		coins200LedsArray[1] = false;
		break;

	case 2:
		coins200LedsArray[0] = true;
		coins200LedsArray[1] = true;
		break;

	default:
		break;
	}
}

void HardwareControl::SetSoap2Led(bool boolean)
{
	soap2 = boolean;
}

void HardwareControl::SetSoap1Led(bool boolean)
{
	soap1 = boolean;
}

void HardwareControl::SetProgramLed(int x)
{
	switch (x)
	{
	case 1:
		OUT_GROUP2 = 1;
		OUT_GROUP1 = 1;
		programLedsArray[0] = true;
		programLedsArray[1] = false;
		programLedsArray[2] = false;

		break;

	case 2:
		OUT_GROUP2 = 1;
		OUT_GROUP1 = 1;
		programLedsArray[0] = false;
		programLedsArray[1] = true;
		programLedsArray[2] = false;

		break;

	case 3:
		OUT_GROUP2 = 1;
		OUT_GROUP1 = 1;
		programLedsArray[0] = false;
		programLedsArray[1] = false;
		programLedsArray[2] = true;

		break;

	default:
		OUT_GROUP2 = 1;
		OUT_GROUP1 = 1;
		programLedsArray[0] = false;
		programLedsArray[1] = false;
		programLedsArray[2] = false;
		break;
	}
}

/* PUBLIC GETTERS */
Temp HardwareControl::GetTemperature()
{
	switch (heaterTemp)
	{
	case BitMaskTempCold:
		return COLD;
		break;

	case BitMaskTempWarm:
		return WARM;
		break;

	case BitMaskTempWarmer:
		return WARMER;
		break;

	case BitMaskTempHot:
		return HOT;
		break;

	default:
		return COLD;
		break;
	}
}

WaterLevel HardwareControl::GetWaterLevel()
{
	switch (waterLevel)
	{
	case 0:
		return EMPTY;
		break;

	case 1:
		return ALMOSTEMPTY;
		break;

	case 2:
		return ALMOSTFULL;
		break;

	case 3:
		return FULL;
		break;

	default:
		return EMPTY;
		break;
	}
}

char HardwareControl::GetRawInputByte()
{
	return inputReadings;
}

void HardwareControl::SetGlobalInputByte(char data)
{
	inputReadings = data;
}

char HardwareControl::GetGlobalInputByte()
{
	return inputReadings;
}


/*
bool HardwareControl::CheckSwitchClick(char bitm, char key, char in, char prev)
{
  bool response = false;
  if ((in | bitm) == in)
  {
	if ((in | key) != in)
	{
	  response = true;
	  if (prev == bitm)
	  {
		if (in == bitm)
		{
		  response = true;
		}
	  }
	  if ((prev | bitm) != prev)
	  {
		response = true;
	  }
	}
  }
  return response;
}
*/

bool HardwareControl::CheckSimpleClick(char bitm, char in)
{
	bool response = false;
	if (bitm == in)
	{
		response = true;
	}
	return response;
}
/*
bool HardwareControl::CheckSwitchSoapClick(byte bitm, byte key, byte in, byte *prev)
{
  bool response = false;
  if ((in | bitm) == in)
  {
	if ((in | key) != in)
	{
	  //////serial.println(*prev, BIN);
	  //response = true;
	  if (*prev == bitm)
	  {
		if (in == bitm)
		{
		  response = true;
		}
	  }
	  if ((*prev | bitm) != *prev)
	  {
		response = true;
	  }
	  /*if ((*prev == (BitMaskSoap1 | BitMaskSoap2))&((in | *prev) != in))
	  {
		if(bitm == BitMaskSoap1)
		{
		  *prev = (*prev & ~BitMaskSoap2);
		}
		if(bitm == BitMaskSoap2)
		{
		  *prev = (*prev & ~BitMaskSoap1);
		}
		//*prev = 0x00;
		//////serial.println(GetGlobalInputByte(),BIN);
		//////serial.println(*prev, BIN);
	  }
	}
  }

  //////serial.print(GetGlobalInputByte(), BIN);
  //////serial.print("  ");
  //////serial.println(previousByteSwitches, BIN);
  return response;
}
*/


bool HardwareControl::Soap1Action()
{
	//bool response = CheckSwitchSoapClick(BitMaskSoap1, BitMaskKeyselect, GetGlobalInputByte(), &previousByteSwitches);
	//bool response = CheckSwitchClick(BitMaskSoap1, BitMaskKeyselect, GetGlobalInputByte(), previousByteSwitches);
	bool response = CheckSimpleClick(BitMaskSoap1, GetGlobalInputByte());
	if (response)
	{
		//previousByteSwitches = GetGlobalInputByte();
		previousByteButtons = GetGlobalInputByte();
		SetGlobalInputByte(BitMaskEmpty);
	}
	return response;
}

bool HardwareControl::Soap2Action()
{
	//bool response = CheckSwitchSoapClick(BitMaskSoap2, BitMaskKeyselect, GetGlobalInputByte(), &previousByteSwitches);
	//bool response = CheckSwitchClick(BitMaskSoap2, BitMaskKeyselect, GetGlobalInputByte(), previousByteSwitches);
	bool response = CheckSimpleClick(BitMaskSoap2, GetGlobalInputByte());
	if (response)
	{
		//previousByteSwitches = GetGlobalInputByte();
		previousByteButtons = GetGlobalInputByte();
		SetGlobalInputByte(BitMaskEmpty);
	}
	return response;
}

bool HardwareControl::DoorAction()
{
	//bool response = CheckSwitchClick(BitMaskDoorlock, BitMaskKeyselect, GetGlobalInputByte(), previousByteSwitches);
	bool response = CheckSimpleClick(BitMaskDoorlock, GetGlobalInputByte());
	if (response)
	{
		//previousByteSwitches = GetGlobalInputByte();
		previousByteButtons = GetGlobalInputByte();
		SetGlobalInputByte(BitMaskEmpty);
	}
	return response;
}

bool HardwareControl::PressureAction()
{
	//bool response = CheckSwitchClick(BitMaskPressure, BitMaskKeyselect, GetGlobalInputByte(), previousByteSwitches);
	bool response = CheckSimpleClick(BitMaskPressure, GetGlobalInputByte());
	if (response)
	{
		//previousByteSwitches = GetGlobalInputByte();
		previousByteButtons = GetGlobalInputByte();
		SetGlobalInputByte(BitMaskEmpty);
	}
	return response;
}

bool HardwareControl::Coin10Action()
{
	//bool response = CheckButtonClick(BitMaskCoin10, GetGlobalInputByte(), previousByteButtons);
	bool response = CheckSimpleClick(BitMaskCoin10, GetGlobalInputByte());
	if (response)
	{
		previousByteButtons = GetGlobalInputByte();
		SetGlobalInputByte(BitMaskEmpty);
	}
	return response;
}

bool HardwareControl::Coin50Action()
{
	//bool response = CheckButtonClick(BitMaskCoin50, GetGlobalInputByte(), previousByteButtons);  
	bool response = CheckSimpleClick(BitMaskCoin50, GetGlobalInputByte());
	if (response)
	{
		previousByteButtons = GetGlobalInputByte();
		SetGlobalInputByte(BitMaskEmpty);
	}
	return response;
}

bool HardwareControl::Coin200Action()
{
	//bool response = CheckButtonClick(BitMaskCoin200, GetGlobalInputByte(), previousByteButtons);
	bool response = CheckSimpleClick(BitMaskCoin200, GetGlobalInputByte());
	if (response)
	{
		previousByteButtons = GetGlobalInputByte();
		SetGlobalInputByte(BitMaskEmpty);
	}
	return response;
}

bool HardwareControl::ClearAction()
{
	//bool response = CheckButtonClick(BitMaskClear, GetGlobalInputByte(), previousByteButtons);
	bool response = CheckSimpleClick(BitMaskClear, GetGlobalInputByte());
	if (response)
	{
		previousByteButtons = GetGlobalInputByte();
		SetGlobalInputByte(BitMaskEmpty);
	}
	return response;
}

bool HardwareControl::ProgramAction()
{
	//bool response = CheckButtonClick(BitMaskProgram, GetGlobalInputByte(), previousByteButtons);
	bool response = CheckSimpleClick(BitMaskProgram, GetGlobalInputByte());
	if (response)
	{
		previousByteButtons = GetGlobalInputByte();
		SetGlobalInputByte(BitMaskEmpty);
	}
	return response;
}

bool HardwareControl::StartAction()
{
	//bool response = CheckButtonClick(BitMaskStart, GetGlobalInputByte(), previousByteButtons);
	bool response = CheckSimpleClick(BitMaskStart, GetGlobalInputByte());
	if (response)
	{
		previousByteButtons = GetGlobalInputByte();
		SetGlobalInputByte(BitMaskEmpty);
	}
	return response;
}
