/* This namespace contains all the shared enumeration
types + a global static instance of the Centpede 
library */
#ifndef SHAREDNAMESPACE_H
#define SHAREDNAMESPACE_H

#include <Centipede.h>

namespace sharedNamespace
{
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