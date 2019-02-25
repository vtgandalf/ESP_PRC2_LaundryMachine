#ifndef HARDWARECONTROL_H
#define HARDWARECONTROL_H

#include <Wire.h>
#include <Centipede.h>

class HardwareControl
{
  public:
    // enums
    enum Rotation { COUNTERCLOCKWISE, CLOCKWISE };
    enum WaterLevel { EMPTY, ALMOSTEMPTY, ALMOSTFULL, FULL };
    enum Temp { COLD, WARM, WARMER, HOT };
    enum Speed { OFF, LOWSPEED, MEDIUMSPEED, HIGHSPEED };
    // methods for returning the last set value of
    // the heater, buzzer, speed, lock, drain,
    // sink and rotation
    bool Heater();
    bool Buzzer();
    Speed CurentSpeed();
    bool Lock();
    bool Drain();
    bool Sink();
    Rotation CurentRotation();
    // constructor
    HardwareControl();
    // methods to get the water level and temp info
    WaterLevel GetWaterLevel();
    Temp GetTemperature();
    // methods for setting up the rest of the hardware
    void SetHeater(bool);
    void SetBuzzer(bool);
    void SetSpeed(Speed);
    void SetLock(bool);
    void SetDrain(bool);
    void SetSink(bool);
    void SetRotation(Rotation);

  private:
    // private vars to save the last set value of
    // the heater, buzzer, speed, lock, drain,
    // sink and rotation
    bool heater;
    bool buzzer;
    Speed speed;
    bool lock;
    bool drain;
    bool sink;
    Rotation rotation;
    // local var for init the centepide lib
    Centipede centipede;
};

#endif
