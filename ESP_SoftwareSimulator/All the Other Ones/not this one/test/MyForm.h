#include "HardwareControl.h"
//#include "InputManager.h"
#include "SecurityManager.h"
#include "SoapHandler.h"
#include "CoinHandler.h"

#pragma once

namespace test {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		// 'Hardware' Objects
		HardwareControl *hwc;
		//InputManager *inm;
		SecurityManager *scm;
		SoapHandler *sph;
			 CoinHandler *cnh;

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			hwc = new HardwareControl();
			//inm = new InputManager();
			scm = new SecurityManager();
			sph = new SoapHandler();
			cnh = new CoinHandler();

			scm->setHwc(hwc);
			sph->setHwc(hwc);
			cnh->setHwc(hwc);


		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^  cbLock;
	public:
	private: System::Windows::Forms::Button^  btnCoin10;
	private: System::Windows::Forms::Button^  btnCoin50;
	private: System::Windows::Forms::Button^  btnCoin200;

	private: System::Windows::Forms::CheckBox^  cbDrain;
	public:
	private: System::Windows::Forms::CheckBox^  cbSink;
	private: System::Windows::Forms::CheckBox^  cbWaterLevel3;
	private: System::Windows::Forms::CheckBox^  cbWaterLevel1;
	private: System::Windows::Forms::CheckBox^  cbWaterLevel2;
	private: System::Windows::Forms::CheckBox^  cbTemp3;
	private: System::Windows::Forms::CheckBox^  cbTemp1;
	private: System::Windows::Forms::CheckBox^  cbTemp2;
	private: System::Windows::Forms::CheckBox^  cbHeater;
	private: System::Windows::Forms::CheckBox^  cbProgramA;
	public:
	private: System::Windows::Forms::CheckBox^  cbProgramB;
	private: System::Windows::Forms::CheckBox^  cbProgramC;

	protected:

	protected:

	private: System::Windows::Forms::CheckBox^  cbCoin200_1;
	public:
	private: System::Windows::Forms::CheckBox^  cbCoin200_2;
	private: System::Windows::Forms::CheckBox^  cbCoin50_1;
	private: System::Windows::Forms::CheckBox^  cbCoin50_2;
	private: System::Windows::Forms::CheckBox^  cbCoin50_3;
	private: System::Windows::Forms::CheckBox^  cbCoin10_3;
	private: System::Windows::Forms::CheckBox^  cbCoin10_1;
	private: System::Windows::Forms::CheckBox^  cbCoin10_2;


	private: System::Windows::Forms::Button^  btnSoap1;
	private: System::Windows::Forms::Button^  btnSoap2;


	private: System::Windows::Forms::CheckBox^  cbSoap1;

	private: System::Windows::Forms::CheckBox^  cbSoap2;




	private: System::Windows::Forms::TextBox^  tbWarnings;
	private: System::Windows::Forms::Button^  btnProgram;

	private: System::Windows::Forms::Button^  btnStart;










	private: System::Windows::Forms::Label^  lblBalance;
















	private: System::Windows::Forms::Button^  btnPressure;
	private: System::Windows::Forms::Button^  btnHeater;
	private: System::Windows::Forms::RadioButton^  rb3;



	private: System::Windows::Forms::RadioButton^  rb2;

	private: System::Windows::Forms::RadioButton^  rb1;
	private: System::Windows::Forms::RadioButton^  rb5;


	private: System::Windows::Forms::RadioButton^  rb4;
	private: System::Windows::Forms::RadioButton^  rb6;
	private: System::Windows::Forms::RadioButton^  rb17;



	private: System::Windows::Forms::RadioButton^  rb16;

	private: System::Windows::Forms::RadioButton^  rb15;

	private: System::Windows::Forms::RadioButton^  rb13;

	private: System::Windows::Forms::RadioButton^  rb12;

	private: System::Windows::Forms::RadioButton^  rb11;

	private: System::Windows::Forms::RadioButton^  rb9;

	private: System::Windows::Forms::RadioButton^  rb8;

	private: System::Windows::Forms::RadioButton^  rb7;
private: System::Windows::Forms::RadioButton^  rb18;
private: System::Windows::Forms::RadioButton^  rb19;
private: System::Windows::Forms::RadioButton^  rb20;
private: System::Windows::Forms::RadioButton^  rb21;
private: System::Windows::Forms::RadioButton^  rb22;























private: System::Windows::Forms::RadioButton^  rb10;
private: System::Windows::Forms::RadioButton^  rb14;


