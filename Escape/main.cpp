#include <iostream>
#include "TitleScene.h"
#include "Utility.h"

int main()
{
	int cntidx{ 0 };

	// ������ �迭�� �̿�
	Scene* scene[2];

	scene[0] = new TitleScene;

	scene[cntidx]->run();

	// gameMgr, sceneMgr 2���� �����Ѵ�

	return 0;
}