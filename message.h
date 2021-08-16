#pragma once
using namespace std;
#include<iostream>
#include<string>
#include<msclr/marshal_cppstd.h>
namespace LIbraryMnagementSystem {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for message
	/// </summary>
	public ref class message : public System::Windows::Forms::Form
	{
	public:
		Form^ obj;
		message(Form^ obj1,string msg,string head)
		{
			InitializeComponent();
			obj = obj1;
			this->mesg->Text= msclr::interop::marshal_as< String^ >(msg);
			this->heading->Text= msclr::interop::marshal_as< String^ >(head);
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~message()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ heading;
	private: System::Windows::Forms::Label^ mesg;
	private: System::Windows::Forms::Button^ ok;

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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->heading = (gcnew System::Windows::Forms::Label());
			this->mesg = (gcnew System::Windows::Forms::Label());
			this->ok = (gcnew System::Windows::Forms::Button());
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Gray;
			this->panel1->Location = System::Drawing::Point(0, 201);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(522, 35);
			this->panel1->TabIndex = 0;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Blue;
			this->panel2->Controls->Add(this->heading);
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(522, 47);
			this->panel2->TabIndex = 1;
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
			// mesg
			// 
			this->mesg->AutoSize = true;
			this->mesg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mesg->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->mesg->Location = System::Drawing::Point(29, 59);
			this->mesg->Name = L"mesg";
			this->mesg->Size = System::Drawing::Size(64, 25);
			this->mesg->TabIndex = 2;
			this->mesg->Text = L"mesg";
			// 
			// ok
			// 
			this->ok->BackColor = System::Drawing::Color::Red;
			this->ok->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->ok->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ok->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ok->Location = System::Drawing::Point(413, 160);
			this->ok->Name = L"ok";
			this->ok->Size = System::Drawing::Size(92, 35);
			this->ok->TabIndex = 3;
			this->ok->Text = L"OK";
			this->ok->UseVisualStyleBackColor = false;
			this->ok->Click += gcnew System::EventHandler(this, &message::ok_Click);
			// 
			// message
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(517, 239);
			this->Controls->Add(this->ok);
			this->Controls->Add(this->mesg);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"message";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"message";
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ok_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		obj->Show();
	}
};
}
