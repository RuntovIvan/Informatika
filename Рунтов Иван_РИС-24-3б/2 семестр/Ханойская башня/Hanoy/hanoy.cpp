#include <iostream>
#include <clocale>
using namespace std;

void han(int n, int start, int point, int temp, int** arr, int kol);
void print_disk(int n, int kol);
void print_sticks(int** arr, int kol);
void shift(int** arr, int kol, int start, int point);

int moves = 0;

int main()
{
	setlocale(LC_ALL, "RU");

	int n;
	cout << "Введите количество дисков: ";
	cin >> n;

	while (n < 1)
	{
		cout << "Количество дисков должно быть натуральным числом. Введите еще раз: ";
		cin >> n;
	}

	int** stick = new int* [3];
	for (int i = 0; i < 3; i++)
		stick[i] = new int[n] {};

	for (int i = 0; i < n; i++)
		stick[0][i] = i + 1;

	print_sticks(stick, n);

	han(n, 1, 3, 2, stick, n);

	cout << endl << "Количество ходов: " << moves << endl;
	delete[] stick;
	return 0;
}

void han(int n, int start, int point, int temp, int** arr, int kol)
{
	if (n != 0)
	{
		han(n - 1, start, temp, point, arr, kol);

		cout << start << " => " << point << endl;
		moves++;
		shift(arr, kol, start, point);
		print_sticks(arr, kol);

		han(n - 1, temp, point, start, arr, kol);
	}
}

void print_disk(int n, int kol)
{
	int max_p = (kol + (kol % 2 == 0)) / 2;

	int tek_p = max_p - n / 2;
	for (int i = 1; i <= tek_p; i++)
		cout << ' ';

	if (n % 2 != 0)
		for (int i = 1; i <= n; i++)
			cout << '*';
	else
	{
		for (int i = 1; i <= n / 2; i++)
			cout << '*';

		cout << '|';

		for (int i = 1; i <= n / 2; i++)
			cout << '*';
	}

	for (int i = 1; i <= tek_p; i++)
		cout << ' ';
}

void print_sticks(int** arr, int kol)
{
	cout << endl;
	for (int i = 0; i < kol; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			print_disk(arr[j][i], kol);
			cout << '\t';
		}
		cout << endl;
	}
	for (int i = 1; i <= (kol + 8) * 3; i++)
		cout << '_';
	cout << endl;
}

void shift(int** arr, int kol, int start, int point)
{
	int* start_stick = arr[start - 1];
	int* point_stick = arr[point - 1];

	int i = 0;
	while (start_stick[i] == 0)
		i++;

	int tmp = start_stick[i];
	start_stick[i] = 0;

	i = kol - 1;
	while (point_stick[i] != 0)
		i--;

	point_stick[i] = tmp;
}