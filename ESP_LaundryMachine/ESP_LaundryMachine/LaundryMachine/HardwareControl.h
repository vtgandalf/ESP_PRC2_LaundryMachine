#ifndef HARDWARECONTROL_H
#define HARDWARECONTROL_H

#include <Wire.h>
#include <Centipede.h>

class HardwareControl
{
  public:
    HardwareControl();

  private:
    Centipede centipede;
};

#endif
