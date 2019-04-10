#ifndef ICOIN_H
#define ICOIN_H

#include "SharedNamespace.h"
#include "IO.h"

class ICoin
{
    public:
        virtual void SetCoin10Led(int)=0;
        virtual void SetCoin50Led(int)=0;
        virtual void SetCoin200Led(int)=0;
        
};

#endif
