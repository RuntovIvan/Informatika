#include "Object.h"
#include "Print.h"
#include "Magazine.h"
#include "Vector.h"
#include "Dialog.h"
#include <iostream>
#include <clocale>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	system("chcp 1251");
	system("cls");

	Dialog D;
	D.Execute();

	return 0;
}