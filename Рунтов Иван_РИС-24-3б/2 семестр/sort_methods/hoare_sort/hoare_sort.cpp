#include <iostream>
#include <ctime>
using namespace std;

void show(int* arr, int n);
void swap(int& a, int& b);
void hoare_sort(int* arr, int start_ind, int end_ind);

int main()
{
	clock_t start = clock();
	srand(time(nullptr));

	const int n = 20000;
	int arr[n];
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 20000 + 1;

	show(arr, n);

	hoare_sort(arr, 0, n - 1);
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

void hoare_sort(int* arr, int start_ind, int end_ind)
{
	if (start_ind >= end_ind)
		return;

	int pivot = arr[(start_ind + end_ind) / 2];
	int left = start_ind;
	int right = end_ind;

	while (left < right)
	{
		while (arr[left] < pivot)
			left++;

		while (arr[right] > pivot)
			right--;

		if (left <= right)
		{
			swap(arr[left], arr[right]);
			left++;
			right--;
		}
	}

	hoare_sort(arr, start_ind, right);
	hoare_sort(arr, left, end_ind);
}