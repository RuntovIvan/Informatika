#include "Print.h"
#include <iostream>
#include <string>
using namespace std;

// ����������� ��� ����������
Print::Print()
{
	name = "";
	author = "";
}

// ����������� � �����������
Print::Print(string N, string A)
{
	name = N;
	author = A;
}

//����������� �����������
Print::Print(const Print& p)
{
	name = p.name;
	author = p.author;
}

// ����������
Print::~Print() {}

//��������
string Print::get_name()
{
	return name;
}

string Print::get_author()
{
	return author;
}

// ������������
void Print::set_name(string N)
{
	name = N;
}

void Print::set_author(string A)
{
	author = A;
}

// �������� ������������
Print& Print::operator=(const Print& p)
{
	if (this == &p) return *this;
	name = p.name;
	author = p.author;
	return *this;
}

// �������� ���������
void Print::Show()
{
	cout << endl << "��������: " << name << endl;
	cout << "�����: " << author << endl << endl;
}

// ���� ���������
void Print::Input()
{
	cout << endl << "������� ��������: "; getline(cin, name);
	cout << "������� ������: "; getline(cin, author);
	cout << endl;
}

void Print::HandleEvent(const TEvent& e)
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