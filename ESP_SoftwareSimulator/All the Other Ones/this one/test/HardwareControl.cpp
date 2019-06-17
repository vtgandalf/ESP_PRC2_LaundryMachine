#include "HardwareControl.h"
#include "MyForm.h"

/*#define OUT_GROUP2      0
#define OUT_GROUP1      0
#define OUT_STROBE      2
#define OUT_KEYSELECT   3
#define OUT_BUZZER      4
#define OUT_HEATER      5
#define OUT_SPEED2      6
#define OUT_SPEED1      7
#define OUT_DATAC       8
#define OUT_DATAB       9
#define OUT_DATAA       10
#define OUT_MOTOR_RL    11
#define OUT_SOAP1       12
#define OUT_SINK        13
#define OUT_DRAIN       14
#define OUT_LOCK        15
#define IN_W2           16
#define IN_W1           17
#define IN_T2           18
#define IN_T1           19
#define IN_IN3          20
#define IN_IN2          21
#define IN_IN1          22
#define IN_IN0          23
*/
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
#define BitMaskHeater 0x1F
#define BitMaskKeyselect 0x10

int OUT_GROUP1 = 0;
int OUT_GROUP2 = 0;


void HardwareControl::HardwareControlSetup()
{
  //Serial.begin(9600);
  //Wire.begin();           // start I2C 
  //centipede.initialize();
  /*for (int i = 0; i <= 15; i++)
  {
    centipede.pinMode(i, OUTPUT);
  }
  for (int i = 16; i <= 23; i++)
  {
    centipede.pinMode(i, INPUT);
  }*/
  //centipede.portMode(0, 0b0000000000000000); // set all pins on chip 0 to output (0 to 15)
  //centipede.portMode(1, 0b1111111111111111); // set all pins on chip 1 to output (16 to 31)
  //Serial.write("-centipede has been initalized-");
  //centipede.digitalWrite(OUT_GROUP2, LOW);
  //centipede.digitalWrite(OUT_GROUP1, LOW);
  SetStrobe(false);
  SetKeyselect(true);
  SetBuzzer(false);
  SetHeater(false);
  SetSpeed(OFF);
  //centipede.digitalWrite(OUT_DATAC, LOW);
  //centipede.digitalWrite(OUT_DATAB, LOW);
  //centipede.digitalWrite(OUT_DATAA, LOW);
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

HardwareControl* HardwareControl::instance = 0;

HardwareControl* HardwareControl::GetInstance()
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
  //make the rbs spin faster or slower
  switch (motorSpeed)
  {
    case HIGHSPEED:
      
      break;

    case MEDIUMSPEED:
     
      break;

    case LOWSPEED:
      
      break;

    case OFF:
      
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
      //rb rotating clockwise
      
      break;

    case COUNTERCLOCKWISE:
      //rb rotating counter-clockwise
      break;

    default:
      break;
  }
  rotation = tankRotation;
}

void HardwareControl::SetKeyselect(bool boolean)
{
  if (boolean) keyselect = 1;
  else keyselect = 0;
  
}

void HardwareControl::SetCoin10Led(int x)
{
  switch (x)
  {
    case 0:
      //all rbs are false
      coins10LedsArray[0] = false;
      coins10LedsArray[1] = false;
      coins10LedsArray[2] = false;
     
      break;
      
    case 1:
      //rb1 is true
      coins10LedsArray[0] = true;
      coins10LedsArray[1] = false;
      coins10LedsArray[2] = false;
      
      break;

    case 2:
      //rb1 and 2 are true
      coins10LedsArray[0] = true;
      coins10LedsArray[1] = true;
      coins10LedsArray[2] = false;
      
      break;

    case 3:
      //all rbs are true
      coins10LedsArray[0] = true;
      coins10LedsArray[1] = true;
      coins10LedsArray[2] = true;
      
      break;

    default:
      break;
  }
  OUT_GROUP2 = 0;
  OUT_GROUP1 = 0;
  
}

void HardwareControl::SetCoin50Led(int x)
{
  switch (x)
  {
    case 0:
      //all rbs are false
      coins50LedsArray[0] = false;
      coins50LedsArray[1] = false;
      coins50LedsArray[2] = false;
      
      break;

    case 1:
      //rb1 is true
      coins50LedsArray[0] = true;
      coins50LedsArray[1] = false;
      coins50LedsArray[2] = false;
      
      break;

    case 2:
      //rb1 and 2 are true
      coins50LedsArray[0] = true;
      coins50LedsArray[1] = true;
      coins50LedsArray[2] = false;
      
      break;

    case 3:
      //all rbs are true
      coins50LedsArray[0] = true;
      coins50LedsArray[1] = true;
      coins50LedsArray[2] = true;
      
      break;

    default:
      break;
  }
  OUT_GROUP2 = 0;
  OUT_GROUP1 = 1;

  
}

