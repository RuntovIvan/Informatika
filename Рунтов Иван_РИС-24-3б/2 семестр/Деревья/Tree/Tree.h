#pragma once
#include <iostream>
#include <vector>
using namespace std;

template<class T>
class Tree
{
private:
	T data;												// данные
	Tree<T>* parent;									// ссылка на родителя
	Tree<T>* left;										// ссылка на левого потомка
	Tree<T>* right;										// ссылка на правого потомка
	double x;
	double y;

public:

	Tree(T);											// конструктор с параметрами
	Tree();												// конструктор без параметров
	~Tree();											// деструктор

	Tree<T>* minimum();									// нахождение узла с минимальным значением
	Tree<T>* maximum();									// нахождение узла с максимальным значением
	Tree<T>* find(T);									// найти узел по ключу
	Tree<T>* next();									// найти следующий
	Tree<T>* prev();									// найти предыдущий
	void insert(T);										// вставка значения
	void erase(T);										// удаление узла по значению
	void clear();										// удаление дерева
	void balance();										// преобразование в ИСД
	void inOrdertraversal(Tree<T>*, vector<T>&);		// преобразование дерева в список симметричным
	Tree<T>* buildBalancedTree(vector<T>&, int, int);	//построение ИСД

	int get_height();
	int get_width();
	void set_x(double, double);
	void set_y(double, int);
	void set_coords(double, double);

	T get_data();										// получение значения узла дерева
	void replace(T);									// замена значения узла
	void delete_left();									// удаление левого потомка узла
	void delete_right();								// удаление правого потомка узла
	void insert_left(T);								// добавление левого потомка узла
	void insert_right(T);								// добавление правого потомка узла
	void direct_way();									// прямой обход
	void symmetric_way();								// симметричный обход
	void reverse_way();									// обратный обход
	void add_left(Tree<T>*);							// добавление левого узла
	void add_right(Tree<T>*);							//добавление правого узла
};

template<class T>
Tree<T>::Tree(T d)
{
	data = d;
	parent = left = right = nullptr;
}

template<class T>
Tree<T>::Tree()
{
	parent = left = right = nullptr;
}

template<class T>
Tree<T>::~Tree()
{
	//clear();
}

template<class T>
Tree<T>* Tree<T>::minimum()
{
	if (this->left == nullptr) return this;
	else return this->left->minimum();
}

template<class T>
Tree<T>* Tree<T>::maximum()
{
	if (this->right == nullptr) return this;
	else return this->right->maximum();
}

template<class T>
Tree<T>* Tree<T>::find(T key)
{
	if (this->data == key || this == nullptr)
		return this;
	else if (key < this->data)
		return this->left->find(key);
	else
		return this->right->find(key);
}

template<class T>
Tree<T>* Tree<T>::next()
{
	Tree<T>* cur = this;
	if (cur->right != nullptr)
		return cur->right->minimum();

	Tree<T>* p = cur->parent;
	while (p != nullptr && cur == p->right)
	{
		cur = p;
		p = cur->parent;
	}
	return p;
}

template<class T>
Tree<T>* Tree<T>::prev()
{
	Tree<T>* cur = this;
	if (cur->left != nullptr)
		return cur->left->maximun();

	Tree<T>* p = cur->parent;
	while (p != nullptr && cur == p->left)
	{
		cur = p;
		p = cur->parent;
	}
	return p;
}

