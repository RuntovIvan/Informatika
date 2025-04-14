#include "List.h"
#include <iostream>
#include <clocale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	List a(10);
	cout << endl << a << endl;

	for (int i = 0; i < a(); i++)
		a[i] = i * i;
	cout << endl << a << endl;

	List b(a);
	cout << endl << b << endl;

	b.push_front(100);
	b.pop_back();
	cout << endl << b << endl;

	List c(5);
	cin >> c;
	cout << endl << c << endl;

	List d = c * b;
	cout << endl << d << endl;

	cout << "Работа с итератором:" << endl;
	Iterator it = d.first();
	cout << "Первый элемент списка d: " << *it << endl;
	cout << "Второй элемент списка d: " << *(++it) << endl;
	cout << "Четвертый элемент списка d: " << *(it + 2) << endl;

	cout << endl << "Вывод списка d с помощью итератора: " << endl;
	for (Iterator iter = d.first(); iter != d.last(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	cout << endl << "Вывод списка a с помощью итератора: " << endl;
	for (Iterator iter = a.first(); iter != a.last(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	cout << endl << "Вывод первых 4 элементов списка b с помощью итератора: " << endl;
	for (Iterator iter = b.first(); iter != b.first() + 4; ++iter)
		cout << *iter << ' ';
	cout << endl;

	cout << endl << "Вывод списка c с помощью итератора: " << endl;
	for (Iterator iter = c.first(); iter != c.last(); ++iter)
		cout << *iter << ' ';
	cout << endl;
	return 0;
}