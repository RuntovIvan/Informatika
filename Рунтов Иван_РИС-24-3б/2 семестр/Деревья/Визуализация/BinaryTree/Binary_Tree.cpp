#include "Binary_Tree.h"
#include "Tree.h"

Binary_Tree::Binary_Tree()
{
	root = nullptr;
}

Binary_Tree::Binary_Tree(double value)
{
	root = new Tree(value);
}

void Binary_Tree::insert(double value)
{
	if (root == nullptr)
		root = new Tree(value);
	else
		root->insert(value);
}

Tree* Binary_Tree::find(double value)
{
	return root->find(value);
}

void Binary_Tree::erase(double value)
{
	if (root != nullptr)
		root = root->erase(value);
}

void Binary_Tree::balance()
{
	if (root != nullptr)
	{
		root = root->balance();
	}
}

void Binary_Tree::clear()
{
	root->clear();
	root = nullptr;
}

void Binary_Tree::set_coords(double window_width, double window_height, double shift_x)
{
	if (root != nullptr)
		root->set_coords(window_width, window_height, shift_x);
}