#include <iostream>
#include "TitleScene.h"
#include "Utility.h"

int main()
{
	int cntidx{ 0 };

	// 포인터 배열을 이용
	Scene* scene[2];

	scene[0] = new TitleScene;

	scene[cntidx]->run();

	// gameMgr, sceneMgr 2개를 제작한다

	return 0;
}