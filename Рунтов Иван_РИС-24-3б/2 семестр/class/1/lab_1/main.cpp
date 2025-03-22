#include <iostream>
#include <clocale>
#include "progression.h"
using namespace std;

Progression make_Progression(double F, int S)
{
	Progression t;
	t.init(F, S);
	return t;
}

int main()
{
	setlocale(LC_ALL, "RU");

	Progression A, B;
	cout << "Объект A\n";
	A.init(1.1, 3);
	A.show();
	cout << "A.element(3) = " << A.element(3) << endl;
	
	cout << "\nОбъект B\n";
	B.read();
	B.show();
	cout << "B.element(3) = " << B.element(3) << endl;

	Progression* X = new Progression;
	cout << "\nОбъект X\n";
	X->init(1.3, 3);
	X->show();
	cout << "X->element(3) = " << X->element(3) << endl;
	delete X;

	Progression arr[3];
	cout << "\nСтатический массив\n";
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << endl;
		arr[i].read();
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << endl;
		arr[i].show();
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
		cout << "arr[" << i << "].element(3) = " << arr[i].element(3) << endl;

	Progression* dyn_arr = new Progression[3];
	cout << "\nДинамический массив\n";
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << endl;
		dyn_arr[i].read();
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << endl;
		dyn_arr[i].show();
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
		cout << "dyn_arr[" << i << "].element(3) = " << dyn_arr[i].element(3) << endl;
	delete[] dyn_arr;

	cout << "\nФункция make_Progression\n";
	double f;
	int s;
	cout << "Введите первый элемент: ";
	cin >> f;
	cout << "Введите второй элемент: ";
	cin >> s;
	Progression F = make_Progression(f, s);
	F.show();
	cout << "F.element(3) = " << F.element(3) << endl;
	return 0;
}