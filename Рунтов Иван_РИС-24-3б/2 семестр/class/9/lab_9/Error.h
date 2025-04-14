#pragma once
#include <iostream>
#include <string>
using namespace std;

class Error
{
protected:
	string message;
public:
	Error() { message = "Error"; }
	void what() { cout << endl << message << endl; }
};

class Error_Index_Min : public Error
{
public:
	Error_Index_Min() { message = "Error: Index less than zero"; }
};

class Error_Index_Max : public Error
{
public:
	Error_Index_Max() { message = "Error: Index is greater than max index"; }
};

class Error_Empty_List : public Error
{
public:
	Error_Empty_List() { message = "Error: List is empty"; }
};

class Error_Iterator : public Error
{
public:
	Error_Iterator() { message = "Error: Iteration error"; }
};

class Error_Size : public Error
{
public:
	Error_Size() { message = "Error: Size must be at least 1"; }
};