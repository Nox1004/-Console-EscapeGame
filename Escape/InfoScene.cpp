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
	cout << '\n';
	Utility::setColor(Utility::lightgreen, Utility::black);
	cout << "                   [ 게 임 이 야 기 ]\n";
	
	Utility::setColor(Utility::white, Utility::black);
	cout << "               지하실에 갇히게 된 주인공..\n";
	cout << "               지하실을 탈출하려고 하는데\n";
	cout << "                 각 층은 미로로 되어있어\n";
	cout << "               탈출이 생각보다 쉽지 않은데..\n";
	cout << "                          과연!\n";
	cout << "   주인공은 미로로 된 지하실을 탈출할 수 있을 것인가?\n\n";
	
	Utility::setColor(Utility::lightgreen, Utility::black);
	cout << "                      [ 조 작 법 ]\n";
	
	Utility::setColor(Utility::white, Utility::black);
	cout << "           이동 : ↑, ←, ↓, → (키보드 방향키)\n\n";

	Utility::setColor(Utility::lightgreen, Utility::black);
	cout << "                     [ 미 로 설 명 ] \n";

	Utility::setColor(Utility::white, Utility::black);
	cout << "                1. 벽\n";
	cout << "                2. 보이지 않는 벽\n";
	cout << "                3. 보이지 않는 추락 함정\n";
	cout << "                4. 보이지 않는 폭탄 함정\n\n";

	Utility::setColor(Utility::lightgreen, Utility::black);
	cout << "                      [ 개 발 자 ]\n";
	Utility::setColor(Utility::white, Utility::black);
	cout << "                        nox1004\n";
	cout << "         블로그 : https://nox1004.tistory.com/ \n\n";
	cout << "         엔터를 누르면 타이틀화면으로 이동합니다.\n";
}

void InfoScene::checkInput()
{
	while (getSceneState())
	{
		int input = InputMgr::instance()->getControl();

		if (input == InputMgr::Enter)
		{
			// 타이틀화면으로 이동
			SceneMgr::instance()->changeScene(SceneMgr::Title);
		}
	}
}