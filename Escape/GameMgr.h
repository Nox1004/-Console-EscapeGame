#pragma once

#include "Singleton.h"

//
// "게임관리자 클래스"
// 게임제작에 들어가기 전까지는 아무기능없다.
//

class GameMgr : public Singleton<GameMgr>
{
	friend class Singleton<GameMgr>;

private:
	GameMgr() { cout << "GameMgr 생성\n"; }
	~GameMgr() { cout << "GameMgr 소멸\n"; }
};