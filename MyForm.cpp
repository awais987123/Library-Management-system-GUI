#include "MyForm.h"
#include"library.h"
#include"subscribers.h"
#include"borrowingrecord.h"
using namespace System;
using namespace System::Windows::Forms;
 [STAThread]

 int main()
 {
	 Application::EnableVisualStyles();
	 Application::SetCompatibleTextRenderingDefault(false);
	 LIbraryMnagementSystem::MyForm form;
	 Application::Run(% form);
 }