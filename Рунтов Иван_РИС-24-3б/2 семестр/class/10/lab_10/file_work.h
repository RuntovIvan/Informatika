#pragma once
#include "Pair.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// �������� �����
int make_file(string filename)
{
	ofstream fout(filename);
	if (!fout) return -1;

	int n;
	Pair p;
	cout << "������� ���������� ���: "; cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> p;
		fout << p << endl;
	}

	fout.close();
	return n; // ���������� ���������� ���������� ��������
}

// ����� ����������� ����� � �������
int print_file(string filename)
{
	ifstream fin(filename);
	if (!fin) return -1;

	Pair p;
	int i = 0;

	cout << "���� " << filename << endl;
	while (fin >> p)
	{
		cout << p << endl;
		i++;
	}
	fin.close();
	return i;
}

// �������� �������, ������� ��������
int del_fewer(string filename)
{
	ofstream temp_fout("temp.txt");
	ifstream fin(filename);
	if (!fin) return -1;

	int x;
	double y;
	cout << "������� ����������� x: "; cin >> x;
	cout << "������� ����������� y: "; cin >> y;

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

// ���������� ������ ����� � ������� � �������� ���������
int add_int(string filename)
{
	ofstream temp_fout("temp.txt");
	ifstream fin(filename);
	if (!fin) return -1;

	int x, l;
	cout << "������� ������� x: "; cin >> x;
	cout << "������� ������������ �����: "; cin >> l;

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

// ���������� ������������� ����� � ������� � �������� ���������
int add_double(string filename)
{
	ofstream temp_fout("temp.txt");
	ifstream fin(filename);
	if (!fin) return -1;

	double y, l;
	cout << "������� ������� y: "; cin >> y;
	cout << "������� ������������ �����: "; cin >> l;

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

// ���������� K ������� ����� ������ � �������� �������
int add_file(string filename)
{
	ofstream temp_fout("temp.txt");
	ifstream fin(filename);
	if (!fin) return -1;

	int k, num;
	cout << "������� �����, ����� �������� ����� ��������: "; cin >> num;
	cout << "������� ���������� ����������� ���������: "; cin >> k;

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