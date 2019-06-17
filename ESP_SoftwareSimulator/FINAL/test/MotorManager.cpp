#include <windows.h>
#include "MotorManager.h"

// Method that handles rotating the tank
bool MotorManager::Rotate(Rotation direction, Speed speed, long duration)
{
    // Var for the response
    bool response = false;
    // If the speed hasnt been set
    if (imotorPtr->CurentSpeed() != speed)
    {
        // Set it
        imotorPtr->SetSpeed(speed);
    }
    // If the rotation direction hasnt been set
    if (imotorPtr->CurentRotation() != direction)
    {
        // Set it
        imotorPtr->SetRotation(direction);
    }
    // If the tank has been rotating for long enough
    if ((GetTickCount() - prevMillis) / 1000 > duration)
    {
        // Set the response to true
        response = true;
    }
    // If the tank has bee rotation for long enough
    if (response)
    {
        // Turn it off
        imotorPtr->SetSpeed(OFF);
        /* Based on the speed it had been rotating add delay
        so the tank can spin down */
        if (speed == LOWSPEED)
        {
            Sleep(1000);
        }
        else if (speed == MEDIUMSPEED)
        {
            Sleep(2000);
        }
        else if (speed == HIGHSPEED)
        {
            Sleep(5000);
        }
    }
    // Return the response
    return response;
}

// Method that saves the current time for further use
void MotorManager::SaveTime()
{
    prevMillis = GetTickCount();
}
