#ifndef IO_H
#define IO_H

#include "SharedNamespace.h"

using namespace sharedNamespace;

class IO
{
	public:

		virtual byte GetRawInputByte()=0;
		virtual void SetGlobalInputByte(byte)=0;
		virtual byte GetGlobalInputByte()=0;


		/* GETTERS */
		/* Method that gets the value stored in
		the private var "globalFunction" in
		HardwareControl.h 
		output: of type sharedNamespace::Function*/
		virtual Function GetGlobalFunction()=0;
		/* Method that returns the raw reading 
		of the multiplexed buttons and switches,
		which later needs to get filtered out
		output: of type sharedNamespace::Function */
    	virtual Function GetButtonsFunction()=0;
		/* Method that returns the Temperature 
		of the water in the laundry machine
		output: of type sharedNamespace::Temp */
    	virtual Temp GetTemperature()=0;

    	/* SETTERS */
		/* Function to set the Buzzer
		input: 
			- true - turns it on
			- false - turns it off */
    	virtual void SetBuzzer(bool)=0;
		/* Function to set the Speed
		input: of type sharedNamespace::Speed */
    	virtual void SetSpeed(Speed)=0;
		/* Function to set the Drain
		input: 
			- true - turns it on
			- false - turns it off */
    	virtual void SetDrain(bool)=0;
		/* Function to set the Sink
		input: 
			- true - turns it on
			- false - turns it off */
    	virtual void SetSink(bool)=0;
		/* Function to set the Rotation
		input: of type sharedNamespace::Rotation */
    	virtual void SetRotation(Rotation)=0;
		/* Function that sets the leds indicating
		which program has been chose
		input:
			- 1 - first led lights up
			- 2 - second led lights up
			- 3 - third led lights up */
    	virtual void SetProgramLed(int)=0;
    	virtual void SetKeyselect(bool)=0;
    	virtual void SetStrobe(bool)=0;
		/* Method that sets the value of
		the private var "globalFunction" in
		HardwareControl.h */
		virtual void SetGlobalFunction(Function)=0;
    	
		/* Fields */
    	virtual bool Heater()=0;	// Returns the heater state
    	virtual bool Buzzer()=0;	// Returns the buzzer state
    	virtual bool Drain()=0;		// Returns the drain state
    	virtual bool Sink()=0;		// Returns the sink state
    	virtual bool Keyselect()=0;	// Returns the keyselect state
    	virtual bool Strobe()=0;	// returns the strobe state
    	virtual Rotation CurentRotation()=0;	// Returns the last set rotation
    	virtual Speed CurentSpeed()=0;	// Returns the last set speed
};

#endif
