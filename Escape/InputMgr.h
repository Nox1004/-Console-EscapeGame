#pragma once

#include "Singleton.h"

//
// "입력관리자 클래스"
// 

class InputMgr : public Singleton<InputMgr>
{
	friend class Singleton<InputMgr>;

public:
	enum KeyInput { Up, Down, Left, Right, Enter };

public:
	int getControl();

private:
	InputMgr() { cout << "InputMgr 생성\n"; }
	~InputMgr() { cout << "InputMgr 소멸\n"; };
};