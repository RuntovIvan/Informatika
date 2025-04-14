#pragma once
#include <iostream>
#include "Pair.h"
using namespace std;

template <class T>
struct Node
{
	Node* next = nullptr;
	Node* prev = nullptr;
	T data;
};

template <class T>
class List
{
private:
	Node<T>* head;
	Node<T>* tail;
	int size;
public:
	List();
	List(int n, T k = 0);
	List(const List<T>& a);
	~List();
	void push_front(T data);
	void push_back(T data);
	void pop_front();
	void pop_back();
	T front();
	T back();
	List<T>& operator=(const List<T>& a);
	T& operator[](int index);
	int& operator()();
	List<T> operator*(List<T>& a);
	friend istream& operator>> <>(istream& in, const List<T>& a);
	friend ostream& operator<< <>(ostream& out, List<T>& a);
};

template <class T>
List<T>::List()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

template <class T>
List<T>::List(int n, T k)
{
	size = n;
	Node<T>* node = new Node<T>;
	node->data = k;
	head = tail = node;
	for (int i = 1; i < size; i++)
	{
		Node<T>* node = new Node<T>;
		node->data = k + i;
		node->prev = tail;
		tail->next = node;
		tail = node;
	}
}

template <class T>
List<T>::List(const List<T>& a)
{
	Node<T>* tmp = a.head;
	while (tmp != nullptr)
	{
		push_back(tmp->data);
		tmp = tmp->next;
	}
}

template <class T>
List<T>::~List()
{
	Node<T>* tmp = head;
	while (tmp != nullptr)
	{
		head = head->next;
		delete tmp;
		tmp = head;
	}
}

template <class T>
void List<T>::push_front(T data)
{
	Node<T>* node = new Node<T>;
	node->data = data;
	node->next = head;

	if (head != nullptr)
		head->prev = node;

	if (tail == nullptr)
		tail = node;

	head = node;
	size++;
}

template <class T>
void List<T>::push_back(T data)
{
	Node<T>* node = new Node<T>;
	node->data = data;

	if (tail != nullptr)
		tail->next = node;

	if (head == nullptr)
		head = node;

	node->prev = tail;
	tail = node;
	size++;
}

template <class T>
void List<T>::pop_front()
{
	if (size == 0)
		return;

	if (size == 1)
	{
		delete head;
		head = tail = nullptr;
		size--;
		return;
	}

	Node<T>* node = head;
	head = head->next;
	head->prev = nullptr;
	delete node;
	size--;
}

template <class T>
void List<T>::pop_back()
{
	if (size == 0)
		return;

	if (size == 1)
	{
		delete tail;
		head = tail = nullptr;
		size--;
		return;
	}

	Node<T>* node = tail;
	tail = tail->prev;
	tail->next = nullptr;
	delete node;
	size--;
}

template <class T>
T List<T>::front()
{
	return head->data;
}

template <class T>
T List<T>::back()
{
	return tail->data;
}

template <class T>
List<T>& List<T>::operator=(const List<T>& a)
{
	if (this == &a) return *this;

	while (size != 0) pop_back();
	head = tail = nullptr;

	Node<T>* tmp = a.head;
	while (tmp != nullptr)
	{
		push_back(tmp->data);
		tmp = tmp->next;
	}
	return *this;
}

template <class T>
T& List<T>::operator[](int index)
{
	if (index >= 0 || index < size)
	{
		Node<T>* tmp = head;
		for (int i = 0; i != index; i++)
			tmp = tmp->next;
		return tmp->data;
	}
	else
	{
		cout << "Неверный индекс!" << endl;
		exit(1);
	}
}

template <class T>
int& List<T>::operator()()
{
	return size;
}

template <class T>
List<T> List<T>::operator*(List<T>& a)
{
	List<T> newlist;
	if (size < a.size)
		newlist = *this;
	else
		newlist = a;

	int newsize = min(size, a.size);
	for (int i = 0; i < newsize; i++)
		newlist[i] = (*this)[i] * a[i];
	return newlist;
}

template <class T>
istream& operator>>(istream& in, const List<T>& a)
{
	cout << endl << "Ввод списка:" << endl;
	Node<T>* node = a.head;
	while (node != nullptr)
	{
		in >> node->data;
		node = node->next;
	}
	return in;
}

template <class T>
ostream& operator<<(ostream& out, List<T>& a)
{
	cout << endl << "Вывод списка:" << endl;
	for (int i = 0; i < a.size; i++)
		cout << a[i] << ' ';
	cout << endl << endl;
	return out;
}