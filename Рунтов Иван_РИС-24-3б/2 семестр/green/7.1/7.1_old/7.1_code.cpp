#include <iostream>
#include <clocale>
using namespace std;

const int rows = 5, cols = 10;

void del(int a[], int* row);
void del(int* a[], int row, int col);
void show_1d(int a[], int row);
void show_2d(int* a[], int row, int col);

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(NULL));

	// создание двумерного массива
	int* a[rows];
	for (int i = 0; i < rows; i++)
		a[i] = new int[cols];

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			a[i][j] = rand() % 6;

	// вывод изначального двумерного массива
	cout << "Изначальный двумерный массив:\n";
	show_2d(a, rows, cols);

	// преобразование двумерного массива
	del(a, rows, cols);

	// вывод преобразованного двумерного массива
	cout << "Преобразованный двумерный массив:\n";
	int kol_rows = rows - ((rows) / 2);
	show_2d(a, kol_rows, cols);

	cout << endl;

	//создание одномерного массива
	int len = rand() % 11 + 10;
	int* b = new int[len];
	for (int i = 0; i < len; i++)
		b[i] = rand() % 11 - 5;

	//вывод изначального одномерного массива
	cout << "Изначальный одномерный массив:\n";
	show_1d(b, len);

	// преобразование одномерного массива
	del(b, &len);

	//вывод преобразованного одномерного массива
	cout << "\nПреобразованный одномерный массив:\n";
	show_1d(b, len);
	return 0;
}

void del(int a[], int* row)
{
	int zero_kol = 0;
	for (int i = 0; i < *row; i++)
		if (a[i] == 0)
			zero_kol += 1;

	if (zero_kol >= 2)
	{
		int i = 0, sum_sdvig = 0;
		int* nums = new int[*row];
		for (int j = 0; j < *row; j++)
			if (a[j] == 0)
			{
				nums[i] = j;
				i++;
			}

		for (int k = 0; k < zero_kol - 1; k++)
		{
			int n_start = nums[k], n_end = nums[k + 1];
			if (n_end - n_start != 1)
			{
				while (a[n_start + 1] != 0)
					for (int j = n_start + 1; j < *row - 1; j++)
						a[j] = a[j + 1];

				int sdvig = n_end - n_start - 1;
				sum_sdvig += sdvig;
				for (int i = k + 1; i < zero_kol; i++)
					nums[i] -= sdvig;
			}
		}
		*row -= sum_sdvig;
	}
}

void del(int* a[], int row, int col)
{
	for (int k = 1; k < (row + 1) / 2 + 1; k++)
	{
		for (int i = k; i < row - 1; i++)
			a[i] = a[i + 1];
	}
}

void show_1d(int a[], int row)
{
	for (int i = 0; i < row; i++)
		cout << a[i] << ' ';
}

void show_2d(int* a[], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
}