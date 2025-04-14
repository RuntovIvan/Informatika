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
	cout << endl << "��������: " << name << endl;
	cout << "�����: " << author << endl;
	cout << "���������� �������: " << pages << endl << endl;
}

void Magazine::Input()
{
	cout << endl << "������� ��������: "; getline(cin, name);
	cout << "������� ������: "; getline(cin, author);
	cout << "������� ���������� �������: "; cin >> pages;
	cout << endl;
}

void Magazine::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		switch (e.command)
		{
		case cmGet:
			cout << "��������: " << name << endl;
			break;
		}
	}
}