#include "Pair.h"
#include <iostream>
using namespace std;

Pair::Pair()
{
	x = 0;
	y = 0.;
}

Pair::Pair(int x_p, double y_p)
{
	x = x_p;
	y = y_p;
}

Pair::Pair(const Pair& p)
{
	x = p.x;
	y = p.y;
}

int Pair::get_x()
{
	return x;
}

double Pair::get_y()
{
	return y;
}

void Pair::set_x(int x_p)
{
	x = x_p;
}

void Pair::set_y(double y_p)
{
	y = y_p;
}

Pair Pair::operator+(int x_p)
{
	return Pair(x + x_p, y);
}

Pair Pair::operator+(double y_p)
{
	return Pair(x, y + y_p);
}

Pair Pair::operator-(const Pair& p)
{
	return Pair(x - p.x, y - p.y);
}

Pair& Pair::operator=(const Pair& p)
{
	if (this == &p) return *this;
	x = p.x;
	y = p.y;
	return *this;
}

Pair Pair::operator*(const Pair& p)
{
	return Pair(this->x * p.x, this->y * p.y);
}

Pair operator+(int x_p, Pair& p)
{
	return p + x_p;
}

Pair operator+(double y_p, Pair& p)
{
	return p + y_p;
}

istream& operator>>(istream& in, Pair& p)
{
	cout << "x = ";
	in >> p.x;
	cout << "y = ";
	in >> p.y;
	return in;
}

ostream& operator<<(ostream& out, const Pair& p)
{
	cout << '(' << p.x << " : " << p.y << ')';
	return out;
}