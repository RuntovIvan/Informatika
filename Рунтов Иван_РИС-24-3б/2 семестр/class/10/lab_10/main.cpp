#include "Pair.h"
#include "file_work.h"
#include <iostream>
#include <fstream>
#include <clocale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	Pair p;
	int kol, code;
	string filename;

	do
	{
		cout << endl << "1. Создать файл" << endl;
		cout << "2. Вывод в консоль" << endl;
		cout << "3. Удаление меньше заданного" << endl;
		cout << "4. Прибавить целое число" << endl;
		cout << "5. Прибавить вещественное число" << endl;
		cout << "6. Добавить K элементов после заданного номера" << endl;
		cout << "0. Выход" << endl;
		cout << '>';  cin >> code; cin.ignore(1);

		switch (code)
		{
		case 1:
			cout << "Введите имя файла: "; getline(cin, filename);
			kol = make_file(filename);
			if (kol < 0) cout << "Невозможно создать файл\n";
			break;
		case 2:
			cout << "Введите имя файла: "; getline(cin, filename);
			kol = print_file(filename);
			if (kol < 0) cout << "Невозможно прочитать файл\n";
			if (kol == 0) cout << "Файл пустой\n";
			break;
		case 3:
			cout << "Введите имя файла: "; getline(cin, filename);
			kol = del_fewer(filename);
			if (kol < 0) cout << "Невозможно прочитать файл\n";
			if (kol == 0) cout << "Файл пустой\n";
			break;
		case 4:
			cout << "Введите имя файла: "; getline(cin, filename);
			kol = add_int(filename);
			if (kol < 0) cout << "Невозможно прочитать файл\n";
			if (kol == 0) cout << "Файл пустой\n";
			break;
		case 5:
			cout << "Введите имя файла: "; getline(cin, filename);
			kol = add_double(filename);
			if (kol < 0) cout << "Невозможно прочитать файл\n";
			if (kol == 0) cout << "Файл пустой\n";
			break;
		case 6:
			cout << "Введите имя файла: "; getline(cin, filename);
			kol = add_file(filename);
			if (kol < 0) cout << "Невозможно прочитать файл\n";
			if (kol == 0) cout << "Файл пустой\n";
			break;
		}
	} while (code != 0);

	return 0;
}


