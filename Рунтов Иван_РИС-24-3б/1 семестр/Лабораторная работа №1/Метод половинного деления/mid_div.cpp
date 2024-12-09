#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

// вычисление значения функции
double f(double x)
{
	return x - 2 + sin(1 / x);
}

int main()
{
	setlocale(LC_ALL, "RU");
	double a, b, eps;
	cout << "Введите границы интервала через пробел: ";
	cin >> a >> b;
	while (a >= b)
	{
		cout << "Левая граница должна быть меньше правой. \
Осуществите повторный ввод границ через пробел: ";
		cin >> a >> b;
	}
	cout << "Введите точность вычислений: ";
	cin >> eps;

	if (f(a) * f(b) < 0)
	{
		double c;
		int k = 1;
		while (abs(a - b) >= eps)
		{
			c = (a + b) / 2;
			cout << "Итерация " << k << ':' << c << endl;
			k++;
			if (f(a) * f(c) < 0)
				b = c;
			else
				a = c;
		}
		cout << "Найденное значение корня: " << b;
	}
	else
		cout << "Корня на интервале не существует.";
	return 0;
}

