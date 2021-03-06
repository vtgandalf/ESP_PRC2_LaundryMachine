#include "../lib/HardwareControl.h"

#define OUT_GROUP2 0
#define OUT_GROUP1 1
#define OUT_STROBE 2
#define OUT_KEYSELECT 3
#define OUT_BUZZER 4
#define OUT_HEATER 5
#define OUT_SPEED2 6
#define OUT_SPEED1 7
#define OUT_DATAC 8
#define OUT_DATAB 9
#define OUT_DATAA 10
#define OUT_MOTOR_RL 11
#define OUT_SOAP1 12
#define OUT_SINK 13
#define OUT_DRAIN 14
#define OUT_LOCK 15
#define IN_W2 16
#define IN_W1 17
#define IN_T2 18
#define IN_T1 19
#define IN_IN3 20
#define IN_IN2 21
#define IN_IN1 22
#define IN_IN0 23

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
  Serial.begin(9600);
  Wire.begin(); // start I2C
  centipede.initialize();
  for (int i = 0; i <= 15; i++)
  {
    centipede.pinMode(i, OUTPUT);
  }
  /*for (int i = 16; i <= 23; i++)
  {
    centipede.pinMode(i, INPUT);
  }*/
  //centipede.portMode(0, 0b0000000000000000); // set all pins on chip 0 to output (0 to 15)
  //centipede.portMode(1, 0b1111111111111111); // set all pins on chip 1 to output (16 to 31)
  Serial.println("---centipede has been initalized---");
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
  SetProgramLed(0);
  SetCoin200Led(0);
  delay(200);
}

