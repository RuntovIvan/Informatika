#include <iostream>
#include <clocale>
using namespace std;

const int row = 5, col = 6;

void show_2d(int arr[][col], int row, int col);
void show_1d(int arr[], int n);
void fill_2d(int arr[][col], int row, int col);
void fill_1d(int arr_1d[], int arr[][col], int row, int col);
void back(int arr_1d[], int n, int arr[][col], int row, int col);

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(NULL));

	int arr[row][col]{};

	// запись значений в двумерный массив
	fill_2d(arr, row, col);

	// вывод изначального двумерного массива
	cout << "Изначальный двумерный массив:\n";
	show_2d(arr, row, col);
	cout << endl;

	int arr_1d[2 * row * col]{};

	// запись элементов в одномерный массив
	fill_1d(arr_1d, arr, row, col);
	
	// вывод одномерного массива
	cout << "Полученный одномерный массив:\n";
	show_1d(arr_1d, 2 * row * col);
	cout << endl;

	int newarr[row][col]{};

	// запись из одномерного в двумерный
	back(arr_1d, 2 * row * col, newarr, row, col);

	// вывод полученного двумерного массива
	cout << "Полученный двумерный массив:\n";
	show_2d(newarr, row, col);
	cout << endl;

	return 0;
}

void show_2d(int arr[][col], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << arr[i][j] << '\t';
		cout << endl;
	}
}

void show_1d(int arr[], int n)
{
	cout << '{';
	for (int i = 0; i < n; i++)
	{
		cout << arr[i];
		cout << ((i == n - 1) ? "}\n\n" : ", ");
	}
}

void fill_2d(int arr[][col], int row, int col)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			arr[i][j] = i * col + j + 1;
}

void fill_1d(int arr_1d[], int arr[][col], int row, int col)
{
	int sdvig_row = rand() % (row - 1) + 1;
	int sdvig_col = rand() % (col - 1) + 1;

	int ind = 0;

	// запись строк в одномерный массив
	for (int i = sdvig_row; i < row + sdvig_row; i++)
		for (int j = 0; j < col; j++)
		{
			arr_1d[ind] = arr[i % row][j];
			ind++;
		}

	// запись столбцов в одномерный массив
	for (int j = sdvig_col; j < col + sdvig_col; j++)
		for (int i = 0; i < row; i++)
		{
			arr_1d[ind] = arr[i][j % col];
			ind++;
		}
}

void back(int arr_1d[], int n, int arr[][col], int row, int col)
{
	for (int i = 0; i < n / 2; i++)
	{
		int t = arr_1d[i];

		int j = n / 2;
		while (arr_1d[j] != t)
			j++;

		arr[j % row][i % col] = t;
	}
}