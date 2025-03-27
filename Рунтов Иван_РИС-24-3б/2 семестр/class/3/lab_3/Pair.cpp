#include <iostream>
#include "Pair.h"
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

// перегрузка оператора + для целого числа
Pair Pair::operator+(int x_p)
{
	return Pair(x + x_p, y);
}

// перегрузка оператора + для дробного числа
Pair Pair::operator+(double y_p)
{
	return Pair(x, y + y_p);
}

// перегрузка оператора - для вычитания пар чисел
Pair Pair::operator-(Pair& p)
{
	return Pair(x - p.x, y - p.y);
}

// перегрузка оператора =
Pair Pair::operator=(Pair p)
{
	if (&p == this) return *this;
	x = p.x;
	y = p.y;
	return *this;
}

// перегрузка оператора + для целого числа
Pair operator+(int x_p, Pair& p)
{
	return p + x_p;
}

// перегрузка оператора + для дробного числа
Pair operator+(double y_p, Pair& p)
{
	return p + y_p;
}

// перегрузка оператора <<
ostream& operator<<(ostream& out, Pair p)
{
	out << '(' << p.x << ':' << p.y << ')';
	return out;
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