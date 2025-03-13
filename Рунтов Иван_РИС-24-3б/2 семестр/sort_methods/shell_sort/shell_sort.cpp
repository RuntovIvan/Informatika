#include <iostream>
using namespace std;

void show(int* arr, int n);
void shell_sort(int* arr, int n);

const int n = 10;

int main()
{
	srand(time(nullptr));

	int arr[n];
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 100 + 1;

	show(arr, n);
	shell_sort(arr, n);
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

void shell_sort(int* arr, int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i++)
		{
			int temp = arr[i];

			for (int j = i - gap; j >= 0 && temp < arr[j]; j -= gap)
			{
				arr[j + gap] = arr[j];
				arr[j] = temp;
				show(arr, n);
			}
		}
	}
}