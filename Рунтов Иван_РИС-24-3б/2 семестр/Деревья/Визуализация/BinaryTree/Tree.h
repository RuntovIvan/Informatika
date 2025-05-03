#pragma once
#include <iostream>
#include <vector>

struct Tree
{
	double data;													// ������
	Tree* parent;													// ������ �� ��������
	Tree* left;														// ������ �� ������ �������
	Tree* right;													// ������ �� ������� �������
	float x;
	float y;

	Tree(double value);													// ����������� � �����������
	Tree();															// ����������� ��� ����������
	~Tree();														// ����������

	Tree* minimum();												// ���������� ���� � ����������� ���������
	Tree* maximum();												// ���������� ���� � ������������ ���������
	Tree* find(double value);												// ����� ���� �� �����
	Tree* next();													// ����� ���������
	Tree* prev();													// ����� ����������
	void insert(double value);											// ������� ��������
	Tree* erase(double value);											// �������� ���� �� ��������
	void clear();													// �������� ������
	Tree* balance();												// �������������� � ���
	void inOrdertraversal(std::vector<double>& vec);					// �������������� ������ � ������ ������������ �������
	Tree* buildBalancedTree(const std::vector<double>& vec, int start, int end);	//���������� ���

	int get_height();
	void set_x(double min, double max);
	void set_y(double window_height, int tree_height, int cur);
	void set_coords(double window_width, double window_height, double shift_x);
};