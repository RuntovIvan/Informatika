#include <iostream>
#include <clocale>
#include <map>
#include "Pair.h"
#include <algorithm>
using namespace std;

typedef map<int, Pair> Pmap;

Pmap make_map(int n)
{
	Pmap m;
	for (int i = 0; i < n; i++)
	{
		Pair tmp(rand() % 10, (double)(rand() % 10) / 2.5);
		m.insert(make_pair(i, tmp));
	}
	return m;
}

void show(Pmap m)
{
	cout << endl << "Словарь:" << endl;
	for_each(m.begin(), m.end(), [m](pair<int, Pair> p) {cout << p.first << " : " << p.second << endl; });
	cout << endl;
}

Pair srednee(Pmap m)
{
	Pair tmp;
	for_each(m.begin(), m.end(), [&tmp](pair<int, Pair> p) {tmp = tmp + p.second; });
	tmp = tmp / m.size();
	return tmp;
}

void erase_by_key(Pmap& m, Pair p1, Pair p2)
{
	Pmap tmp_m;
	for (Pmap::iterator it = m.begin(); it != m.end(); it++)
		if (!((*it).second > p1 && (*it).second < p2))
			tmp_m.insert(*it);
	m = tmp_m;
}

void add_min_max(Pmap& m)
{
	Pair min, max;
	for (Pmap::iterator it = m.begin(); it != m.end(); it++)
		if ((*it).second < min)
			min = (*it).second;
		else if ((*it).second > max)
			max = (*it).second;

	cout << endl << "min = " << min << endl;
	cout << "max = " << max << endl;
	cout << "min + max = " << min + max << endl;

	Pmap new_m;
	for_each(m.begin(), m.end(), [min, max, &new_m](pair<int, Pair> p) {new_m.insert(make_pair(p.first, p.second + min + max)); });
	m = new_m;
}

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(nullptr));

	Pmap m = make_map(5);
	show(m);

	// задание 3
	cout << endl << "Среднее:" << srednee(m) << endl;
	m.insert(make_pair(m.size(), srednee(m)));
	show(m);

	// задание 4
	Pair p1, p2;
	cout << endl << "Первая пара диапазона: "; cin >> p1;
	cout << "Вторая пара диапазона: "; cin >> p2;
	if (p1 > p2)
		swap(p1, p2);
	erase_by_key(m, p1, p2);
	show(m);

	// задание 5
	add_min_max(m);
	show(m);

	return 0;
}