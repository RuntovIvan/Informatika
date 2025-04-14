#pragma once
#include "Vector.h"
#include "Event.h"

class Dialog : public Vector
{
protected:
	int EndState;
public:
	Dialog();
	virtual ~Dialog();

	virtual void GetEvent(TEvent& event); // получить событие
	virtual void HandleEvent(TEvent& event); // обработчик события
	virtual void ClearEvent(TEvent& event); // очистить событие
	virtual int Execute(); // главный цикл обработки событий
	int Valid(); // проверка EndState
	void EndExec(); // обработка события конца работы
};