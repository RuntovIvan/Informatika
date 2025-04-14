#include "Person.h"
#include "Object.h"
#include <iostream>
#include <string>
using namespace std;

// конструктор без парамтеров
Person::Person() : name(""), age(0) {}
// конструктор с параметрами
Person::Person(string N, int A) : name(N), age(A) {}
// конструктор копирования
Person::Person(Person& p) { name = p.name; age = p.age; }
// деструтор
Person::~Person() {}

// модификаторы
void Person::set_name(string N) { name = N; }
void Person::set_age(int A) { age = A; }

// селекторы
string Person::get_name() { return name; }
int Person::get_age() { return age; }

void Person::show()
{
	cout << "Имя: " << name << endl;
	cout << "Возраст: " << age << endl << endl;
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
	cout << "Имя: "; in >> p.name;
	cout << "Возраст: "; in >> p.age;
	cout << endl;
	return in;
}

ostream& operator<<(ostream& out, Person& p)
{
	out << "Имя: " << p.name << endl;
	out << "Возраст: " << p.age << endl << endl;
	return out;
}