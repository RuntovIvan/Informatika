#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

// вычисление значения основной функции
double f(double x)
{
	return x - 2 + sin(1 / x);
}

// вычисление значения дополнительной функции x = phi(x)
double phi(double x)
{
	return 2 - sin(1 / x);
}

// вычисление значения производной от дополнительной функции
double pr_phi(double x)
{
	return cos(1 / x) / pow(x, 2);
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

	if (abs(pr_phi(a)) < 1 || abs(pr_phi(b)) < 1) // проверка на сходиость
	{
		double x0 = b;
		double x1 = phi(x0);
		int k = 1;
		while (abs(x1 - x0) >= eps)
		{
			cout << "Итерация " << k << ": " << x1 << endl;
			k++;
			x0 = x1;
			x1 = phi(x0);
		}
		cout << "Найденное значение корня: " << x1;
	}
	else
		cout << "Корня на интервале не существует.";
	return 0;
}

