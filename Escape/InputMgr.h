#pragma once

#include "Singleton.h"

//
// "�Է°����� Ŭ����"
// 

class InputMgr : public Singleton<InputMgr>
{
	friend class Singleton<InputMgr>;

public:
	enum KeyInput { Up, Down, Left, Right, Enter };

public:
	int getControl();

private:
	InputMgr() { cout << "InputMgr ����\n"; }
	~InputMgr() { cout << "InputMgr �Ҹ�\n"; };
};