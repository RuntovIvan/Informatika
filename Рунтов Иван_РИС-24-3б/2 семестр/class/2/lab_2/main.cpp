#include <iostream>
#include <string>
#include <clocale>
#include "Salary.h"
using namespace std;

Salary make_Salary() // выполняется конструктор копирования
{
	string fio;
	double salary;
	int bonus;
	cout << "Введите ФИО: ";
	getline(cin, fio);
	cout << "Введите оклад: ";
	cin >> salary;
	cout << "Введите премию (%): ";
	cin >> bonus;

	Salary t(fio, salary, bonus);
	return t;
}

void print_Salary(Salary t) // и здесь выполняется конструктор копирования
{
	t.show();
}

int main()
{
	setlocale(LC_ALL, "RU");
	system("chcp 1251");
	system("cls");

	// конструктор без параметров
	Salary s1;
	s1.show();

	// конструктор с параметрами
	Salary s2("Иванов Иван Иванович", 50450.45, 35);
	s2.show();

	// конструктор копирования
	Salary s3 = s1;
	s3.set_fio("Дурбажев Даниил Игоревич");
	s3.set_salary(120550.0);
	s3.set_bonus(75);
	print_Salary(s3);

	s1 = make_Salary();
	s1.show();
	return 0;
}