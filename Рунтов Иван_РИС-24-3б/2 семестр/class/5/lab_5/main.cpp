#include "Object.h"
#include "Person.h"
#include "Student.h"
#include "Vector.h"
#include <iostream>
#include <clocale>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	system("chcp 1251");
	system("cls");

	Vector v(5);
	Person a;
	Student b;

	cin >> a >> b;

	Object* p = &a;
	v.add(p);
	p = &b;
	v.add(p);

	cout << v;
	return 0;
}