#include "Person.h"
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

Student::Student() : Person(), subject(""), mark(0) {}
Student::Student(string N, int A, string S, int M) : Person(N, A), subject(S), mark(M) {}
Student::Student(Student& s) : Person(s) { mark = s.mark; subject = s.subject; }
Student::~Student() {}

void Student::set_subject(string S) { subject = S; }
void Student::set_mark(int M) { mark = M; }

string Student::get_subject() { return subject; }
int Student::get_mark() { return mark; }

void Student::printinfo()
{
	Person::printinfo();
	cout << "Предмет: " << subject << "\nОценка: " << mark << endl << endl;
}

void Student::badmark()
{
	if (mark < 3)
		cout << "Плохая оценка!" << endl;
}

Student& Student::operator=(Student& s)
{
	if (this == &s) return *this;
	name = s.name;
	age = s.age;
	subject = s.subject;
	mark = s.mark;
	return *this;
}

istream& operator>>(istream& in, Student& s)
{
	Person* ptr = &s;
	in >> *ptr;
	cout << "Предмет: "; in >> s.subject;
	cout << "Оценка: "; in >> s.mark;
	cout << endl;
	return in;
}

ostream& operator<<(ostream& out, Student& s)
{
	Person* ptr = &s;
	out << *ptr;
	out << "Предмет: " << s.subject << endl;
	out << "Оценка: " << s.mark << endl;
	return out;
}