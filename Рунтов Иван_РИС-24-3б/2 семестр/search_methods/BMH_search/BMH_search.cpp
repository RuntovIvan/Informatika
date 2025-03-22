#include <iostream>
#include <clocale>
#include <string>
using namespace std;

int table[256]{};
void build_table(string obraz);
void BMH_search(string str, string obraz);

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
	
	build_table(obraz);
	BMH_search(str, obraz);

	return 0;
}

void build_table(string obraz)
{
	for (int i = 0; i < 256; i++)
		table[i] = obraz.length();

	for (int i = 0; i < obraz.length() - 1; i++)
		table[static_cast<unsigned char>(obraz[i])] = obraz.length() - i - 1;
}

void BMH_search(string str, string obraz)
{
	int sdvig = 0;
	while (sdvig + obraz.length() <= str.length())
	{
		bool flag = true;
		for (int i = obraz.length() - 1; i >= 0 && flag == true; i--)
			if (str[i + sdvig] != obraz[i])
			{
				flag = false;
				sdvig += table[static_cast<unsigned char>(str[i])];
			}
		if (flag == true)
		{
			cout << "ќбраз найден" << endl;
			return;
		}
	}
	cout << "ќбраз не найден" << endl;
}