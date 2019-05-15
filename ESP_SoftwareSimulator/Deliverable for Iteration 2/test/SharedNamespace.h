/* This namespace contains all the shared enumeration
types + a global static instance of the Centpede 
library */
#ifndef ENUMS_H
#define ENUMS_H

//#include "Centipede.h"

namespace sharedNamespace
{
static char bitMaskClear = 0x1E;
static char bitMaskProgram = 0x19;
static char bitMaskCoin10 = 0x18;
static char bitMaskCoin50 = 0x14;
static char bitMaskCoin200 = 0x12;
static char bitMaskStart = 0x11;
static char bitMaskDoorlock = 0x08;
static char bitMaskSoap2 = 0x04;
static char bitMaskSoap1 = 0x02;
static char bitMaskPressure = 0x01;
static char bitMaskKeyselect = 0x10;
enum WaterLevel
{
    EMPTY,
    ALMOSTEMPTY,
    ALMOSTFULL,
    FULL
};
enum Temp
{
    COLD,
    WARM,
    WARMER,
    HOT
};
enum Speed
{
    OFF,
    LOWSPEED,
    MEDIUMSPEED,
    HIGHSPEED
};
enum Rotation
{
    COUNTERCLOCKWISE,
    CLOCKWISE
};
//extern Centipede centipede;
} // namespace sharedNamespace

#endif