#pragma once
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

template<class T>
class List
{
private:
	priority_queue<T> pq;
	int size;
	priority_queue<T> copy_vec_to_pq(vector<T> v);
	vector<T> copy_pq_to_vec(priority_queue<T> q);

public:
	List() { size = 0; }
	List(int n);
	~List() {}

	int get_size();
	void show();
	T srednee();
	void add(T data);
	void erase_by_key(T key, int start, int end);
	void add_min_max();
};

template<class T>
priority_queue<T> List<T>::copy_vec_to_pq(vector<T> v)
{
	priority_queue<T> q;
	for (int i = 0; i < v.size(); i++)
		q.push(v[i]);
	return q;
}

template<class T>
vector<T> List<T>::copy_pq_to_vec(priority_queue<T> q)
{
	vector<T> vec;
	while (!q.empty())
	{
		vec.push_back(q.top());
		q.pop();
	}
	return vec;
}

template<class T>
List<T>::List(int n)
{
	T tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		pq.push(tmp);
	}
	size = pq.size();
}

template<class T>
void List<T>::show()
{
	vector<T> v = copy_pq_to_vec(pq);

	cout << "Приоритетная очередь" << endl;
	while (!pq.empty())
	{
		cout << pq.top() << endl;
		pq.pop();
	}

	pq = copy_vec_to_pq(v);
}

template<class T>
T List<T>::srednee()
{
	vector<T> v = copy_pq_to_vec(pq);
	T tmp;
	int size = pq.size();
	for (; !pq.empty(); pq.pop())
		tmp = tmp + pq.top();
	tmp = tmp / size;
	pq = copy_vec_to_pq(v);
	size = pq.size();
	return tmp;
}

template<class T>
void List<T>::add(T data)
{
	pq.push(data);
	size = pq.size();
}

template<class T>
void List<T>::erase_by_key(T key, int start, int end)
{
	vector<T> v;

	for (int i = 0; i < start && !pq.empty(); i++, pq.pop())
		v.push_back(pq.top());

	for (int i = start; i < end && !pq.empty(); i++)
		if (pq.top() == key)
			pq.pop();
		else
		{
			v.push_back(pq.top());
			pq.pop();
		}

	for (; !pq.empty(); pq.pop())
		v.push_back(pq.top());

	pq = copy_vec_to_pq(v);
	size = pq.size();
}


template<class T>
void List<T>::add_min_max()
{
	vector<T> v = copy_pq_to_vec(pq);
	T min = pq.top(), max = pq.top();

	for (; !pq.empty(); pq.pop())
		if (pq.top() > max)
			max = pq.top();
		else if (pq.top() < min)
			min = pq.top();

	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] + min + max;

	pq = copy_vec_to_pq(v);
}

template<class T>
int List<T>::get_size()
{
	return size;
}