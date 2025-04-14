#include "Pair.h"
#include <iostream>
using namespace std;

// конструктор без параметров
Pair::Pair()
{
	x = 0;
	y = 0.;
}

// конструктор с параметрами
Pair::Pair(int x_p, double y_p)
{
	x = x_p;
	y = y_p;
}

// конструктор копирования
Pair::Pair(const Pair& p)
{
	x = p.x;
	y = p.y;
}

// селекторы
int Pair::get_x()
{
	return x;
}

double Pair::get_y()
{
	return y;
}

// модификаторы
void Pair::set_x(int x_p)
{
	x = x_p;
}

void Pair::set_y(double y_p)
{
	y = y_p;
}

// перегрузка оператора +int
Pair Pair::operator+(int x_p)
{
	return Pair(x + x_p, y);
}

// перегрузка оператора +double
Pair Pair::operator+(double y_p)
{
	return Pair(x, y + y_p);
}

// перегрузка оператора -
Pair Pair::operator-(const Pair& p)
{
	return Pair(x - p.x, y - p.y);
}

// перегрузка оператора присваивания
Pair& Pair::operator=(const Pair& p)
{
	if (this == &p) return *this;
	x = p.x;
	y = p.y;
	return *this;
}

// перегрузка оператора int + Pair
Pair operator+(int x_p, Pair& p)
{
	return p + x_p;
}

// перегрузка оператора double + Pair
Pair operator+(double y_p, Pair& p)
{
	return p + y_p;
}

// перегрузка оператора ввода
istream& operator>>(istream& in, Pair& p)
{
	cout << "x = ";
	in >> p.x;
	cout << "y = ";
	in >> p.y;
	return in;
}

// перегрузка оператора вывода
ostream& operator<<(ostream& out, const Pair& p)
{
	cout << '(' << p.x << " : " << p.y << ')';
	return out;
}

// перегрузка оператора ввода из файла
ifstream& operator>>(ifstream& fin, Pair& p)
{
	fin >> p.x;
	fin >> p.y;
	return fin;
}

// перегрузка оператора вывода в файл
ofstream& operator<<(ofstream& fout, const Pair& p)
{
	fout << p.x << " " << p.y;
	return fout;
}