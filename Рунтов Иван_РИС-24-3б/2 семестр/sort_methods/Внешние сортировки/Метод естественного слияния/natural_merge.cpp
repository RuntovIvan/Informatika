#include <iostream>
#include <clocale>
#include <fstream>
using namespace std;

void show_arr(int* arr, int start, int end);
int get_arr_size(string filename);
void fill_arr(int* arr, int size, string filename);
void arr_to_file(int* arr, int size, string filename);
void merge(int* arr, int start, int mid, int end);
void natural_sort(int* arr, int size);

int main()
{
	setlocale(LC_ALL, "RU");

	// запись из файла в массив
	int size = get_arr_size("F1.txt");
	int* arr = new int[size];
	fill_arr(arr, size, "F1.txt");

	show_arr(arr, 0, size - 1);
	natural_sort(arr, size);
	show_arr(arr, 0, size - 1);

	arr_to_file(arr, size, "F2.txt");
	return 0;
}

void fill_arr(int* arr, int size, string filename)
{
	ifstream fin(filename);
	for (int i = 0; i < size; i++)
		fin >> arr[i];
	fin.close();
}

void show_arr(int* arr, int start, int end)
{
	cout << '{';
	for (int i = start; i <= end; i++)
		cout << arr[i] << ((i == end) ? "}\n" : ", ");
	cout << endl;
}

int get_arr_size(string filename)
{
	ifstream fin(filename);
	int count = 0;
	int t;
	while (fin >> t)
		count++;
	fin.close();
	return count;
}

void arr_to_file(int* arr, int size, string filename)
{
	ofstream fout(filename);

	for (int i = 0; i < size; i++)
		fout << arr[i] << ' ';

	fout.close();
}

void merge(int* arr, int start, int end, int mid)
{
	int left = start;
	int right = mid + 1;

	int len = end - start + 1;
	int* merge_arr = new int[len];

	for (int i = 0; i < len; i++)
		if (left <= mid && (right > end || arr[left] < arr[right]))
			merge_arr[i] = arr[left++];
		else
			merge_arr[i] = arr[right++];

	int ind = start;
	for (int i = 0; i < len; i++)
		arr[ind++] = merge_arr[i];

	delete[] merge_arr;
}

void natural_sort(int* arr, int size)
{
	int i = 0;
	while (i < size)
	{
		int mid = 0, end = 0;
		i = 0;
		while (i < size - 1 && arr[i] < arr[i + 1])
			i++;

		mid = i;
		i++;

		while (i < size - 1 && arr[i] < arr[i + 1])
			i++;

		end = i;
		i++;

		// вывод серий
		cout << "Серии:" << endl;
		show_arr(arr, 0, mid);
		show_arr(arr, mid + 1, end);

		merge(arr, 0, end, mid);

		// вывод после слияния серий
		cout << "После слияния серий:" << endl;
		show_arr(arr, 0, size - 1);
		cout << endl;
	}
}