#pragma once

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::Configuration;
	using namespace msclr::interop;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace ModuleNet;//!!!!!!!!!!!

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ adr;
	private: System::Windows::Forms::Button^ btnOK;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ subnetLabel;
	private: System::Windows::Forms::Label^ broadcastLabel;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ errorLabel;
	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->adr = (gcnew System::Windows::Forms::TextBox());
			this->btnOK = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->subnetLabel = (gcnew System::Windows::Forms::Label());
			this->broadcastLabel = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->errorLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// adr
			// 
			this->adr->Location = System::Drawing::Point(154, 66);
			this->adr->Name = L"adr";
			this->adr->Size = System::Drawing::Size(229, 22);
			this->adr->TabIndex = 0;
			this->adr->Text = L"192.168.100.21/26";
			// 
			// btnOK
			// 
			this->btnOK->Location = System::Drawing::Point(202, 321);
			this->btnOK->Name = L"btnOK";
			this->btnOK->Size = System::Drawing::Size(75, 23);
			this->btnOK->TabIndex = 1;
			this->btnOK->Text = L"ok";
			this->btnOK->UseVisualStyleBackColor = true;
			this->btnOK->Click += gcnew System::EventHandler(this, &Form1::btnOK_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(34, 69);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(71, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"IPv4/CIDR";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(37, 24);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(240, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Podaj adres IP w postaci: a.b.c.d/cidr";
			// 
			// subnetLabel
			// 
			this->subnetLabel->AutoSize = true;
			this->subnetLabel->Location = System::Drawing::Point(192, 144);
			this->subnetLabel->Name = L"subnetLabel";
			this->subnetLabel->Size = System::Drawing::Size(57, 17);
			this->subnetLabel->TabIndex = 4;
			this->subnetLabel->Text = L"podsieć";
			// 
			// broadcastLabel
			// 
			this->broadcastLabel->AutoSize = true;
			this->broadcastLabel->Location = System::Drawing::Point(192, 184);
			this->broadcastLabel->Name = L"broadcastLabel";
			this->broadcastLabel->Size = System::Drawing::Size(71, 17);
			this->broadcastLabel->TabIndex = 5;
			this->broadcastLabel->Text = L"broadcast";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(34, 144);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(105, 17);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Adres podsieci:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(37, 184);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(149, 17);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Adres rozgłoszeniowy:";
			// 
			// errorLabel
			// 
			this->errorLabel->AutoSize = true;
			this->errorLabel->Location = System::Drawing::Point(154, 252);
			this->errorLabel->Name = L"errorLabel";
			this->errorLabel->Size = System::Drawing::Size(0, 17);
			this->errorLabel->TabIndex = 8;
			this->errorLabel->ForeColor = System::Drawing::Color::Red;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(498, 385);
			this->Controls->Add(this->errorLabel);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->broadcastLabel);
			this->Controls->Add(this->subnetLabel);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnOK);
			this->Controls->Add(this->adr);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnOK_Click(System::Object^ sender, System::EventArgs^ e) {
		//String^ ip_ = gcnew String(adresiptextBox->Text);
		System::String^ ip_ = adr->Text;
		//std::string ip_ = adr->Text;
		//skierować dane między typami macierzystymi i zarządzanymi String -> string
		msclr::interop::marshal_context context;
		std::string ip = context.marshal_as<std::string>(ip_);
		std::regex ipv4("(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])(\\/)([1-9]|[1-2][0-9]|3[0-2])");
		if (std::regex_match(ip, ipv4)) {
			this->errorLabel->Text = "";
			calc ip1(ip);
			std::string s = ip1.getsubnet();
			this->subnetLabel->Text = gcnew String(s.c_str());
			s = ip1.getbroadcast();
			this->broadcastLabel->Text = gcnew String(s.c_str());
		}
		else {
			this->errorLabel->Text = "Podany adres jest nieprawidłowy!";
		}
	}
	};
}
