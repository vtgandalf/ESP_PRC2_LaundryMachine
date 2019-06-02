#include "lib/Program.h"
#include "lib/HardwareControl.h"
#include "lib/InputManager.h"
#include "lib/HeaterHandler.h"
#include "lib/Controller.h"

Controller ctrl;

void setup()
{

}

void loop()
{
    ctrl.MainStateMachine();
}
