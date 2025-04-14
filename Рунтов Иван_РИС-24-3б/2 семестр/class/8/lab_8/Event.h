#pragma once

const int evNothing = 0; // пустое событие
const int evMessage = 100; // непустое событие
const int cmAdd = 1; // добавить в группу
const int cmDel = 2; // удалить из группы
const int cmGet = 3; // вывести названия всех
const int cmShow = 4; // вывести всю информацию обо всех
const int cmMake = 6; // создать группу
const int cmQuit = 101; // выход

struct TEvent
{
	int what; // тип события: пустое/непустое
	union
	{
		int command; // код команды
		struct
		{
			int message; // команда
			int a; // параметр команды
		};
	};
};