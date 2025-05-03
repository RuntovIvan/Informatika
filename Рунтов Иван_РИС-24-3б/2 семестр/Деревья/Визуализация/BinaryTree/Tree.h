#pragma once
#include <iostream>
#include <vector>

struct Tree
{
	double data;													// данные
	Tree* parent;													// ссылка на родителя
	Tree* left;														// ссылка на левого потомка
	Tree* right;													// ссылка на правого потомка
	float x;
	float y;

	Tree(double value);													// конструктор с параметрами
	Tree();															// конструктор без параметров
	~Tree();														// деструктор

	Tree* minimum();												// нахождение узла с минимальным значением
	Tree* maximum();												// нахождение узла с максимальным значением
	Tree* find(double value);												// найти узел по ключу
	Tree* next();													// найти следующий
	Tree* prev();													// найти предыдущий
	void insert(double value);											// вставка значения
	Tree* erase(double value);											// удаление узла по значению
	void clear();													// удаление дерева
	Tree* balance();												// преобразование в ИСД
	void inOrdertraversal(std::vector<double>& vec);					// преобразование дерева в список симметричным обходом
	Tree* buildBalancedTree(const std::vector<double>& vec, int start, int end);	//построение ИСД

	int get_height();
	void set_x(double min, double max);
	void set_y(double window_height, int tree_height, int cur);
	void set_coords(double window_width, double window_height, double shift_x);
};