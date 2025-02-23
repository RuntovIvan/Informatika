#include <iostream>
#include <clocale>
#include <cmath>
#include <cstdarg>
using namespace std;

double length(double x0, double y0, double x, double y);
double square(double x1, double y1, double x2, double y2, double x3, double y3);
void square1(int k, ...);

int main()
{
	setlocale(LC_ALL, "RU");

	double list4[8] = { 0, 0, 0, 5, 5, 0, 5, 5 };
	square1(4, list4[0], list4[1], list4[2], list4[3], list4[4], list4[5], list4[6], list4[7]);
	cout << endl;

	double list5[10] = { 0, 0, 0, 5, 5, 0, 5, 5, 7, 2.5 };
	square1(5, list5[0], list5[1], list5[2], list5[3], list5[4], list5[5], list5[6], list5[7], list5[8], list5[9]);
	cout << endl;

	double list8[16] = { 0, 0, -2, 2, -2, 6, 0, 8, 4, 8, 6, 6, 6, 2, 4, 0 };
	square1(8, list8[0], list8[1], list8[2], list8[3], list8[4], list8[5], list8[6], list8[7], list8[8], list8[9], \
		list8[10], list8[11], list8[12], list8[13], list8[14], list8[15]);
	cout << endl;
	return 0;
}

// ���������� ����� ������� �� ����������� �����
double length(double x0, double y0, double x, double y)
{
	return sqrt(pow(x - x0, 2) + pow(y - y0, 2));
}

// ���������� ������� ������������ �� ����������� �����
double square(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double a = length(x1, y1, x2, y2);
	double b = length(x1, y1, x3, y3);
	double c = length(x2, y2, x3, y3);

	double p = (a + b + c) / 2.;

	double s = sqrt(p * (p - a) * (p - b) * (p - c));
	return s;
}

// ���������� ������������ ���������; ������� �����������, ���������� ��; � ������� ���������� x � ������ ��������� �����
void square1(int k, ...)
{
	double* points = new double[k * 2];

	va_list arg;
	va_start(arg, k);

	for (int i = 0; i < k * 2; i++)
		points[i] = va_arg(arg, double);

	va_end(arg);

	double max_length = 0, l;
	int points_num[2]{}; // �������� �������� ��������� x �����, ���������� ������������ ���������

	for (int i = 0; i < k * 2 - 3; i += 2)
		for (int j = i + 2; j < k * 2 - 1; j += 2)
		{
			l = length(points[i], points[i + 1], points[j], points[j + 1]);
			if (l > max_length)
			{
				max_length = l;
				points_num[0] = i;
				points_num[1] = j;
			}
		}

	int f = 0; // ������ ���������� x ������� �����, ���������� �����������
	while ((f == points_num[0] || f == points_num[1]) && f < k * 2 - 1)
		f += 2;

	double x1 = points[points_num[0]]; // ���������� x 1-� �����, ���������� ������������ ���������
	double y1 = points[points_num[0] + 1]; // ���������� y 1-� �����, ���������� ������������ ���������
	double x2 = points[points_num[1]]; // ���������� x 2-� �����, ���������� ������������ ���������
	double y2 = points[points_num[1] + 1]; // ���������� y 2-� �����, ���������� ������������ ���������
	double x3 = points[f]; // ���������� x 3-� �����
	double y3 = points[f + 1]; // ���������� y 3-� �����

	double s = square(x1, y1, x2, y2, x3, y2);

	cout << "������������� � " << k << " ��������� � ������ : \n";
	for (int i = 0; i < k * 2 - 1; i += 2)
		cout << "(" << points[i] << " ; " << points[i + 1] << ")\n";
	delete[] points;

	cout << "������������ ���������: " << max_length << '\n';
	cout << "��������� �������� ����� �����: " << '(' << x1 << " ; " << y1 << ')'\
		<< " , " << '(' << x2 << " ; " << y2 << ")\n";
	cout << "������� ������������: " << s << '\n';
	cout << "����������� �������� ����� �����: " << '(' << x1 << " ; " << y1 << ')'\
		<< " , " << '(' << x2 << " ; " << y2 << ')' << " , " << '(' << x3 << " ; " << y3 << ")\n";
}