#include "Print.h"
#include <iostream>
#include <string>
using namespace std;

// конструктор без параметров
Print::Print()
{
	name = "";
	author = "";
}

// конструктор с параметрами
Print::Print(string N, string A)
{
	name = N;
	author = A;
}

//конструктор копирования
Print::Print(const Print& p)
{
	name = p.name;
	author = p.author;
}

// деструктор
Print::~Print() {}

//селеторы
string Print::get_name()
{
	return name;
}

string Print::get_author()
{
	return author;
}

// модификаторы
void Print::set_name(string N)
{
	name = N;
}

void Print::set_author(string A)
{
	author = A;
}

// оператор присваивания
Print& Print::operator=(const Print& p)
{
	if (this == &p) return *this;
	name = p.name;
	author = p.author;
	return *this;
}

// просмотр атрибутов
void Print::Show()
{
	cout << endl << "Название: " << name << endl;
	cout << "Автор: " << author << endl << endl;
}

// ввод атрибутов
void Print::Input()
{
	cout << endl << "Введите название: "; getline(cin, name);
	cout << "Введите автора: "; getline(cin, author);
	cout << endl;
}

void Print::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		switch (e.command)
		{
		case cmGet:
			cout << "Название: " << name << endl;
			break;
		}
	}
}