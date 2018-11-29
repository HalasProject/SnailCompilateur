#include "Home.h"
#include "pch.h"
//#include "Boit.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	SnailG::Home form;
	Application::Run(%form);
	return 0;
}