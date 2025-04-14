#include "Vector.h"
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
	beg = new Object * [n];
	size = n;
	cur = 0;
}

Vector::~Vector()
{
	if (beg != nullptr) delete[] beg;
	beg = nullptr;
}

void Vector::add(Object* p)
{
	if (cur < size)
	{
		beg[cur] = p;
		cur++;
	}
}

ostream& operator<<(ostream& out, const Vector& v)
{
	if (v.size == 0)
	{
		out << "Вектор пустой" << endl;
		return out;
	}

	Object** p = v.beg;
	for (int i = 0; i < v.cur; i++)
	{
		(*p)->show();
		p++;
	}
	return out;
}