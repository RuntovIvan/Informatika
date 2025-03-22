#include <iostream>
#include <clocale>
#include <string>
using namespace std;

int* build_table(string obraz);
int KMP_search(string str, string obraz, int* table);

int main()
{
	setlocale(LC_ALL, "RU");
	system("chcp 1251");
	system("cls");

	string str, obraz;
	cout << "¬ведите строку: ";
	getline(cin, str);
	cout << "¬ведите образ: ";
	getline(cin, obraz);

	int* table = build_table(obraz);
	int ind = KMP_search(str, obraz, table);

	delete[] table;
	cout << ind << endl;
	return 0;
}

int* build_table(string obraz)
{
	int* table = new int[obraz.length()] {};
	int j = 0, i = 1; // указатели на символы образа
	while (i < obraz.length())
		if (obraz[j] == obraz[i])
		{
			table[i] = j + 1;
			i++;
			j++;
		}
		else if (j == 0)
		{
			table[i] = 0;
			i++;
		}
		else
			j = table[j - 1];

	return table;
}

int KMP_search(string str, string obraz, int* table)
{
	int k = 0, l = 0; // указатели на символы строки и образа соответственно
	while (k < str.length())
		if (str[k] == obraz[l])
		{
			k++;
			l++;
			if (l == obraz.length())
				return k - obraz.length();
		}
		else if (l == 0)
		{
			k++;
			if (k == str.length())
				return -1;
		}
		else
			l = table[l - 1];
}