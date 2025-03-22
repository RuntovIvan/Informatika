#include <iostream>
#include <string>
#include "Salary.h"
using namespace std;

Salary::Salary()
{
	fio = "-";
	salary = 0;
	bonus = 0;
	cout << "����������� ��� ���������� ��� ������� " << this << endl;
}

Salary::Salary(string F, double S, int B)
{
	fio = F;
	salary = S;
	bonus = B;
	cout << "����������� � ����������� ��� ������� " << this << endl;
}

Salary::Salary(const Salary& t)
{
	fio = t.fio;
	salary = t.salary;
	bonus = t.bonus;
	cout << "����������� ����������� ��� ������� " << this << endl;
}

Salary::~Salary()
{
	cout << "���������� ��� ������� " << this << endl;
}

string Salary::get_fio()
{
	return fio;
}

double Salary::get_salary()
{
	return salary;
}

int Salary::get_bonus()
{
	return bonus;
}

void Salary::set_fio(string F)
{
	fio = F;
}

void Salary::set_salary(double S)
{
	salary = S;
}

void Salary::set_bonus(int B)
{
	bonus = B;
}

void Salary::show()
{
	cout << "���: " << fio << endl;
	cout << "�����: " << salary << endl;
	cout << "������: " << bonus << '%' << endl << endl;
}