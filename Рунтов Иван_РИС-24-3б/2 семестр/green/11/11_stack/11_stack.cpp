#include <iostream>
#include <clocale>
using namespace std;

struct Node
{
	char data;
	Node* next_ptr;

	void init_node(char Data, Node* Next_ptr)
	{
		data = Data;
		next_ptr = Next_ptr;
	}
};

struct Stack
{
	Node* head = nullptr;
	int size = 0;

	void push(char data)
	{
		Node* node = new Node;
		node->init_node(data, head);
		head = node;
		size++;
	}

	void pop()
	{
		if (head != nullptr)
		{
			Node* node = head;
			head = head->next_ptr;
			delete node;
			size--;
		}
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
	}

	void show()
	{
		cout << "����: ";
		for (Node* node = head; node != nullptr; node = node->next_ptr)
			cout << node->data << ' ';
		cout << endl;
	}
};

void del(Stack& stack, char key);
void insert(Stack& stack, int k, int num);

int main()
{
	setlocale(LC_ALL, "RU");
	Stack stack;

	int size;
	cout << "������� ���������� ���������: ";
	cin >> size;

	char value;
	for (int i = 1; i <= size; i++)
	{
		cout << "������� �������: ";
		cin >> value;
		stack.push(value);
	}
	stack.show();

	char key;
	cout << "������� ���� ��� ��������: ";
	cin >> key;

	del(stack, key);
	cout << "���� ����� �������� �� �����:\n";
	stack.show();

	int k, num;
	cout << "������� �����, ����� ������� ����� �������� ��������: ";
	cin >> num;
	cout << "������� ���������� ����������� ���������: ";
	cin >> k;

	insert(stack, k, num);
	cout << "���� ����� ���������� ���������:\n";
	stack.show();

	return 0;
}

void del(Stack& stack, char key)
{
	Stack new_stack;
	int size = stack.size;
	for (int i = 0; i < size; i++)
	{
		if (stack.head->data != key)
			new_stack.push(stack.head->data);
		stack.pop();
	}

	size = new_stack.size;
	for (int i = 0; i < size; i++)
	{
		stack.push(new_stack.head->data);
		new_stack.pop();
	}
}

void insert(Stack& stack, int k, int num)
{
	Stack new_stack;
	for (int i = 1; i < num; i++)
	{
		new_stack.push(stack.head->data);
		stack.pop();
	}

	char value;
	for (int i = 1; i <= k; i++)
	{
		cout << "������� ����� �������: ";
		cin >> value;
		stack.push(value);
	}

	int size = new_stack.size;
	for (int i = 0; i < size; i++)
	{
		stack.push(new_stack.head->data);
		new_stack.pop();
	}
}