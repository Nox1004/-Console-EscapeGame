#include "FailureScene.h"
#include "SceneMgr.h"
#include "InputMgr.h"

void FailureScene::run()
{
	Utility::clean();

	failureDraw();
}

void FailureScene::failureDraw()
{
	cout << "탈출에 실패했습니다.\n";

	Utility::delay(1);

	cout << "1초 뒤 메인화면으로 넘어갑니다.";

	Utility::delay(1);

	SceneMgr::instance()->changeScene(SceneMgr::Title);
}
