#include <iostream>
#include <clocale>
using namespace std;

int binary_search(int* arr, int n, int key);

int main()
{
	setlocale(LC_ALL, "RU");

	const int n = 10;
	int arr[n] = { -10, -5, 2, 4, 4, 6, 9, 15, 20, 95};

	cout << "Массив:\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;

	int key;
	cout << "Введите ключ значение: ";
	cin >> key;

	int ind = binary_search(arr, n, key);

	if (ind >= 0)
		cout << "Массив содержит искомый элемент по индексу: " << ind << endl;
	else
		cout << "Массив не содержит искомый элемент" << endl;
	return 0;
}

int binary_search(int* arr, int n, int key)
{
	int left = 0, right = n - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (arr[mid] == key)
			return mid;
		else if (arr[mid] < key)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}