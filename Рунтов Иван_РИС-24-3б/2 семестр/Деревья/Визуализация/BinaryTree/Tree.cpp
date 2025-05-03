#include "Tree.h"

Tree::Tree(double d)
{
	data = d;
	parent = left = right = nullptr;
	x = y = 0;
}

Tree::Tree()
{
	parent = left = right = nullptr;
	x = y = 0;
}

Tree::~Tree()
{
	//clear();
}

Tree* Tree::minimum()
{
	if (this == nullptr || this->left == nullptr) return this;
	return this->left->minimum();
}

Tree* Tree::maximum()
{
	if (this->right == nullptr) return this;
	else return this->right->maximum();
}

Tree* Tree::find(double key)
{
	if (this == nullptr || this->data == key)
		return this;
	else if (key < this->data)
		return this->left->find(key);
	else
		return this->right->find(key);
}

Tree* Tree::next()
{
	Tree* cur = this;
	if (cur->right != nullptr)
		return cur->right->minimum();

	Tree* p = cur->parent;
	while (p != nullptr && cur == p->right)
	{
		cur = p;
		p = p->parent;
	}
	return p;
}

Tree* Tree::prev()
{
	Tree* cur = this;
	if (cur->left != nullptr)
		return cur->left->maximum();

	Tree* p = cur->parent;
	while (p != nullptr && cur == p->left)
	{
		cur = p;
		p = p->parent;
	}
	return p;
}

void Tree::insert(double key)
{
	Tree* tmp = new Tree(key);
	Tree* cur = this;

	while (cur != nullptr)
		if (key < cur->data)
			if (cur->left != nullptr)
				cur = cur->left;
			else
			{
				tmp->parent = cur;
				cur->left = tmp;
				return;
			}
		else if (key > cur->data)
			if (cur->right != nullptr)
				cur = cur->right;
			else
			{
				tmp->parent = cur;
				cur->right = tmp;
				return;
			}
		else if (key == cur->data)
		{
			delete tmp;
			return;
		}
}

Tree* Tree::erase(double key)
{
	Tree* root = this;
	Tree* del = this->find(key);
	if (del == nullptr) return root;

	Tree* p = del->parent;
	if (del->left == nullptr && del->right == nullptr) // когда у удаляемого элемента нет потомков
	{
		if (del->parent != nullptr)
		{
			if (del == p->left)
				p->left = nullptr;
			else
				p->right = nullptr;
		}
		else
		{
			delete del;
			return nullptr;
		}
		delete del;
	}

	else if (del->left == nullptr || del->right == nullptr) // когда у удаляемого элемента один потомок
	{
		Tree* child;
		if (del->left == nullptr)
			child = del->right;
		else if (del->right == nullptr)
			child = del->left;
		
		if (del->parent != nullptr)
		{
			if (del->parent->left == del)
				del->parent->left = child;
			else
				del->parent->right = child;
			child->parent = del->parent;
		}
		else
		{
			root = child;
			child->parent = nullptr;
		}
		delete del;
	}

	else // когда у удаляемого элемента два потомка
	{
		Tree* dnext = del->next();
		del->data = dnext->data;
		if (dnext == dnext->parent->left)
		{
			dnext->parent->left = dnext->right;
			if (dnext->right != nullptr)
				dnext->right->parent = dnext->parent;
		}
		else if (dnext == dnext->parent->right)
		{
			dnext->parent->right = dnext->right;
			if (dnext->right != nullptr)
				dnext->right->parent = dnext->parent;
		}
		delete dnext;
	}

	return root;
}

void Tree::clear()
{
	if (this != nullptr)
	{
		this->left->clear();
		this->right->clear();
		delete this;
		return;
	}
	else return;
}

Tree* Tree::balance()
{
	std::vector<double> vec;
	this->inOrdertraversal(vec);
	Tree* balanced_tree = buildBalancedTree(vec, 0, vec.size() - 1);
	this->clear();
	return balanced_tree;
	//this = balanced_tree;
}

void Tree::inOrdertraversal(std::vector<double>& vec)
{
	if (this != nullptr)
	{
		this->left->inOrdertraversal(vec);
		vec.push_back(this->data);
		this->right->inOrdertraversal(vec);
	}
}

Tree* Tree::buildBalancedTree(const std::vector<double>& vec, int start, int end)
{
	if (start > end) return nullptr;

	int mid = (start + end) / 2;
	Tree* root = new Tree(vec[mid]);

	root->left = buildBalancedTree(vec, start, mid - 1);
	if (root->left != nullptr)
		root->left->parent = root;

	root->right = buildBalancedTree(vec, mid + 1, end);
	if (root->right != nullptr)
		root->right->parent = root;

	return root;
}

int Tree::get_height()
{
	if (this == nullptr)
		return 0;
	else if (this->left == nullptr && this->right == nullptr)
		return 1;
	else if (this->left->get_height() > this->right->get_height())
		return this->left->get_height() + 1;
	else
		return this->right->get_height() + 1;
}

void Tree::set_x(double min, double max)
{
	if (this == nullptr)
		return;

	this->x = (min + max) / 2;
	this->left->set_x(min, x);
	this->right->set_x(x, max);
}

void Tree::set_y(double window_height, int tree_height, int cur)
{
	if (this == nullptr)
		return;
	
	this->y = (window_height * (2 * cur - 1)) / (2 * tree_height);
	this->left->set_y(window_height, tree_height, cur + 1);
	this->right->set_y(window_height, tree_height, cur + 1);
}

void Tree::set_coords(double window_width, double window_height, double shift_x)
{
	if (this == nullptr)
		return;

	this->set_x(shift_x, window_width - shift_x);
	this->set_y(window_height, this->get_height(), 1);
}