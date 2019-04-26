/* This namespace contains all the shared enumeration
types + a global static instance of the Centpede 
library */
#ifndef ENUMS_H
#define ENUMS_H

#include <Centipede.h>

namespace sharedNamespace
{
static byte bitMaskClear = 0x1E;
static byte bitMaskProgram = 0x19;
static byte bitMaskCoin10 = 0x18;
static byte bitMaskCoin50 = 0x14;
static byte bitMaskCoin200 = 0x12;
static byte bitMaskStart = 0x11;
static byte bitMaskDoorlock = 0x08;
static byte bitMaskSoap2 = 0x04;
static byte bitMaskSoap1 = 0x02;
static byte bitMaskPressure = 0x01;
static byte bitMaskKeyselect = 0x10;
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
extern Centipede centipede;
} // namespace sharedNamespace

#endif