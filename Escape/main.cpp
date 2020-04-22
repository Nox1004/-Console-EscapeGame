#include <iostream>
#include "TitleScene.h"
#include "Utility.h"
#include "GameMgr.h"
#include "SceneMgr.h"
#include "InputMgr.h"
#include <thread>

SceneMgr *sceneMgr = SceneMgr::instance();

int main()
{
	sceneMgr->run();

	return 0;
}