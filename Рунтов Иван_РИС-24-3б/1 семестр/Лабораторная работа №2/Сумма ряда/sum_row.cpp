#include <iostream>
#include <clocale>
using namespace std;

// ������� ���������� ������� �����
double pow(double a, int b)
{
    if (b == 0)
        return 1;
    return a * pow(a, b - 1);
}

// ������� ���������� ���������� �����
int factorial(int a)
{
    if (a == 1)
        return 1;
    return a * factorial(a - 1);
}

// ������� ���������� ����� ������������������
double get_sum(double x, int n)
{
    if (n == 0)
        return x;
    return (pow(x, 2 * n + 1) / factorial(2 * n + 1)) + get_sum(x, n - 1);
}

int main()
{
    setlocale(LC_ALL, "RU");
    int num;
    double x, s;

    cout << "������� �������� x:\n";
    cout << "x = ";
    cin >> x;
    cout << "������� ���������� ������ ����:\n";
    cin >> num;
    while (num < 1)
    {
        cout << "���������� ������ ������ ���� ����������� ������.\
 ���������� ��� ���:\n";
        cin >> num;
    }
    cout << '\n';

    s = get_sum(x, num - 1);
    cout << "s = " << s;

    return 0;
}