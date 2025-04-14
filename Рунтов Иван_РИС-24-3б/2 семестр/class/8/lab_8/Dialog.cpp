#include "Dialog.h"
#include "Vector.h"
#include "Event.h"
#include "Object.h"
#include <iostream>
#include <string>
using namespace std;

Dialog::Dialog() : Vector()
{
	EndState = 0;
}

Dialog::~Dialog() {}

void Dialog::GetEvent(TEvent& event)
{
	string OpInt = "+-mszq";
	string s, param;

	char code;
	cout << '>';
	cin >> s;
	code = s[0];

	if (OpInt.find(code) >= 0)
	{
		event.what = evMessage;
		switch (code)
		{
		case 'm': event.message = cmMake; break;
		case '+': event.message = cmAdd; break;
		case '-': event.message = cmDel; break;
		case 's': event.message = cmShow; break;
		case 'z': event.message = cmGet; break;
		case 'q': event.message = cmQuit; break;
		}

		if (s.length() > 1)
		{
			param = s.substr(1, s.length() - 1);
			int A = atoi(param.c_str());
			event.a = A;
		}
	}
	else
		event.what = evNothing;
}

void Dialog::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmMake:
			size = event.a;
			cur = 0;
			beg = new Object* [size];
			ClearEvent(event);
			break;
		case cmAdd:
			Add();
			ClearEvent(event);
			break;
		case cmDel:
			Del();
			ClearEvent(event);
			break;
		case cmGet:
			Vector::HandleEvent(event);
			ClearEvent(event);
			break;
		case cmShow:
			Show();
			ClearEvent(event);
			break;
		case cmQuit:
			EndExec();
			ClearEvent(event);
			break;
		}
	}
}

void Dialog::ClearEvent(TEvent& event)
{
	event.what = evNothing;
}

int Dialog::Valid()
{
	if (EndState == 0) return 0;
	return 1;
}

void Dialog::EndExec()
{
	EndState = 1;
}

int Dialog::Execute()
{
	TEvent event;
	do {
		EndState = 0;
		GetEvent(event);
		HandleEvent(event);
	} while (!Valid());
	return EndState;
}