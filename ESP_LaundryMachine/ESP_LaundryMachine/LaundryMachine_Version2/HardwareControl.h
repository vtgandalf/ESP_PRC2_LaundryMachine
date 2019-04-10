#ifndef HARDWARECONTROL_H
#define HARDWARECONTROL_H

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
        static HardwareControl* GetInstance();
        void HardwareControlSetup();

    
    //protected:
        virtual Function GetButtonsFunction();
        virtual Function GetButtonsFunctionDebounced();
        virtual Temp GetTemperature();
        virtual void SetBuzzer(bool);
        virtual void SetSpeed(Speed);
        virtual void SetDrain(bool);
        virtual void SetSink(bool);
        virtual void SetRotation(Rotation);
		virtual void SetSoap1Led(bool);
        virtual void SetSoap2Led(bool);
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
        Function previousState = NOTHING;
        Function state = NOTHING;
        unsigned long timerTreshold = 50;
        unsigned long lastDebounceTime = 0;
        Function Debounce(Function*, Function*, Function, unsigned long*);
        static HardwareControl* instance;
        bool coins10LedsArray[3] = {LOW, LOW, LOW};
        bool coins50LedsArray[3] = {LOW, LOW, LOW};
        bool coins200LedsArray[2] = {LOW, LOW}; 
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
