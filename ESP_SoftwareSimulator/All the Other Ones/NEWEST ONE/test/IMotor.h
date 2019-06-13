#ifndef IMOTOR_H
#define IMOTOR_H

#include "SharedNamespace.h"
using namespace sharedNamespace;

class IMotor
{
public:
    /* SETTERS */
    /* Function to set the Speed
		input: of type sharedNamespace::Speed */
	virtual void SetSpeed(Speed) = 0;
	/* Function to set the Rotation
		input: of type sharedNamespace::Rotation */
	virtual void SetRotation(Rotation) = 0;
    /* GETTERS */
	virtual Rotation CurentRotation() = 0; // Returns the last set rotation
	virtual Speed CurentSpeed() = 0;	   // Returns the last set speed
};

#endif