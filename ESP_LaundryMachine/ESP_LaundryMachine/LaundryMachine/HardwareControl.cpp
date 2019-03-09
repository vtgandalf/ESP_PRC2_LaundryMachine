#include "HardwareControl.h"

#define OUT_GROUP2      0
#define OUT_GROUP1      1
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

HardwareControl::HardwareControl()
{
  Wire.begin();           // start I2C
  centipede.initialize(); // set all registers to default
  for (int i = 0; i <= 15; i++)
  {
    centipede.pinMode(i, OUTPUT);
  }
  centipede.digitalWrite(OUT_GROUP2, LOW);
  centipede.digitalWrite(OUT_GROUP1, LOW);
  SetStrobe(false);       // centipede.digitalWrite(OUT_STROBE, LOW);
  SetKeyselect(true);     // centipede.digitalWrite(OUT_KEYSELECT, HIGH);
  SetBuzzer(true);        // centipede.digitalWrite(OUT_BUZZER, HIGH);
  SetHeater(false);       // centipede.digitalWrite(OUT_HEATER, HIGH);
  SetSpeed(OFF);          // centipede.digitalWrite(OUT_SPEED2, HIGH);
                          // centipede.digitalWrite(OUT_SPEED1, HIGH);
  centipede.digitalWrite(OUT_DATAC, LOW);
  centipede.digitalWrite(OUT_DATAB, LOW);
  centipede.digitalWrite(OUT_DATAA, LOW);
  SetRotation(CLOCKWISE); // centipede.digitalWrite(OUT_MOTOR_RL, LOW);
  centipede.digitalWrite(OUT_SOAP1, LOW);
  SetSink(false);         // centipede.digitalWrite(OUT_SINK, LOW);
  SetDrain(false);        // centipede.digitalWrite(OUT_DRAIN, LOW);
  SetLock(false);         // centipede.digitalWrite(OUT_LOCK, LOW);
}

/* PUBLIC PROPERTIES (read only)*/
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

HardwareControl::Rotation HardwareControl::CurentRotation()
{
  return rotation;
}

HardwareControl::Speed HardwareControl::CurentSpeed()
{
  return speed;
}

/* PUBLIC SETTERS */
void HardwareControl::SetStrobe(bool boolean)
{
  if (boolean) centipede.digitalWrite(OUT_STROBE, HIGH);
  else centipede.digitalWrite(OUT_STROBE, LOW);
  strobe = boolean;
}

void HardwareControl::SetHeater(bool boolean)
{
  if (boolean) centipede.digitalWrite(OUT_HEATER, HIGH);
  else centipede.digitalWrite(OUT_HEATER, LOW);
  heater = boolean;
}

void HardwareControl::SetBuzzer(bool boolean)
{
  if (boolean) centipede.digitalWrite(OUT_BUZZER, HIGH);
  else centipede.digitalWrite(OUT_BUZZER, LOW);
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
  if (boolean) centipede.digitalWrite(OUT_LOCK, HIGH);
  else centipede.digitalWrite(OUT_LOCK, LOW);
  lock = boolean;
}

void HardwareControl::SetDrain(bool boolean)
{
  if (boolean) centipede.digitalWrite(OUT_DRAIN, HIGH);
  else centipede.digitalWrite(OUT_DRAIN, LOW);
  drain = boolean;
}

void HardwareControl::SetSink(bool boolean)
{
  if (boolean) centipede.digitalWrite(OUT_SINK, HIGH);
  else centipede.digitalWrite(OUT_SINK, LOW);
  sink = boolean;
}

void HardwareControl::SetRotation(Rotation tankRotation)
{
  switch (tankRotation)
  {
    case CLOCKWISE:
      centipede.digitalWrite(OUT_MOTOR_RL, LOW);
      break;

    case COUNTERCLOCKWISE:
      centipede.digitalWrite(OUT_MOTOR_RL, HIGH);
      break;

    default:
      break;
  }
  rotation = tankRotation;
}

void HardwareControl::SetKeyselect(bool boolean)
{
  if (boolean) centipede.digitalWrite(OUT_KEYSELECT, HIGH);
  else centipede.digitalWrite(OUT_KEYSELECT, LOW);
  keyselect = boolean;
}

void HardwareControl::SetCoin10Led(int x)
{
  switch (x)
  {
    case 1:
      digitalWrite(OUT_GROUP2, LOW);
      digitalWrite(OUT_GROUP1, LOW);
      digitalWrite(OUT_DATAC, LOW);
      digitalWrite(OUT_DATAB, LOW);
      digitalWrite(OUT_DATAA, HIGH);
      break;

    case 2:
      digitalWrite(OUT_GROUP2, LOW);
      digitalWrite(OUT_GROUP1, LOW);
      digitalWrite(OUT_DATAC, LOW);
      digitalWrite(OUT_DATAB, HIGH);
      digitalWrite(OUT_DATAA, LOW);
      break;

    case 3:
      digitalWrite(OUT_GROUP2, LOW);
      digitalWrite(OUT_GROUP1, LOW);
      digitalWrite(OUT_DATAC, HIGH);
      digitalWrite(OUT_DATAB, LOW);
      digitalWrite(OUT_DATAA, LOW);
      break;

    default:
      break;
  }
}

