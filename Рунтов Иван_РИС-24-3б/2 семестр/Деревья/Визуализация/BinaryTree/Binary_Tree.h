#pragma once
#include "Tree.h"

struct Binary_Tree
{
	Tree* root;

	Binary_Tree();
	Binary_Tree(double value);
	void insert(double value);
	Tree* find(double value);
	void erase(double value);
	void balance();
	void clear();
	void set_coords(double window_width, double window_height, double shift_x);
};