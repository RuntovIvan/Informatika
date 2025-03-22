#pragma once
#include <string>
using namespace std;

class Salary
{
	string fio;
	double salary;
	int bonus;
public:
	Salary(); // конструктор без параметров
	Salary(string, double, int); // конструктор с параметрами
	Salary(const Salary&); // конструктор копирования
	~Salary(); // деструктор
	string get_fio(); // селектор
	void set_fio(string); // модификатор
	double get_salary(); // селектор
	void set_salary(double); // модификатор
	int get_bonus(); // селектор
	void set_bonus(int); // модификатор
	void show();
};