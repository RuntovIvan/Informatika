#include <iostream>
#include <clocale>
#include <fstream>
using namespace std;

void show_arr(int* arr, int start, int end);
int get_arr_size(string filename);
void fill_arr(int* arr, int size, string filename);
void balanced_sort(int* arr, int start, int end);
void merge(int* arr, int start, int end, int mid);
void arr_to_file(int* arr, int size, string filename);

int main()
{
	setlocale(LC_ALL, "RU");

	// запись из файла в массив
	int size = get_arr_size("F1.txt");
	int* arr = new int[size];
	fill_arr(arr, size, "F1.txt");
	
	show_arr(arr, 0, size - 1);
	balanced_sort(arr, 0, size - 1);
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

void balanced_sort(int* arr, int start, int end)
{
	if (start >= end)
		return;

	int mid = (start + end) / 2;

	balanced_sort(arr, start, mid);
	balanced_sort(arr, mid + 1, end);
	merge(arr, start, end, mid);
	show_arr(arr, start, end);
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

void arr_to_file(int* arr, int size, string filename)
{
	ofstream fout(filename);

	for (int i = 0; i < size; i++)
		fout << arr[i] << ' ';

	fout.close();
}