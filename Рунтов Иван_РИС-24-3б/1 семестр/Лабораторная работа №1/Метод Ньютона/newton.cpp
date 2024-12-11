#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

// ���������� �������� �������
double f(double x)
{
	return x - 2 + sin(1 / x);
}

// ���������� �������� ������ ����������� �� �������
double pr_1(double x)
{
	return 1 - (cos(1 / x) / pow(x, 2));
}

// ���������� �������� ������ ����������� �� �������
double pr_2(double x)
{
	return (2 * cos(1 / x) * x - sin(1 / x)) / pow(x, 4);
}


int main()
{
	setlocale(LC_ALL, "RU");
	double a, b, eps;
	cout << "������� ������� ��������� ����� ������: ";
	cin >> a >> b;
	while (a >= b)
	{
		cout << "����� ������� ������ ���� ������ ������. ����������� ��������� ���� ������ ����� ������: ";
		cin >> a >> b;
	}
	cout << "������� �������� ����������: ";
	cin >> eps;
	if (f(a) * pr_2(a) > 0 || f(b) * pr_2(b) > 0)
	{
		double x0 = b;
		double x1 = x0 - (f(x0) / pr_1(x0));
		int k = 1;
		while (abs(x1 - x0) >= eps)
		{
			cout << "�������� " << k << ':' << x1 << endl;
			k++;
			x0 = x1;
			x1 = x0 - (f(x0) / pr_1(x0));
		}
		cout << "��������� �������� �����: " << x1;
	}
	else
		cout << "����� �� ��������� ���.";
	return 0;
}