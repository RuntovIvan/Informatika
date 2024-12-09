#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

// ���������� �������� �������
double f(double x)
{
	return x - 2 + sin(1 / x);
}

int main()
{
	setlocale(LC_ALL, "RU");
	double a, b, eps;
	cout << "������� ������� ��������� ����� ������: ";
	cin >> a >> b;
	while (a >= b)
	{
		cout << "����� ������� ������ ���� ������ ������. \
����������� ��������� ���� ������ ����� ������: ";
		cin >> a >> b;
	}
	cout << "������� �������� ����������: ";
	cin >> eps;

	if (f(a) * f(b) < 0)
	{
		double c;
		int k = 1;
		while (abs(a - b) >= eps)
		{
			c = (a + b) / 2;
			cout << "�������� " << k << ':' << c << endl;
			k++;
			if (f(a) * f(c) < 0)
				b = c;
			else
				a = c;
		}
		cout << "��������� �������� �����: " << b;
	}
	else
		cout << "����� �� ��������� �� ����������.";
	return 0;
}

