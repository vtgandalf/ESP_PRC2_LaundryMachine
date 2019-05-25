#include "../lib/MotorManager.h"

bool MotorManager::Rotate(Rotation direction, Speed speed, long duration)
{
    bool response = false;
    /*Serial.print("Motor starts rotating ");
    Serial.print(direction);
    Serial.print(" ");
    Serial.print(speed);
    Serial.print(" ");
    Serial.print(duration);
    Serial.print(" ... ");*/
    if (imotorPtr->CurentSpeed() != speed)
    {
        imotorPtr->SetSpeed(speed);
    }
    if (imotorPtr->CurentRotation() != direction)
    {
        imotorPtr->SetRotation(direction);
    }
    if ((millis() - prevMillis) / 1000 > duration)
    {
        response = true;
    }
    if (response)
    {
        imotorPtr->SetSpeed(OFF);
        if (speed == LOWSPEED)
        {
            delay(1000);
        }
        else if (speed == MEDIUMSPEED)
        {
            delay(2000);
        }
        else if (speed == HIGHSPEED)
        {
            delay(5000);
        }
    }
    //Serial.println("Done!");
    return response;
}

void MotorManager::SaveTime()
{
    prevMillis = millis();
}