HardwareControl *HardwareControl::GetInstance()
{
  // Guaranteed to be destroyed.
  // Instantiated on first use. 
  static HardwareControl instance;
  return &instance;
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

void HardwareControl::SetStrobe(bool boolean)
{
  if (boolean)
    centipede.digitalWrite(OUT_STROBE, HIGH);
  else
    centipede.digitalWrite(OUT_STROBE, LOW);
  strobe = boolean;
}

void HardwareControl::SetHeater(bool boolean)
{
  if (!boolean)
    centipede.digitalWrite(OUT_HEATER, HIGH);
  else
    centipede.digitalWrite(OUT_HEATER, LOW);
  heater = boolean;
}

void HardwareControl::SetBuzzer(bool boolean)
{
  if (!boolean)
    centipede.digitalWrite(OUT_BUZZER, HIGH);
  else
    centipede.digitalWrite(OUT_BUZZER, LOW);
  buzzer = boolean;
}

void HardwareControl::SetSpeed(Speed motorSpeed)
{
  switch (motorSpeed)
  {
  case HIGHSPEED:
    centipede.digitalWrite(OUT_SPEED2, LOW);
    centipede.digitalWrite(OUT_SPEED1, LOW);
    break;

  case MEDIUMSPEED:
    centipede.digitalWrite(OUT_SPEED2, LOW);
    centipede.digitalWrite(OUT_SPEED1, HIGH);
    break;

  case LOWSPEED:
    centipede.digitalWrite(OUT_SPEED2, HIGH);
    centipede.digitalWrite(OUT_SPEED1, LOW);
    break;

  case OFF:
    centipede.digitalWrite(OUT_SPEED2, HIGH);
    centipede.digitalWrite(OUT_SPEED1, HIGH);
    break;

  default:
    break;
  }
  speed = motorSpeed;
}

void HardwareControl::SetLock(bool boolean)
{
  if (boolean)
    centipede.digitalWrite(OUT_LOCK, HIGH);
  else
    centipede.digitalWrite(OUT_LOCK, LOW);
  lock = boolean;
}

void HardwareControl::SetDrain(bool boolean)
{
  if (boolean)
    centipede.digitalWrite(OUT_DRAIN, HIGH);
  else
    centipede.digitalWrite(OUT_DRAIN, LOW);
  drain = boolean;
}

void HardwareControl::SetSink(bool boolean)
{
  if (boolean)
    centipede.digitalWrite(OUT_SINK, HIGH);
  else
    centipede.digitalWrite(OUT_SINK, LOW);
  sink = boolean;
}

void HardwareControl::SetRotation(Rotation tankRotation)
{
  switch (tankRotation)
  {
  case CLOCKWISE:
    centipede.digitalWrite(OUT_MOTOR_RL, HIGH);
    break;

  case COUNTERCLOCKWISE:
    centipede.digitalWrite(OUT_MOTOR_RL, LOW);
    break;

  default:
    break;
  }
  rotation = tankRotation;
}

void HardwareControl::SetKeyselect(bool boolean)
{
  if (boolean)
    centipede.digitalWrite(OUT_KEYSELECT, HIGH);
  else
    centipede.digitalWrite(OUT_KEYSELECT, LOW);
  keyselect = boolean;
}

void HardwareControl::SetCoin10Led(int x)
{
  switch (x)
  {
  case 0:
    coins10LedsArray[0] = LOW;
    coins10LedsArray[1] = LOW;
    coins10LedsArray[2] = LOW;
    break;

  case 1:
    coins10LedsArray[0] = HIGH;
    coins10LedsArray[1] = LOW;
    coins10LedsArray[2] = LOW;
    break;

  case 2:
    coins10LedsArray[0] = HIGH;
    coins10LedsArray[1] = HIGH;
    break;

  case 3:
    coins10LedsArray[0] = HIGH;
    coins10LedsArray[1] = HIGH;
    coins10LedsArray[2] = HIGH;
    break;

  default:
    break;
  }
  centipede.digitalWrite(OUT_GROUP2, LOW);
  centipede.digitalWrite(OUT_GROUP1, LOW);
  centipede.digitalWrite(OUT_DATAC, coins10LedsArray[2]);
  centipede.digitalWrite(OUT_DATAB, coins10LedsArray[1]);
  centipede.digitalWrite(OUT_DATAA, coins10LedsArray[0]);
  delay(100);
}

void HardwareControl::SetCoin50Led(int x)
{
  switch (x)
  {
  case 0:
    coins50LedsArray[0] = LOW;
    coins50LedsArray[1] = LOW;
    coins50LedsArray[2] = LOW;
    break;

  case 1:
    coins50LedsArray[0] = HIGH;
    coins50LedsArray[1] = LOW;
    coins50LedsArray[2] = LOW;
    break;

  case 2:
    coins50LedsArray[0] = HIGH;
    coins50LedsArray[1] = HIGH;
    break;

  case 3:
    coins50LedsArray[0] = HIGH;
    coins50LedsArray[1] = HIGH;
    coins50LedsArray[2] = HIGH;
    break;

  default:
    break;
  }
  centipede.digitalWrite(OUT_GROUP2, LOW);
  centipede.digitalWrite(OUT_GROUP1, HIGH);
  centipede.digitalWrite(OUT_DATAC, coins50LedsArray[2]);
  centipede.digitalWrite(OUT_DATAB, coins50LedsArray[1]);
  centipede.digitalWrite(OUT_DATAA, coins50LedsArray[0]);
  delay(100);
}

void HardwareControl::SetCoin200Led(int x)
{
  switch (x)
  {
  case 0:
    coins200LedsArray[0] = LOW;
    coins200LedsArray[1] = LOW;
    break;

  case 1:
    coins200LedsArray[0] = HIGH;
    coins200LedsArray[1] = LOW;
    break;

  case 2:
    coins200LedsArray[0] = HIGH;
    coins200LedsArray[1] = HIGH;
    break;

  default:
    break;
  }
  centipede.digitalWrite(OUT_GROUP2, HIGH);
  centipede.digitalWrite(OUT_GROUP1, LOW);
  centipede.digitalWrite(OUT_DATAC, soap2);
  centipede.digitalWrite(OUT_DATAB, coins200LedsArray[1]);
  centipede.digitalWrite(OUT_DATAA, coins200LedsArray[0]);
}

void HardwareControl::SetSoap2Led(bool boolean)
{
  if (boolean)
  {
    soap2 = HIGH;
  }
  else
  {
    soap2 = LOW;
  }
  centipede.digitalWrite(OUT_GROUP2, HIGH);
  centipede.digitalWrite(OUT_GROUP1, LOW);
  centipede.digitalWrite(OUT_DATAC, soap2);
  centipede.digitalWrite(OUT_DATAB, coins200LedsArray[1]);
  centipede.digitalWrite(OUT_DATAA, coins200LedsArray[0]);
}

void HardwareControl::SetSoap1Led(bool boolean)
{
  if (boolean)
  {
    soap1 = HIGH;
  }
  else
  {
    soap1 = LOW;
  }
  centipede.digitalWrite(OUT_SOAP1, soap1);
}

void HardwareControl::SetProgramLed(int x)
{
  switch (x)
  {
  case 0:
    centipede.digitalWrite(OUT_GROUP2, HIGH);
    centipede.digitalWrite(OUT_GROUP1, HIGH);
    centipede.digitalWrite(OUT_DATAC, LOW);
    centipede.digitalWrite(OUT_DATAB, LOW);
    centipede.digitalWrite(OUT_DATAA, LOW);
    break;

  case 1:
    centipede.digitalWrite(OUT_GROUP2, HIGH);
    centipede.digitalWrite(OUT_GROUP1, HIGH);
    centipede.digitalWrite(OUT_DATAC, LOW);
    centipede.digitalWrite(OUT_DATAB, LOW);
    centipede.digitalWrite(OUT_DATAA, HIGH);
    break;

  case 2:
    centipede.digitalWrite(OUT_GROUP2, HIGH);
    centipede.digitalWrite(OUT_GROUP1, HIGH);
    centipede.digitalWrite(OUT_DATAC, LOW);
    centipede.digitalWrite(OUT_DATAB, HIGH);
    centipede.digitalWrite(OUT_DATAA, LOW);
    break;

  case 3:
    centipede.digitalWrite(OUT_GROUP2, HIGH);
    centipede.digitalWrite(OUT_GROUP1, HIGH);
    centipede.digitalWrite(OUT_DATAC, HIGH);
    centipede.digitalWrite(OUT_DATAB, LOW);
    centipede.digitalWrite(OUT_DATAA, LOW);
    break;

  default:
    break;
  }
  delay(75);
}

/* PUBLIC GETTERS */
Temp HardwareControl::GetTemperature()
{
  Temp response = COLD;
  byte temp = BitMaskEmpty;
  temp |= centipede.digitalRead(IN_T2) << 1;
  temp |= centipede.digitalRead(IN_T1);
  if (temp)
    switch (temp)
    {
    case BitMaskTempCold:
      response = COLD;
      break;

    case BitMaskTempWarm:
      response = WARM;
      break;

    case BitMaskTempWarmer:
      response = WARMER;
      break;

    case BitMaskTempHot:
      response = HOT;
      break;

    default:
      break;
    }
  return response;
}

WaterLevel HardwareControl::GetWaterLevel()
{
  int level[] = {centipede.digitalRead(IN_W2), centipede.digitalRead(IN_W1)};
  switch (level[0])
  {
  case 0:
    if (level[1])
      return ALMOSTEMPTY;
    else
      return EMPTY;
    break;

  case 1:
    if (level[1])
      return FULL;
    else
      return ALMOSTFULL;
    break;

  default:
    return NULL;
    break;
  }
}

byte HardwareControl::GetRawInputByte()
{
  // reading the buttons and storring their data
  // into the reading byte
  byte temp = BitMaskEmpty;
  temp |= centipede.digitalRead(IN_IN0);
  temp |= centipede.digitalRead(IN_IN1) << 1;
  temp |= centipede.digitalRead(IN_IN2) << 2;
  temp |= centipede.digitalRead(IN_IN3) << 3;
  temp |= Keyselect() << 4;
  return temp;
}

void HardwareControl::SetGlobalInputByte(byte data)
{
  inputReadings = data;
}

byte HardwareControl::GetGlobalInputByte()
{
  return inputReadings;
}

bool HardwareControl::CheckCoinGroupButtonClick(byte bitm, byte in)
{
  bool response = false;
  if ((in | bitm) == in)
  {
    if(((in | bitm) != BitMaskProgram)&&((in | bitm) != BitMaskStart))
    {
      response = true;
    }
  }
  return response;
}

bool HardwareControl::CheckSoapGroupSwitchClick(byte bitm, byte key, byte in)
{
  bool response = false;
  if ((in | bitm) == in)
  {
    if ((in | key) != in)
    {
      response = true;
    }
  }
  return response;
}

bool HardwareControl::CheckProgramGroupButtonClick(byte bitm, byte in)
{
  bool response = false;
  if ((in | bitm) == in)
  {
    response = true;
  }
  return response;
}

bool HardwareControl::CheckOtherGroupSwitchClick(byte bitm, byte key, byte in)
{
  bool response = false;
  if ((in | bitm) == in)
  {
    if ((in | key) != in)
    {
      response = true;
    }
  }
  return response;
}

bool HardwareControl::Soap1Action()
{
  bool response = CheckSoapGroupSwitchClick(BitMaskSoap1, BitMaskKeyselect, GetGlobalInputByte());
  if (response)
  {
    SetGlobalInputByte(BitMaskEmpty);
  }
  return response;
}

bool HardwareControl::Soap2Action()
{
  bool response = CheckSoapGroupSwitchClick(BitMaskSoap2, BitMaskKeyselect, GetGlobalInputByte());
  if (response)
  {
    SetGlobalInputByte(BitMaskEmpty);
  }
  return response;
}

bool HardwareControl::DoorAction()
{
  SetKeyselect(false);
  bool response = CheckOtherGroupSwitchClick(BitMaskDoorlock, BitMaskKeyselect, GetRawInputByte());
  return response;
}

bool HardwareControl::PressureAction()
{
  SetKeyselect(false);
  bool response = CheckOtherGroupSwitchClick(BitMaskPressure, BitMaskKeyselect, GetRawInputByte());
  return response;
}

bool HardwareControl::Coin10Action()
{
  bool response = CheckCoinGroupButtonClick(BitMaskCoin10, GetGlobalInputByte());
  if (response)
  {
    SetGlobalInputByte(BitMaskEmpty);
  }
  return response;
}

bool HardwareControl::Coin50Action()
{
  bool response = CheckCoinGroupButtonClick(BitMaskCoin50, GetGlobalInputByte());
  if (response)
  {
    SetGlobalInputByte(BitMaskEmpty);
  }
  return response;
}

bool HardwareControl::Coin200Action()
{
  bool response = CheckCoinGroupButtonClick(BitMaskCoin200, GetGlobalInputByte());
  if (response)
  {
    SetGlobalInputByte(BitMaskEmpty);
  }
  return response;
}

bool HardwareControl::ClearAction()
{
  bool response = CheckCoinGroupButtonClick(BitMaskClear, GetGlobalInputByte());  
  if (response)
  {
    SetGlobalInputByte(BitMaskEmpty);
  }
  return response;
}

bool HardwareControl::ProgramAction()
{
  bool response = CheckProgramGroupButtonClick(BitMaskProgram, GetGlobalInputByte());
  if (response)
  {
    SetGlobalInputByte(BitMaskEmpty);
  }
  return response;
}

bool HardwareControl::StartAction()
{
  bool response = CheckProgramGroupButtonClick(BitMaskStart, GetGlobalInputByte());
  if (response)
  {
    SetGlobalInputByte(BitMaskEmpty);
  }
  return response;
}