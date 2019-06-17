#include "SimulatorLayer.h"
#include "HardwareControl.h"



SimulatorLayer::SimulatorLayer()
{

}

bool SimulatorLayer::digitalRead(simPins pin) {
	// Read the values from specific "pins" of the form
	switch (pin)
	{
		// Input (Buttons)
	case simBtnPressure:
		
		break;
	case simBtnHeater:
		break;
	case simBtnCloseDoor:
		break;
	case simBtnSoap1:
		break;
	case simBtnSoap2:
		break;
	case simBtnCoin10:
		break;
	case simBtnCoin50:
		break;
	case simBtnCoin200:
		break;
	case simBtnReset:
		break;
	case simBtnProgram:
		break;
	case simBtnStart:
		break;

		// Output (radioButtons)
	case simRbSoap1:
		return rbSoap1.Checked;
		break;
	case simRbSoap2:
		break;
	case simRbCoin10_1:
		break;
	case simRbCoin10_2:
		break;
	case simRbCoin10_3:
		break;
	case simRbCoin50_1:
		break;
	case simRbCoin50_2:
		break;
	case simRbCoin50_3:
		break;
	case simRbCoin200_1:
		break;
	case simRbCoin200_2:
		break;
	case simRbProgramA:
		break;
	case simRbProgramB:
		break;
	case simRbProgramC:
		break;
	case simRbDrain:
		break;
	case simRbSink:
		break;
	case simRbLock:
		break;
	case simRb1:
		break;
	case simRb2:
		break;
	case simRb3:
		break;
	case simRb4:
		break;
	case simRb5:
		break;
	case simRb6:
		break;
	case simRb7:
		break;
	case simRb8:
		break;
	case simRb9:
		break;
	case simRb10:
		break;
	case simRb11:
		break;
	case simRb12:
		break;
	case simRb13:
		break;
	case simRb14:
		break;
	case simRb15:
		break;
	case simRb16:
		break;
	case simRb17:
		break;
	case simRb18:
		break;
	case simRb19:
		break;
	case simRb20:
		break;
	case simRb21:
		break;
	case simRb22:
		break;
	case simRbHeater:
		break;
	case simRbTemp1:
		break;
	case simRbTemp2:
		break;
	case simRbTemp3:
		break;
	case simRbWaterLevel1:
		break;
	case simRbWaterLevel2:
		break;
	case simRbWaterLevel3:
		break;
	}
}

void SimulatorLayer::digitalWrite(simPins pin, bool value) {
	// Write the values to specific "pins" on the form
	switch (pin)
	{
		// Input (Buttons)
	case simBtnPressure:

		break;
	case simBtnHeater:
		break;
	case simBtnCloseDoor:
		break;
	case simBtnSoap1:
		break;
	case simBtnSoap2:
		break;
	case simBtnCoin10:
		break;
	case simBtnCoin50:
		break;
	case simBtnCoin200:
		break;
	case simBtnReset:
		break;
	case simBtnProgram:
		break;
	case simBtnStart:
		break;

		// Output (radioButtons)
	case simRbSoap1:
		break;
	case simRbSoap2:
		break;
	case simRbCoin10_1:
		break;
	case simRbCoin10_2:
		break;
	case simRbCoin10_3:
		break;
	case simRbCoin50_1:
		break;
	case simRbCoin50_2:
		break;
	case simRbCoin50_3:
		break;
	case simRbCoin200_1:
		break;
	case simRbCoin200_2:
		break;
	case simRbProgramA:
		break;
	case simRbProgramB:
		break;
	case simRbProgramC:
		break;
	case simRbDrain:
		break;
	case simRbSink:
		break;
	case simRbLock:
		break;
	case simRb1:
		break;
	case simRb2:
		break;
	case simRb3:
		break;
	case simRb4:
		break;
	case simRb5:
		break;
	case simRb6:
		break;
	case simRb7:
		break;
	case simRb8:
		break;
	case simRb9:
		break;
	case simRb10:
		break;
	case simRb11:
		break;
	case simRb12:
		break;
	case simRb13:
		break;
	case simRb14:
		break;
	case simRb15:
		break;
	case simRb16:
		break;
	case simRb17:
		break;
	case simRb18:
		break;
	case simRb19:
		break;
	case simRb20:
		break;
	case simRb21:
		break;
	case simRb22:
		break;
	case simRbHeater:
		break;
	case simRbTemp1:
		break;
	case simRbTemp2:
		break;
	case simRbTemp3:
		break;
	case simRbWaterLevel1:
		break;
	case simRbWaterLevel2:
		break;
	case simRbWaterLevel3:
		break;
	}
}

