#include <iostream>
#include "TitleScene.h"
#include "Utility.h"
#include "GameMgr.h"
#include "SceneMgr.h"
#include "InputMgr.h"

SceneMgr *sceneMgr = SceneMgr::instance();

int main()
{
	sceneMgr->run();

	return 0;
}