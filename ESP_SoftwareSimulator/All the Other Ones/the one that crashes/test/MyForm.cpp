#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//WinformCDemo is your project name
	test::MyForm MyForm;
	
	Application::Run(%MyForm);
	/*
	while (1)
	{
		// Test Program Here
		MyForm.rbSoap2_On = LED_Soap;
	}
	*/
	
}

