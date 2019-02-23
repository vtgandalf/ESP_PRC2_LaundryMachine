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
  Wire.begin(); // start I2C
  centipede.initialize(); // set all registers to default
  for (int i = 0; i <= 15; i++) 
  {
    centipede.pinMode(i, OUTPUT);
  }
  centipede.digitalWrite(OUT_GROUP2, LOW);
  centipede.digitalWrite(OUT_GROUP1, LOW);
  centipede.digitalWrite(OUT_STROBE, LOW);
  centipede.digitalWrite(OUT_KEYSELECT, HIGH);
  centipede.digitalWrite(OUT_BUZZER, HIGH);
  centipede.digitalWrite(OUT_HEATER, HIGH);
  centipede.digitalWrite(OUT_SPEED2, HIGH);
  centipede.digitalWrite(OUT_SPEED1, HIGH);
  centipede.digitalWrite(OUT_DATAC, LOW);
  centipede.digitalWrite(OUT_DATAB, LOW);
  centipede.digitalWrite(OUT_DATAA, LOW);
  centipede.digitalWrite(OUT_MOTOR_RL, LOW);
  centipede.digitalWrite(OUT_SOAP1, LOW);
  centipede.digitalWrite(OUT_SINK, LOW);
  centipede.digitalWrite(OUT_DRAIN, LOW);
  centipede.digitalWrite(OUT_LOCK, LOW);
}

HardwareControl::SetHeater(bool boolean)
{
  if (boolean) centipede.digitalWrite(OUT_HEATER, HIGH);
  else centipede.digitalWrite(OUT_HEATER, LOW);
  heater = boolean;
}

HardwareControl::SetBuzzer(bool boolean)
{
  if (boolean) centipede.digitalWrite(OUT_BUZZER, HIGH);
  else centipede.digitalWrite(OUT_BUZZER, LOW);
  buzzer = boolean;
}

HardwareControl::SetSpeed(Speed motorSpeed)
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
  speed = motorSpeed
}

HardwareControl::SetLock(bool boolean)
{
  if(boolean) centipede.digitalWrite(OUT_LOCK, HIGH);
  else centipede.digitalWrite(OUT_LOCK, LOW);
  lock = boolean;
}

HardwareControl::SetDrain(bool boolean)
{
  if(boolean) centipede.digitalWrite(OUT_DRAIN, HIGH);
  else centipede.digitalWrite(OUT_DRAIN, LOW);
  drain = boolean;
}

HardwareControl::SetSink(bool boolean)
{
  if(boolean) centipede.digitalWrite(OUT_SINK, HIGH);
  else centipede.digitalWrite(OUT_SINK, LOW);
  sink = boolean;
}

HardwareControl::SetRotation(Rotation tankRotation)
{
  switch (tankRotation)
  {
    case CLOCKWISE:
      centipede.digitalWrite(OUT_MOTOR_RL, LOW);
      break;

    case CLOCKWISE:
      centipede.digitalWrite(OUT_MOTOR_RL, HIGH);
      break;
    
    default:
      break;
  }
  rotation = tankRotation;
}

HardwareControl::GetTemperature()
{
  // to be implemented
}

HardwareControl::GetWaterLevel()
{
  // to be implemented
}