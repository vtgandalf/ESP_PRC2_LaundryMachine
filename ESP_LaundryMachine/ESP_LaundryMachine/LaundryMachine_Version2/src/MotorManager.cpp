#include "../lib/MotorManager.h"

void MotorManager::Rotate(Rotation direction, Speed speed, long duration)
{
    if (direction == CLOCKWISE)
    {
        prevMillis = millis();
        imotorPtr -> SetSpeed(speed);
        imotorPtr -> SetRotation(direction);
        bool trig = false;
        while(!trig)
        {
            if((millis() - prevMillis)/ 1000 > duration)
            {
                trig = true;
            }
        }
        imotorPtr -> SetSpeed(OFF);
    }   
    else if (direction == COUNTERCLOCKWISE)
    {
        prevMillis = millis();
        imotorPtr -> SetSpeed(speed);
        imotorPtr -> SetRotation(direction);
        bool trig = false;
        while(!trig)
        {
            if((millis() - prevMillis)/ 1000 > duration)
            {
                trig = true;
            }
        }
        imotorPtr -> SetSpeed(OFF);
    }
    if (speed == LOWSPEED)
        { 
            delay(1000);
        }
    else if (speed  == MEDIUMSPEED)
    {
        delay(2000);
    }
    else if (speed == HIGHSPEED)
    {
        delay(5000);
    } 
}
