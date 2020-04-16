#pragma once

#include "Singleton.h"

//
// "씬 관리자 클래스" 
// 씬 제작에 들어가기 전까지는 아무기능없다.
//

class SceneMgr : public Singleton<SceneMgr>
{
	friend class Singleton<SceneMgr>;

private:
	SceneMgr() { cout << "SceneMgr 생성\n"; }
	~SceneMgr() { cout << "SceneMgr 소멸\n"; };
};