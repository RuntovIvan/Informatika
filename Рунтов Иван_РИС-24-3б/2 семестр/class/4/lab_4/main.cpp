#include "Person.h"
#include "Student.h"
#include <iostream>
#include <clocale>
#include <string>
using namespace std;

void f1(Person& c)
{
	c.set_name("Олег");
	cout << c;
}

Person f2()
{
	Student l("Антон", 18, "информатика", 3);
	return l;
}

int main()
{
	setlocale(LC_ALL, "RU");
	system("chcp 1251");
	system("cls");

	Person a;
	cin >> a;
	cout << a;

	Person b("Анатолий", 45);
	cout << b;
	a = b;
	cout << a;

	Student c;
	cin >> c;
	cout << c;

	f1(c);
	a = f2();
	cout << a;
	return 0;
}