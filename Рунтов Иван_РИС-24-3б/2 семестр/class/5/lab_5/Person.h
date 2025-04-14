#pragma once
#include "Object.h"
#include <iostream>
#include <string>
using namespace std;

class Person : public Object
{
protected:
	string name;
	int age;
public:
	Person();
	Person(string N, int A);
	Person(Person& p);
	~Person();
	void set_name(string N);
	void set_age(int A);
	string get_name();
	int get_age();
	void show() override;
	Person& operator=(const Person& p);
	friend istream& operator>>(istream& in, Person& p);
	friend ostream& operator<<(ostream& out, Person& p);
};