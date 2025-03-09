#include <iostream>
#include <clocale>
using namespace std;

void show_arr(int arr[], int n); // отображение массива
void fill_arr(int arr[], int n); // заполнение массива случайными числами
void copy(int arr1[], int arr2[], int n); // копирование элементов массива в другой массив
void bubble_sort(int arr[], int n); // сортировка пузырьком
void selection_sort(int arr[], int n); // сортировка выбором
void insertion_sort(int arr[], int n); // сортировка вставкой

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(NULL));

	const int n = 6;
	int arr[n];
	int arr_copy[n];
	fill_arr(arr, n);

	cout << "Сортировка пузырьком\n";
	cout << "Изначальный массив:\n";
	show_arr(arr, n);
	copy(arr, arr_copy, n);
	bubble_sort(arr_copy, n);
	cout << "Отсортированный массив:\n";
	show_arr(arr_copy, n);

	cout << "Сортировка выбором\n";
	cout << "Изначальный массив:\n";
	show_arr(arr, n);
	copy(arr, arr_copy, n);
	selection_sort(arr_copy, n);
	cout << "Отсортированный массив:\n";
	show_arr(arr_copy, n);

	cout << "Сортировка вставкой\n";
	cout << "Изначальный массив:\n";
	show_arr(arr, n);
	copy(arr, arr_copy, n);
	insertion_sort(arr_copy, n);
	cout << "Отсортированный массив:\n";
	show_arr(arr_copy, n);
	return 0;
	return 0;
}

void show_arr(int arr[], int n)
{
	cout << '{';
	for (int i = 0; i < n; i++)
	{
		cout << arr[i];
		if (i == n - 1)
			cout << "}\n";
		else
			cout << ", ";
	}
	cout << endl;
}

void fill_arr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 101;
}

void copy(int arr1[], int arr2[], int n)
{
	for (int i = 0; i < n; i++)
		arr2[i] = arr1[i];
}

void bubble_sort(int arr[], int n)
{
	for (int kol = 1; kol <= n - 1; kol++) // количество проходов по массиву
		for (int i = 0; i < n - kol; i++)
			if (arr[i] > arr[i + 1])
			{
				int t = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = t;

				// вывод массива после каждого изменения
				show_arr(arr, n);
			}
}

void selection_sort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min_el = arr[i];
		int min_i = i;

		for (int j = i + 1; j < n; j++)
			if (arr[j] < min_el)
			{
				min_el = arr[j];
				min_i = j;
			}

		int t = arr[i];
		arr[i] = arr[min_i];
		arr[min_i] = t;

		// вывод массива после каждого изменения
		show_arr(arr, n);
	}
}

void insertion_sort(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int r = arr[i];
		for (int j = i - 1; j >= 0 && r < arr[j]; j--)
		{
			arr[j + 1] = arr[j];
			arr[j] = r;
		}

		// вывод массива после каждого изменения
		show_arr(arr, n);
	}
}