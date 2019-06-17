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
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
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
	private: System::Windows::Forms::Button^  btnCoin10;
	private: System::Windows::Forms::Button^  btnCoin50;
	private: System::Windows::Forms::Button^  btnCoin200;

	protected:

	protected:



	private: System::Windows::Forms::Button^  btnSoap1;
	private: System::Windows::Forms::Button^  btnSoap2;






	private: System::Windows::Forms::TextBox^  tbWarnings;
	private: System::Windows::Forms::Button^  btnProgram;

	private: System::Windows::Forms::Button^  btnStart;



	private: System::Windows::Forms::RadioButton^  rbSoap1;
	private: System::Windows::Forms::RadioButton^  rbSoap2;





	private: System::Windows::Forms::Label^  lblBalance;
	private: System::Windows::Forms::RadioButton^  rbCoin10_1;
	private: System::Windows::Forms::RadioButton^  rbCoin10_2;
	private: System::Windows::Forms::RadioButton^  rbCoin10_3;
	private: System::Windows::Forms::RadioButton^  rbCoin50_1;
	private: System::Windows::Forms::RadioButton^  rbCoin50_2;
	private: System::Windows::Forms::RadioButton^  rbCoin50_3;
	private: System::Windows::Forms::RadioButton^  rbCoin200_1;
	private: System::Windows::Forms::RadioButton^  rbCoin200_2;








	private: System::Windows::Forms::Button^  btnPressure;
	private: System::Windows::Forms::Button^  btnHeater;


	private: System::Windows::Forms::RadioButton^  radioButton14;
	private: System::Windows::Forms::RadioButton^  radioButton15;
	private: System::Windows::Forms::RadioButton^  radioButton16;
	private: System::Windows::Forms::RadioButton^  radioButton17;
	private: System::Windows::Forms::RadioButton^  radioButton18;
	private: System::Windows::Forms::RadioButton^  radioButton19;
	private: System::Windows::Forms::RadioButton^  radioButton20;
	private: System::Windows::Forms::RadioButton^  radioButton21;
	private: System::Windows::Forms::RadioButton^  radioButton22;
	private: System::Windows::Forms::RadioButton^  radioButton23;
	private: System::Windows::Forms::RadioButton^  radioButton24;
	private: System::Windows::Forms::RadioButton^  radioButton25;
	private: System::Windows::Forms::RadioButton^  radioButton26;
	private: System::Windows::Forms::RadioButton^  radioButton27;
	private: System::Windows::Forms::RadioButton^  radioButton28;
	private: System::Windows::Forms::RadioButton^  radioButton29;
	private: System::Windows::Forms::RadioButton^  radioButton30;
	private: System::Windows::Forms::RadioButton^  radioButton31;
	private: System::Windows::Forms::RadioButton^  radioButton32;
	private: System::Windows::Forms::RadioButton^  radioButton33;
	private: System::Windows::Forms::RadioButton^  radioButton34;
	private: System::Windows::Forms::RadioButton^  radioButton35;
	private: System::Windows::Forms::RadioButton^  radioButton36;
	private: System::Windows::Forms::RadioButton^  radioButton37;
	private: System::Windows::Forms::RadioButton^  radioButton38;
	private: System::Windows::Forms::RadioButton^  radioButton39;
	private: System::Windows::Forms::RadioButton^  radioButton40;
	private: System::Windows::Forms::RadioButton^  radioButton41;
	private: System::Windows::Forms::RadioButton^  radioButton42;
private: System::Windows::Forms::RadioButton^  rbProgramA;
private: System::Windows::Forms::RadioButton^  rbProgramB;
private: System::Windows::Forms::RadioButton^  rbProgramC;
private: System::Windows::Forms::RadioButton^  rbDrain;
private: System::Windows::Forms::RadioButton^  rbSink;
private: System::Windows::Forms::RadioButton^  rbDoorLock;






