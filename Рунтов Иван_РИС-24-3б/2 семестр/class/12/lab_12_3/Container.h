#pragma once
#include <iostream>
#include <set>
using namespace std;

template <class T>
class Container
{
private:
	multiset<T> ms;
	int size;
public:
	Container() { size = 0; }
	Container(int n);
	Container(const Container& c);
	~Container();

	void show();
	T srednee();
	void insert(T data);
	void erase_by_key(T key, int start, int end);
	void add_min_max();
};

template<class T>
Container<T>::Container(int n)
{
	T tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		ms.insert(tmp);
	}
	size = ms.size();
}

template<class T>
Container<T>::Container(const Container& c)
{
	if (this == &c) return *this;
	ms = c.ms;
	size = c.size;
	return *this;
}

template<class T>
Container<T>::~Container() {}

template<class T>
void Container<T>::show()
{
	cout << endl << "Множество с дубликатами:" << endl;
	for (multiset<T>::template iterator it = ms.begin(); it != ms.end(); it++)
		cout << *it << endl;
	cout << endl;
}

template<class T>
T Container<T>::srednee()
{
	T tmp;
	for (multiset<T>::template iterator it = ms.begin(); it != ms.end(); it++)
		tmp = tmp + *it;
	tmp = tmp / ms.size();
	return tmp;
}

template<class T>
void Container<T>::insert(T data)
{
	ms.insert(data);
}

template<class T>
void Container<T>::erase_by_key(T key, int start, int end)
{
	multiset<T>::template iterator it = ms.begin();
	for (int i = 0; i < start; i++)
		it++;

	for (int i = start; i < end; i++)
		if (*it == key)
			it = ms.erase(it);
		else
			it++;
	size = ms.size();
}

template<class T>
void Container<T>::add_min_max()
{
	multiset<T>::template iterator it = ms.begin();
	T min = *it, max = *it;

	for (; it != ms.end(); it++)
		if (*it > max)
			max = *it;
		else if (*it < min)
			min = *it;

	cout << endl << "min = " << min << endl;
	cout << "max = " << max << endl;
	cout << "min + max = " << min + max << endl;

	multiset<T> new_ms;
	for (it = ms.begin(); it != ms.end(); it++)
		new_ms.insert(*it + min + max);
	ms = new_ms;
	size = ms.size();
}


