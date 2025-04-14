#include "List.h"
#include "Error.h"
#include <iostream>
#include <clocale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	try
	{
		int size;
		cout << "Введите количество элементов: ";
		cin >> size;
		List list(size, 1);

		cout << list << endl;

		int index;
		cout << "Введите индекс элемента: ";
		cin >> index;
		cout << "list[" << index << "] = " << list[index] << endl << endl;

		Iterator it = list.first();
		cout << "Введите индекс элемента для обращения через итератор: ";
		cin >> index;
		cout << "*(it + " << index << ") = " << *(it + index) << endl << endl;
	}

	catch (Error& e)
	{
		e.what();
	}

	return 0;
}