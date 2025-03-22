#include <iostream>
#include <string>
#include <clocale>
#include "Salary.h"
using namespace std;

Salary make_Salary() // ����������� ����������� �����������
{
	string fio;
	double salary;
	int bonus;
	cout << "������� ���: ";
	getline(cin, fio);
	cout << "������� �����: ";
	cin >> salary;
	cout << "������� ������ (%): ";
	cin >> bonus;

	Salary t(fio, salary, bonus);
	return t;
}

void print_Salary(Salary t) // � ����� ����������� ����������� �����������
{
	t.show();
}

int main()
{
	setlocale(LC_ALL, "RU");

	// ����������� ��� ����������
	Salary s1;
	s1.show();

	// ����������� � �����������
	Salary s2("������ ���� ��������", 50450.45, 35);
	s2.show();

	// ����������� �����������
	Salary s3 = s1;
	s3.set_fio("�������� ������ ��������");
	s3.set_salary(120550.0);
	s3.set_bonus(75);
	print_Salary(s3);

	s1 = make_Salary();
	s1.show();
	return 0;
}