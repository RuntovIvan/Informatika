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

	virtual void GetEvent(TEvent& event); // �������� �������
	virtual void HandleEvent(TEvent& event); // ���������� �������
	virtual void ClearEvent(TEvent& event); // �������� �������
	virtual int Execute(); // ������� ���� ��������� �������
	int Valid(); // �������� EndState
	void EndExec(); // ��������� ������� ����� ������
};