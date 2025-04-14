#pragma once
#include "Object.h"

class Vector
{
protected:
	Object** beg;
	int size;
	int cur;
public:
	Vector();
	Vector(int n);
	~Vector();

	void Add();
	void Del();
	void Show();

	int operator()();

	void HandleEvent(const TEvent& e);
};