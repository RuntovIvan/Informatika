#include <iostream>
#include <clocale>
using namespace std;

void show_2d(int** arr, int row, int col);
void show_1d(int* arr, int len);
void del(int**& arr, int& row, int col); // удаление четных строк двумерного массива
void del(int* arr, int& len); // удаляет все элементы, заключенные между двумя нулевыми элементами одномерного массива

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(NULL));

	// создание двумерного массива
	int rows = 6, cols = 10;

	int** a = new int* [rows];
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
	show_2d(a, rows, cols);

	for (int i = 0; i < rows; i++)
		delete[] a[i];
	delete[] a;

	//создание одномерного массива
	int len = rand() % 11 + 10;
	int* b = new int[len];
	for (int i = 0; i < len; i++)
		b[i] = rand() % 11 - 5;

	//вывод изначального одномерного массива
	cout << "Изначальный одномерный массив:\n";
	show_1d(b, len);

	// преобразование одномерного массива
	del(b, len);

	//вывод преобразованного одномерного массива
	cout << "\nПреобразованный одномерный массив:\n";
	show_1d(b, len);

	delete[] b;
	return 0;
}

void show_2d(int** arr, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << arr[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

void show_1d(int* arr, int len)
{
	cout << '{';
	for (int i = 0; i < len; i++)
	{
		cout << arr[i];
		cout << ((i == len - 1) ? "}\n" : ", ");
	}
	cout << endl;
}

void del(int**& arr, int& row, int col)
{
	int** new_arr = new int* [row - row / 2];
	for (int i = 0; i < row - row / 2; i++)
		new_arr[i] = new int[col];

	int ind = 0;
	for (int i = 0; i < row; i++)
		if (i % 2 == 0)
		{
			for (int j = 0; j < col; j++)
				new_arr[ind][j] = arr[i][j];
			ind++;
		}

	for (int i = 0; i < row; i++)
		delete[] arr[i];
	delete[] arr;
	arr = new_arr;

	row -= row / 2;
}

void del(int* arr, int& len)
{
	int null_kol = 0; // количество нулей в массиве
	for (int i = 0; i < len; i++)
		if (arr[i] == 0)
			null_kol += 1;

	int* null_pos = new int[null_kol]; // массив с индексами нулей
	// заполнение массива индексами нулей
	int ind = 0;
	for (int i = 0; i < len; i++)
		if (arr[i] == 0)
		{
			null_pos[ind] = i;
			ind++;
		}

	for (int k = 0; k < null_kol - 1; k++)
	{
		int n_start = null_pos[k], n_end = null_pos[k + 1];

		for (int i = 0; i < n_end - n_start - 1; i++) // сколько элементов заключено между нулями
		{
			for (int j = n_start + 1; j < len - 1; j++)
				arr[j] = arr[j + 1];
			len -= 1;
		}

		// уменьшение индексов следующих нулей
		for (int i = k + 1; i < null_kol; i++)
			null_pos[i] -= n_end - n_start - 1;
	}
	delete[] null_pos;
}