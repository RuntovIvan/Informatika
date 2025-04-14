#include "Vector.h"
#include "Object.h"
#include "Print.h"
#include "Magazine.h"
#include <iostream>
using namespace std;

Vector::Vector()
{
	beg = nullptr;
	size = 0;
	cur = 0;
}

Vector::Vector(int n)
{
	size = n;
	beg = new Object*[size];
	cur = 0;
}

Vector::~Vector()
{
	if (beg != nullptr) delete[] beg;
	beg = nullptr;
}

void Vector::Add()
{
	Object* o;

	cout << "1. Print" << endl;
	cout << "2. Magazine" << endl;

	int y;
	cin >> y;
	getchar();
	if (y == 1)
	{
		Print* p = new Print;
		p->Input();
		o = p;

		if (cur < size)
		{
			beg[cur] = o;
			cur++;
		}
	}
	else if (y == 2)
	{
		Magazine* m = new Magazine;
		m->Input();
		o = m;

		if (cur < size)
		{
			beg[cur] = o;
			cur++;
		}
	}
	else
		return;
}

void Vector::Del()
{
	if (cur == 0) return;
	cur--;
}

void Vector::Show()
{
	if (cur == 0) cout << "Пусто" << endl;
	Object** p = beg;
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();
		p++;
	}
}

int Vector::operator()()
{
	return cur;
}

void Vector::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->HandleEvent(e);
			p++;
		}
	}
}