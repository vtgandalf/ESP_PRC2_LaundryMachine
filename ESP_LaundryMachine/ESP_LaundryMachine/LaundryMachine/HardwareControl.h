#ifndef HARDWARECONTROL_H
#define HARDWARECONTROL_H

#include <Wire.h>
#include <Centipede.h>

class HardwareControl
{
  public:
    enum Rotation { COUNTERCLOCKWISE, CLOCKWISE };

  public:
    enum WaterLevel { EMPTY, ALMOSTEMPTY, ALMOSTFULL, FULL };

  public:
    enum Temp { COLD, WARM, WARMER, HOT };

  public:
    enum Speed { OFF, LOWSPEED, MEDIUMSPEED, HIGHSPEED };

  private:
    bool heater;

  private:
    bool buzzer;

  private:
    Speed speed;

  private:
    bool lock;

  private:
    bool drain;

  private:
    bool sink;

  private:
    Rotation rotation;
  
  public:
    HardwareControl();

  private:
    Centipede centipede;

  public:
    WaterLevel GetWaterLevel();
  
  public:
    Temp GetTemperature();

  public:
    void SetHeater(bool);

  public:
    void SetBuzzer(bool);

  public:
    void SetSpeed(Speed);

  public:
    void SetLock(bool);

  public:
    void SetDrain(bool);

  public:
    void SetSink(bool);

  public:
    void SetRotation(Rotation);
};

#endif
