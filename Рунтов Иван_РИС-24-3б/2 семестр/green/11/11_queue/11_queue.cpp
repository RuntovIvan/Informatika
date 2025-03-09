#include <iostream>
#include <clocale>
using namespace std;

struct Node
{
	char data;
	Node* next_ptr;

	void init_node(char Data)
	{
		data = Data;
		next_ptr = nullptr;
	}
};

struct Queue
{
	Node* head = nullptr;
	Node* tail = nullptr;
	int size = 0;

	void push(char data)
	{
		Node* node = new Node;
		node->init_node(data);
		size++;

		if (tail == nullptr)
		{
			head = tail = node;
			return;
		}

		tail->next_ptr = node;
		tail = node;
	}

	void pop()
	{
		if (head == nullptr)
			return;
		
		if (head == tail)
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

	void clear()
	{
		while (head != nullptr)
		{
			Node* node = head;
			head = head->next_ptr;
			delete node;
			size--;
		}
		tail = nullptr;
	}

	void show()
	{
		cout << "�������: ";
		for (Node* node = head; node != nullptr; node = node->next_ptr)
			cout << node->data << ' ';
		cout << endl;
	}
};

void del(Queue& queue, char key);
void insert(Queue& queue, int k, int num);

int main()
{
	setlocale(LC_ALL, "RU");
	Queue queue;

	int size;
	cout << "������� ���������� ���������: ";
	cin >> size;

	char value;
	for (int i = 1; i <= size; i++)
	{
		cout << "������� �������: ";
		cin >> value;
		queue.push(value);
	}
	queue.show();

	char key;
	cout << "������� ���� ��� ��������: ";
	cin >> key;

	del(queue, key);
	cout << "������� ����� �������� �� �����:\n";
	queue.show();

	int k, num;
	cout << "������� �����, ����� ������� ����� �������� ��������: ";
	cin >> num;
	cout << "������� ���������� ����������� ���������: ";
	cin >> k;

	insert(queue, k, num);
	cout << "������� ����� ���������� ���������:\n";
	queue.show();

	queue.clear();
	return 0;
}

void del(Queue& queue, char key)
{
	int size = queue.size;
	for (int i = 0; i < size; i++)
		if (queue.head->data == key)
			queue.pop();
		else
		{
			queue.push(queue.head->data);
			queue.pop();
		}
}

void insert(Queue& queue, int k, int num)
{
	for (int i = 1; i < num; i++)
	{
		queue.push(queue.head->data);
		queue.pop();
	}

	char value;
	for (int i = 1; i <= k; i++)
	{
		cout << "������� ����� �������: ";
		cin >> value;
		queue.push(value);
	}

	int size = queue.size;
	for (int i = num; i <= size - k; i++)
	{
		queue.push(queue.head->data);
		queue.pop();
	}
}