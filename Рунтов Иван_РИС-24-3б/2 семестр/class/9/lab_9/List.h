#pragma once
#include "Error.h"
#include <iostream>
using namespace std;

struct Node
{
	Node* next = nullptr;
	Node* prev = nullptr;
	int data;
};

class Iterator
{
	Node* elem;
public:
	Iterator() { elem = nullptr; }
	Iterator(const Iterator& it) { elem = it.elem; }
	bool operator==(const Iterator& it) { return elem == it.elem; }
	bool operator!=(const Iterator& it) { return elem != it.elem; }

	Iterator& operator++()
	{
		if (elem == nullptr) throw Error_Iterator();
		elem = elem->next;
		return *this;
	}

	Iterator& operator--()
	{
		if (elem == nullptr) throw Error_Iterator();
		elem = elem->prev;
		return *this;
	}

	int& operator*() const
	{
		if (elem == nullptr) throw Error_Iterator();
		return elem->data;
	}

	Iterator& operator+(const int& k)
	{
		for (int i = 0; i < k; i++)
		{
			if (elem == nullptr) throw Error_Iterator();
			elem = elem->next;
		}
		return *this;
	}

	Iterator& operator-(const int& k)
	{
		for (int i = 0; i < k; i++)
		{
			if (elem == nullptr) throw Error_Iterator();
			elem = elem->prev;
		}
		return *this;
	}

	Iterator& operator=(const Iterator& it)
	{
		if (this == &it) return *this;
		elem = it.elem;
		return *this;
	}

	friend class List;
};

class List
{
	Node* head;
	Node* tail;
	int size;
	Iterator beg;
	Iterator end;
public:
	List();
	List(int n, int k = 0);
	List(const List& a);
	~List();
	void push_front(int data);
	void push_back(int data);
	void pop_front();
	void pop_back();
	int front();
	int back();
	List& operator=(const List& a);
	int& operator[](int index);
	int& operator()();
	List operator*(List& a);
	friend istream& operator>>(istream&, const List& a);
	friend ostream& operator<<(ostream&, List& a);
	Iterator first() { return beg; }
	Iterator last() { return end; }
};