#include <iostream>
#include <clocale>
#include <string>
using namespace std;

void show(string str);

int main()
{
	setlocale(LC_ALL, "RU");
	system("chcp 1251");
	system("cls");

	string str;
	cout << "Введите строку:\n";
	getline(cin, str);

	cout << "\nСтрока, выведенная по функции модуля:\n\n";
	show(str);
	return 0;
}

void show(string str)
{
	int len = str.length();
	int row = (len + (len % 2 != 0)) / 2;
	int p_betw = len - 2;

	for (int k = 0; k < row; k++)
	{
		for (int p = 0; p < k; p++)
			cout << ' ';

		if (k != row - 1)
		{
			cout << str[k];
			for (int p = 0; p < p_betw; p++)
				cout << ' ';
			cout << str[len - k - 1] << endl;
		}
		else
			if (len % 2 == 0)
				cout << str[k] << str[len - k - 1] << endl;
			else
				cout << str[k] << endl;

		p_betw -= 2;
	}
}