#include <iostream>
using namespace std;

void show(int* arr, int n);
void swap(int& a, int& b);
void hoare_sort(int* arr, int start_ind, int end_ind);

const int n = 9;

int main()
{
	srand(time(nullptr));
	
	int arr[n];
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 100 + 1;

	show(arr, n);
	hoare_sort(arr, 0, n - 1);
	show(arr, n);

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
			show(arr, n);
			left++;
			right--;
		}
	}

	hoare_sort(arr, start_ind, right);
	hoare_sort(arr, left, end_ind);
}