void HardwareControl::SetCoin200Led(int x)
{
  switch (x) //counter
  {
    case 0:
      //all rb is false
      coins200LedsArray[0] = false;
      coins200LedsArray[1] = false;
      
      break;
      
    case 1:
      //rb1 is true
      coins200LedsArray[0] = true;
      coins200LedsArray[1] = false;
      
      break;

    case 2:
      //both rbs are true
      coins200LedsArray[0] = true;
      coins200LedsArray[1] = true;
      
      break;

    default:
      break;
  }
  OUT_GROUP2 = 1;
  OUT_GROUP1 = 0;
 
}

void HardwareControl::SetSoap2Led(bool boolean)
{
   if(boolean) 
  {
    //rb is true
    soap2 = true;
  }
  else 
  {
    //rb is false
    soap2 = false;
  }
 
}

void HardwareControl::SetSoap1Led(bool boolean)
{
  if(boolean) 
  {
    //rb is true
    soap1 = true;
  }
  else 
  {
    //rb is false
    soap1 = false;

  }
  
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

void HardwareControl::UpdateTemperature()
{
	heaterTemp++;
	if (heaterTemp > 3)
	{
		heaterTemp = 3;
	}
}

void HardwareControl::UpdateWaterLevel()
{
	waterLvl++;
	if (waterLvl > 3)
	{
		waterLvl = 3;
	}
}

/* PUBLIC GETTERS */
Temp HardwareControl::GetTemperature()
{
	switch (heaterTemp)
	{
	case 0:
		return COLD;
		break;

	case 1:
		return WARM;
		break;

	case 2:
		return WARMER;
		break;

	case 3:
		return HOT;
		break;

	default:
		return COLD;
		break;
	}
  
}


WaterLevel HardwareControl::GetWaterLevel()
{
  //read the rbs and return the water level
	switch (waterLvl)
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

void HardwareControl::SimulatorUpdateIO(char input)
{
	simulatorRawIO = input;
}

char HardwareControl::GetRawInputByte()
{
 
	return simulatorRawIO;
}

void HardwareControl::SetGlobalInputByte(char data)
{
  inputReadings = data;
}

char HardwareControl::GetGlobalInputByte()
{
  return inputReadings;
}

bool HardwareControl::CheckButtonClick(char bitm, char in, char prev)
{
	bool response = false;
	/*if ((in & bitm) == in)
	{
		response = true;
		if (prev == bitm)
		{
			if (in == bitm)
			{
				response = true;
			}
		}
		if ((prev & bitm) != prev)
		{
			response = true;
		}
	}*/

		if (in == bitm) 
		{
			response = true;
		}
		
	
	return response;
}

bool HardwareControl::Coin10Action()
{
	bool response = CheckButtonClick(BitMaskCoin10, GetGlobalInputByte(), previousByteButtons);
	if (response)
	{
		previousByteButtons = GetGlobalInputByte();
		SetGlobalInputByte(0x00);
	}
	return response;
}

bool HardwareControl::Coin50Action()
{
	bool response = CheckButtonClick(BitMaskCoin50, GetGlobalInputByte(), previousByteButtons);
	if (response)
	{
		previousByteButtons = GetGlobalInputByte();
		SetGlobalInputByte(0x00);
	}
	return response;
}

bool HardwareControl::Coin200Action()
{
	bool response = CheckButtonClick(BitMaskCoin200, GetGlobalInputByte(), previousByteButtons);
	if (response)
	{
		previousByteButtons = GetGlobalInputByte();
		SetGlobalInputByte(0x00);
	}
	return response;
}

bool HardwareControl::ClearAction()
{
	bool response = CheckButtonClick(BitMaskClear, GetGlobalInputByte(), previousByteButtons);
	if (response)
	{
		previousByteButtons = GetGlobalInputByte();
		SetGlobalInputByte(0x00);
	}
	return response;
}


bool HardwareControl::ProgramAction()
{
	bool response = CheckButtonClick(BitMaskProgram, GetGlobalInputByte(), previousByteButtons);
	if (response)
	{
		previousByteButtons = GetGlobalInputByte();
		SetGlobalInputByte(0x00);
	}
	return response;
}

bool HardwareControl::StartAction()
{
	bool response = CheckButtonClick(BitMaskStart, GetGlobalInputByte(), previousByteButtons);
	if (response)
	{
		previousByteButtons = GetGlobalInputByte();
		SetGlobalInputByte(0x00);
	}
	return response;
}

bool HardwareControl::PressureAction()
{
	bool response = CheckButtonClick(BitMaskPressure, GetGlobalInputByte(), previousByteButtons);
	if (response)
	{
		previousByteButtons = GetGlobalInputByte();
		SetGlobalInputByte(0x00);
	}
	return response;
}

bool HardwareControl::HeaterAction()
{
	bool response = CheckButtonClick(BitMaskHeater, GetGlobalInputByte(), previousByteButtons);
	if (response)
	{
		previousByteButtons = GetGlobalInputByte();
		SetGlobalInputByte(0x00);
	}
	return response;
}