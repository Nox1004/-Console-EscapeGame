#include <iostream>
#include "TitleScene.h"
#include "Utility.h"
#include "GameMgr.h"
#include "InputMgr.h"

int main()
{
	int cntidx{ 0 };

	InputMgr::instance();
	GameMgr::instance();

	// 포인터 배열을 이용
	Scene* scene[2];

	Utility::setColor(Utility::lightgreen, 0);
	cout << "TEST입니다\n";

	Utility::setColor(Utility::white, 0);
	return 0;
}