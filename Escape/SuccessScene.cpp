#include "SuccessScene.h"
#include "SceneMgr.h"
#include "InputMgr.h"

void SuccessScene::run()
{
	Utility::clean();

	successDraw();
}

void SuccessScene::successDraw()
{
	cout << "탈출에 성공했습니다.\n";

	Utility::delay(1);

	cout << "1초 뒤 메인화면으로 넘어갑니다.";

	Utility::delay(1);

	SceneMgr::instance()->changeScene(SceneMgr::Title);
}
