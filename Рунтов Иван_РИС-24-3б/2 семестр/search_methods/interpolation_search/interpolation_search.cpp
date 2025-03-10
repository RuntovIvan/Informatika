#include <iostream>
#include <clocale>
using namespace std;

int interpolation_search(int* arr, int n, int key);

int main()
{
	setlocale(LC_ALL, "RU");

	const int n = 10;
	int arr[n] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

	cout << "Массив:\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;

	int key;
	cout << "Введите ключ значение: ";
	cin >> key;

	int ind = interpolation_search(arr, n, key);

	if (ind >= 0)
		cout << "Массив содержит искомый элемент по индексу: " << ind << endl;
	else
		cout << "Массив не содержит искомый элемент" << endl;
	return 0;
}

int interpolation_search(int* arr, int n, int key)
{
	int left = 0, right = n - 1;
	while (left <= right)
	{
		if (left == right)
			if (arr[left] == key)
				return left;
			else
				return -1;

		int ind = left + ((key - arr[left]) * (right - left)) / (arr[right] - arr[left]);

		if (arr[ind] == key)
			return ind;
		else if (arr[ind] < key)
			left = ind + 1;
		else
			right = ind - 1;
	}
	return -1;
}