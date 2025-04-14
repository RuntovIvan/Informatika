#pragma once
#include "Object.h"
#include <string>
#include <iostream>
using namespace std;

class Print : public Object
{
protected:
	string name;
	string author;
public:
	Print();
	Print(string N, string A);
	Print(const Print& p);
	~Print();

	string get_name();
	string get_author();

	void set_name(string N);
	void set_author(string A);

	Print& operator=(const Print& p);

	void Show() override;
	void Input() override;

	void HandleEvent(const TEvent& e) override;
};