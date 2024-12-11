#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

// вычисление значения функции
double f(double x)
{
	return x - 2 + sin(1 / x);
}

// вычисление значения первой производной от функции
double pr_1(double x)
{
	return 1 - (cos(1 / x) / pow(x, 2));
}

// вычисление значения второй производной от функции
double pr_2(double x)
{
	return (2 * cos(1 / x) * x - sin(1 / x)) / pow(x, 4);
}


int main()
{
	setlocale(LC_ALL, "RU");
	double a, b, eps;
	cout << "Введите границы интервала через пробел: ";
	cin >> a >> b;
	while (a >= b)
	{
		cout << "Левая граница должна быть меньше правой. Осуществите повторный ввод границ через пробел: ";
		cin >> a >> b;
	}
	cout << "Введите точность вычислений: ";
	cin >> eps;
	if (f(a) * pr_2(a) > 0 || f(b) * pr_2(b) > 0)
	{
		double x0 = b;
		double x1 = x0 - (f(x0) / pr_1(x0));
		int k = 1;
		while (abs(x1 - x0) >= eps)
		{
			cout << "Итерация " << k << ':' << x1 << endl;
			k++;
			x0 = x1;
			x1 = x0 - (f(x0) / pr_1(x0));
		}
		cout << "Найденное значение корня: " << x1;
	}
	else
		cout << "Корня на интервале нет.";
	return 0;
}