#pragma once
#include "Print.h"
#include <string>
#include <iostream>
using namespace std;

class Magazine : public Print
{
protected:
	int pages;
public:
	Magazine();
	Magazine(string N, string A, int P);
	Magazine(const Magazine& m);

	int get_pages();

	void set_pages(int P);

	Magazine& operator=(const Magazine& m);

	void Show() override;
	void Input() override;

	void HandleEvent(const TEvent& e) override;
};