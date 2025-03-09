#include <iostream>
#include <clocale>
#include <string>
using namespace std;

struct Node
{
	char data;
	Node* next_ptr;

	void input_data(char Data, Node* Next_ptr)
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
		node->input_data(data, head);
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
};

int main()
{
	setlocale(LC_ALL, "RU");
	system("chcp 1251");
	system("cls");

	Stack open_brackets;

	string str;
	cout << "Введите строку: ";
	getline(cin, str);

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			open_brackets.push(str[i]);

		if (str[i] == ')' && open_brackets.head->data == '(')
			open_brackets.pop();
		
		if (str[i] == ']' && open_brackets.head->data == '[')
			open_brackets.pop();

		if (str[i] == '}' && open_brackets.head->data == '{')
			open_brackets.pop();
	}

	if (open_brackets.size == 0)
		cout << "Последовательность скобок верная." << endl;
	else
		cout << "Последовательность скобок неверная." << endl;

	return 0;
}