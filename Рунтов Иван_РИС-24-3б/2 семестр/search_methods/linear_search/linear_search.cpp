#include <iostream>
#include <clocale>
using namespace std;

int linear_search(int* arr, int n, int key);

int main()
{
	setlocale(LC_ALL, "RU");

	const int n = 10;
	int arr[n] = { -2, 1000, 36, 45, 70, -9, 4, 4, 4, 3};

	cout << "������:\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;

	int key;
	cout << "������� ���� ��������: ";
	cin >> key;

	int ind = linear_search(arr, n, key);
	
	if (ind >= 0)
		cout << "������ �������� ������� ������� �� �������: " << ind << endl;
	else
		cout << "������ �� �������� ������� �������" << endl;
	return 0;
}

int linear_search(int* arr, int n, int key)
{
	for (int i = 0; i < n; i++)
		if (arr[i] == key)
			return i;
	return -1;
}