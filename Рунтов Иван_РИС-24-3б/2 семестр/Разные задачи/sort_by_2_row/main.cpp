#include <iostream>
#include <clocale>
using namespace std;

void show_arr(int* arr, const int row, const int col);
void sort(int* arr, const int row, const int col);
void init_arr(int* arr, const int row, const int col);

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(NULL));

	const int row = 5;
	const int col = 5;
	int arr[row][col];
	init_arr(&arr[0][0], row, col);

	cout << "Изначальный массив:\n";
	show_arr(&arr[0][0], row, col);

	sort(&arr[0][0], row, col);

	cout << endl;
	cout << "Отсортированный по 2 строке массив:\n";
	show_arr(&arr[0][0], row, col);
	return 0;
}

void show_arr(int* arr, const int row, const int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << arr[i * col + j] << '\t';
		cout << endl;
	}
}

void sort(int* arr, const int row, const int col)
{
	for (int i = 0; i < col - 1; i++)
	{
		int min_el = arr[col + i];
		int min_i = i;
		for (int j = i + 1; j < col; j++)
			if (arr[col + j] < min_el)
			{
				min_el = arr[col + j];
				min_i = j;
			}

		for (int k = 0; k < row; k++)
		{
			int t = arr[k * col + i];
			arr[k * col + i] = arr[k * col + min_i];
			arr[k * col + min_i] = t;
		}
	}
}

void init_arr(int* arr, const int row, const int col)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			arr[i * col + j] = rand() % 26;
}