private: System::Windows::Forms::Button^  btnReset;

	private: System::Windows::Forms::Button^  btnLockDoor;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnCoin10 = (gcnew System::Windows::Forms::Button());
			this->btnCoin50 = (gcnew System::Windows::Forms::Button());
			this->btnCoin200 = (gcnew System::Windows::Forms::Button());
			this->btnSoap1 = (gcnew System::Windows::Forms::Button());
			this->btnSoap2 = (gcnew System::Windows::Forms::Button());
			this->tbWarnings = (gcnew System::Windows::Forms::TextBox());
			this->btnProgram = (gcnew System::Windows::Forms::Button());
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->rbSoap1 = (gcnew System::Windows::Forms::RadioButton());
			this->rbSoap2 = (gcnew System::Windows::Forms::RadioButton());
			this->lblBalance = (gcnew System::Windows::Forms::Label());
			this->rbCoin10_1 = (gcnew System::Windows::Forms::RadioButton());
			this->rbCoin10_2 = (gcnew System::Windows::Forms::RadioButton());
			this->rbCoin10_3 = (gcnew System::Windows::Forms::RadioButton());
			this->rbCoin50_1 = (gcnew System::Windows::Forms::RadioButton());
			this->rbCoin50_2 = (gcnew System::Windows::Forms::RadioButton());
			this->rbCoin50_3 = (gcnew System::Windows::Forms::RadioButton());
			this->rbCoin200_1 = (gcnew System::Windows::Forms::RadioButton());
			this->rbCoin200_2 = (gcnew System::Windows::Forms::RadioButton());
			this->btnPressure = (gcnew System::Windows::Forms::Button());
			this->btnHeater = (gcnew System::Windows::Forms::Button());
			this->radioButton14 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton15 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton16 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton17 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton18 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton19 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton20 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton21 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton22 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton23 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton24 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton25 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton26 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton27 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton28 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton29 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton30 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton31 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton32 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton33 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton34 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton35 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton36 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton37 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton38 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton39 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton40 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton41 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton42 = (gcnew System::Windows::Forms::RadioButton());
			this->rbProgramA = (gcnew System::Windows::Forms::RadioButton());
			this->rbProgramB = (gcnew System::Windows::Forms::RadioButton());
			this->rbProgramC = (gcnew System::Windows::Forms::RadioButton());
			this->rbDrain = (gcnew System::Windows::Forms::RadioButton());
			this->rbSink = (gcnew System::Windows::Forms::RadioButton());
			this->rbDoorLock = (gcnew System::Windows::Forms::RadioButton());
			this->btnReset = (gcnew System::Windows::Forms::Button());
			this->btnLockDoor = (gcnew System::Windows::Forms::Button());
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
			// 
			// btnSoap1
			// 
			this->btnSoap1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->btnSoap1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSoap1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSoap1->Location = System::Drawing::Point(80, 196);
			this->btnSoap1->Name = L"btnSoap1";
			this->btnSoap1->Size = System::Drawing::Size(180, 58);
			this->btnSoap1->TabIndex = 4;
			this->btnSoap1->Text = L"SOAP 1";
			this->btnSoap1->UseVisualStyleBackColor = false;
			// 
			// btnSoap2
			// 
			this->btnSoap2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->btnSoap2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSoap2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSoap2->Location = System::Drawing::Point(80, 264);
			this->btnSoap2->Name = L"btnSoap2";
			this->btnSoap2->Size = System::Drawing::Size(180, 58);
			this->btnSoap2->TabIndex = 5;
			this->btnSoap2->Text = L"SOAP 2";
			this->btnSoap2->UseVisualStyleBackColor = false;
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
			this->btnProgram->Location = System::Drawing::Point(896, 12);
			this->btnProgram->Name = L"btnProgram";
			this->btnProgram->Size = System::Drawing::Size(137, 106);
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
			// 
			// rbSoap1
			// 
			this->rbSoap1->AutoSize = true;
			this->rbSoap1->Location = System::Drawing::Point(283, 219);
			this->rbSoap1->Name = L"rbSoap1";
			this->rbSoap1->Size = System::Drawing::Size(21, 20);
			this->rbSoap1->TabIndex = 14;
			this->rbSoap1->UseVisualStyleBackColor = true;
			// 
			// rbSoap2
			// 
			this->rbSoap2->AutoSize = true;
			this->rbSoap2->Location = System::Drawing::Point(283, 287);
			this->rbSoap2->Name = L"rbSoap2";
			this->rbSoap2->Size = System::Drawing::Size(21, 20);
			this->rbSoap2->TabIndex = 16;
			this->rbSoap2->UseVisualStyleBackColor = true;
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
			// rbCoin10_1
			// 
			this->rbCoin10_1->AutoSize = true;
			this->rbCoin10_1->Location = System::Drawing::Point(108, 425);
			this->rbCoin10_1->Name = L"rbCoin10_1";
			this->rbCoin10_1->Size = System::Drawing::Size(21, 20);
			this->rbCoin10_1->TabIndex = 21;
			this->rbCoin10_1->UseVisualStyleBackColor = true;
			// 
			// rbCoin10_2
			// 
			this->rbCoin10_2->AutoSize = true;
			this->rbCoin10_2->Location = System::Drawing::Point(108, 399);
			this->rbCoin10_2->Name = L"rbCoin10_2";
			this->rbCoin10_2->Size = System::Drawing::Size(21, 20);
			this->rbCoin10_2->TabIndex = 20;
			this->rbCoin10_2->UseVisualStyleBackColor = true;
			// 
			// rbCoin10_3
			// 
			this->rbCoin10_3->AutoSize = true;
			this->rbCoin10_3->Location = System::Drawing::Point(108, 373);
			this->rbCoin10_3->Name = L"rbCoin10_3";
			this->rbCoin10_3->Size = System::Drawing::Size(21, 20);
			this->rbCoin10_3->TabIndex = 19;
			this->rbCoin10_3->UseVisualStyleBackColor = true;
			// 
			// rbCoin50_1
			// 
			this->rbCoin50_1->AutoSize = true;
			this->rbCoin50_1->Location = System::Drawing::Point(183, 425);
			this->rbCoin50_1->Name = L"rbCoin50_1";
			this->rbCoin50_1->Size = System::Drawing::Size(21, 20);
			this->rbCoin50_1->TabIndex = 24;
			this->rbCoin50_1->UseVisualStyleBackColor = true;
			// 
			// rbCoin50_2
			// 
			this->rbCoin50_2->AutoSize = true;
			this->rbCoin50_2->Location = System::Drawing::Point(183, 399);
			this->rbCoin50_2->Name = L"rbCoin50_2";
			this->rbCoin50_2->Size = System::Drawing::Size(21, 20);
			this->rbCoin50_2->TabIndex = 23;
			this->rbCoin50_2->UseVisualStyleBackColor = true;
			// 
			// rbCoin50_3
			// 
			this->rbCoin50_3->AutoSize = true;
			this->rbCoin50_3->Location = System::Drawing::Point(183, 373);
			this->rbCoin50_3->Name = L"rbCoin50_3";
			this->rbCoin50_3->Size = System::Drawing::Size(21, 20);
			this->rbCoin50_3->TabIndex = 22;
			this->rbCoin50_3->UseVisualStyleBackColor = true;
			// 
			// rbCoin200_1
			// 
			this->rbCoin200_1->AutoSize = true;
			this->rbCoin200_1->Location = System::Drawing::Point(259, 425);
			this->rbCoin200_1->Name = L"rbCoin200_1";
			this->rbCoin200_1->Size = System::Drawing::Size(21, 20);
			this->rbCoin200_1->TabIndex = 27;
			this->rbCoin200_1->UseVisualStyleBackColor = true;
			// 
			// rbCoin200_2
			// 
			this->rbCoin200_2->AutoSize = true;
			this->rbCoin200_2->Location = System::Drawing::Point(259, 399);
			this->rbCoin200_2->Name = L"rbCoin200_2";
			this->rbCoin200_2->Size = System::Drawing::Size(21, 20);
			this->rbCoin200_2->TabIndex = 26;
			this->rbCoin200_2->UseVisualStyleBackColor = true;
			// 
			// btnPressure
			// 
			this->btnPressure->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->btnPressure->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnPressure->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnPressure->Location = System::Drawing::Point(52, 46);
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
			this->btnHeater->Location = System::Drawing::Point(189, 46);
			this->btnHeater->Name = L"btnHeater";
			this->btnHeater->Size = System::Drawing::Size(131, 50);
			this->btnHeater->TabIndex = 29;
			this->btnHeater->Text = L"Heater";
			this->btnHeater->UseVisualStyleBackColor = false;
			this->btnHeater->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// radioButton14
			// 
			this->radioButton14->AutoSize = true;
			this->radioButton14->Location = System::Drawing::Point(729, 216);
			this->radioButton14->Name = L"radioButton14";
			this->radioButton14->Size = System::Drawing::Size(21, 20);
			this->radioButton14->TabIndex = 32;
			this->radioButton14->UseVisualStyleBackColor = true;
			// 
			// radioButton15
			// 
			this->radioButton15->AutoSize = true;
			this->radioButton15->Location = System::Drawing::Point(696, 216);
			this->radioButton15->Name = L"radioButton15";
			this->radioButton15->Size = System::Drawing::Size(21, 20);
			this->radioButton15->TabIndex = 31;
			this->radioButton15->UseVisualStyleBackColor = true;
			// 
			// radioButton16
			// 
			this->radioButton16->AutoSize = true;
			this->radioButton16->Location = System::Drawing::Point(663, 216);
			this->radioButton16->Name = L"radioButton16";
			this->radioButton16->Size = System::Drawing::Size(21, 20);
			this->radioButton16->TabIndex = 30;
			this->radioButton16->UseVisualStyleBackColor = true;
			// 
			// radioButton17
			// 
			this->radioButton17->AutoSize = true;
			this->radioButton17->Location = System::Drawing::Point(762, 244);
			this->radioButton17->Name = L"radioButton17";
			this->radioButton17->Size = System::Drawing::Size(21, 20);
			this->radioButton17->TabIndex = 34;
			this->radioButton17->UseVisualStyleBackColor = true;
			// 
			// radioButton18
			// 
			this->radioButton18->AutoSize = true;
			this->radioButton18->Location = System::Drawing::Point(762, 216);
			this->radioButton18->Name = L"radioButton18";
			this->radioButton18->Size = System::Drawing::Size(21, 20);
			this->radioButton18->TabIndex = 33;
			this->radioButton18->UseVisualStyleBackColor = true;
			// 
			// radioButton19
			// 
			this->radioButton19->AutoSize = true;
			this->radioButton19->Location = System::Drawing::Point(762, 273);
			this->radioButton19->Name = L"radioButton19";
			this->radioButton19->Size = System::Drawing::Size(21, 20);
			this->radioButton19->TabIndex = 36;
			this->radioButton19->UseVisualStyleBackColor = true;
			// 
			// radioButton20
			// 
			this->radioButton20->AutoSize = true;
			this->radioButton20->Location = System::Drawing::Point(804, 286);
			this->radioButton20->Name = L"radioButton20";
			this->radioButton20->Size = System::Drawing::Size(21, 20);
			this->radioButton20->TabIndex = 35;
			this->radioButton20->UseVisualStyleBackColor = true;
			// 
			// radioButton21
			// 
			this->radioButton21->AutoSize = true;
			this->radioButton21->Location = System::Drawing::Point(829, 316);
			this->radioButton21->Name = L"radioButton21";
			this->radioButton21->Size = System::Drawing::Size(21, 20);
			this->radioButton21->TabIndex = 37;
			this->radioButton21->UseVisualStyleBackColor = true;
			// 
			// radioButton22
			// 
			this->radioButton22->AutoSize = true;
			this->radioButton22->Location = System::Drawing::Point(841, 348);
			this->radioButton22->Name = L"radioButton22";
			this->radioButton22->Size = System::Drawing::Size(21, 20);
			this->radioButton22->TabIndex = 38;
			this->radioButton22->UseVisualStyleBackColor = true;
			// 
			// radioButton23
			// 
			this->radioButton23->AutoSize = true;
			this->radioButton23->Location = System::Drawing::Point(801, 407);
			this->radioButton23->Name = L"radioButton23";
			this->radioButton23->Size = System::Drawing::Size(21, 20);
			this->radioButton23->TabIndex = 39;
			this->radioButton23->UseVisualStyleBackColor = true;
			// 
			// radioButton24
			// 
			this->radioButton24->AutoSize = true;
			this->radioButton24->Location = System::Drawing::Point(762, 424);
			this->radioButton24->Name = L"radioButton24";
			this->radioButton24->Size = System::Drawing::Size(21, 20);
			this->radioButton24->TabIndex = 40;
			this->radioButton24->UseVisualStyleBackColor = true;
			// 
			// radioButton25
			// 
			this->radioButton25->AutoSize = true;
			this->radioButton25->Location = System::Drawing::Point(725, 407);
			this->radioButton25->Name = L"radioButton25";
			this->radioButton25->Size = System::Drawing::Size(21, 20);
			this->radioButton25->TabIndex = 41;
			this->radioButton25->UseVisualStyleBackColor = true;
			// 
			// radioButton26
			// 
			this->radioButton26->AutoSize = true;
			this->radioButton26->Location = System::Drawing::Point(688, 349);
			this->radioButton26->Name = L"radioButton26";
			this->radioButton26->Size = System::Drawing::Size(21, 20);
			this->radioButton26->TabIndex = 42;
			this->radioButton26->UseVisualStyleBackColor = true;
			// 
			// radioButton27
			// 
			this->radioButton27->AutoSize = true;
			this->radioButton27->Location = System::Drawing::Point(700, 311);
			this->radioButton27->Name = L"radioButton27";
			this->radioButton27->Size = System::Drawing::Size(21, 20);
			this->radioButton27->TabIndex = 43;
			this->radioButton27->UseVisualStyleBackColor = true;
			// 
			// radioButton28
			// 
			this->radioButton28->AutoSize = true;
			this->radioButton28->Location = System::Drawing::Point(727, 285);
			this->radioButton28->Name = L"radioButton28";
			this->radioButton28->Size = System::Drawing::Size(21, 20);
			this->radioButton28->TabIndex = 44;
			this->radioButton28->UseVisualStyleBackColor = true;
			// 
			// radioButton29
			// 
			this->radioButton29->AutoSize = true;
			this->radioButton29->Location = System::Drawing::Point(762, 454);
			this->radioButton29->Name = L"radioButton29";
			this->radioButton29->Size = System::Drawing::Size(21, 20);
			this->radioButton29->TabIndex = 45;
			this->radioButton29->UseVisualStyleBackColor = true;
			// 
			// radioButton30
			// 
			this->radioButton30->AutoSize = true;
			this->radioButton30->Location = System::Drawing::Point(762, 481);
			this->radioButton30->Name = L"radioButton30";
			this->radioButton30->Size = System::Drawing::Size(21, 20);
			this->radioButton30->TabIndex = 46;
			this->radioButton30->UseVisualStyleBackColor = true;
			// 
			// radioButton31
			// 
			this->radioButton31->AutoSize = true;
			this->radioButton31->Location = System::Drawing::Point(795, 481);
			this->radioButton31->Name = L"radioButton31";
			this->radioButton31->Size = System::Drawing::Size(21, 20);
			this->radioButton31->TabIndex = 47;
			this->radioButton31->UseVisualStyleBackColor = true;
			// 
			// radioButton32
			// 
			this->radioButton32->AutoSize = true;
			this->radioButton32->Location = System::Drawing::Point(827, 481);
			this->radioButton32->Name = L"radioButton32";
			this->radioButton32->Size = System::Drawing::Size(21, 20);
			this->radioButton32->TabIndex = 48;
			this->radioButton32->UseVisualStyleBackColor = true;
			// 
			// radioButton33
			// 
			this->radioButton33->AutoSize = true;
			this->radioButton33->Location = System::Drawing::Point(859, 481);
			this->radioButton33->Name = L"radioButton33";
			this->radioButton33->Size = System::Drawing::Size(21, 20);
			this->radioButton33->TabIndex = 49;
			this->radioButton33->UseVisualStyleBackColor = true;
			// 
			// radioButton34
			// 
			this->radioButton34->AutoSize = true;
			this->radioButton34->Location = System::Drawing::Point(762, 381);
			this->radioButton34->Name = L"radioButton34";
			this->radioButton34->Size = System::Drawing::Size(21, 20);
			this->radioButton34->TabIndex = 50;
			this->radioButton34->UseVisualStyleBackColor = true;
			// 
			// radioButton35
			// 
			this->radioButton35->AutoSize = true;
			this->radioButton35->Location = System::Drawing::Point(734, 377);
			this->radioButton35->Name = L"radioButton35";
			this->radioButton35->Size = System::Drawing::Size(21, 20);
			this->radioButton35->TabIndex = 51;
			this->radioButton35->UseVisualStyleBackColor = true;
			// 
			// radioButton36
			// 
			this->radioButton36->AutoSize = true;
			this->radioButton36->Location = System::Drawing::Point(734, 357);
			this->radioButton36->Name = L"radioButton36";
			this->radioButton36->Size = System::Drawing::Size(21, 20);
			this->radioButton36->TabIndex = 52;
			this->radioButton36->UseVisualStyleBackColor = true;
			// 
			// radioButton37
			// 
			this->radioButton37->AutoSize = true;
			this->radioButton37->Location = System::Drawing::Point(734, 337);
			this->radioButton37->Name = L"radioButton37";
			this->radioButton37->Size = System::Drawing::Size(21, 20);
			this->radioButton37->TabIndex = 53;
			this->radioButton37->UseVisualStyleBackColor = true;
			// 
			// radioButton38
			// 
			this->radioButton38->AutoSize = true;
			this->radioButton38->Location = System::Drawing::Point(789, 337);
			this->radioButton38->Name = L"radioButton38";
			this->radioButton38->Size = System::Drawing::Size(21, 20);
			this->radioButton38->TabIndex = 54;
			this->radioButton38->UseVisualStyleBackColor = true;
			// 
			// radioButton39
			// 
			this->radioButton39->AutoSize = true;
			this->radioButton39->Location = System::Drawing::Point(789, 357);
			this->radioButton39->Name = L"radioButton39";
			this->radioButton39->Size = System::Drawing::Size(21, 20);
			this->radioButton39->TabIndex = 55;
			this->radioButton39->UseVisualStyleBackColor = true;
			// 
			// radioButton40
			// 
			this->radioButton40->AutoSize = true;
			this->radioButton40->Location = System::Drawing::Point(789, 377);
			this->radioButton40->Name = L"radioButton40";
			this->radioButton40->Size = System::Drawing::Size(21, 20);
			this->radioButton40->TabIndex = 56;
			this->radioButton40->UseVisualStyleBackColor = true;
			// 
			// radioButton41
			// 
			this->radioButton41->AutoSize = true;
			this->radioButton41->Location = System::Drawing::Point(697, 385);
			this->radioButton41->Name = L"radioButton41";
			this->radioButton41->Size = System::Drawing::Size(21, 20);
			this->radioButton41->TabIndex = 57;
			this->radioButton41->UseVisualStyleBackColor = true;
			// 
			// radioButton42
			// 
			this->radioButton42->AutoSize = true;
			this->radioButton42->Location = System::Drawing::Point(828, 383);
			this->radioButton42->Name = L"radioButton42";
			this->radioButton42->Size = System::Drawing::Size(21, 20);
			this->radioButton42->TabIndex = 58;
			this->radioButton42->UseVisualStyleBackColor = true;
			// 
			// rbProgramA
			// 
			this->rbProgramA->AutoSize = true;
			this->rbProgramA->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->rbProgramA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rbProgramA->Location = System::Drawing::Point(540, 57);
			this->rbProgramA->Name = L"rbProgramA";
			this->rbProgramA->Size = System::Drawing::Size(59, 36);
			this->rbProgramA->TabIndex = 59;
			this->rbProgramA->Text = L"A";
			this->rbProgramA->UseVisualStyleBackColor = false;
			// 
			// rbProgramB
			// 
			this->rbProgramB->AutoSize = true;
			this->rbProgramB->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->rbProgramB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rbProgramB->Location = System::Drawing::Point(672, 57);
			this->rbProgramB->Name = L"rbProgramB";
			this->rbProgramB->Size = System::Drawing::Size(59, 36);
			this->rbProgramB->TabIndex = 60;
			this->rbProgramB->Text = L"B";
			this->rbProgramB->UseVisualStyleBackColor = false;
			// 
			// rbProgramC
			// 
			this->rbProgramC->AutoSize = true;
			this->rbProgramC->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->rbProgramC->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rbProgramC->Location = System::Drawing::Point(804, 57);
			this->rbProgramC->Name = L"rbProgramC";
			this->rbProgramC->Size = System::Drawing::Size(60, 36);
			this->rbProgramC->TabIndex = 61;
			this->rbProgramC->Text = L"C";
			this->rbProgramC->UseVisualStyleBackColor = false;
			// 
			// rbDrain
			// 
			this->rbDrain->AutoSize = true;
			this->rbDrain->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->rbDrain->Location = System::Drawing::Point(561, 212);
			this->rbDrain->Name = L"rbDrain";
			this->rbDrain->Size = System::Drawing::Size(72, 24);
			this->rbDrain->TabIndex = 62;
			this->rbDrain->Text = L"Drain";
			this->rbDrain->UseVisualStyleBackColor = false;
			// 
			// rbSink
			// 
			this->rbSink->AutoSize = true;
			this->rbSink->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->rbSink->Location = System::Drawing::Point(905, 479);
			this->rbSink->Name = L"rbSink";
			this->rbSink->Size = System::Drawing::Size(65, 24);
			this->rbSink->TabIndex = 63;
			this->rbSink->Text = L"Sink";
			this->rbSink->UseVisualStyleBackColor = false;
			// 
			// rbDoorLock
			// 
			this->rbDoorLock->AutoSize = true;
			this->rbDoorLock->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->rbDoorLock->Location = System::Drawing::Point(741, 310);
			this->rbDoorLock->Name = L"rbDoorLock";
			this->rbDoorLock->Size = System::Drawing::Size(68, 24);
			this->rbDoorLock->TabIndex = 64;
			this->rbDoorLock->Text = L"Lock";
			this->rbDoorLock->UseVisualStyleBackColor = false;
			// 
			// btnReset
			// 
			this->btnReset->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->btnReset->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnReset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnReset->Location = System::Drawing::Point(310, 452);
			this->btnReset->Name = L"btnReset";
			this->btnReset->Size = System::Drawing::Size(70, 66);
			this->btnReset->TabIndex = 65;
			this->btnReset->Text = L"Reset";
			this->btnReset->UseVisualStyleBackColor = false;
			// 
			// btnLockDoor
			// 
			this->btnLockDoor->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->btnLockDoor->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLockDoor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLockDoor->Location = System::Drawing::Point(80, 132);
			this->btnLockDoor->Name = L"btnLockDoor";
			this->btnLockDoor->Size = System::Drawing::Size(180, 58);
			this->btnLockDoor->TabIndex = 66;
			this->btnLockDoor->Text = L"Lock Door";
			this->btnLockDoor->UseVisualStyleBackColor = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)), static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(66)));
			this->ClientSize = System::Drawing::Size(1058, 590);
			this->Controls->Add(this->btnLockDoor);
			this->Controls->Add(this->btnReset);
			this->Controls->Add(this->rbDoorLock);
			this->Controls->Add(this->rbSink);
			this->Controls->Add(this->rbDrain);
			this->Controls->Add(this->rbProgramC);
			this->Controls->Add(this->rbProgramB);
			this->Controls->Add(this->rbProgramA);
			this->Controls->Add(this->radioButton42);
			this->Controls->Add(this->radioButton41);
			this->Controls->Add(this->radioButton40);
			this->Controls->Add(this->radioButton39);
			this->Controls->Add(this->radioButton38);
			this->Controls->Add(this->radioButton37);
			this->Controls->Add(this->radioButton36);
			this->Controls->Add(this->radioButton35);
			this->Controls->Add(this->radioButton34);
			this->Controls->Add(this->radioButton33);
			this->Controls->Add(this->radioButton32);
			this->Controls->Add(this->radioButton31);
			this->Controls->Add(this->radioButton30);
			this->Controls->Add(this->radioButton29);
			this->Controls->Add(this->radioButton28);
			this->Controls->Add(this->radioButton27);
			this->Controls->Add(this->radioButton26);
			this->Controls->Add(this->radioButton25);
			this->Controls->Add(this->radioButton24);
			this->Controls->Add(this->radioButton23);
			this->Controls->Add(this->radioButton22);
			this->Controls->Add(this->radioButton21);
			this->Controls->Add(this->radioButton19);
			this->Controls->Add(this->radioButton20);
			this->Controls->Add(this->radioButton17);
			this->Controls->Add(this->radioButton18);
			this->Controls->Add(this->radioButton14);
			this->Controls->Add(this->radioButton15);
			this->Controls->Add(this->radioButton16);
			this->Controls->Add(this->btnHeater);
			this->Controls->Add(this->btnPressure);
			this->Controls->Add(this->rbCoin200_1);
			this->Controls->Add(this->rbCoin200_2);
			this->Controls->Add(this->rbCoin50_1);
			this->Controls->Add(this->rbCoin50_2);
			this->Controls->Add(this->rbCoin50_3);
			this->Controls->Add(this->rbCoin10_1);
			this->Controls->Add(this->rbCoin10_2);
			this->Controls->Add(this->rbCoin10_3);
			this->Controls->Add(this->rbSoap2);
			this->Controls->Add(this->rbSoap1);
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
	
};
}
