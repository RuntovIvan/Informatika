#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Pair
{
private:
	int x;
	double y;
public:
	Pair();
	Pair(int x_p, double y_p);
	Pair(const Pair& p);

	int get_x();
	double get_y();
	void set_x(int x_p);
	void set_y(double y_p);

	Pair operator+(int x_p);
	Pair operator+(double y_p);
	Pair operator-(const Pair& p);
	Pair& operator=(const Pair& p);

	friend Pair operator+(int x_p, Pair& p);
	friend Pair operator+(double y_p, Pair& p);
	friend istream& operator>>(istream& in, Pair& p);
	friend ostream& operator<<(ostream& out, const Pair& p);
	friend ifstream& operator>>(ifstream& fin, Pair& p);
	friend ofstream& operator<<(ofstream& fout, const Pair& p);
};