#include <iostream>
#include "Tree.h"
using namespace std;

int main()
{
	Tree<int>* tree = new Tree<int>(10);

	cout << tree->get_height() << ' ' << tree->get_width() << endl;

	for (int i = 9; i > 1; i--)
		tree->insert(i);

	cout << tree->get_height() << ' ' << tree->get_width() << endl;

	tree->balance();
	tree->set_coords(1000, 800);
	cout << tree->get_height() << ' ' << tree->get_width() << endl;


	tree->direct_way();
	cout << endl;

	tree->symmetric_way();
	cout << endl;

	tree->reverse_way();
	cout << endl;
	return 0;
}