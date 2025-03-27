#include <iostream>
#include "Pair.h"
using namespace std;

// ����������� ��� ����������
Pair::Pair()
{
	x = 0;
	y = 0.;
}

// ����������� � �����������
Pair::Pair(int x_p, double y_p)
{
	x = x_p;
	y = y_p;
}

// ���������� ��������� + ��� ������ �����
Pair Pair::operator+(int x_p)
{
	return Pair(x + x_p, y);
}

// ���������� ��������� + ��� �������� �����
Pair Pair::operator+(double y_p)
{
	return Pair(x, y + y_p);
}

// ���������� ��������� - ��� ��������� ��� �����
Pair Pair::operator-(Pair& p)
{
	return Pair(x - p.x, y - p.y);
}

// ���������� ��������� =
Pair Pair::operator=(Pair p)
{
	if (&p == this) return *this;
	x = p.x;
	y = p.y;
	return *this;
}

// ���������� ��������� + ��� ������ �����
Pair operator+(int x_p, Pair& p)
{
	return p + x_p;
}

// ���������� ��������� + ��� �������� �����
Pair operator+(double y_p, Pair& p)
{
	return p + y_p;
}

// ���������� ��������� <<
ostream& operator<<(ostream& out, Pair p)
{
	out << '(' << p.x << ':' << p.y << ')';
	return out;
}

// ���������
int Pair::get_x()
{
	return x;
}

double Pair::get_y()
{
	return y;
}

// ������������
void Pair::set_x(int x_p)
{
	x = x_p;
}

void Pair::set_y(double y_p)
{
	y = y_p;
}