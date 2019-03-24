#ifndef IO_H
#define IO_H

#include "SharedNamespace.h"

using namespace sharedNamespace;

class IO
{
	public:
		// getters
    	virtual Function GetButtonsFunction()=0;
    	virtual Temp GetTemperature()=0;
    	// setters
    	
    	virtual void SetBuzzer(bool)=0;
    	virtual void SetSpeed(Speed)=0;
    	virtual void SetDrain(bool)=0;
    	virtual void SetSink(bool)=0;
    	virtual void SetRotation(Rotation)=0;
        virtual void SetSoap2Led()=0;
    	virtual void SetProgramLed(int)=0;
    	virtual void SetKeyselect(bool)=0;
    	virtual void SetStrobe(bool)=0;
    	// fields
    	virtual bool Heater()=0;
    	virtual bool Buzzer()=0;
    	virtual bool Drain()=0;
    	virtual bool Sink()=0;
    	virtual bool Keyselect()=0;
    	virtual bool Strobe()=0;
    	
    	virtual Rotation CurentRotation()=0;
    	virtual Speed CurentSpeed()=0;
};

#endif
