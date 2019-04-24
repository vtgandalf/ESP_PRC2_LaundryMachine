#ifndef ISOAP_H
#define ISOAP_H

#include "SharedNamespace.h"

class ISoap
{
	public:
	/* These methods set the leds for soap 1
	and 2 compartments
        input:
            - 1 - the first led gets turned on
            - 2 - the second led gets turned on */
		virtual void SetSoap2Led(bool)=0;
		virtual void SetSoap1Led(bool)=0;
};

#endif
