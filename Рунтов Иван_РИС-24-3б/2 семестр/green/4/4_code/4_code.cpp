#include <iostream>
#include <clocale>
using namespace std;

void fill_array(int arr[], int len);
void show_array(int arr[], int len);
void ring(int arr[], int len);
void sort(int arr[], int len);
void del_odd(int arr[], int& len);

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(NULL));

	int arr[101]{};
	int len;

	cout << "Введите длину массива от 1 до 100: ";
	cin >> len;
	while (len < 1 || len > 100)
	{
		cout << "Неверный ввод. Введите длину массива от 1 до 100:  ";
		cin >> len;
	}

	fill_array(arr, len);

	cout << "Исходный массив:\n";
	show_array(arr, len);

	cout << "Просмотр кольца\n";
	ring(arr, len);
	show_array(arr, len);

	cout << "Сортировка массива по убыванию\n";
	sort(arr, len);
	show_array(arr, len);

	cout << "Удаление из массива нечетных элементов\n";
	del_odd(arr, len);
	show_array(arr, len);
	
	cout << "Просмотр кольца\n";
	ring(arr, len);
	show_array(arr, len);

	return 0;
}

void fill_array(int arr[], int len)
{
	for (int i = 0; i < len; i++)
		arr[i] = rand() % 30 + 1;
}

void show_array(int arr[], int len)
{
	cout << '{';
	for (int i = 0; i < len; i++)
	{
		cout << arr[i];
		cout << ((i == len - 1) ? "}\n\n" : ", ");
	}
	if (len == 0)
		cout << "}\n\n";
}

void ring(int arr[], int len)
{
	int num;
	cout << "Введите номер элемента, с которого начинается просмотр: ";
	cin >> num;

	while (num < 1 || num > len)
	{
		cout << "Номер элемента может быть от 1 до " << len << ". Повторите ввод: ";
		cin >> num;
	}
	
	for (int i = 0; i < num / 2; i++)
	{
		int t = arr[i];
		arr[i] = arr[num - i - 1];
		arr[num - i - 1] = t;
	}

	for (int i = num; i < (len + num) / 2; i++)
	{
		int t = arr[i];
		arr[i] = arr[(len + num) - i - 1];
		arr[(len + num) - i - 1] = t;
	}
}

void sort(int arr[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int max_el = arr[i];
		int max_i = i;

		for (int j = i + 1; j < len; j++)
			if (arr[j] > max_el)
			{
				max_el = arr[j];
				max_i = j;
			}

		int t = arr[i];
		arr[i] = arr[max_i];
		arr[max_i] = t;
	}
}

void del_odd(int arr[], int& len)
{
	int i = 0;
	while (i != len)
		if (arr[i] % 2 != 0)
		{
			for (int j = i; j < len; j++)
				arr[j] = arr[j + 1];
			len--;
		}
		else
			i++;
}