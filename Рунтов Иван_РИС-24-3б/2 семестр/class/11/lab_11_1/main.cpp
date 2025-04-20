#include <iostream>
#include <clocale>
#include <list>
using namespace std;

// создание списка
list<double> make_list(int n)
{
	list<double> lst;
	for (int i = 0; i < n; i++)
		lst.push_back(rand() % 10);
	return lst;
}

// вывод списка
void show(list<double> lst)
{
	for (list<double>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << *it << ' ';
	cout << endl;
}

// нахождение среднего арифметического
double srednee(list<double> lst)
{
	double s = 0.0;
	for (list<double>::iterator it = lst.begin(); it != lst.end(); it++)
		s += *it;

	return s / lst.size();
}

// удаление ключа из диапазона
void erase_by_key(list<double>& lst, double key, int start, int end)
{
	list<double>::iterator iter = lst.begin();
	for (int i = 0; i < start; i++)
		iter++;

	for (int i = start; i < end; i++)
		if (*iter == key)
			iter = lst.erase(iter);
		else
			iter++;
}

// добавить сумму мин и макс
void add_min_max(list<double>& lst)
{
	list<double>::iterator iter = lst.begin();
	double min = *iter, max = *iter;
	for (; iter != lst.end(); iter++)
		if (*iter > max)
			max = *iter;
		else if (*iter < min)
			min = *iter;

	for (iter = lst.begin(); iter != lst.end(); iter++)
		*iter += min + max;
}

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(nullptr));

	list<double> lst = make_list(10);

	cout << endl << "Список:" << endl;
	show(lst);

	// задание 3
	lst.push_back(srednee(lst)); // добавление в конец среднего арифметического

	cout << endl << "Список:" << endl;
	show(lst);

	// задание 4
	double key;
	int start, end;
	cout << "Введите ключ и границы интервала:" << endl;
	cout << "key = "; cin >> key;
	cout << "start = "; cin >> start;
	cout << "end = "; cin >> end;

	erase_by_key(lst, key, start, end);

	cout << endl << "Список:" << endl;
	show(lst);

	// задание 5
	add_min_max(lst);

	cout << endl << "Список:" << endl;
	show(lst);
	return 0;
}