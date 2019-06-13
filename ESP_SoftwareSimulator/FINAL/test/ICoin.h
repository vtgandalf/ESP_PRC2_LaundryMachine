#ifndef ICOIN_H
#define ICOIN_H

//#include "SharedNamespace.h"

class ICoin
{
public:
    /* These methods set the leds for coins 
        with value 10, 50 and 200.
        input:
            - 1 - the first led gets turned on
            - 2 - the second led gets turned on
            - 3 - the third one gets turned on
                    (not for coin200) */
    virtual void SetCoin10Led(int) = 0;
    virtual void SetCoin50Led(int) = 0;
    virtual void SetCoin200Led(int) = 0;
    /* Method that checks if coin10 button has been 
    pressed
    output:
        - true - it has been pressed
        - false - it hasnt been pressed */
    virtual bool Coin10Action() = 0;
    /* Method that checks if coin50 button has been 
    pressed
    output:
        - true - it has been pressed
        - false - it hasnt been pressed */
    virtual bool Coin50Action() = 0;
    /* Method that checks if coin200 button has been 
    pressed
    output:
        - true - it has been pressed
        - false - it hasnt been pressed */
    virtual bool Coin200Action() = 0;
    /* Method that checks if clear button has been 
    pressed
    output:
        - true - it has been pressed
        - false - it hasnt been pressed */
    virtual bool ClearAction() = 0;
};

#endif
