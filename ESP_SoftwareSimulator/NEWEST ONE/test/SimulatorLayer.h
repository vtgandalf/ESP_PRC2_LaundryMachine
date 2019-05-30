#pragma once
ref class SimulatorLayer
{
public:
	SimulatorLayer();

	typedef enum {
		// Input (Buttons)
		simBtnPressure,
		simBtnHeater,
		simBtnCloseDoor,
		simBtnSoap1,
		simBtnSoap2,
		simBtnCoin10,
		simBtnCoin50,
		simBtnCoin200,
		simBtnReset,
		simBtnProgram,
		simBtnStart,
		// Output (radioButtons)
		simRbSoap1,
		simRbSoap2,
		simRbCoin10_1,
		simRbCoin10_2,
		simRbCoin10_3,
		simRbCoin50_1,
		simRbCoin50_2,
		simRbCoin50_3,
		simRbCoin200_1,
		simRbCoin200_2,
		simRbProgramA,
		simRbProgramB,
		simRbProgramC,
		simRbDrain,
		simRbSink,
		simRbLock,
		simRb1,
		simRb2,
		simRb3,
		simRb4,
		simRb5,
		simRb6,
		simRb7,
		simRb8,
		simRb9,
		simRb10,
		simRb11,
		simRb12,
		simRb13,
		simRb14,
		simRb15,
		simRb16,
		simRb17,
		simRb18,
		simRb19,
		simRb20,
		simRb21,
		simRb22,
		simRbHeater,
		simRbTemp1,
		simRbTemp2,
		simRbTemp3,
		simRbWaterLevel1,
		simRbWaterLevel2,
		simRbWaterLevel3
	}simPins;

	bool digitalRead(simPins pin);
	void digitalWrite(simPins pin, bool value);
};

