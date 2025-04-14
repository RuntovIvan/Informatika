#include "List.h"
#include "Pair.h"
#include <iostream>
#include <clocale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	cout << "Работа с классом-контейнером int" << endl;
	List<int>lst_int1(10, 1);
	cout << lst_int1 << endl;

	List<int>lst_int2(8, 1);
	cout << lst_int2 << endl;

	List<int>lst_int3 = lst_int1 * lst_int2;
	cout << lst_int3 << endl;

	cout << "Работа с классом-контейнером float" << endl;
	List<float>lst_float1(7, 1.5);
	cout << lst_float1 << endl;

	List<float>lst_float2(3, 2.1);
	cout << lst_float2 << endl;

	List<float>lst_float3 = lst_float1 * lst_float2;
	cout << lst_float3 << endl;

	cout << "Работа с классом-контейнером double" << endl;
	List<double>lst_double1(2, 6.8);
	cout << lst_double1 << endl;

	List<double>lst_double2(3, 6.8);
	cout << lst_double2 << endl;

	List<double>lst_double3 = lst_double1 * lst_double2;
	cout << lst_double3 << endl;

	cout << "Работа с классом-контейнером Pair" << endl;
	Pair p1(1, 2.5);
	List<Pair>lst_pair1(5, p1);
	cout << lst_pair1 << endl;

	Pair p2(2, 1.5);
	List<Pair>lst_pair2(5, p2);
	cout << lst_pair2 << endl;

	List<Pair>lst_pair3 = lst_pair1 * lst_pair2;
	cout << lst_pair3 << endl;
	return 0;
}