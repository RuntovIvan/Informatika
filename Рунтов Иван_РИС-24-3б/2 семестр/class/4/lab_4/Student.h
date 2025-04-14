#pragma once
#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

class Student : public Person
{
protected:
	string subject;
	int mark;
public:
	Student();
	Student(string N, int A, string S, int M);
	Student(Student& s);
	~Student();
	void set_subject(string S);
	void set_mark(int M);
	string get_subject();
	int get_mark();
	void printinfo();
	void badmark();
	Student& operator=(Student& s);
	friend istream& operator>>(istream& in, Student& s);
	friend ostream& operator<<(ostream& out, Student& s);
};