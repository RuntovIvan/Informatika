#include "List.h"
#include "Error.h"
#include <iostream>
using namespace std;

List::List()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
	beg.elem = nullptr;
	end.elem = nullptr;
}

List::List(int n, int k)
{
	if (n < 1) throw Error_Size();
	size = n;
	Node* node = new Node;
	node->data = k;
	head = tail = node;
	for (int i = 1; i < size; i++)
	{
		Node* node = new Node;
		node->data = k + i;
		node->prev = tail;
		tail->next = node;
		tail = node;
	}
	beg.elem = head;
	end.elem = tail->next;
}

List::List(const List& a)
{
	Node* tmp = a.head;
	while (tmp != nullptr)
	{
		push_back(tmp->data);
		tmp = tmp->next;
	}
	beg = a.beg;
	end = a.end;
}

List::~List()
{
	Node* tmp = head;
	while (tmp != nullptr)
	{
		head = head->next;
		delete tmp;
		tmp = head;
	}
}

void List::push_front(int data)
{
	Node* node = new Node;
	node->data = data;
	node->next = head;

	if (head != nullptr)
		head->prev = node;

	if (tail == nullptr)
		tail = node;

	head = node;
	size++;
	beg.elem = head;
	end.elem = tail->next;
}

void List::push_back(int data)
{
	Node* node = new Node;
	node->data = data;

	if (tail != nullptr)
		tail->next = node;

	if (head == nullptr)
		head = node;

	node->prev = tail;
	tail = node;
	size++;
	beg.elem = head;
	end.elem = tail->next;
}

void List::pop_front()
{
	if (size == 0) throw Error_Empty_List();

	if (size == 1)
	{
		delete head;
		head = tail = nullptr;
		size--;
		return;
	}

	Node* node = head;
	head = head->next;
	head->prev = nullptr;
	delete node;
	size--;
	beg.elem = head;
	end.elem = tail->next;
}

void List::pop_back()
{
	if (size == 0) throw Error_Empty_List();

	if (size == 1)
	{
		delete tail;
		head = tail = nullptr;
		size--;
		return;
	}

	Node* node = tail;
	tail = tail->prev;
	tail->next = nullptr;
	delete node;
	size--;
	beg.elem = head;
	end.elem = tail->next;
}

int List::front()
{
	if (size == 0) throw Error_Empty_List();
	return head->data;
}

int List::back()
{
	if (size == 0) throw Error_Empty_List();
	return tail->data;
}

List& List::operator=(const List& a)
{
	if (this == &a) return *this;

	while (size != 0) pop_back();
	head = tail = nullptr;

	Node* tmp = a.head;
	while (tmp != nullptr)
	{
		push_back(tmp->data);
		tmp = tmp->next;
	}
	beg.elem = head;
	end.elem = tail->next;
	return *this;
}

int& List::operator[](int index)
{
	if (index < 0) throw Error_Index_Min();
	if (index >= size) throw Error_Index_Max();
	Node* tmp = head;
	for (int i = 0; i != index; i++)
		tmp = tmp->next;
	return tmp->data;
}

int& List::operator()()
{
	return size;
}

List List::operator*(List& a)
{
	int newsize = min(size, a.size);
	List newlist(newsize);
	for (int i = 0; i < newsize; i++)
		newlist[i] = (*this)[i] * a[i];
	return newlist;
}

istream& operator>>(istream& in, const List& a)
{
	cout << endl << "Ввод списка:" << endl;
	Node* node = a.head;
	while (node != nullptr)
	{
		in >> node->data;
		node = node->next;
	}
	return in;
}

ostream& operator<<(ostream& out, List& a)
{
	cout << endl << "Вывод списка:" << endl;
	for (int i = 0; i < a.size; i++)
		cout << a[i] << ' ';
	cout << endl << endl;
	return out;
}