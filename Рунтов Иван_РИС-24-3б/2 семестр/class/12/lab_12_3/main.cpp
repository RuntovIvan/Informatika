#include <iostream>
#include <clocale>
#include "Container.h"
#include "Pair.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(nullptr));

	Container<Pair> c(5);
	c.show();

	//задание 3
	cout << endl << "Среднее: " << c.srednee() << endl;
	c.insert(c.srednee());
	c.show();

	//задание 4
	Pair key;
	int start, end;
	cout << endl;
	cout << "Введите ключ и диапазон для удаления:" << endl;
	cout << "key:\n"; cin >> key;
	cout << "start = "; cin >> start;
	cout << "end = "; cin >> end;

	c.erase_by_key(key, start, end);
	c.show();

	//задание 5
	c.add_min_max();
	c.show();

	return 0;
}