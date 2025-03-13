#include <iostream>
using namespace std;

void show(int* arr, int n);
void counting_sort(int* arr, int n);

const int n = 10;

int main()
{
	srand(time(nullptr));

	int arr[n];
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 100 - 50;

	show(arr, n);
	counting_sort(arr, n);
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

void counting_sort(int* arr, int n)
{
	if (n < 2)
		return;

	int min = arr[0], max = arr[0];

	for (int i = 0; i < n; i++)
		if (arr[i] < min)
			min = arr[i];
		else if (arr[i] > max)
			max = arr[i];

	int len = max - min + 1;
	int* diapazon = new int[len] {};

	for (int i = 0; i < n; i++)
		diapazon[arr[i] - min]++;

	cout << "Diapazon:\n";
	show(diapazon, len);

	int ind = 0;
	for (int i = 0; i < len; i++)
		for (int j = 0; j < diapazon[i]; j++)
			arr[ind++] = i + min;

	delete[] diapazon;
}