void HardwareControl::SetCoin50Led(int x)
{
  switch (x)
  {
    case 1:
      digitalWrite(OUT_GROUP2, LOW);
      digitalWrite(OUT_GROUP1, HIGH);
      digitalWrite(OUT_DATAC, LOW);
      digitalWrite(OUT_DATAB, LOW);
      digitalWrite(OUT_DATAA, HIGH);
      break;

    case 2:
      digitalWrite(OUT_GROUP2, LOW);
      digitalWrite(OUT_GROUP1, HIGH);
      digitalWrite(OUT_DATAC, LOW);
      digitalWrite(OUT_DATAB, HIGH);
      digitalWrite(OUT_DATAA, LOW);
      break;

    case 3:
      digitalWrite(OUT_GROUP2, LOW);
      digitalWrite(OUT_GROUP1, HIGH);
      digitalWrite(OUT_DATAC, HIGH);
      digitalWrite(OUT_DATAB, LOW);
      digitalWrite(OUT_DATAA, LOW);
      break;

    default:
      break;
  }
}

void HardwareControl::SetCoin200Led(int x)
{
  switch (x)
  {
    case 1:
      digitalWrite(OUT_GROUP2, HIGH);
      digitalWrite(OUT_GROUP1, LOW);
      digitalWrite(OUT_DATAC, LOW);
      digitalWrite(OUT_DATAB, LOW);
      digitalWrite(OUT_DATAA, HIGH);
      break;

    case 2:
      digitalWrite(OUT_GROUP2, HIGH);
      digitalWrite(OUT_GROUP1, LOW);
      digitalWrite(OUT_DATAC, LOW);
      digitalWrite(OUT_DATAB, HIGH);
      digitalWrite(OUT_DATAA, LOW);
      break;

    default:
      break;
  }
}

void HardwareControl::SetSoap2Led()
{
  digitalWrite(OUT_GROUP2, HIGH);
  digitalWrite(OUT_GROUP1, LOW);
  digitalWrite(OUT_DATAC, HIGH);
  digitalWrite(OUT_DATAB, LOW);
  digitalWrite(OUT_DATAA, LOW);
}

void HardwareControl::SetProgramLed(int x)
{
  switch (x)
  {
    case 1:
      digitalWrite(OUT_GROUP2, HIGH);
      digitalWrite(OUT_GROUP1, HIGH);
      digitalWrite(OUT_DATAC, LOW);
      digitalWrite(OUT_DATAB, LOW);
      digitalWrite(OUT_DATAA, HIGH);
      break;

    case 2:
      digitalWrite(OUT_GROUP2, HIGH);
      digitalWrite(OUT_GROUP1, HIGH);
      digitalWrite(OUT_DATAC, LOW);
      digitalWrite(OUT_DATAB, HIGH);
      digitalWrite(OUT_DATAA, LOW);
      break;

    case 3:
      digitalWrite(OUT_GROUP2, HIGH);
      digitalWrite(OUT_GROUP1, HIGH);
      digitalWrite(OUT_DATAC, HIGH);
      digitalWrite(OUT_DATAB, LOW);
      digitalWrite(OUT_DATAA, LOW);
      break;

    default:
      break;
  }
}

/* PUBLIC GETTERS */
HardwareControl::Temp HardwareControl::GetTemperature()
{
  int temp[] = {centipede.digitalRead(IN_T2), centipede.digitalRead(IN_T1)};
  switch (temp[0])
  {
    case 0:
      if (temp[1]) return WARM;
      else return COLD;
      break;

    case 1:
      if (temp[1]) HOT;
      else return WARMER;
      break;

    default:
      return NULL;
      break;
  }
}

HardwareControl::WaterLevel HardwareControl::GetWaterLevel()
{
  int level[] = {centipede.digitalRead(IN_W2), centipede.digitalRead(IN_W1)};
  switch (level[0])
  {
    case 0:
      if (level[1]) return ALMOSTEMPTY;
      else return EMPTY;
      break;

    case 1:
      if (level[1]) FULL;
      else return ALMOSTFULL;
      break;

    default:
      return NULL;
      break;
  }
}

HardwareControl::Function HardwareControl::GetButtonsFunction()
{
  switch (Keyselect())
  {
    case true:
      if (digitalRead(IN_IN3) && digitalRead(IN_IN2) && digitalRead(IN_IN1)) return CLEAR;
      else if (digitalRead(IN_IN3) && digitalRead(IN_IN0)) return PROGRAM;
      else if (digitalRead(IN_IN0)) return START;
      else if (digitalRead(IN_IN3)) return COIN10;
      else if (digitalRead(IN_IN2)) return COIN50;
      else if (digitalRead(IN_IN1)) return COIN200;
      break;

    case false:
      if (digitalRead(IN_IN3)) return DOORLOCK;
      if (digitalRead(IN_IN2)) return SOAP2;
      if (digitalRead(IN_IN1)) return SOAP1;
      if (digitalRead(IN_IN0)) return PRESSURE;
      break;

    default:
      break;
  }
}