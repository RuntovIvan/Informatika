#include <iostream>
#include <clocale>
using namespace std;

void fill_array(int* arr, int n); // заполнение массива
void show_array(int* arr, int n); // вывод массива
void add_first(int*& arr, int& n); // добавление первого элемента
void add_last(int*& arr, int& n); // добавление последнего элемента
void add_by_index(int*& arr, int& n); // добавление элемента по индексу
void del_first(int*& arr, int& n); // удаление первого элемента
void del_last(int*& arr, int& n); // удаление последнего элемента
void del_by_index(int*& arr, int& n); // удаление элемента по индексу

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(NULL));

	int n;
	cout << "Введите длину массива: ";
	cin >> n;

	int* arr = new int[n];
	fill_array(arr, n);
	show_array(arr, n);
	cout << endl;

	cout << "Добавление первого элемента\n";
	add_first(arr, n);
	show_array(arr, n);
	cout << endl;

	cout << "Добавление последнего элемента\n";
	add_last(arr, n);
	show_array(arr, n);
	cout << endl;

	cout << "Добавление элемента по индексу\n";
	add_by_index(arr, n);
	show_array(arr, n);
	cout << endl;

	cout << "Удаление первого элемента\n";
	del_first(arr, n);
	show_array(arr, n);
	cout << endl;

	cout << "Удаление последнего элемента\n";
	del_last(arr, n);
	show_array(arr, n);
	cout << endl;

	cout << "Удаление элемента по индексу\n";
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
	cout << "Введите индекс, по которому нужно добавить элемент: ";
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
	cout << "Введите индекс элемента, который нужно удалить: ";
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