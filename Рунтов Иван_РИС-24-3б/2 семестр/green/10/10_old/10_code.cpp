#include  <iostream>
#include <clocale>
#define STR_LEN 50
using namespace std;

void get_str(char* str, int len);
void skip();
void fill_str_mass(char** str, int len);
void print_mass(char** str, int len);
void paste_str(char** str, int len, int pos);

int main()
{
	setlocale(LC_ALL, "RU");
	system("chcp 1251");
	system("cls");

	// определение количества строк
	int n;
	cout << "Введите количество строк: ";
	cin >> n;
	while (n < 1)
	{
		cout << "Количество строк должно быть натуральным. Введите ещё раз: ";
		cin >> n;
	}

	// создание двумерного динамического массива
	char** str = new char* [n + 1];
	for (int i = 0; i < n + 1; i++)
		str[i] = new char[STR_LEN];

	skip();
	// заполнение n строк
	cout << "Введите строки:\n";
	fill_str_mass(str, n);

	// вывод изначального массива
	cout << endl;
	cout << "Вы ввели следующие строки:\n";
	print_mass(str, n);

	// запрос номера новой строки
	int pos;
	cout << endl;
	cout << "Введите номер новой строки: ";
	cin >> pos;
	while (pos < 1 || pos > n + 1)
	{
		cout << "Номер строки должен быть от " << 1 << " до " << n + 1 << ". Введите ещё раз: ";
		cin >> pos;
	}

	// добавление новой строки
	paste_str(str, n + 1, pos);

	// вывод измененного массива
	cout << endl;
	cout << "Строки с учетом добавленной строки:\n";
	print_mass(str, n + 1);

	// удаление массива
	for (int i = 0; i < n + 1; i++)
		delete[] str[i];

	delete[] str;
	return 0;
}

// ввод строки с консоли
void get_str(char* str, int len)
{
	char ch = getchar();
	int i = 0;
	while (ch != '\n' && i < len - 1)
	{
		str[i] = ch;
		ch = getchar();
		i++;
	}
	str[i] = '\0';
}

// пропуск символа '\n' при вводе целочисленных параметров
void skip()
{
	int ch = getchar();
}

// заполение массива строками
void fill_str_mass(char** str, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << i + 1 << ". ";
		get_str(str[i], STR_LEN);
	}
}

// вывод массива строк
void print_mass(char** str, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << i + 1 << ". ";
		int j = 0;
		while (str[i][j] != '\0')
		{
			cout << str[i][j];
			j++;
		}
		cout << endl;
	}
}

// ввод новой строки
void paste_str(char** str, int len, int pos)
{
	if (pos == len)
	{
		cout << "Введите новую строку:\n";
		skip();
		get_str(str[pos - 1], STR_LEN);
	}
	else
	{
		for (int i = len - 1; i > pos - 1; i--)
			for (int j = 0; j < STR_LEN; j++)
				str[i][j] = str[i - 1][j];

		cout << "Введите новую строку:\n";
		skip();
		get_str(str[pos - 1], STR_LEN);
	}
}