#include <iostream>
using namespace std;

void show(int* arr, int n);
void swap(int& a, int& b);
void hoare_sort(int* arr, int start_ind, int end_ind);
void bucket_sort(int* arr, int n);

const int n = 20;

int main()
{
	srand(time(nullptr));

	int arr[n];
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 100 - 50;

	show(arr, n);
	bucket_sort(arr, n);
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
			left++;
			right--;
		}
	}

	hoare_sort(arr, start_ind, right);
	hoare_sort(arr, left, end_ind);
}

void bucket_sort(int* arr, int n)
{
	if (n < 2)
		return;

	int min = arr[0], max = arr[0];
	for (int i = 0; i < n; i++)
		if (arr[i] < min)
			min = arr[i];
		else if (arr[i] > max)
			max = arr[i];

	int len = max / 10 - min / 10 + 1;
	int* lens = new int[len] {};
	int** blocks = new int* [len] {};

	for (int i = 0; i < n; i++)
	{
		int p = arr[i] / 10 - min / 10;
		if (blocks[p] == nullptr)
		{
			int* block = new int[1] {arr[i]};
			blocks[p] = block;
			lens[p]++;
		}
		else
		{
			int l = lens[p];
			int* block = new int[l + 1];
			for (int j = 0; j < l; j++)
				block[j] = blocks[p][j];
			block[l] = arr[i];
			delete[] blocks[p];
			blocks[p] = block;
			lens[p]++;
		}
	}
	
	for (int i = 0; i < len; i++)
		hoare_sort(blocks[i], 0, lens[i] - 1);

	for (int i = 0; i < len; i++)
		show(blocks[i], lens[i]);

	int ind = 0;
	for (int i = 0; i < len; i++)
		for (int j = 0; j < lens[i]; j++)
			arr[ind++] = blocks[i][j];

	for (int i = 0; i < len; i++)
		delete[] blocks[i];
	delete[] blocks;
	delete[] lens;
}