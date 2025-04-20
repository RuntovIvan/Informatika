#pragma once
#include <iostream>
using namespace std;

class Pair
{
private:
	int first;
	double second;
public:
	Pair();
	Pair(int F, double S);
	Pair(const Pair& p);
	
	int get_first();
	double get_second();
	void set_first(int F);
	void set_second(double S);

	Pair operator=(const Pair& p);
	bool operator==(const Pair& p);
	bool operator>(const Pair& p);
	bool operator<(const Pair& p);
	Pair operator+(const Pair& p);
	Pair operator/(const int n);

	friend istream& operator>>(istream& in, Pair& p);
	friend ostream& operator<<(ostream& out, const Pair& p);
};