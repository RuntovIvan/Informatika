#pragma once
#include <iostream>
using namespace std;

class Pair
{
	int x;
	double y;
public:
	Pair();
	Pair(int x_p, double y_p);
	Pair operator+(int x_p);
	Pair operator+(double y_p);
	Pair operator-(Pair& p);
	Pair operator=(Pair p);
	friend Pair operator+(int x_p, Pair& p);
	friend Pair operator+(double y_p, Pair& p);
	friend ostream& operator<<(ostream& out, Pair p);
	int get_x();
	double get_y();
	void set_x(int x_p);
	void set_y(double y_p);
};