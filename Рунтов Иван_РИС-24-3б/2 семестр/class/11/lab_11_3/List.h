#pragma once
#include <list>
#include <iostream>
using namespace std;

template<class T>
class List
{
private:
	list<T> lst;
	int size;
public:
	List();
	List(int n);
	~List() {}

	void show();
	T srednee();
	void add(T data);
	void erase_by_key(T key, int start, int end);
	void add_min_max();
};

template<class T>
List<T>::List()
{
	size = 0;
}

template<class T>
List<T>::List(int n)
{
	T tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		lst.push_back(tmp);
	}
	size = lst.size();
}

template<class T>
void List<T>::show()
{
	cout << endl << "Список:" << endl;
	for (list<T>::template iterator it = lst.begin(); it != lst.end(); it++)
		cout << *it << endl;
	cout << endl;
}

template<class T>
T List<T>::srednee()
{
	T tmp;
	for (list<T>::template iterator it = lst.begin(); it != lst.end(); it++)
		tmp = tmp + *it;
	tmp = tmp / size;
	return tmp;
}

template<class T>
void List<T>::add(T data)
{
	lst.push_back(data);
}

template<class T>
void List<T>::erase_by_key(T key, int start, int end)
{
	list<T>::template iterator iter = lst.begin();
	for (int i = 0; i < start; i++)
		iter++;

	for (int i = start; i < end; i++)
		if (*iter == key)
			iter = lst.erase(iter);
		else
			iter++;
}

template<class T>
void List<T>::add_min_max()
{
	list<T>::template iterator iter = lst.begin();
	T min = *iter, max = *iter;
	for (; iter != lst.end(); iter++)
		if (*iter > max)
			max = *iter;
		else if (*iter < min)
			min = *iter;

	for (iter = lst.begin(); iter != lst.end(); iter++)
		*iter = *iter + min + max;
}
