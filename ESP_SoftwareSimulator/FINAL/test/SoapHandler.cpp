#include "SoapHandler.h"

// Macros for the max values that you can add for each compartment
#define soap1max 2
#define soap2max 3

/* Method that indicates the user if the soap is not enough 
by blink the appropriate leds*/
void SoapHandler::IndicateMissingSoap(int soap1Required, int soap2Required)
{
    /* Blink the leds depending how much soap is missing */
    for (int i = 0; i < (soap1Required - soap1); i++)
    {
        isoapPtr->SetSoap1Led(true);
        //delay(250);
        isoapPtr->SetSoap1Led(false);
        //delay(250);
    }
    /* Blink the leds depending how much soap is missing */
    for (int i = 0; i < (soap2Required - soap2); i++)
    {
        isoapPtr->SetSoap2Led(true);
        //delay(250);
        isoapPtr->SetSoap2Led(false);
        //delay(250);
    }
}

/* Method that checks if there is enough soap added */
bool SoapHandler::IsSoapEnough(int soap1Required, int soap2Required)
{
    // Var for the response
    bool returnVal;
    // If either of the soap types is not enough
    if ((soap1 < soap1Required) | (soap2 < soap2Required))
    {
        // Set the response to false
        returnVal = false;
        // Indicate how much soap is missing (leds)
        IndicateMissingSoap(soap1Required, soap2Required);
    }
    // If there is enough soap
    else
    {
        // Set the response to true
        returnVal = true;
    }
    // Return the response
    return returnVal;
}

// Method to handle updating the leds according to the soap vars
void SoapHandler::SetLed()
{
    // If maximum amount of soap has been added
    if (soap1 == soap1max)
    {
        // If the led hasn't been already set
        if (!soap1LedHasBeenSetUp)
        {
            // Turn on the led
            isoapPtr->SetSoap1Led(true);
            // Show that it has been turned on
            soap1LedHasBeenSetUp = true;
            //Serial.println("SetSoap1Led has been set.");
        }
    }
    // If maximum amount of soap has been added
    if (soap2 == soap2max)
    {
        // If the led hasn't been already set
        if (!soap2LedHasBeenSetUp)
        {
            // Turn on the led
            isoapPtr->SetSoap2Led(true);
            // Show that it has been turned on
            soap2LedHasBeenSetUp = true;
            //Serial.println("SetSoap2Led has been set.");
        }
    }
}

// Method that handles the soap switches actions
void SoapHandler::InsertSoap()
{
    /* If the current compartment is not full and the
    switch has been pressed */
    if ((soap1 < soap1max) && isoapPtr->Soap1Action())
    {
        // Increment the soap counter
        soap1++;
        // Indicate that the led should update
        soap1LedHasBeenSetUp = false;
        //Serial.print("Soap1 has been added.");
        //Serial.println(soap1);
    }
    /* If the current compartment is not full and the
    switch has been pressed */
    if ((soap2 < soap2max) && isoapPtr->Soap2Action())
    {
        // Increment the soap counter
        soap2++;
        // Indicate that the led should update
        soap2LedHasBeenSetUp = false;
        //Serial.print("Soap2 has been added.");
        //Serial.println(soap2);
    }
}

// Method that handles the polling functions
void SoapHandler::Polling()
{
    // Read if any input
    InsertSoap();
    // Update the leds
    SetLed();
}

// Method that handles taking x amount of soap from the compartment
bool SoapHandler::UseSoap1(int x)
{
    // If x could be taken
    if (soap1 - x >= 0)
    {
        //Serial.println("Soap 1 added!");
        // Take the amount
        soap1 -= x;
        // Turn off the led for that compartment
        isoapPtr->SetSoap1Led(false);
        // Return true (soap has been taken)
        return true;
    }
    else
    {
        // Return false (there was an error)
        return false;
    }
}

// Method that handles taking x amount of soap from the compartment
bool SoapHandler::UseSoap2(int x)
{
    //Serial.println("Soap 2 added!");
    // If x could be taken
    if (soap2 - x >= 0)
    {
        // Take the amount
        soap2 -= x;
        // Turn off the led for the compartment
        isoapPtr->SetSoap2Led(false);
        // Return true (soap has been taken)
        return true;
    }
    else
    {
        // Return false (there was an error)
        return false;
    }
}