	private: System::Windows::Forms::Button^  btnCloseDoor;
	private: System::Windows::Forms::Button^  btnReset;










private: System::Windows::Forms::Timer^  timer;
private: System::ComponentModel::IContainer^  components;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->btnCoin10 = (gcnew System::Windows::Forms::Button());
			this->btnCoin50 = (gcnew System::Windows::Forms::Button());
			this->btnCoin200 = (gcnew System::Windows::Forms::Button());
			this->btnSoap1 = (gcnew System::Windows::Forms::Button());
			this->btnSoap2 = (gcnew System::Windows::Forms::Button());
			this->tbWarnings = (gcnew System::Windows::Forms::TextBox());
			this->btnProgram = (gcnew System::Windows::Forms::Button());
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->lblBalance = (gcnew System::Windows::Forms::Label());
			this->btnPressure = (gcnew System::Windows::Forms::Button());
			this->btnHeater = (gcnew System::Windows::Forms::Button());
			this->rb3 = (gcnew System::Windows::Forms::RadioButton());
			this->rb2 = (gcnew System::Windows::Forms::RadioButton());
			this->rb1 = (gcnew System::Windows::Forms::RadioButton());
			this->rb5 = (gcnew System::Windows::Forms::RadioButton());
			this->rb4 = (gcnew System::Windows::Forms::RadioButton());
			this->rb6 = (gcnew System::Windows::Forms::RadioButton());
			this->rb17 = (gcnew System::Windows::Forms::RadioButton());
			this->rb16 = (gcnew System::Windows::Forms::RadioButton());
			this->rb15 = (gcnew System::Windows::Forms::RadioButton());
			this->rb13 = (gcnew System::Windows::Forms::RadioButton());
			this->rb12 = (gcnew System::Windows::Forms::RadioButton());
			this->rb11 = (gcnew System::Windows::Forms::RadioButton());
			this->rb9 = (gcnew System::Windows::Forms::RadioButton());
			this->rb8 = (gcnew System::Windows::Forms::RadioButton());
			this->rb7 = (gcnew System::Windows::Forms::RadioButton());
			this->rb18 = (gcnew System::Windows::Forms::RadioButton());
			this->rb19 = (gcnew System::Windows::Forms::RadioButton());
			this->rb20 = (gcnew System::Windows::Forms::RadioButton());
			this->rb21 = (gcnew System::Windows::Forms::RadioButton());
			this->rb22 = (gcnew System::Windows::Forms::RadioButton());
			this->rb10 = (gcnew System::Windows::Forms::RadioButton());
			this->rb14 = (gcnew System::Windows::Forms::RadioButton());
			this->btnCloseDoor = (gcnew System::Windows::Forms::Button());
			this->btnReset = (gcnew System::Windows::Forms::Button());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->cbSoap1 = (gcnew System::Windows::Forms::CheckBox());
			this->cbSoap2 = (gcnew System::Windows::Forms::CheckBox());
			this->cbCoin200_1 = (gcnew System::Windows::Forms::CheckBox());
			this->cbCoin200_2 = (gcnew System::Windows::Forms::CheckBox());
			this->cbCoin50_1 = (gcnew System::Windows::Forms::CheckBox());
			this->cbCoin50_2 = (gcnew System::Windows::Forms::CheckBox());
			this->cbCoin50_3 = (gcnew System::Windows::Forms::CheckBox());
			this->cbCoin10_3 = (gcnew System::Windows::Forms::CheckBox());
			this->cbCoin10_1 = (gcnew System::Windows::Forms::CheckBox());
			this->cbCoin10_2 = (gcnew System::Windows::Forms::CheckBox());
			this->cbProgramA = (gcnew System::Windows::Forms::CheckBox());
			this->cbProgramB = (gcnew System::Windows::Forms::CheckBox());
			this->cbProgramC = (gcnew System::Windows::Forms::CheckBox());
			this->cbLock = (gcnew System::Windows::Forms::CheckBox());
			this->cbDrain = (gcnew System::Windows::Forms::CheckBox());
			this->cbSink = (gcnew System::Windows::Forms::CheckBox());
			this->cbWaterLevel3 = (gcnew System::Windows::Forms::CheckBox());
			this->cbWaterLevel1 = (gcnew System::Windows::Forms::CheckBox());
			this->cbWaterLevel2 = (gcnew System::Windows::Forms::CheckBox());
			this->cbTemp3 = (gcnew System::Windows::Forms::CheckBox());
			this->cbTemp1 = (gcnew System::Windows::Forms::CheckBox());
			this->cbTemp2 = (gcnew System::Windows::Forms::CheckBox());
			this->cbHeater = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// btnCoin10
			// 
			this->btnCoin10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->btnCoin10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCoin10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCoin10->Location = System::Drawing::Point(82, 451);
			this->btnCoin10->Name = L"btnCoin10";
			this->btnCoin10->Size = System::Drawing::Size(70, 66);
			this->btnCoin10->TabIndex = 0;
			this->btnCoin10->Text = L"¢10";
			this->btnCoin10->UseVisualStyleBackColor = false;
			this->btnCoin10->Click += gcnew System::EventHandler(this, &MyForm::btnCoin10_Click);
			// 
			// btnCoin50
			// 
			this->btnCoin50->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->btnCoin50->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCoin50->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCoin50->Location = System::Drawing::Point(158, 451);
			this->btnCoin50->Name = L"btnCoin50";
			this->btnCoin50->Size = System::Drawing::Size(70, 66);
			this->btnCoin50->TabIndex = 1;
			this->btnCoin50->Text = L"¢50";
			this->btnCoin50->UseVisualStyleBackColor = false;
			this->btnCoin50->Click += gcnew System::EventHandler(this, &MyForm::btnCoin50_Click);
			// 
			// btnCoin200
			// 
			this->btnCoin200->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->btnCoin200->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCoin200->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCoin200->Location = System::Drawing::Point(234, 451);
			this->btnCoin200->Name = L"btnCoin200";
			this->btnCoin200->Size = System::Drawing::Size(70, 66);
			this->btnCoin200->TabIndex = 2;
			this->btnCoin200->Text = L"€2";
			this->btnCoin200->UseVisualStyleBackColor = false;
			this->btnCoin200->Click += gcnew System::EventHandler(this, &MyForm::btnCoin200_Click);
			// 
			// btnSoap1
			// 
			this->btnSoap1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->btnSoap1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSoap1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSoap1->Location = System::Drawing::Point(80, 211);
			this->btnSoap1->Name = L"btnSoap1";
			this->btnSoap1->Size = System::Drawing::Size(180, 58);
			this->btnSoap1->TabIndex = 4;
			this->btnSoap1->Text = L"SOAP 1";
			this->btnSoap1->UseVisualStyleBackColor = false;
			this->btnSoap1->Click += gcnew System::EventHandler(this, &MyForm::btnSoap1_Click);
			// 
			// btnSoap2
			// 
			this->btnSoap2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->btnSoap2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSoap2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSoap2->Location = System::Drawing::Point(80, 279);
			this->btnSoap2->Name = L"btnSoap2";
			this->btnSoap2->Size = System::Drawing::Size(180, 58);
			this->btnSoap2->TabIndex = 5;
			this->btnSoap2->Text = L"SOAP 2";
			this->btnSoap2->UseVisualStyleBackColor = false;
			this->btnSoap2->Click += gcnew System::EventHandler(this, &MyForm::btnSoap2_Click);
			// 
			// tbWarnings
			// 
			this->tbWarnings->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->tbWarnings->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbWarnings->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbWarnings->Location = System::Drawing::Point(650, 533);
			this->tbWarnings->Name = L"tbWarnings";
			this->tbWarnings->Size = System::Drawing::Size(263, 28);
			this->tbWarnings->TabIndex = 9;
			this->tbWarnings->Text = L"WARNINGS";
			// 
			// btnProgram
			// 
			this->btnProgram->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->btnProgram->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnProgram->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnProgram->Location = System::Drawing::Point(904, 18);
			this->btnProgram->Name = L"btnProgram";
			this->btnProgram->Size = System::Drawing::Size(133, 106);
			this->btnProgram->TabIndex = 10;
			this->btnProgram->Text = L"Program";
			this->btnProgram->UseVisualStyleBackColor = false;
			// 
			// btnStart
			// 
			this->btnStart->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->btnStart->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnStart->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnStart->Location = System::Drawing::Point(503, 130);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(534, 59);
			this->btnStart->TabIndex = 13;
			this->btnStart->Text = L"START";
			this->btnStart->UseVisualStyleBackColor = false;
			this->btnStart->Click += gcnew System::EventHandler(this, &MyForm::btnStart_Click);
			// 
			// lblBalance
			// 
			this->lblBalance->AutoSize = true;
			this->lblBalance->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->lblBalance->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBalance->Location = System::Drawing::Point(77, 532);
			this->lblBalance->Name = L"lblBalance";
			this->lblBalance->Size = System::Drawing::Size(106, 29);
			this->lblBalance->TabIndex = 6;
			this->lblBalance->Text = L"Balance:";
			// 
			// btnPressure
			// 
			this->btnPressure->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->btnPressure->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnPressure->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnPressure->Location = System::Drawing::Point(52, 68);
			this->btnPressure->Name = L"btnPressure";
			this->btnPressure->Size = System::Drawing::Size(131, 50);
			this->btnPressure->TabIndex = 28;
			this->btnPressure->Text = L"Pressure";
			this->btnPressure->UseVisualStyleBackColor = false;
			// 
			// btnHeater
			// 
			this->btnHeater->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->btnHeater->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnHeater->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnHeater->Location = System::Drawing::Point(189, 68);
			this->btnHeater->Name = L"btnHeater";
			this->btnHeater->Size = System::Drawing::Size(131, 50);
			this->btnHeater->TabIndex = 29;
			this->btnHeater->Text = L"Heater";
			this->btnHeater->UseVisualStyleBackColor = false;
			// 
			// rb3
			// 
			this->rb3->AutoSize = true;
			this->rb3->Location = System::Drawing::Point(729, 216);
			this->rb3->Name = L"rb3";
			this->rb3->Size = System::Drawing::Size(21, 20);
			this->rb3->TabIndex = 32;
			this->rb3->TabStop = true;
			this->rb3->UseVisualStyleBackColor = true;
			// 
			// rb2
			// 
			this->rb2->AutoSize = true;
			this->rb2->Location = System::Drawing::Point(696, 216);
			this->rb2->Name = L"rb2";
			this->rb2->Size = System::Drawing::Size(21, 20);
			this->rb2->TabIndex = 31;
			this->rb2->TabStop = true;
			this->rb2->UseVisualStyleBackColor = true;
			// 
			// rb1
			// 
			this->rb1->AutoSize = true;
			this->rb1->Location = System::Drawing::Point(663, 216);
			this->rb1->Name = L"rb1";
			this->rb1->Size = System::Drawing::Size(21, 20);
			this->rb1->TabIndex = 30;
			this->rb1->TabStop = true;
			this->rb1->UseVisualStyleBackColor = true;
			// 
			// rb5
			// 
			this->rb5->AutoSize = true;
			this->rb5->Location = System::Drawing::Point(762, 244);
			this->rb5->Name = L"rb5";
			this->rb5->Size = System::Drawing::Size(21, 20);
			this->rb5->TabIndex = 34;
			this->rb5->TabStop = true;
			this->rb5->UseVisualStyleBackColor = true;
			// 
			// rb4
			// 
			this->rb4->AutoSize = true;
			this->rb4->Location = System::Drawing::Point(762, 216);
			this->rb4->Name = L"rb4";
			this->rb4->Size = System::Drawing::Size(21, 20);
			this->rb4->TabIndex = 33;
			this->rb4->TabStop = true;
			this->rb4->UseVisualStyleBackColor = true;
			// 
			// rb6
			// 
			this->rb6->AutoSize = true;
			this->rb6->Location = System::Drawing::Point(762, 273);
			this->rb6->Name = L"rb6";
			this->rb6->Size = System::Drawing::Size(21, 20);
			this->rb6->TabIndex = 36;
			this->rb6->TabStop = true;
			this->rb6->UseVisualStyleBackColor = true;
			// 
			// rb17
			// 
			this->rb17->AutoSize = true;
			this->rb17->Location = System::Drawing::Point(804, 286);
			this->rb17->Name = L"rb17";
			this->rb17->Size = System::Drawing::Size(21, 20);
			this->rb17->TabIndex = 35;
			this->rb17->TabStop = true;
			this->rb17->UseVisualStyleBackColor = true;
			// 
			// rb16
			// 
			this->rb16->AutoSize = true;
			this->rb16->Location = System::Drawing::Point(829, 316);
			this->rb16->Name = L"rb16";
			this->rb16->Size = System::Drawing::Size(21, 20);
			this->rb16->TabIndex = 37;
			this->rb16->TabStop = true;
			this->rb16->UseVisualStyleBackColor = true;
			// 
			// rb15
			// 
			this->rb15->AutoSize = true;
			this->rb15->Location = System::Drawing::Point(841, 348);
			this->rb15->Name = L"rb15";
			this->rb15->Size = System::Drawing::Size(21, 20);
			this->rb15->TabIndex = 38;
			this->rb15->TabStop = true;
			this->rb15->UseVisualStyleBackColor = true;
			// 
			// rb13
			// 
			this->rb13->AutoSize = true;
			this->rb13->Location = System::Drawing::Point(801, 407);
			this->rb13->Name = L"rb13";
			this->rb13->Size = System::Drawing::Size(21, 20);
			this->rb13->TabIndex = 39;
			this->rb13->TabStop = true;
			this->rb13->UseVisualStyleBackColor = true;
			// 
			// rb12
			// 
			this->rb12->AutoSize = true;
			this->rb12->Location = System::Drawing::Point(762, 424);
			this->rb12->Name = L"rb12";
			this->rb12->Size = System::Drawing::Size(21, 20);
			this->rb12->TabIndex = 40;
			this->rb12->TabStop = true;
			this->rb12->UseVisualStyleBackColor = true;
			// 
			// rb11
			// 
			this->rb11->AutoSize = true;
			this->rb11->Location = System::Drawing::Point(725, 407);
			this->rb11->Name = L"rb11";
			this->rb11->Size = System::Drawing::Size(21, 20);
			this->rb11->TabIndex = 41;
			this->rb11->TabStop = true;
			this->rb11->UseVisualStyleBackColor = true;
			// 
			// rb9
			// 
			this->rb9->AutoSize = true;
			this->rb9->Location = System::Drawing::Point(688, 349);
			this->rb9->Name = L"rb9";
			this->rb9->Size = System::Drawing::Size(21, 20);
			this->rb9->TabIndex = 42;
			this->rb9->TabStop = true;
			this->rb9->UseVisualStyleBackColor = true;
			// 
			// rb8
			// 
			this->rb8->AutoSize = true;
			this->rb8->Location = System::Drawing::Point(700, 311);
			this->rb8->Name = L"rb8";
			this->rb8->Size = System::Drawing::Size(21, 20);
			this->rb8->TabIndex = 43;
			this->rb8->TabStop = true;
			this->rb8->UseVisualStyleBackColor = true;
			// 
			// rb7
			// 
			this->rb7->AutoSize = true;
			this->rb7->Location = System::Drawing::Point(727, 285);
			this->rb7->Name = L"rb7";
			this->rb7->Size = System::Drawing::Size(21, 20);
			this->rb7->TabIndex = 44;
			this->rb7->TabStop = true;
			this->rb7->UseVisualStyleBackColor = true;
			// 
			// rb18
			// 
			this->rb18->AutoSize = true;
			this->rb18->Location = System::Drawing::Point(762, 454);
			this->rb18->Name = L"rb18";
			this->rb18->Size = System::Drawing::Size(21, 20);
			this->rb18->TabIndex = 45;
			this->rb18->TabStop = true;
			this->rb18->UseVisualStyleBackColor = true;
			// 
			// rb19
			// 
			this->rb19->AutoSize = true;
			this->rb19->Location = System::Drawing::Point(762, 481);
			this->rb19->Name = L"rb19";
			this->rb19->Size = System::Drawing::Size(21, 20);
			this->rb19->TabIndex = 46;
			this->rb19->TabStop = true;
			this->rb19->UseVisualStyleBackColor = true;
			// 
			// rb20
			// 
			this->rb20->AutoSize = true;
			this->rb20->Location = System::Drawing::Point(795, 481);
			this->rb20->Name = L"rb20";
			this->rb20->Size = System::Drawing::Size(21, 20);
			this->rb20->TabIndex = 47;
			this->rb20->TabStop = true;
			this->rb20->UseVisualStyleBackColor = true;
			// 
			// rb21
			// 
			this->rb21->AutoSize = true;
			this->rb21->Location = System::Drawing::Point(827, 481);
			this->rb21->Name = L"rb21";
			this->rb21->Size = System::Drawing::Size(21, 20);
			this->rb21->TabIndex = 48;
			this->rb21->TabStop = true;
			this->rb21->UseVisualStyleBackColor = true;
			// 
			// rb22
			// 
			this->rb22->AutoSize = true;
			this->rb22->Location = System::Drawing::Point(859, 481);
			this->rb22->Name = L"rb22";
			this->rb22->Size = System::Drawing::Size(21, 20);
			this->rb22->TabIndex = 49;
			this->rb22->TabStop = true;
			this->rb22->UseVisualStyleBackColor = true;
			// 
			// rb10
			// 
			this->rb10->AutoSize = true;
			this->rb10->Location = System::Drawing::Point(697, 385);
			this->rb10->Name = L"rb10";
			this->rb10->Size = System::Drawing::Size(21, 20);
			this->rb10->TabIndex = 57;
			this->rb10->TabStop = true;
			this->rb10->UseVisualStyleBackColor = true;
			// 
			// rb14
			// 
			this->rb14->AutoSize = true;
			this->rb14->Location = System::Drawing::Point(828, 383);
			this->rb14->Name = L"rb14";
			this->rb14->Size = System::Drawing::Size(21, 20);
			this->rb14->TabIndex = 58;
			this->rb14->TabStop = true;
			this->rb14->UseVisualStyleBackColor = true;
			// 
			// btnCloseDoor
			// 
			this->btnCloseDoor->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->btnCloseDoor->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCloseDoor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCloseDoor->Location = System::Drawing::Point(82, 147);
			this->btnCloseDoor->Name = L"btnCloseDoor";
			this->btnCloseDoor->Size = System::Drawing::Size(180, 58);
			this->btnCloseDoor->TabIndex = 59;
			this->btnCloseDoor->Text = L"Close Door";
			this->btnCloseDoor->UseVisualStyleBackColor = false;
			this->btnCloseDoor->Click += gcnew System::EventHandler(this, &MyForm::btnCloseDoor_Click);
			// 
			// btnReset
			// 
			this->btnReset->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->btnReset->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnReset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnReset->Location = System::Drawing::Point(310, 451);
			this->btnReset->Name = L"btnReset";
			this->btnReset->Size = System::Drawing::Size(73, 66);
			this->btnReset->TabIndex = 60;
			this->btnReset->Text = L"Reset";
			this->btnReset->UseVisualStyleBackColor = false;
			this->btnReset->Click += gcnew System::EventHandler(this, &MyForm::btnReset_Click);
			// 
			// timer
			// 
			this->timer->Enabled = true;
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// cbSoap1
			// 
			this->cbSoap1->AutoSize = true;
			this->cbSoap1->Location = System::Drawing::Point(283, 235);
			this->cbSoap1->Name = L"cbSoap1";
			this->cbSoap1->Size = System::Drawing::Size(22, 21);
			this->cbSoap1->TabIndex = 67;
			this->cbSoap1->UseVisualStyleBackColor = true;
			// 
			// cbSoap2
			// 
			this->cbSoap2->AutoSize = true;
			this->cbSoap2->Location = System::Drawing::Point(282, 303);
			this->cbSoap2->Name = L"cbSoap2";
			this->cbSoap2->Size = System::Drawing::Size(22, 21);
			this->cbSoap2->TabIndex = 68;
			this->cbSoap2->UseVisualStyleBackColor = true;
			// 
			// cbCoin200_1
			// 
			this->cbCoin200_1->AutoSize = true;
			this->cbCoin200_1->Location = System::Drawing::Point(259, 423);
			this->cbCoin200_1->Name = L"cbCoin200_1";
			this->cbCoin200_1->Size = System::Drawing::Size(22, 21);
			this->cbCoin200_1->TabIndex = 70;
			this->cbCoin200_1->UseVisualStyleBackColor = true;
			// 
			// cbCoin200_2
			// 
			this->cbCoin200_2->AutoSize = true;
			this->cbCoin200_2->Location = System::Drawing::Point(259, 396);
			this->cbCoin200_2->Name = L"cbCoin200_2";
			this->cbCoin200_2->Size = System::Drawing::Size(22, 21);
			this->cbCoin200_2->TabIndex = 69;
			this->cbCoin200_2->UseVisualStyleBackColor = true;
			// 
			// cbCoin50_1
			// 
			this->cbCoin50_1->AutoSize = true;
			this->cbCoin50_1->Location = System::Drawing::Point(189, 425);
			this->cbCoin50_1->Name = L"cbCoin50_1";
			this->cbCoin50_1->Size = System::Drawing::Size(22, 21);
			this->cbCoin50_1->TabIndex = 72;
			this->cbCoin50_1->UseVisualStyleBackColor = true;
			// 
			// cbCoin50_2
			// 
			this->cbCoin50_2->AutoSize = true;
			this->cbCoin50_2->Location = System::Drawing::Point(189, 398);
			this->cbCoin50_2->Name = L"cbCoin50_2";
			this->cbCoin50_2->Size = System::Drawing::Size(22, 21);
			this->cbCoin50_2->TabIndex = 71;
			this->cbCoin50_2->UseVisualStyleBackColor = true;
			// 
			// cbCoin50_3
			// 
			this->cbCoin50_3->AutoSize = true;
			this->cbCoin50_3->Location = System::Drawing::Point(189, 371);
			this->cbCoin50_3->Name = L"cbCoin50_3";
			this->cbCoin50_3->Size = System::Drawing::Size(22, 21);
			this->cbCoin50_3->TabIndex = 73;
			this->cbCoin50_3->UseVisualStyleBackColor = true;
			// 
			// cbCoin10_3
			// 
			this->cbCoin10_3->AutoSize = true;
			this->cbCoin10_3->Location = System::Drawing::Point(109, 369);
			this->cbCoin10_3->Name = L"cbCoin10_3";
			this->cbCoin10_3->Size = System::Drawing::Size(22, 21);
			this->cbCoin10_3->TabIndex = 76;
			this->cbCoin10_3->UseVisualStyleBackColor = true;
			// 
			// cbCoin10_1
			// 
			this->cbCoin10_1->AutoSize = true;
			this->cbCoin10_1->Location = System::Drawing::Point(109, 423);
			this->cbCoin10_1->Name = L"cbCoin10_1";
			this->cbCoin10_1->Size = System::Drawing::Size(22, 21);
			this->cbCoin10_1->TabIndex = 75;
			this->cbCoin10_1->UseVisualStyleBackColor = true;
			// 
			// cbCoin10_2
			// 
			this->cbCoin10_2->AutoSize = true;
			this->cbCoin10_2->Location = System::Drawing::Point(109, 396);
			this->cbCoin10_2->Name = L"cbCoin10_2";
			this->cbCoin10_2->Size = System::Drawing::Size(22, 21);
			this->cbCoin10_2->TabIndex = 74;
			this->cbCoin10_2->UseVisualStyleBackColor = true;
			// 
			// cbProgramA
			// 
			this->cbProgramA->AutoSize = true;
			this->cbProgramA->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->cbProgramA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cbProgramA->Location = System::Drawing::Point(584, 54);
			this->cbProgramA->Name = L"cbProgramA";
			this->cbProgramA->Size = System::Drawing::Size(60, 36);
			this->cbProgramA->TabIndex = 77;
			this->cbProgramA->Text = L"A";
			this->cbProgramA->UseVisualStyleBackColor = false;
			// 
			// cbProgramB
			// 
			this->cbProgramB->AutoSize = true;
			this->cbProgramB->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->cbProgramB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cbProgramB->Location = System::Drawing::Point(700, 54);
			this->cbProgramB->Name = L"cbProgramB";
			this->cbProgramB->Size = System::Drawing::Size(60, 36);
			this->cbProgramB->TabIndex = 78;
			this->cbProgramB->Text = L"B";
			this->cbProgramB->UseVisualStyleBackColor = false;
			// 
			// cbProgramC
			// 
			this->cbProgramC->AutoSize = true;
			this->cbProgramC->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->cbProgramC->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cbProgramC->Location = System::Drawing::Point(817, 54);
			this->cbProgramC->Name = L"cbProgramC";
			this->cbProgramC->Size = System::Drawing::Size(61, 36);
			this->cbProgramC->TabIndex = 79;
			this->cbProgramC->Text = L"C";
			this->cbProgramC->UseVisualStyleBackColor = false;
			// 
			// cbLock
			// 
			this->cbLock->AutoSize = true;
			this->cbLock->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->cbLock->Location = System::Drawing::Point(735, 310);
			this->cbLock->Name = L"cbLock";
			this->cbLock->Size = System::Drawing::Size(69, 24);
			this->cbLock->TabIndex = 80;
			this->cbLock->Text = L"Lock";
			this->cbLock->UseVisualStyleBackColor = false;
			// 
			// cbDrain
			// 
			this->cbDrain->AutoSize = true;
			this->cbDrain->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->cbDrain->Location = System::Drawing::Point(571, 215);
			this->cbDrain->Name = L"cbDrain";
			this->cbDrain->Size = System::Drawing::Size(73, 24);
			this->cbDrain->TabIndex = 81;
			this->cbDrain->Text = L"Drain";
			this->cbDrain->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->cbDrain->UseVisualStyleBackColor = false;
			// 
			// cbSink
			// 
			this->cbSink->AutoSize = true;
			this->cbSink->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->cbSink->Location = System::Drawing::Point(904, 480);
			this->cbSink->Name = L"cbSink";
			this->cbSink->Size = System::Drawing::Size(66, 24);
			this->cbSink->TabIndex = 82;
			this->cbSink->Text = L"Sink";
			this->cbSink->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->cbSink->UseVisualStyleBackColor = false;
			// 
			// cbWaterLevel3
			// 
			this->cbWaterLevel3->AutoSize = true;
			this->cbWaterLevel3->Location = System::Drawing::Point(738, 338);
			this->cbWaterLevel3->Name = L"cbWaterLevel3";
			this->cbWaterLevel3->Size = System::Drawing::Size(22, 21);
			this->cbWaterLevel3->TabIndex = 85;
			this->cbWaterLevel3->UseVisualStyleBackColor = true;
			// 
			// cbWaterLevel1
			// 
			this->cbWaterLevel1->AutoSize = true;
			this->cbWaterLevel1->Location = System::Drawing::Point(738, 380);
			this->cbWaterLevel1->Name = L"cbWaterLevel1";
			this->cbWaterLevel1->Size = System::Drawing::Size(22, 21);
			this->cbWaterLevel1->TabIndex = 84;
			this->cbWaterLevel1->UseVisualStyleBackColor = true;
			// 
			// cbWaterLevel2
			// 
			this->cbWaterLevel2->AutoSize = true;
			this->cbWaterLevel2->Location = System::Drawing::Point(738, 359);
			this->cbWaterLevel2->Name = L"cbWaterLevel2";
			this->cbWaterLevel2->Size = System::Drawing::Size(22, 21);
			this->cbWaterLevel2->TabIndex = 83;
			this->cbWaterLevel2->UseVisualStyleBackColor = true;
			// 
			// cbTemp3
			// 
			this->cbTemp3->AutoSize = true;
			this->cbTemp3->Location = System::Drawing::Point(785, 339);
			this->cbTemp3->Name = L"cbTemp3";
			this->cbTemp3->Size = System::Drawing::Size(22, 21);
			this->cbTemp3->TabIndex = 88;
			this->cbTemp3->UseVisualStyleBackColor = true;
			// 
			// cbTemp1
			// 
			this->cbTemp1->AutoSize = true;
			this->cbTemp1->Location = System::Drawing::Point(785, 381);
			this->cbTemp1->Name = L"cbTemp1";
			this->cbTemp1->Size = System::Drawing::Size(22, 21);
			this->cbTemp1->TabIndex = 87;
			this->cbTemp1->UseVisualStyleBackColor = true;
			// 
			// cbTemp2
			// 
			this->cbTemp2->AutoSize = true;
			this->cbTemp2->Location = System::Drawing::Point(785, 360);
			this->cbTemp2->Name = L"cbTemp2";
			this->cbTemp2->Size = System::Drawing::Size(22, 21);
			this->cbTemp2->TabIndex = 86;
			this->cbTemp2->UseVisualStyleBackColor = true;
			// 
			// cbHeater
			// 
			this->cbHeater->AutoSize = true;
			this->cbHeater->Location = System::Drawing::Point(761, 386);
			this->cbHeater->Name = L"cbHeater";
			this->cbHeater->Size = System::Drawing::Size(22, 21);
			this->cbHeater->TabIndex = 89;
			this->cbHeater->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)), static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(66)));
			this->ClientSize = System::Drawing::Size(1058, 590);
			this->Controls->Add(this->cbHeater);
			this->Controls->Add(this->cbTemp3);
			this->Controls->Add(this->cbTemp1);
			this->Controls->Add(this->cbTemp2);
			this->Controls->Add(this->cbWaterLevel3);
			this->Controls->Add(this->cbWaterLevel1);
			this->Controls->Add(this->cbWaterLevel2);
			this->Controls->Add(this->cbSink);
			this->Controls->Add(this->cbDrain);
			this->Controls->Add(this->cbLock);
			this->Controls->Add(this->cbProgramC);
			this->Controls->Add(this->cbProgramB);
			this->Controls->Add(this->cbProgramA);
			this->Controls->Add(this->cbCoin10_3);
			this->Controls->Add(this->cbCoin10_1);
			this->Controls->Add(this->cbCoin10_2);
			this->Controls->Add(this->cbCoin50_3);
			this->Controls->Add(this->cbCoin50_1);
			this->Controls->Add(this->cbCoin50_2);
			this->Controls->Add(this->cbCoin200_1);
			this->Controls->Add(this->cbCoin200_2);
			this->Controls->Add(this->cbSoap2);
			this->Controls->Add(this->cbSoap1);
			this->Controls->Add(this->btnReset);
			this->Controls->Add(this->btnCloseDoor);
			this->Controls->Add(this->rb14);
			this->Controls->Add(this->rb10);
			this->Controls->Add(this->rb22);
			this->Controls->Add(this->rb21);
			this->Controls->Add(this->rb20);
			this->Controls->Add(this->rb19);
			this->Controls->Add(this->rb18);
			this->Controls->Add(this->rb7);
			this->Controls->Add(this->rb8);
			this->Controls->Add(this->rb9);
			this->Controls->Add(this->rb11);
			this->Controls->Add(this->rb12);
			this->Controls->Add(this->rb13);
			this->Controls->Add(this->rb15);
			this->Controls->Add(this->rb16);
			this->Controls->Add(this->rb6);
			this->Controls->Add(this->rb17);
			this->Controls->Add(this->rb5);
			this->Controls->Add(this->rb4);
			this->Controls->Add(this->rb3);
			this->Controls->Add(this->rb2);
			this->Controls->Add(this->rb1);
			this->Controls->Add(this->btnHeater);
			this->Controls->Add(this->btnPressure);
			this->Controls->Add(this->btnStart);
			this->Controls->Add(this->btnProgram);
			this->Controls->Add(this->tbWarnings);
			this->Controls->Add(this->lblBalance);
			this->Controls->Add(this->btnSoap2);
			this->Controls->Add(this->btnSoap1);
			this->Controls->Add(this->btnCoin200);
			this->Controls->Add(this->btnCoin50);
			this->Controls->Add(this->btnCoin10);
			this->Name = L"MyForm";
			this->Text = L"Laundry Machine Software Simulator";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


