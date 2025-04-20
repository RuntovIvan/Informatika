#include <queue>
#include <vector>
#include "Pair.h"
#include <iostream>
#include <clocale>
using namespace std;

vector<Pair> copy_pq_to_vec(priority_queue<Pair> q)
{
	vector<Pair> vec;
	while (!q.empty())
	{
		vec.push_back(q.top());
		q.pop();
	}
	return vec;
}

priority_queue<Pair> copy_vec_to_pq(vector<Pair> vec)
{
	priority_queue<Pair> q;
	for (int i = 0; i < vec.size(); i++)
		q.push(vec[i]);
	return q;
}

priority_queue<Pair> make_pq(int n)
{
	priority_queue<Pair> q;
	for (int i = 0; i < n; i++)
	{
		Pair tmp(rand() % 10, (double)(rand() % 10) / 2);
		q.push(tmp);
	}

	return q;
}

void show(priority_queue<Pair> q)
{
	cout << "Приоритетная очередь" << endl;
	while (!q.empty())
	{
		cout << q.top() << endl;
		q.pop();
	}
}

Pair srednee(priority_queue<Pair> q)
{
	Pair tmp;
	int size = q.size();
	for (; !q.empty(); q.pop())
		tmp = tmp + q.top();
	tmp = tmp / size;
	return tmp;
}

void erase_by_key(priority_queue<Pair>& q, Pair key, int start, int end)
{
	vector<Pair> v;

	for (int i = 0; i < start && !q.empty(); i++, q.pop())
		v.push_back(q.top());

	for (int i = start; i < end && !q.empty(); i++)
		if (q.top() == key)
			q.pop();
		else
		{
			v.push_back(q.top());
			q.pop();
		}

	for (; !q.empty(); q.pop())
		v.push_back(q.top());

	q = copy_vec_to_pq(v);
}

void add_min_max(priority_queue<Pair>& q)
{
	vector<Pair> v = copy_pq_to_vec(q);
	Pair min = q.top(), max = q.top();
	
	for (; !q.empty(); q.pop())
		if (q.top() > max)
			max = q.top();
		else if (q.top() < min)
			min = q.top();

	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] + min + max;

	q = copy_vec_to_pq(v);
}

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(nullptr));
	try
	{
		priority_queue<Pair> q = make_pq(5);
		show(q);

		// задание 3
		q.push(srednee(q));
		show(q);

		// задание 4
		Pair key;
		int start, end;

		cout << "Введите ключ и границы интервала:" << endl;
		cout << "key:"; cin >> key;
		cout << "start = "; cin >> start; if (start < 0) throw 1;
		cout << "end = "; cin >> end; if (end >= q.size()) throw 2;

		erase_by_key(q, key, start, end);
		show(q);

		// задание 5
		add_min_max(q);
		show(q);
	}

	catch (int)
	{
		cout << endl << "error" << endl;
	}
	return 0;
}