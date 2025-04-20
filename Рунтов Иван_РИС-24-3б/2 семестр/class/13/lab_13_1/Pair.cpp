#include "Pair.h"
#include <iostream>
using namespace std;

Pair::Pair()
{
	first = 0;
	second = 0.0;
}

Pair::Pair(int F, double S)
{
	first = F;
	second = S;
}

Pair::Pair(const Pair& p)
{
	first = p.first;
	second = p.second;
}

int Pair::get_first()
{
	return first;
}

double Pair::get_second()
{
	return second;
}

void Pair::set_first(int F)
{
	first = F;
}

void Pair::set_second(double S)
{
	second = S;
}

Pair Pair::operator=(const Pair& p)
{
	if (this == &p) return *this;
	first = p.first;
	second = p.second;
	return *this;
}

istream& operator>>(istream& in, Pair& p)
{
	cout << endl;
	cout << "Enter first: "; in >> p.first;
	cout << "Enter second: "; in >> p.second;
	cout << endl;
	return in;
}

ostream& operator<<(ostream& out, const Pair& p)
{
	out << '(' << p.first << " : " << p.second << ')';
	return out;
}

bool Pair::operator==(const Pair& p) const
{
	return (first == p.first && second == p.second);
}

bool Pair::operator>(const Pair& p) const
{
	return (first + second > p.first + p.second);
}

bool Pair::operator<(const Pair& p) const
{
	return (first + second < p.first + p.second);
}

Pair Pair::operator-(const Pair& p) const
{
	return Pair(first - p.first, second - p.second);
}

Pair Pair::operator+(const Pair& p)
{
	return Pair(first + p.first, second + p.second);
}

Pair Pair::operator/(const int n)
{
	return Pair(first / n, second / n);
}