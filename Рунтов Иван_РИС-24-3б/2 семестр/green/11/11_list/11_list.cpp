#include <iostream>
#include <clocale>
using namespace std;

struct Node
{
	char data;
	Node* next_ptr = nullptr;

	void init_node(char Data)
	{
		data = Data;
	}
};

struct List
{
	Node* head = nullptr;
	Node* tail = nullptr;
	int size = 0;

	void push_back(int data)
	{
		Node* node = new Node;
		node->init_node(data);

		if (tail != nullptr)
			tail->next_ptr = node;

		if (head == nullptr)
			head = node;

		tail = node;
		size++;
	}

	void push_front(int data)
	{
		Node* node = new Node;
		node->init_node(data);

		if (tail == nullptr)
			tail = node;

		node->next_ptr = head;
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
		head = head->next_ptr;
		delete node;
		size--;
	}

	void pop_back()
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
		while (node->next_ptr != tail)
			node = node->next_ptr;

		delete tail;
		node->next_ptr = nullptr;
		tail = node;
		size--;
	}

	Node* get_el(int k)
	{
		if (k < 1)
			return nullptr;

		Node* node = head;
		int n = 1;

		while (node && node->next_ptr && n != k)
		{
			node = node->next_ptr;
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
		node->init_node(data);
		
		Node* right = left->next_ptr;
		left->next_ptr = node;
		node->next_ptr = right;

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

		Node* left = get_el(k - 1);
		Node* node = left->next_ptr;
		Node* right = node->next_ptr;

		left->next_ptr = right;
		delete node;
		size--;
	}

	void show()
	{
		cout << "ќднонапрвленный список: ";
		for (Node* node = head; node != nullptr; node = node->next_ptr)
			cout << node->data << ' ';
		cout << endl;
	}
};

void del(List& list, char key);
void insert(List& list, int k, int num);

int main()
{
	setlocale(LC_ALL, "RU");
	List list;

	int size;
	cout << "¬ведите количество элементов: ";
	cin >> size;

	char value;
	for (int i = 1; i <= size; i++)
	{
		cout << "¬ведите элемент: ";
		cin >> value;
		list.push_back(value);
	}
	list.show();

	char key;
	cout << "¬ведите ключ дл€ удалени€: ";
	cin >> key;

	del(list, key);
	cout << "ќднонапрвленный список после удалени€ по ключу:\n";
	list.show();

	int k, num;
	cout << "¬ведите номер, перед которым нужно добавить элементы: ";
	cin >> num;
	cout << "¬ведите количество добавл€емых элементов: ";
	cin >> k;

	insert(list, k, num);
	cout << "ќднонапрвленный список после добавлени€ элементов:\n";
	list.show();

	return 0;
}

void del(List& list, char key)
{
	int size = list.size;
	for (int i = 1; i <= size; i++)
		if (list.head->data == key)
			list.pop_front();
		else
		{
			list.push_back(list.head->data);
			list.pop_front();
		}
}

void insert(List& list, int k, int num)
{
	char value;
	for (int i = 1; i <= k; i++)
	{
		cout << "¬ведите новый элемент: ";
		cin >> value;
		list.insert_el(num, value);
		num++;
	}
}