#ifndef HARDWARECONTROL_H
#define HARDWARECONTROL_H

#include <Wire.h>
#include "ICoin.h"
#include "IO.h"
#include "ISecurity.h"
#include "ISoap.h"
#include "SharedNamespace.h"
using namespace sharedNamespace;

class HardwareControl: public ICoin, public ISecurity, public ISoap
{
    public:
        HardwareControl();
        virtual Function GetButtonsFunction();
        virtual Temp GetTemperature();
        
        virtual void SetBuzzer(bool);
        virtual void SetSpeed(Speed);
        virtual void SetDrain(bool);
        virtual void SetSink(bool);
        virtual void SetRotation(Rotation);
        virtual void SetSoap2Led();
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

        virtual void SetCoin10Led(int);
        virtual void SetCoin50Led(int);
        virtual void SetCoin200Led(int);

        virtual WaterLevel GetWaterLevel();
        virtual void SetHeater(bool);
        virtual void SetLock(bool);
        virtual bool Lock();  
        

    private:
        bool coins10LedsArray[3] = {false, false, false};
        bool coins50LedsArray[3] = {false, false, false};
        bool coins200LedsArray[2] = {false, false}; 
        Rotation rotation;
        bool heater;
        bool buzzer;
        Speed speed;
        bool lock;
        bool drain;
        bool sink;
        bool keyselect;
        bool strobe;
};

#endif
