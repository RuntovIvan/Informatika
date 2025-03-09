#include <iostream>
#include <ctime>
using namespace std;

void show(int* arr, int n);
void swap(int& a, int& b);
void quick_sort(int* arr, int start_ind, int pivot_ind);

int main()
{
	clock_t start = clock();
	srand(time(nullptr));

	const int n = 20000;
	int arr[n];
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 20000 + 1;

	show(arr, n);

	quick_sort(arr, 0, n - 1);
	clock_t end = clock();
	show(arr, n);
	cout << (double)(end - start) / CLOCKS_PER_SEC;
	return 0;
}

void show(int* arr, int n)
{
	cout << '{';
	for (int i = 0; i < n; i++)
		cout << arr[i] << ((i == n - 1) ? "}\n" : ", ");
	cout << endl;
}

void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void quick_sort(int* arr, int start_ind, int pivot_ind)
{
	if (start_ind >= pivot_ind)
		return;

	int left_ind = start_ind;

	for (int i = left_ind; i < pivot_ind; i++)
		if (arr[i] < arr[pivot_ind])
		{
			swap(arr[i], arr[left_ind]);
			left_ind++;
		}

	swap(arr[left_ind], arr[pivot_ind]);
	quick_sort(arr, start_ind, left_ind - 1);
	quick_sort(arr, left_ind + 1, pivot_ind);
}