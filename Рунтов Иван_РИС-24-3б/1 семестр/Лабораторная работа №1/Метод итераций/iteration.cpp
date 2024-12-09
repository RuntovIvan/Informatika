#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

// ���������� �������� �������� �������
double f(double x)
{
	return x - 2 + sin(1 / x);
}

// ���������� �������� �������������� ������� x = phi(x)
double phi(double x)
{
	return 2 - sin(1 / x);
}

// ���������� �������� ����������� �� �������������� �������
double pr_phi(double x)
{
	return cos(1 / x) / pow(x, 2);
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

	if (abs(pr_phi(a)) < 1 || abs(pr_phi(b)) < 1) // �������� �� ���������
	{
		double x0 = b;
		double x1 = phi(x0);
		int k = 1;
		while (abs(x1 - x0) >= eps)
		{
			cout << "�������� " << k << ": " << x1 << endl;
			k++;
			x0 = x1;
			x1 = phi(x0);
		}
		cout << "��������� �������� �����: " << x1;
	}
	else
		cout << "����� �� ��������� �� ����������.";
	return 0;
}

