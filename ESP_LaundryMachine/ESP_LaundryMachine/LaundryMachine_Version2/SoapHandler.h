#ifndef SOAPHANDLER_H
#define SOAPHANDLER_H

#include "HardwareControl.h"

class SoapHandler
{
    public:
        byte bitMaskSoap2 = 0x04;
        byte bitMaskSoap1 = 0x02;
        void InsertSoapByte();
        /* Method that handles all the essential
        proccesses for this object that have to 
        be ran during the main loop of the arduino
        program */
        void Polling();
        
    private:
        /* Booleans that indicate wheter or not an led has
        been already lit up after the last command. Those
        are neccessary since without them we do keep turning
        on leds that have already been turned on, which only
        wastes cpu cycles.*/
        bool soap1LedHasBeenSetUp = true;
        bool soap2LedHasBeenSetUp = true;
        // accessing the library through interfaces
        IO* ioPtr = (IO*)HardwareControl::GetInstance();
        ISoap* isoapPtr = (ISoap*)HardwareControl::GetInstance();
        /* This is a function(enum from sharedNamespace) 
        container for storing the last function which has
        been reccorded of the buttons*/
        sharedNamespace::Function function;
        // vars storing the inserted soap
        int soap1 = 0;
        int soap2 = 0;
        /* Method that sets the leds next to the 
        soap compartments accordingly to the local 
        variables */
        void SetLed();
        /* Method that controls an led to show that 
        there is more soap required in order to start
        the selected program */
        void IndicateMissingSoap();
        /* Method that handles the incrementing of
        the local variables on input */
        void InsertSoap();
};

#endif