template<class T>
void Tree<T>::insert(T key)
{
	Tree<T>* tmp = new Tree<T>(key);
	Tree<T>* cur = this;

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

template<class T>
void Tree<T>::erase(T key)
{
	Tree<T>* del = this->find(key);
	if (del == nullptr) return;

	Tree<T>* p = del->parent;
	if (del->left == nullptr && del->right == nullptr) // когда у удаляемого элемента нет потомков
	{
		if (del == p->left)
			p->left = nullptr;
		else
			p->right = nullptr;
		delete del;
		return;
	}

	else if (del->left == nullptr || del->right == nullptr) // когда у удаляемого элемента один потомок
	{
		if (del->left != nullptr)
		{
			if (del == p->left)
				p->left = del->left;
			else
				p->right = del->left;
			del->left->parent = p;
		}
		else if (del->right != nullptr)
		{
			if (del == p->left)
				p->left = del->right;
			else
				p->right = del->right;
			del->right->parent = p;
		}
		delete del;
		return;
	}

	else // когда у удаляемого элемента два потомка
	{
		Tree<T>* dnext = del->next();
		del->data = dnext->data;
		if (dnext = dnext->parent->left)
		{
			dnext->parent->left = dnext->right;
			if (dnext->right != nullptr)
				dnext->right->parent = dnext->parent;
		}
		else
		{
			dnext->parent->right = dnext->right;
			if (dnext->right != nullptr)
				dnext->right->parent = dnext->parent;
		}
		delete dnext;
		return;
	}
}

template<class T>
void Tree<T>::clear()
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

template<class T>
void Tree<T>::balance()
{
	vector<T> vec;
	this->inOrdertraversal(this, vec);
	Tree<T>* balanced_tree = buildBalancedTree(vec, 0, vec.size() - 1);

	//this->clear();
	*this = *balanced_tree;
}

template<class T>
void Tree<T>::inOrdertraversal(Tree<T>* node, vector<T>& vec)
{
	if (node != nullptr)
	{
		inOrdertraversal(node->left, vec);
		vec.push_back(node->data);
		inOrdertraversal(node->right, vec);
	}
}

template<class T>
Tree<T>* Tree<T>::buildBalancedTree(vector<T>& vec, int start, int end)
{
	if (start > end) return nullptr;

	int mid = (start + end) / 2;
	Tree<T>* root = new Tree<T>(vec[mid]);

	root->left = buildBalancedTree(vec, start, mid - 1);
	if (root->left != nullptr)
		root->left->parent = root;

	root->right = buildBalancedTree(vec, mid + 1, end);
	if (root->right != nullptr)
		root->right->parent = root;

	return root;
}

template<class T>
T Tree<T>::get_data()
{
	return this->data;
}

template<class T>
void Tree<T>::replace(T d)
{
	this->data = d;
}

template<class T>
void Tree<T>::delete_left()
{
	this->left->clear();
}

template<class T>
void Tree<T>::delete_right()
{
	this->right->clear();
}

template<class T>
void Tree<T>::insert_left(T d)
{
	this->left->insert(d);
}

template<class T>
void Tree<T>::insert_right(T d)
{
	this->right->insert(d);
}

template<class T>
void Tree<T>::direct_way()
{
	if (this != nullptr)
	{
		cout << this->data << ' ';
		this->left->direct_way();
		this->right->direct_way();
	}
}

template<class T>
void Tree<T>::symmetric_way()
{
	if (this != nullptr)
	{
		this->left->symmetric_way();
		cout << this->data << ' ';
		this->right->symmetric_way();
	}
}

template<class T>
void Tree<T>::reverse_way()
{
	if (this != nullptr)
	{
		this->left->reverse_way();
		this->right->reverse_way();
		cout << this->data << ' ';
	}
}

template<class T>
void Tree<T>::add_left(Tree<T>* node)
{
	if (this->left == nullptr) this->left = node;
}

template<class T>
void Tree<T>::add_right(Tree<T>* node)
{
	if (this->right == nullptr) this->right = node;
}

template<class T>
int Tree<T>::get_height()
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

//template<class T>
//void Tree<T>::count_width(int& maximum, int& minimum, int cur)
//{
//	if (this == nullptr)
//		return;
//
//	this->left->count_width(maximum, minimum, cur - 1);
//
//	if (cur < minimum)
//		minimum = cur;
//	if (cur > maximum)
//		maximum = cur;
//
//	this->right->count_width(maximum, minimum, cur + 1);
//}
//
//template<class T>
//int Tree<T>::get_width()
//{
//	int maximum = 0, minimum = 0;
//	this->count_width(maximum, minimum, 0);
//
//	return abs(minimum) + maximum + 1;
//}

template<class T>
int Tree<T>::get_width()
{
	return 2 * pow(2, this->get_height()) - 1;
}

template<class T>
void Tree<T>::set_x(double min, double max)
{
	if (this == nullptr)
		return;
	this->x = (min + max) / 2;
	this->left->set_x(min, x);
	this->right->set_x(x, max);
}

template<class T>
void Tree<T>::set_y(double window_height, int tree_height)
{
	if (this == nullptr)
		return;

	this->y = (window_height * (2 * this->get_height() - 1)) / (2 * tree_height);
	this->left->set_y(window_height, tree_height);
	this->right->set_y(window_height, tree_height);
}

template<class T>
void Tree<T>::set_coords(double window_width, double window_height)
{
	this->set_x(0, window_width);
	this->set_y(window_height, this->get_height());
}