#include "Print.h"
#include "Magazine.h"
#include <iostream>
#include <string>
using namespace std;

Magazine::Magazine() : Print()
{
	pages = 0;
}

Magazine::Magazine(string N, string A, int P) : Print(N, A)
{
	pages = P;
}

Magazine::Magazine(const Magazine& m)
{
	name = m.name;
	author = m.author;
	pages = m.pages;
}

int Magazine::get_pages()
{
	return pages;
}

void Magazine::set_pages(int P)
{
	pages = P;
}

Magazine& Magazine::operator=(const Magazine& m)
{
	if (this == &m) return *this;
	name = m.name;
	author = m.author;
	pages = m.pages;
	return *this;
}

void Magazine::Show()
{
	cout << endl << "Название: " << name << endl;
	cout << "Автор: " << author << endl;
	cout << "Количество страниц: " << pages << endl << endl;
}

void Magazine::Input()
{
	cout << endl << "Введите название: "; getline(cin, name);
	cout << "Введите автора: "; getline(cin, author);
	cout << "Введите количество страниц: "; cin >> pages;
	cout << endl;
}

void Magazine::HandleEvent(const TEvent& e)
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