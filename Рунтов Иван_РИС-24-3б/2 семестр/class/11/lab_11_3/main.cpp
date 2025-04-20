#include "List.h"
#include "Pair.h"
#include <iostream>
#include <clocale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(nullptr));

	List<Pair> list(3);
	list.show();

	// ������� 3
	list.add(list.srednee());
	list.show();

	// ������� 4
	Pair key;
	int start, end;

	cout << "������� ���� � ������� ���������:" << endl;
	cout << "key:"; cin >> key;
	cout << "start = "; cin >> start;
	cout << "end = "; cin >> end;

	list.erase_by_key(key, start, end);
	list.show();

	// ������� 5
	list.add_min_max();
	list.show();
	return 0;
}