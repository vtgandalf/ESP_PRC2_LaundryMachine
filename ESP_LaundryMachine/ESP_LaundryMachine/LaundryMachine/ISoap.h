#ifndef ISOAP_H
#define ISOAP_H

#include "SharedNamespace.h"

class ISoap
{
	public:
		virtual void SetSoap2Led(bool)=0;
		virtual void SetSoap1Led(bool)=0;
};

#endif
