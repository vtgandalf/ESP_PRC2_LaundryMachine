#include "MotorManager.h"

bool MotorManager::Rotate(Rotation direction, Speed speed, long duration)
{
    bool response = false;
    /*//////serial.print("Motor starts rotating ");
    //////serial.print(direction);
    //////serial.print(" ");
    //////serial.print(speed);
    //////serial.print(" ");
    //////serial.print(duration);
    //////serial.print(" ... ");*/
    if (imotorPtr->CurentSpeed() != speed)
    {
        imotorPtr->SetSpeed(speed);
    }
    if (imotorPtr->CurentRotation() != direction)
    {
        imotorPtr->SetRotation(direction);
    }
    /*if ((millis() - prevMillis) / 1000 > duration)
    {
        response = true;
    }*/
    if (response)
    {
        imotorPtr->SetSpeed(OFF);
        if (speed == LOWSPEED)
        {
            //delay(1000);
        }
        else if (speed == MEDIUMSPEED)
        {
            //delay(2000);
        }
        else if (speed == HIGHSPEED)
        {
            //delay(5000);
        }
    }
    ////////serial.println("Done!");
    return response;
}

void MotorManager::SaveTime()
{
    //prevMillis = millis();
}
