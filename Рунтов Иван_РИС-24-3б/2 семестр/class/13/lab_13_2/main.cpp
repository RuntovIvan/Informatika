#include <iostream>
#include <clocale>
#include <queue>
#include <vector>
#include "Pair.h"
#include <algorithm>
using namespace std;

typedef priority_queue<Pair> PQ;
typedef vector<Pair> VEC;

VEC pq_to_vec(PQ pq)
{
	VEC v;
	for (; !pq.empty(); pq.pop())
		v.push_back(pq.top());
	return v;
}

PQ vec_to_pq(VEC v)
{
	PQ pq;
	for (int i = 0; i < v.size(); i++)
		pq.push(v[i]);
	return pq;
}

PQ make_pq(int n)
{
	PQ pq;
	for (int i = 0; i < n; i++)
	{
		Pair tmp(rand() % 10, (double)(rand() % 10) / 2.5);
		pq.push(tmp);
	}
	return pq;
}

void show(PQ pq)
{
	cout << endl << "Очередь с приоритетами:" << endl;
	for (; !pq.empty(); pq.pop())
		cout << pq.top() << endl;
	cout << endl;
}

Pair srednee(PQ pq)
{
	Pair tmp;
	PQ tmp_pq = pq;
	for (; !pq.empty(); pq.pop())
		tmp = tmp + pq.top();
	tmp = tmp / tmp_pq.size();
	return tmp;
}

void erase_by_key(PQ& pq, Pair p1, Pair p2)
{
	VEC v;
	for (; !pq.empty(); pq.pop())
		if (pq.top() > p1 && pq.top() < p2)
			continue;
		else
			v.push_back(pq.top());
	pq = vec_to_pq(v);
}

void add_min_max(PQ& pq)
{
	VEC v = pq_to_vec(pq);
	Pair min = v[v.size() - 1], max = v[0];

	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] + min + max;

	cout << endl << "min = " << min << endl;
	cout << "max = " << max << endl;
	cout << "min + max = " << min + max << endl;

	pq = vec_to_pq(v);
}

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(nullptr));

	PQ pq = make_pq(5);
	show(pq);

	// задание 3
	cout << endl << "Среднее:" << srednee(pq) << endl;
	pq.push(srednee(pq));
	show(pq);

	// задание 4
	Pair p1, p2;
	cout << endl << "Первая пара диапазона: "; cin >> p1;
	cout << "Вторая пара диапазона: "; cin >> p2;
	if (p1 > p2)
		swap(p1, p2);
	erase_by_key(pq, p1, p2);
	show(pq);

	// задание 5
	add_min_max(pq);
	show(pq);

	return 0;
}