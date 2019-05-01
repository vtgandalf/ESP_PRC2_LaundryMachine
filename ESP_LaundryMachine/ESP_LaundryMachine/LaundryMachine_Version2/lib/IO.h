#ifndef IO_H
#define IO_H

#include "SharedNamespace.h"
using namespace sharedNamespace;

class IO
{
public:
	/* GETTERS */
	/* Method that returns the raw readings from
		the multiplexed input pins + keyselect
		output: byte */
	virtual byte GetRawInputByte() = 0;
	/* Method that gets the value stored in
		the private var HardwareControl::inputReadings in
		HardwareControl.h 
		output: byte*/
	virtual byte GetGlobalInputByte() = 0;
	/* SETTERS */
	/* Function to set the Buzzer
		input: 
			- true - turns it on
			- false - turns it off */
	virtual void SetBuzzer(bool) = 0;
	/* Function that sets the leds indicating
		which program has been chose
		input:
			- 1 - first led lights up
			- 2 - second led lights up
			- 3 - third led lights up */
	virtual void SetProgramLed(int) = 0;
	virtual void SetKeyselect(bool) = 0;
	virtual void SetStrobe(bool) = 0;
	/* Method that sets the value of
		the private var HardwareControl::inputReadings in
		HardwareControl.h */
	virtual void SetGlobalInputByte(byte) = 0;

	/* Fields */
	virtual bool Buzzer() = 0;			   // Returns the buzzer state
	virtual bool Keyselect() = 0;		   // Returns the keyselect state
	virtual bool Strobe() = 0;			   // returns the strobe state
};

#endif
