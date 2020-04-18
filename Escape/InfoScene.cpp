#include "InfoScene.h"
#include "SceneMgr.h"
#include "inputMgr.h"

void InfoScene::run()
{
	Utility::clean();

	explanationDraw();

	checkInput();
}

void InfoScene::explanationDraw()
{
	cout << "어디서 찍히느거야!";
	cout << "\n\n";
	cout << "        그래라";
}

void InfoScene::checkInput()
{
	while (1)
	{
		int input = InputMgr::instance()->getControl();

		if (input == InputMgr::Enter)
		{
			// 타이틀화면으로 이동
			SceneMgr::instance()->changeScene(SceneMgr::Title);
		}
	}
}