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
	cout << "Введите первый элемент: ";
	cin >> first;
	cout << "Введите второй элемент: ";
	cin >> second;
}

void Progression::show()
{
	cout << "Первый элемент: " << first << endl;
	cout << "Второй элемент: " << second << endl;
}

double Progression::element(int j)
{
	return first * pow(second, j);
}