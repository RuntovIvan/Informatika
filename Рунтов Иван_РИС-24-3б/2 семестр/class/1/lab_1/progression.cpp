#include <iostream>
#include <cmath>
#include "progression.h"
using namespace std;

void Progression::init(double F, int S)
{
	first = F;
	second = S;
}

void Progression::read()
{
	cout << "������� ������ �������: ";
	cin >> first;
	cout << "������� ������ �������: ";
	cin >> second;
}

void Progression::show()
{
	cout << "������ �������: " << first << endl;
	cout << "������ �������: " << second << endl;
}

double Progression::element(int j)
{
	return first * pow(second, j);
}