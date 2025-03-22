#pragma once
#include <string>
using namespace std;

class Salary
{
	string fio;
	double salary;
	int bonus;
public:
	Salary(); // ����������� ��� ����������
	Salary(string, double, int); // ����������� � �����������
	Salary(const Salary&); // ����������� �����������
	~Salary(); // ����������
	string get_fio(); // ��������
	void set_fio(string); // �����������
	double get_salary(); // ��������
	void set_salary(double); // �����������
	int get_bonus(); // ��������
	void set_bonus(int); // �����������
	void show();
};