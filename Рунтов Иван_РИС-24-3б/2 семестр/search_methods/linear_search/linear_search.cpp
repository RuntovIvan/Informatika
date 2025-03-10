#include <iostream>
#include <clocale>
using namespace std;

int linear_search(int* arr, int n, int key);

int main()
{
	setlocale(LC_ALL, "RU");

	const int n = 10;
	int arr[n] = { -2, 1000, 36, 45, 70, -9, 4, 4, 4, 3};

	cout << "Массив:\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;

	int key;
	cout << "Введите ключ значение: ";
	cin >> key;

	int ind = linear_search(arr, n, key);
	
	if (ind >= 0)
		cout << "Массив содержит искомый элемент по индексу: " << ind << endl;
	else
		cout << "Массив не содержит искомый элемент" << endl;
	return 0;
}

int linear_search(int* arr, int n, int key)
{
	for (int i = 0; i < n; i++)
		if (arr[i] == key)
			return i;
	return -1;
}