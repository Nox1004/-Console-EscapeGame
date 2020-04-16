#pragma once

#include "Singleton.h"

//
// "���Ӱ����� Ŭ����"
// �������ۿ� ���� �������� �ƹ���ɾ���.
//

class GameMgr : public Singleton<GameMgr>
{
	friend class Singleton<GameMgr>;

private:
	GameMgr() { cout << "GameMgr ����\n"; }
	~GameMgr() { cout << "GameMgr �Ҹ�\n"; }
};