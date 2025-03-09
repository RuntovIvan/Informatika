#include <iostream>
#include <clocale>
using namespace std;

struct Node
{
	char data;
	Node* next = nullptr;
	Node* prev = nullptr;
};

struct LinkedList
{
	Node* head = nullptr;
	Node* tail = nullptr;
	int size = 0;

	void push_back(char data)
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
	}

	void push_front(char data)
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
	}

	void pop_front()
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

		Node* node = head;
		head = head->next;
		head->prev = nullptr;
		delete node;
		size--;
	}

	void pop_back()
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

		Node* node = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete node;
		size--;
	}

	Node* get_el(int k)
	{
		if (k < 1)
			return nullptr;

		Node* node = head;
		int n = 1;

		while (node && node->next && n != k)
		{
			node = node->next;
			n++;
		}

		if (n == k)
			return node;
		return nullptr;
	}

	void insert_el(int k, char data) // перед k
	{
		Node* left = get_el(k - 1);
		if (left == nullptr)
		{
			push_front(data);
			return;
		}

		Node* node = new Node;
		node->data = data;

		Node* right = left->next;
		left->next = node;
		node->next = right;
		node->prev = left;

		if (right != nullptr)
			right->prev = node;

		if (tail == left)
			tail = node;
		size++;
	}

	void erase_el(int k)
	{
		if (k < 1 || k > size) return;
		if (k == 1)
		{
			pop_front();
			return;
		}
		if (k == size)
		{
			pop_back();
			return;
		}

		Node* node = get_el(k);
		Node* left = node->prev;
		Node* right = node->next;

		left->next = right;
		right->prev = left;
		delete node;
		size--;
	}

	void show_front()
	{
		cout << "Двунаправленный список: ";
		for (Node* node = head; node != nullptr; node = node->next)
			cout << node->data << ' ';
		cout << endl;
	}

	void show_back()
	{
		cout << "Двунаправленный список: ";
		for (Node* node = tail; node != nullptr; node = node->prev)
			cout << node->data << ' ';
		cout << endl;
	}
};

void del(LinkedList& llist, char key);
void insert(LinkedList& llist, int k, int num);

int main()
{
	setlocale(LC_ALL, "RU");
	LinkedList llist;

	int size;
	cout << "Введите количество элементов: ";
	cin >> size;

	char value;
	for (int i = 1; i <= size; i++)
	{
		cout << "Введите элемент: ";
		cin >> value;
		llist.push_back(value);
	}
	llist.show_front();

	char key;
	cout << "Введите ключ для удаления: ";
	cin >> key;

	del(llist, key);
	cout << "Двунапрвленный список после удаления по ключу:\n";
	llist.show_front();

	int k, num;
	cout << "Введите номер, перед которым нужно добавить элементы: ";
	cin >> num;
	cout << "Введите количество добавляемых элементов: ";
	cin >> k;

	insert(llist, k, num);
	cout << "Двунапрвленный список после добавления элементов:\n";
	llist.show_front();

	return 0;
}

void del(LinkedList& llist, char key)
{
	int size = llist.size;
	for (int i = 1; i <= size; i++)
		if (llist.head->data == key)
			llist.pop_front();
		else
		{
			llist.push_back(llist.head->data);
			llist.pop_front();
		}
}

void insert(LinkedList& llist, int k, int num)
{
	char value;
	for (int i = 1; i <= k; i++)
	{
		cout << "Введите новый элемент: ";
		cin >> value;
		llist.insert_el(num, value);
		num++;
	}
}