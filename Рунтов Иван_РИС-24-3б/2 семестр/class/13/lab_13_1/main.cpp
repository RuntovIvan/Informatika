#include <iostream>
#include <clocale>
#include <list>
#include "Pair.h"
#include <algorithm>
using namespace std;

typedef list<Pair> plst;

plst make_list(int n)
{
	plst lst;
	for (int i = 0; i < n; i++)
	{
		Pair tmp(rand() % 10, (double)(rand() % 10) / 2.5);
		lst.push_back(tmp);
	}
	return lst;
}

void show(plst lst)
{
	cout << endl << "Список:" << endl;
	for (plst::iterator it = lst.begin(); it != lst.end(); it++)
		cout << *it << endl;
	cout << endl;
}

Pair srednee(plst lst)
{
	Pair tmp;
	for_each(lst.begin(), lst.end(), [&tmp](Pair& p) {tmp = tmp + p; });
	tmp = tmp / lst.size();
	return tmp;
}

void erase_by_key(plst& lst, Pair p1, Pair p2)
{
	plst::iterator it = remove_if(lst.begin(), lst.end(), [p1, p2](Pair& p) {return p > p1 && p < p2; });
	lst.erase(it, lst.end());
}

void add_min_max(plst& lst)
{
	plst::iterator it_min = min_element(lst.begin(), lst.end());
	plst::iterator it_max = max_element(lst.begin(), lst.end());
	Pair min = *it_min, max = *it_max;

	cout << endl << "min = " << *it_min << endl;
	cout << "max = " << *it_max << endl;
	cout << "min + max = " << *it_min + *it_max << endl;

	for_each(lst.begin(), lst.end(), [&lst, min, max](Pair& p) {p = p + min + max; });
}

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(nullptr));

	plst lst = make_list(5);
	show(lst);
	
	// задание 3
	cout << endl << "Среднее:" << srednee(lst) << endl;
	lst.push_back(srednee(lst));
	show(lst);

	// задание 4
	Pair p1, p2;
	cout << endl << "Первая пара диапазона: "; cin >> p1;
	cout << "Вторая пара диапазона: "; cin >> p2;
	if (p1 > p2)
		swap(p1, p2);
	erase_by_key(lst, p1, p2);
	show(lst);

	// задание 5
	add_min_max(lst);
	show(lst);

	return 0;
}