private: System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e) {
	//asyiaap++;
	//bool temp[3] = { false,false,false };
	//temp = hwc->SetCoin10Led(2);
}
private: System::Void btnCloseDoor_Click(System::Object^  sender, System::EventArgs^  e) {
	hwc->SetGlobalInputByte(0b01000);
}

private: System::Void timer_Tick(System::Object^  sender, System::EventArgs^  e) {
	
	// Check Inputs

	// Call all polling functions
	scm->Polling();
	sph->Polling();
	cnh->Polling();
	//inm->Polling();

	// Handle Outputs
	cbLock->Checked = hwc->Lock();
	cbSoap1->Checked = hwc->Soap1();
	cbSoap2->Checked = hwc->Soap2();
	cbCoin10_1->Checked = (hwc->Coin10()) & 0b001;
	cbCoin10_2->Checked = (hwc->Coin10()) & 0b010;
	cbCoin10_3->Checked = (hwc->Coin10()) & 0b100;
	cbCoin50_1->Checked = (hwc->Coin50()) & 0b001;
	cbCoin50_2->Checked = (hwc->Coin50()) & 0b010;
	cbCoin50_3->Checked = (hwc->Coin50()) & 0b100;
	cbCoin200_1->Checked = (hwc->Coin200()) & 0b01;
	cbCoin200_2->Checked = (hwc->Coin200()) & 0b10;

}
private: System::Void btnSoap1_Click(System::Object^  sender, System::EventArgs^  e) {
	hwc->SetGlobalInputByte(0b00010);
}
private: System::Void btnSoap2_Click(System::Object^  sender, System::EventArgs^  e) {
	hwc->SetGlobalInputByte(0b00100);

}
private: System::Void btnCoin10_Click(System::Object^  sender, System::EventArgs^  e) {
	hwc->SetGlobalInputByte(0b11000);
}
private: System::Void btnCoin50_Click(System::Object^  sender, System::EventArgs^  e) {
	hwc->SetGlobalInputByte(0b10100);

}
private: System::Void btnCoin200_Click(System::Object^  sender, System::EventArgs^  e) {
	hwc->SetGlobalInputByte(0b10010);
}
private: System::Void btnReset_Click(System::Object^  sender, System::EventArgs^  e) {
	hwc->SetGlobalInputByte(0b11110);
}
};
}
