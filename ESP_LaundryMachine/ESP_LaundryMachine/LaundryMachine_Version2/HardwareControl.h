#ifndef HARDWARECONTROL_H
#define HARDWARECONTROL_H

/* This is a library that operates between the centipede
class and the rest of the program. It is intended to be
a dummy class. It is implementing four interfaces through
which every other object will be able to access it. That
will be restricted to only what every object needs.
This library is designed to be used in as a singleton
instance */

#include <Wire.h>
#include "ICoin.h"
#include "IO.h"
#include "ISecurity.h"
#include "ISoap.h"
#include "SharedNamespace.h"
using namespace sharedNamespace;

class HardwareControl: public ICoin, public ISecurity, public ISoap, public IO
{
    public:
        // Method that returns the singleton instance
        static HardwareControl* GetInstance();
        /* This method used to be the constructor, but
        since such a big function containing loops makes
        the arduino crash it has been put as a normal
        function to be called duting the stetup(). It
        takes care of initializing the centipede library
        and turning off the components of the laundry
        machine */
        void HardwareControlSetup();

    
    protected:
        /* IMPLEMENTATION OF IO */
        virtual Function GetGlobalFunction();
        virtual void SetGlobalFunction(Function);
        virtual Function GetButtonsFunction();
        virtual Temp GetTemperature();
        virtual void SetBuzzer(bool);
        virtual void SetSpeed(Speed);
        virtual void SetDrain(bool);
        virtual void SetSink(bool);
        virtual void SetRotation(Rotation);
        virtual void SetProgramLed(int);
        virtual void SetKeyselect(bool);
        virtual void SetStrobe(bool);
        virtual bool Heater();
        virtual bool Buzzer();
        virtual bool Drain();
        virtual bool Sink();
        virtual bool Keyselect();
        virtual bool Strobe();
        virtual Rotation CurentRotation();
        virtual Speed CurentSpeed();

        /* IMPLEMENTATION OF ICOIN */
        virtual void SetCoin10Led(int);
        virtual void SetCoin50Led(int);
        virtual void SetCoin200Led(int);

        /* IMPLEMENTATION OF ISOAP */
		virtual void SetSoap1Led(bool);
        virtual void SetSoap2Led(bool);

        /* IMPLEMENTATION OF ISECURITY */
        virtual WaterLevel GetWaterLevel();
        virtual void SetHeater(bool);
        virtual void SetLock(bool);
        virtual bool Lock();
        
    private:
        // Singleton instance
        static HardwareControl* instance;
        /* Arrays that contain the information
        for the leds so whenever an led is set
        the rest keep their previous state */
        bool coins10LedsArray[3] = {LOW, LOW, LOW};
        bool coins50LedsArray[3] = {LOW, LOW, LOW};
        bool coins200LedsArray[2] = {LOW, LOW}; 
        // Var that stores the last set rotation
        Rotation rotation;
        // Var for the heater state
        bool heater;
        // Var for the buzzer state
        bool buzzer;
        // Var for the last set speed
        Speed speed;
        // Var for the lock state
        bool lock;
        // Var for the drain state
        bool drain;
        // Var for the drain state
        bool sink;
        // Var for the keyselect state
        bool keyselect;
        // var for the strobe state
        bool strobe;
        /* This variable stores the last reccorded
        function from the input. It is crutial for 
        properly reading and debouncing the multiplexed
        buttons and switches */
        Function globalFunction = NOTHING;
};

#endif
