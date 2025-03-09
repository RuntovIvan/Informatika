#include <iostream>
#include <clocale>
using namespace std;

void fill_array(int* arr, int n); // ���������� �������
void show_array(int* arr, int n); // ����� �������
void add_first(int*& arr, int& n); // ���������� ������� ��������
void add_last(int*& arr, int& n); // ���������� ���������� ��������
void add_by_index(int*& arr, int& n); // ���������� �������� �� �������
void del_first(int*& arr, int& n); // �������� ������� ��������
void del_last(int*& arr, int& n); // �������� ���������� ��������
void del_by_index(int*& arr, int& n); // �������� �������� �� �������

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(NULL));

	int n;
	cout << "������� ����� �������: ";
	cin >> n;

	int* arr = new int[n];
	fill_array(arr, n);
	show_array(arr, n);
	cout << endl;

	cout << "���������� ������� ��������\n";
	add_first(arr, n);
	show_array(arr, n);
	cout << endl;

	cout << "���������� ���������� ��������\n";
	add_last(arr, n);
	show_array(arr, n);
	cout << endl;

	cout << "���������� �������� �� �������\n";
	add_by_index(arr, n);
	show_array(arr, n);
	cout << endl;

	cout << "�������� ������� ��������\n";
	del_first(arr, n);
	show_array(arr, n);
	cout << endl;

	cout << "�������� ���������� ��������\n";
	del_last(arr, n);
	show_array(arr, n);
	cout << endl;

	cout << "�������� �������� �� �������\n";
	del_by_index(arr, n);
	show_array(arr, n);
	cout << endl;

	delete[] arr;
	return 0;
}

void fill_array(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 101;
}

void show_array(int* arr, int n)
{
	cout << '{';
	for (int i = 0; i < n; i++)
	{
		cout << arr[i];
		i == n - 1 ? cout << "}\n" : cout << ", ";
	}
}

void add_first(int*& arr, int& n)
{
	n++;
	int* new_arr = new int[n];

	for (int i = 1; i < n; i++)
		new_arr[i] = arr[i - 1];

	new_arr[0] = rand() % 101;

	delete[] arr;
	arr = new_arr;
	new_arr = nullptr;
}

void add_last(int*& arr, int& n)
{
	int* new_arr = new int[n + 1];

	for (int i = 0; i < n; i++)
		new_arr[i] = arr[i];

	new_arr[n] = rand() % 101;
	n++;

	delete[] arr;
	arr = new_arr;
	new_arr = nullptr;
}

void add_by_index(int*& arr, int& n)
{
	int ind;
	cout << "������� ������, �� �������� ����� �������� �������: ";
	cin >> ind;

	n++;
	int* new_arr = new int[n];

	for (int i = 0; i < ind; i++)
		new_arr[i] = arr[i];

	new_arr[ind] = rand() % 101;

	for (int i = ind + 1; i < n; i++)
		new_arr[i] = arr[i - 1];

	delete[] arr;
	arr = new_arr;
	new_arr = nullptr;
}

void del_first(int*& arr, int& n)
{
	n--;
	int* new_arr = new int[n];

	for (int i = 0; i < n; i++)
		new_arr[i] = arr[i + 1];

	delete[] arr;
	arr = new_arr;
	new_arr = nullptr;
}

void del_last(int*& arr, int& n)
{
	n--;
	int* new_arr = new int[n];

	for (int i = 0; i < n; i++)
		new_arr[i] = arr[i];

	delete[] arr;
	arr = new_arr;
	new_arr = nullptr;
}

void del_by_index(int*& arr, int& n)
{
	int ind;
	cout << "������� ������ ��������, ������� ����� �������: ";
	cin >> ind;

	n--;
	int* new_arr = new int[n];

	for (int i = 0; i < ind; i++)
		new_arr[i] = arr[i];

	for (int i = ind; i < n; i++)
		new_arr[i] = arr[i + 1];

	delete[] arr;
	arr = new_arr;
	new_arr = nullptr;
}