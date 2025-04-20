#include "Pair.h"
#include <iostream>
#include <clocale>
#include <list>
using namespace std;

//�������� ������
list<Pair> make_list(int n)
{
	list<Pair> lst;
	for (int i = 0; i < n; i++)
	{
		Pair tmp(rand() % 10, (double)(rand() % 10) / 2);
		lst.push_back(tmp);
	}
	return lst;
}

// ����� ������
void show(list<Pair> lst)
{
	cout << endl << "������:" << endl;
	for (list<Pair>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << *it << endl;
	cout << endl;
}

// ���������� �������� ���������������
Pair srednee(list<Pair>& lst)
{
	Pair tmp;
	for (list<Pair>::iterator it = lst.begin(); it != lst.end(); it++)
		tmp = tmp + *it;
	tmp = tmp / lst.size();
	return tmp;
}

// �������� ����� �� ���������
void erase_by_key(list<Pair>& lst, Pair key, int start, int end)
{
	list<Pair>::iterator iter = lst.begin();
	for (int i = 0; i < start; i++)
		iter++;

	for (int i = start; i < end; i++)
		if (*iter == key)
			iter = lst.erase(iter);
		else
			iter++;
}

// �������� ����� ��� � ����
void add_min_max(list<Pair>& lst)
{
	list<Pair>::iterator iter = lst.begin();
	Pair min = *iter, max = *iter;
	for (; iter != lst.end(); iter++)
		if (*iter > max)
			max = *iter;
		else if (*iter < min)
			min = *iter;

	for (iter = lst.begin(); iter != lst.end(); iter++)
		*iter = *iter + min + max;
}

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(nullptr));

	list<Pair> lst = make_list(5);
	show(lst);

	// ������� 3
	lst.push_back(srednee(lst));
	show(lst);

	// ������� 4
	Pair key;
	int start, end;

	cout << "������� ���� � ������� ���������:" << endl;
	cout << "key:"; cin >> key;
	cout << "start = "; cin >> start;
	cout << "end = "; cin >> end;

	erase_by_key(lst, key, start, end);
	show(lst);

	// ������� 5
	add_min_max(lst);
	show(lst);
	return 0;
}