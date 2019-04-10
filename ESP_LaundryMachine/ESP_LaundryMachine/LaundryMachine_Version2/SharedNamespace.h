#ifndef ENUMS_H
#define ENUMS_H

#include <Centipede.h>

namespace sharedNamespace{
    enum WaterLevel { EMPTY, ALMOSTEMPTY, ALMOSTFULL, FULL };
    enum Function { COIN10, COIN50, COIN200, CLEAR, PROGRAM, START, DOORLOCK, SOAP2, SOAP1, PRESSURE, NOTHING };
    enum Temp { COLD, WARM, WARMER, HOT };
    enum Speed { OFF, LOWSPEED, MEDIUMSPEED, HIGHSPEED };
    enum Rotation { COUNTERCLOCKWISE, CLOCKWISE };
    extern Centipede centipede;
}

#endif