#include <iostream>
#include <clocale>
#include "Pair.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	Pair A(0, 5.5);
	Pair B(7, 8.5);

	cout << "A = " << A << endl;
	cout << "B = " << B << endl;

	cout << "Вычитание:" << endl;
	cout << "A - B = " << A << " - " << B << " = " << A - B << endl;
	cout << "B - A = " << B << " - " << A << " = " << B - A << endl;

	cout << "Прибавление целой константы к A:" << endl;
	cout << "A + 5 = " << A + 5 << endl;
	cout << "5 + A = " << 5 + A << endl;

	cout << "Прибавление дробной константы к B:" << endl;
	cout << "B + 3.5 = " << B + 3.5 << endl;
	cout << "3.5 + B = " << 3.5 + B << endl;
	return 0;
}