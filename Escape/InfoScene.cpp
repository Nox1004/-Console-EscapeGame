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
	cout << "��� �������ž�!";
	cout << "\n\n";
	cout << "        �׷���";
}

void InfoScene::checkInput()
{
	while (1)
	{
		int input = InputMgr::instance()->getControl();

		if (input == InputMgr::Enter)
		{
			// Ÿ��Ʋȭ������ �̵�
			SceneMgr::instance()->changeScene(SceneMgr::Title);
		}
	}
}