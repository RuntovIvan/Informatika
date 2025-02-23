#include <iostream>
#include <string>
using namespace std;

void fill(string* str, int n);
void show(string* str, int n);
void paste(string*& str, int& n);

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

	// создание одномерного динамического массива
	string* str = new string[n];

	getchar(); // пропуск символа '\n'

	// заполнение n строк
	cout << "Введите строки:\n";
	fill(str, n);

	// вывод изначального массива
	cout << endl;
	cout << "Вы ввели следующие строки:\n";
	show(str, n);

	paste(str, n);

	// вывод измененного массива
	cout << endl;
	cout << "Строки с учетом добавленной строки:\n";
	show(str, n);

	delete[] str;

	return 0;
}

void fill(string* str, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". ";
		getline(cin, str[i]);
	}
}

void show(string* str, int n)
{
	for (int i = 0; i < n; i++)
		cout << i + 1 << ". " << str[i] << endl;
}

void paste(string*& str, int& n)
{
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
	pos -= 1;

	// создание нового массива
	n++;
	string* new_str = new string[n];

	for (int i = 0; i < pos; i++)
		new_str[i] = str[i];

	cout << "Введите новую строку: ";
	getchar(); // пропуск символа '\n'
	getline(cin, new_str[pos]);

	for (int i = pos + 1; i < n; i++)
		new_str[i] = str[i - 1];

	delete[] str;
	str = new_str;
	new_str = nullptr;
}