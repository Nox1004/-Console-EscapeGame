#pragma once

#include "Singleton.h"

//
// "�� ������ Ŭ����" 
// �� ���ۿ� ���� �������� �ƹ���ɾ���.
//

class SceneMgr : public Singleton<SceneMgr>
{
	friend class Singleton<SceneMgr>;

private:
	SceneMgr() { cout << "SceneMgr ����\n"; }
	~SceneMgr() { cout << "SceneMgr �Ҹ�\n"; };
};