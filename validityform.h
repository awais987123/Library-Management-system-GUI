#pragma once
#include<string>
#include<iostream>
#include<msclr/marshal_cppstd.h>
using namespace std;
namespace LIbraryMnagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for validityform
	/// </summary>
	public ref class validityform : public System::Windows::Forms::Form
	{
	public:
		validityform(string msg,string head)
		{
			InitializeComponent();
			String^ input = msclr::interop::marshal_as< String^ >(head);
			this->heading->Text = input;
			String^ mg = msclr::interop::marshal_as< String^ >(msg);
			this->mesg->Text = mg;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~validityform()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ ok;
	protected:
	private: System::Windows::Forms::Label^ mesg;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ heading;

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
			this->ok = (gcnew System::Windows::Forms::Button());
			this->mesg = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->heading = (gcnew System::Windows::Forms::Label());
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// ok
			// 
			this->ok->BackColor = System::Drawing::Color::Red;
			this->ok->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->ok->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ok->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ok->Location = System::Drawing::Point(403, 193);
			this->ok->Name = L"ok";
			this->ok->Size = System::Drawing::Size(92, 35);
			this->ok->TabIndex = 6;
			this->ok->Text = L"OK";
			this->ok->UseVisualStyleBackColor = false;
			this->ok->Click += gcnew System::EventHandler(this, &validityform::ok_Click);
			// 
			// mesg
			// 
			this->mesg->AutoSize = true;
			this->mesg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mesg->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->mesg->Location = System::Drawing::Point(19, 92);
			this->mesg->Name = L"mesg";
			this->mesg->Size = System::Drawing::Size(64, 25);
			this->mesg->TabIndex = 5;
			this->mesg->Text = L"mesg";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Blue;
			this->panel2->Controls->Add(this->heading);
			this->panel2->Location = System::Drawing::Point(0, 1);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(522, 47);
			this->panel2->TabIndex = 4;
			// 
			// heading
			// 
			this->heading->AutoSize = true;
			this->heading->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->heading->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->heading->Location = System::Drawing::Point(12, 0);
			this->heading->Name = L"heading";
			this->heading->Size = System::Drawing::Size(109, 39);
			this->heading->TabIndex = 0;
			this->heading->Text = L"label1";
			// 
			// validityform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Gray;
			this->ClientSize = System::Drawing::Size(502, 261);
			this->Controls->Add(this->ok);
			this->Controls->Add(this->mesg);
			this->Controls->Add(this->panel2);
			this->Name = L"validityform";
			this->Text = L"validityform";
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ok_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
	}
};
}
