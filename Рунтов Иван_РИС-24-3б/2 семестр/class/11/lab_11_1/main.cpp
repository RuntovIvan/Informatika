#include <iostream>
#include <clocale>
#include <list>
using namespace std;

// �������� ������
list<double> make_list(int n)
{
	list<double> lst;
	for (int i = 0; i < n; i++)
		lst.push_back(rand() % 10);
	return lst;
}

// ����� ������
void show(list<double> lst)
{
	for (list<double>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << *it << ' ';
	cout << endl;
}

// ���������� �������� ���������������
double srednee(list<double> lst)
{
	double s = 0.0;
	for (list<double>::iterator it = lst.begin(); it != lst.end(); it++)
		s += *it;

	return s / lst.size();
}

// �������� ����� �� ���������
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

// �������� ����� ��� � ����
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

	cout << endl << "������:" << endl;
	show(lst);

	// ������� 3
	lst.push_back(srednee(lst)); // ���������� � ����� �������� ���������������

	cout << endl << "������:" << endl;
	show(lst);

	// ������� 4
	double key;
	int start, end;
	cout << "������� ���� � ������� ���������:" << endl;
	cout << "key = "; cin >> key;
	cout << "start = "; cin >> start;
	cout << "end = "; cin >> end;

	erase_by_key(lst, key, start, end);

	cout << endl << "������:" << endl;
	show(lst);

	// ������� 5
	add_min_max(lst);

	cout << endl << "������:" << endl;
	show(lst);
	return 0;
}