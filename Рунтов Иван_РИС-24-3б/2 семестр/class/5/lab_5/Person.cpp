#include "Person.h"
#include "Object.h"
#include <iostream>
#include <string>
using namespace std;

// ����������� ��� ����������
Person::Person() : name(""), age(0) {}
// ����������� � �����������
Person::Person(string N, int A) : name(N), age(A) {}
// ����������� �����������
Person::Person(Person& p) { name = p.name; age = p.age; }
// ���������
Person::~Person() {}

// ������������
void Person::set_name(string N) { name = N; }
void Person::set_age(int A) { age = A; }

// ���������
string Person::get_name() { return name; }
int Person::get_age() { return age; }

void Person::show()
{
	cout << "���: " << name << endl;
	cout << "�������: " << age << endl << endl;
}

Person& Person::operator=(const Person& p)
{
	if (this == &p) return *this;
	name = p.name;
	age = p.age;
	return *this;
}

istream& operator>>(istream& in, Person& p)
{
	cout << "���: "; in >> p.name;
	cout << "�������: "; in >> p.age;
	cout << endl;
	return in;
}

ostream& operator<<(ostream& out, Person& p)
{
	out << "���: " << p.name << endl;
	out << "�������: " << p.age << endl << endl;
	return out;
}