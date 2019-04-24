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
	private: System::Windows::Forms::Button^  btnProgramA;
	private: System::Windows::Forms::Button^  btnProgramB;
	private: System::Windows::Forms::Button^  btnProgramC;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::RadioButton^  radioButton5;
	private: System::Windows::Forms::Label^  lblBalance;
	private: System::Windows::Forms::RadioButton^  radioButton6;
	private: System::Windows::Forms::RadioButton^  radioButton7;
	private: System::Windows::Forms::RadioButton^  radioButton8;
	private: System::Windows::Forms::RadioButton^  radioButton9;
	private: System::Windows::Forms::RadioButton^  radioButton10;
	private: System::Windows::Forms::RadioButton^  radioButton11;
	private: System::Windows::Forms::RadioButton^  radioButton12;
	private: System::Windows::Forms::RadioButton^  radioButton13;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
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
			this->btnProgramA = (gcnew System::Windows::Forms::Button());
			this->btnProgramB = (gcnew System::Windows::Forms::Button());
			this->btnProgramC = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->lblBalance = (gcnew System::Windows::Forms::Label());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton7 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton8 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton9 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton10 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton11 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton12 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton13 = (gcnew System::Windows::Forms::RadioButton());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
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
			// btnProgramA
			// 
			this->btnProgramA->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->btnProgramA->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnProgramA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnProgramA->Location = System::Drawing::Point(503, 18);
			this->btnProgramA->Name = L"btnProgramA";
			this->btnProgramA->Size = System::Drawing::Size(174, 106);
			this->btnProgramA->TabIndex = 10;
			this->btnProgramA->Text = L"PROGRAM A";
			this->btnProgramA->UseVisualStyleBackColor = false;
			// 
			// btnProgramB
			// 
			this->btnProgramB->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->btnProgramB->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnProgramB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnProgramB->Location = System::Drawing::Point(683, 18);
			this->btnProgramB->Name = L"btnProgramB";
			this->btnProgramB->Size = System::Drawing::Size(174, 106);
			this->btnProgramB->TabIndex = 11;
			this->btnProgramB->Text = L"PROGRAM B";
			this->btnProgramB->UseVisualStyleBackColor = false;
			// 
			// btnProgramC
			// 
			this->btnProgramC->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->btnProgramC->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnProgramC->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnProgramC->Location = System::Drawing::Point(863, 18);
			this->btnProgramC->Name = L"btnProgramC";
			this->btnProgramC->Size = System::Drawing::Size(174, 106);
			this->btnProgramC->TabIndex = 12;
			this->btnProgramC->Text = L"PROGRAM C";
			this->btnProgramC->UseVisualStyleBackColor = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(503, 130);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(534, 59);
			this->button1->TabIndex = 13;
			this->button1->Text = L"START";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(283, 219);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(21, 20);
			this->radioButton1->TabIndex = 14;
			this->radioButton1->TabStop = true;
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(310, 219);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(21, 20);
			this->radioButton2->TabIndex = 15;
			this->radioButton2->TabStop = true;
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(283, 287);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(21, 20);
			this->radioButton3->TabIndex = 16;
			this->radioButton3->TabStop = true;
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(310, 287);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(21, 20);
			this->radioButton4->TabIndex = 17;
			this->radioButton4->TabStop = true;
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Location = System::Drawing::Point(337, 287);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(21, 20);
			this->radioButton5->TabIndex = 18;
			this->radioButton5->TabStop = true;
			this->radioButton5->UseVisualStyleBackColor = true;
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
			// radioButton6
			// 
			this->radioButton6->AutoSize = true;
			this->radioButton6->Location = System::Drawing::Point(108, 425);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(21, 20);
			this->radioButton6->TabIndex = 21;
			this->radioButton6->TabStop = true;
			this->radioButton6->UseVisualStyleBackColor = true;
			// 
			// radioButton7
			// 
			this->radioButton7->AutoSize = true;
			this->radioButton7->Location = System::Drawing::Point(108, 399);
			this->radioButton7->Name = L"radioButton7";
			this->radioButton7->Size = System::Drawing::Size(21, 20);
			this->radioButton7->TabIndex = 20;
			this->radioButton7->TabStop = true;
			this->radioButton7->UseVisualStyleBackColor = true;
			// 
			// radioButton8
			// 
			this->radioButton8->AutoSize = true;
			this->radioButton8->Location = System::Drawing::Point(108, 373);
			this->radioButton8->Name = L"radioButton8";
			this->radioButton8->Size = System::Drawing::Size(21, 20);
			this->radioButton8->TabIndex = 19;
			this->radioButton8->TabStop = true;
			this->radioButton8->UseVisualStyleBackColor = true;
			// 
			// radioButton9
			// 
			this->radioButton9->AutoSize = true;
			this->radioButton9->Location = System::Drawing::Point(183, 425);
			this->radioButton9->Name = L"radioButton9";
			this->radioButton9->Size = System::Drawing::Size(21, 20);
			this->radioButton9->TabIndex = 24;
			this->radioButton9->TabStop = true;
			this->radioButton9->UseVisualStyleBackColor = true;
			// 
			// radioButton10
			// 
			this->radioButton10->AutoSize = true;
			this->radioButton10->Location = System::Drawing::Point(183, 399);
			this->radioButton10->Name = L"radioButton10";
			this->radioButton10->Size = System::Drawing::Size(21, 20);
			this->radioButton10->TabIndex = 23;
			this->radioButton10->TabStop = true;
			this->radioButton10->UseVisualStyleBackColor = true;
			// 
			// radioButton11
			// 
			this->radioButton11->AutoSize = true;
			this->radioButton11->Location = System::Drawing::Point(183, 373);
			this->radioButton11->Name = L"radioButton11";
			this->radioButton11->Size = System::Drawing::Size(21, 20);
			this->radioButton11->TabIndex = 22;
			this->radioButton11->TabStop = true;
			this->radioButton11->UseVisualStyleBackColor = true;
			// 
			// radioButton12
			// 
			this->radioButton12->AutoSize = true;
			this->radioButton12->Location = System::Drawing::Point(259, 425);
			this->radioButton12->Name = L"radioButton12";
			this->radioButton12->Size = System::Drawing::Size(21, 20);
			this->radioButton12->TabIndex = 27;
			this->radioButton12->TabStop = true;
			this->radioButton12->UseVisualStyleBackColor = true;
			// 
			// radioButton13
			// 
			this->radioButton13->AutoSize = true;
			this->radioButton13->Location = System::Drawing::Point(259, 399);
			this->radioButton13->Name = L"radioButton13";
			this->radioButton13->Size = System::Drawing::Size(21, 20);
			this->radioButton13->TabIndex = 26;
			this->radioButton13->TabStop = true;
			this->radioButton13->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(52, 74);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(131, 50);
			this->button2->TabIndex = 28;
			this->button2->Text = L"Pressure";
			this->button2->UseVisualStyleBackColor = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(189, 74);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(131, 50);
			this->button3->TabIndex = 29;
			this->button3->Text = L"Heater";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// radioButton14
			// 
			this->radioButton14->AutoSize = true;
			this->radioButton14->Location = System::Drawing::Point(729, 216);
			this->radioButton14->Name = L"radioButton14";
			this->radioButton14->Size = System::Drawing::Size(21, 20);
			this->radioButton14->TabIndex = 32;
			this->radioButton14->TabStop = true;
			this->radioButton14->UseVisualStyleBackColor = true;
			// 
			// radioButton15
			// 
			this->radioButton15->AutoSize = true;
			this->radioButton15->Location = System::Drawing::Point(696, 216);
			this->radioButton15->Name = L"radioButton15";
			this->radioButton15->Size = System::Drawing::Size(21, 20);
			this->radioButton15->TabIndex = 31;
			this->radioButton15->TabStop = true;
			this->radioButton15->UseVisualStyleBackColor = true;
			// 
			// radioButton16
			// 
			this->radioButton16->AutoSize = true;
			this->radioButton16->Location = System::Drawing::Point(663, 216);
			this->radioButton16->Name = L"radioButton16";
			this->radioButton16->Size = System::Drawing::Size(21, 20);
			this->radioButton16->TabIndex = 30;
			this->radioButton16->TabStop = true;
			this->radioButton16->UseVisualStyleBackColor = true;
			// 
			// radioButton17
			// 
			this->radioButton17->AutoSize = true;
			this->radioButton17->Location = System::Drawing::Point(762, 244);
			this->radioButton17->Name = L"radioButton17";
			this->radioButton17->Size = System::Drawing::Size(21, 20);
			this->radioButton17->TabIndex = 34;
			this->radioButton17->TabStop = true;
			this->radioButton17->UseVisualStyleBackColor = true;
			// 
			// radioButton18
			// 
			this->radioButton18->AutoSize = true;
			this->radioButton18->Location = System::Drawing::Point(762, 216);
			this->radioButton18->Name = L"radioButton18";
			this->radioButton18->Size = System::Drawing::Size(21, 20);
			this->radioButton18->TabIndex = 33;
			this->radioButton18->TabStop = true;
			this->radioButton18->UseVisualStyleBackColor = true;
			// 
			// radioButton19
			// 
			this->radioButton19->AutoSize = true;
			this->radioButton19->Location = System::Drawing::Point(762, 273);
			this->radioButton19->Name = L"radioButton19";
			this->radioButton19->Size = System::Drawing::Size(21, 20);
			this->radioButton19->TabIndex = 36;
			this->radioButton19->TabStop = true;
			this->radioButton19->UseVisualStyleBackColor = true;
			// 
			// radioButton20
			// 
			this->radioButton20->AutoSize = true;
			this->radioButton20->Location = System::Drawing::Point(804, 286);
			this->radioButton20->Name = L"radioButton20";
			this->radioButton20->Size = System::Drawing::Size(21, 20);
			this->radioButton20->TabIndex = 35;
			this->radioButton20->TabStop = true;
			this->radioButton20->UseVisualStyleBackColor = true;
			// 
			// radioButton21
			// 
			this->radioButton21->AutoSize = true;
			this->radioButton21->Location = System::Drawing::Point(829, 316);
			this->radioButton21->Name = L"radioButton21";
			this->radioButton21->Size = System::Drawing::Size(21, 20);
			this->radioButton21->TabIndex = 37;
			this->radioButton21->TabStop = true;
			this->radioButton21->UseVisualStyleBackColor = true;
			// 
			// radioButton22
			// 
			this->radioButton22->AutoSize = true;
			this->radioButton22->Location = System::Drawing::Point(841, 348);
			this->radioButton22->Name = L"radioButton22";
			this->radioButton22->Size = System::Drawing::Size(21, 20);
			this->radioButton22->TabIndex = 38;
			this->radioButton22->TabStop = true;
			this->radioButton22->UseVisualStyleBackColor = true;
			// 
			// radioButton23
			// 
			this->radioButton23->AutoSize = true;
			this->radioButton23->Location = System::Drawing::Point(801, 407);
			this->radioButton23->Name = L"radioButton23";
			this->radioButton23->Size = System::Drawing::Size(21, 20);
			this->radioButton23->TabIndex = 39;
			this->radioButton23->TabStop = true;
			this->radioButton23->UseVisualStyleBackColor = true;
			// 
			// radioButton24
			// 
			this->radioButton24->AutoSize = true;
			this->radioButton24->Location = System::Drawing::Point(762, 424);
			this->radioButton24->Name = L"radioButton24";
			this->radioButton24->Size = System::Drawing::Size(21, 20);
			this->radioButton24->TabIndex = 40;
			this->radioButton24->TabStop = true;
			this->radioButton24->UseVisualStyleBackColor = true;
			// 
			// radioButton25
			// 
			this->radioButton25->AutoSize = true;
			this->radioButton25->Location = System::Drawing::Point(725, 407);
			this->radioButton25->Name = L"radioButton25";
			this->radioButton25->Size = System::Drawing::Size(21, 20);
			this->radioButton25->TabIndex = 41;
			this->radioButton25->TabStop = true;
			this->radioButton25->UseVisualStyleBackColor = true;
			// 
			// radioButton26
			// 
			this->radioButton26->AutoSize = true;
			this->radioButton26->Location = System::Drawing::Point(688, 349);
			this->radioButton26->Name = L"radioButton26";
			this->radioButton26->Size = System::Drawing::Size(21, 20);
			this->radioButton26->TabIndex = 42;
			this->radioButton26->TabStop = true;
			this->radioButton26->UseVisualStyleBackColor = true;
			// 
			// radioButton27
			// 
			this->radioButton27->AutoSize = true;
			this->radioButton27->Location = System::Drawing::Point(700, 311);
			this->radioButton27->Name = L"radioButton27";
			this->radioButton27->Size = System::Drawing::Size(21, 20);
			this->radioButton27->TabIndex = 43;
			this->radioButton27->TabStop = true;
			this->radioButton27->UseVisualStyleBackColor = true;
			// 
			// radioButton28
			// 
			this->radioButton28->AutoSize = true;
			this->radioButton28->Location = System::Drawing::Point(727, 285);
			this->radioButton28->Name = L"radioButton28";
			this->radioButton28->Size = System::Drawing::Size(21, 20);
			this->radioButton28->TabIndex = 44;
			this->radioButton28->TabStop = true;
			this->radioButton28->UseVisualStyleBackColor = true;
			// 
			// radioButton29
			// 
			this->radioButton29->AutoSize = true;
			this->radioButton29->Location = System::Drawing::Point(762, 454);
			this->radioButton29->Name = L"radioButton29";
			this->radioButton29->Size = System::Drawing::Size(21, 20);
			this->radioButton29->TabIndex = 45;
			this->radioButton29->TabStop = true;
			this->radioButton29->UseVisualStyleBackColor = true;
			// 
			// radioButton30
			// 
			this->radioButton30->AutoSize = true;
			this->radioButton30->Location = System::Drawing::Point(762, 481);
			this->radioButton30->Name = L"radioButton30";
			this->radioButton30->Size = System::Drawing::Size(21, 20);
			this->radioButton30->TabIndex = 46;
			this->radioButton30->TabStop = true;
			this->radioButton30->UseVisualStyleBackColor = true;
			// 
			// radioButton31
			// 
			this->radioButton31->AutoSize = true;
			this->radioButton31->Location = System::Drawing::Point(795, 481);
			this->radioButton31->Name = L"radioButton31";
			this->radioButton31->Size = System::Drawing::Size(21, 20);
			this->radioButton31->TabIndex = 47;
			this->radioButton31->TabStop = true;
			this->radioButton31->UseVisualStyleBackColor = true;
			// 
			// radioButton32
			// 
			this->radioButton32->AutoSize = true;
			this->radioButton32->Location = System::Drawing::Point(827, 481);
			this->radioButton32->Name = L"radioButton32";
			this->radioButton32->Size = System::Drawing::Size(21, 20);
			this->radioButton32->TabIndex = 48;
			this->radioButton32->TabStop = true;
			this->radioButton32->UseVisualStyleBackColor = true;
			// 
			// radioButton33
			// 
			this->radioButton33->AutoSize = true;
			this->radioButton33->Location = System::Drawing::Point(859, 481);
			this->radioButton33->Name = L"radioButton33";
			this->radioButton33->Size = System::Drawing::Size(21, 20);
			this->radioButton33->TabIndex = 49;
			this->radioButton33->TabStop = true;
			this->radioButton33->UseVisualStyleBackColor = true;
			// 
			// radioButton34
			// 
			this->radioButton34->AutoSize = true;
			this->radioButton34->Location = System::Drawing::Point(762, 381);
			this->radioButton34->Name = L"radioButton34";
			this->radioButton34->Size = System::Drawing::Size(21, 20);
			this->radioButton34->TabIndex = 50;
			this->radioButton34->TabStop = true;
			this->radioButton34->UseVisualStyleBackColor = true;
			// 
			// radioButton35
			// 
			this->radioButton35->AutoSize = true;
			this->radioButton35->Location = System::Drawing::Point(734, 377);
			this->radioButton35->Name = L"radioButton35";
			this->radioButton35->Size = System::Drawing::Size(21, 20);
			this->radioButton35->TabIndex = 51;
			this->radioButton35->TabStop = true;
			this->radioButton35->UseVisualStyleBackColor = true;
			// 
			// radioButton36
			// 
			this->radioButton36->AutoSize = true;
			this->radioButton36->Location = System::Drawing::Point(734, 357);
			this->radioButton36->Name = L"radioButton36";
			this->radioButton36->Size = System::Drawing::Size(21, 20);
			this->radioButton36->TabIndex = 52;
			this->radioButton36->TabStop = true;
			this->radioButton36->UseVisualStyleBackColor = true;
			// 
			// radioButton37
			// 
			this->radioButton37->AutoSize = true;
			this->radioButton37->Location = System::Drawing::Point(734, 337);
			this->radioButton37->Name = L"radioButton37";
			this->radioButton37->Size = System::Drawing::Size(21, 20);
			this->radioButton37->TabIndex = 53;
			this->radioButton37->TabStop = true;
			this->radioButton37->UseVisualStyleBackColor = true;
			// 
			// radioButton38
			// 
			this->radioButton38->AutoSize = true;
			this->radioButton38->Location = System::Drawing::Point(789, 337);
			this->radioButton38->Name = L"radioButton38";
			this->radioButton38->Size = System::Drawing::Size(21, 20);
			this->radioButton38->TabIndex = 54;
			this->radioButton38->TabStop = true;
			this->radioButton38->UseVisualStyleBackColor = true;
			// 
			// radioButton39
			// 
			this->radioButton39->AutoSize = true;
			this->radioButton39->Location = System::Drawing::Point(789, 357);
			this->radioButton39->Name = L"radioButton39";
			this->radioButton39->Size = System::Drawing::Size(21, 20);
			this->radioButton39->TabIndex = 55;
			this->radioButton39->TabStop = true;
			this->radioButton39->UseVisualStyleBackColor = true;
			// 
			// radioButton40
			// 
			this->radioButton40->AutoSize = true;
			this->radioButton40->Location = System::Drawing::Point(789, 377);
			this->radioButton40->Name = L"radioButton40";
			this->radioButton40->Size = System::Drawing::Size(21, 20);
			this->radioButton40->TabIndex = 56;
			this->radioButton40->TabStop = true;
			this->radioButton40->UseVisualStyleBackColor = true;
			// 
			// radioButton41
			// 
			this->radioButton41->AutoSize = true;
			this->radioButton41->Location = System::Drawing::Point(697, 385);
			this->radioButton41->Name = L"radioButton41";
			this->radioButton41->Size = System::Drawing::Size(21, 20);
			this->radioButton41->TabIndex = 57;
			this->radioButton41->TabStop = true;
			this->radioButton41->UseVisualStyleBackColor = true;
			// 
			// radioButton42
			// 
			this->radioButton42->AutoSize = true;
			this->radioButton42->Location = System::Drawing::Point(828, 383);
			this->radioButton42->Name = L"radioButton42";
			this->radioButton42->Size = System::Drawing::Size(21, 20);
			this->radioButton42->TabIndex = 58;
			this->radioButton42->TabStop = true;
			this->radioButton42->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)), static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(66)));
			this->ClientSize = System::Drawing::Size(1058, 590);
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
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->radioButton12);
			this->Controls->Add(this->radioButton13);
			this->Controls->Add(this->radioButton9);
			this->Controls->Add(this->radioButton10);
			this->Controls->Add(this->radioButton11);
			this->Controls->Add(this->radioButton6);
			this->Controls->Add(this->radioButton7);
			this->Controls->Add(this->radioButton8);
			this->Controls->Add(this->radioButton5);
			this->Controls->Add(this->radioButton4);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btnProgramC);
			this->Controls->Add(this->btnProgramB);
			this->Controls->Add(this->btnProgramA);
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
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void btnCoin10_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
