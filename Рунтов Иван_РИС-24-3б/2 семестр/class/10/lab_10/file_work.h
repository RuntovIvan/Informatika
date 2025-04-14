#pragma once
#include "Pair.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// создание файла
int make_file(string filename)
{
	ofstream fout(filename);
	if (!fout) return -1;

	int n;
	Pair p;
	cout << "¬ведите количество пар: "; cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> p;
		fout << p << endl;
	}

	fout.close();
	return n; // возвращаем количество записанных объектов
}

// вывод содержимого файла в консоль
int print_file(string filename)
{
	ifstream fin(filename);
	if (!fin) return -1;

	Pair p;
	int i = 0;

	cout << "‘айл " << filename << endl;
	while (fin >> p)
	{
		cout << p << endl;
		i++;
	}
	fin.close();
	return i;
}

// удаление записей, меньших заданной
int del_fewer(string filename)
{
	ofstream temp_fout("temp.txt");
	ifstream fin(filename);
	if (!fin) return -1;

	int x;
	double y;
	cout << "¬ведите минимальное x: "; cin >> x;
	cout << "¬ведите минимальное y: "; cin >> y;

	Pair p;
	int i = 0;
	while (fin >> p)
	{
		if (p.get_x() >= x && p.get_y() >= y)
			temp_fout << p << endl;
		i++;
	}
	temp_fout.close();
	fin.close();
	remove(filename.c_str());
	rename("temp.txt", filename.c_str());
	return i;
}

// добавление целого числа к запис€м с заданным значением
int add_int(string filename)
{
	ofstream temp_fout("temp.txt");
	ifstream fin(filename);
	if (!fin) return -1;

	int x, l;
	cout << "¬ведите искомое x: "; cin >> x;
	cout << "¬ведите прибавл€емое число: "; cin >> l;

	Pair p;
	int i = 0;
	while (fin >> p)
	{
		if (p.get_x() == x)
			p.set_x(x + l);
		temp_fout << p << endl;
		i++;
	}
	temp_fout.close();
	fin.close();
	remove(filename.c_str());
	rename("temp.txt", filename.c_str());
	return i;
}

// добавление вещественного числа к запис€м с заданным значением
int add_double(string filename)
{
	ofstream temp_fout("temp.txt");
	ifstream fin(filename);
	if (!fin) return -1;

	double y, l;
	cout << "¬ведите искомое y: "; cin >> y;
	cout << "¬ведите прибавл€емое число: "; cin >> l;

	Pair p;
	int i = 0;
	while (fin >> p)
	{
		if (p.get_y() == y)
			p.set_y(y + l);
		temp_fout << p << endl;
		i++;
	}
	temp_fout.close();
	fin.close();
	remove(filename.c_str());
	rename("temp.txt", filename.c_str());
	return i;	
}

// добавление K записей после записи с заданным номером
int add_file(string filename)
{
	ofstream temp_fout("temp.txt");
	ifstream fin(filename);
	if (!fin) return -1;

	int k, num;
	cout << "¬ведите номер, после которого нужно вставить: "; cin >> num;
	cout << "¬ведите количество добавл€емых элементов: "; cin >> k;

	Pair p;
	int i = 0;
	while (fin >> p)
	{
		temp_fout << p << endl;
		i++;
		if (i == num)
			for (int i_k = 0; i_k < k; i_k++)
			{
				cin >> p;
				temp_fout << p << endl;
				i++;
			}
	}
	temp_fout.close();
	fin.close();
	remove(filename.c_str());
	rename("temp.txt", filename.c_str());
	return i;
}