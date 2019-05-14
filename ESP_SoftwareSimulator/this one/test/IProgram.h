#ifndef IPROGRAM_H
#define IPROGRAM_H

//#include "SharedNamespace.h"

class IProgram
{
public:
	/* Function that sets the leds indicating
		which program has been chose
		input:
			- 0 - all leds are off
			- 1 - first led lights up
			- 2 - second led lights up
			- 3 - third led lights up */
	virtual void SetProgramLed(int) = 0;
    /* Method that checks if program button has been 
    pressed
    output:
        - true - it has been pressed
        - false - it hasnt been pressed */
    virtual bool ProgramAction() = 0;
	/* Method that checks if start button has been 
    pressed
    output:
        - true - it has been pressed
        - false - it hasnt been pressed */
    virtual bool StartAction() = 0;
};

#endif
