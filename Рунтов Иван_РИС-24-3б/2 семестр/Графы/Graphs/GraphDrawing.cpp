#include "GraphDrawing.h"
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args)
{
	srand(time(nullptr));
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Graphs::GraphDrawing form;
	Application::Run(% form);
}