#include <iostream>
using namespace std;

void show(int* arr, int n);
void merge_sort(int* arr, int start, int end);
void merge(int* arr, int start, int end, int mid);

const int n = 10;

int main()
{
	srand(time(nullptr));

	int arr[n];
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 100 - 50;

	show(arr, n);
	merge_sort(arr, 0, n - 1);
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

	show(arr, n);
}

void merge_sort(int* arr, int start, int end)
{
	if (start >= end)
		return;

	int mid = (start + end) / 2;

	merge_sort(arr, start, mid);
	merge_sort(arr, mid + 1, end);
	merge(arr, start, end, mid);
}