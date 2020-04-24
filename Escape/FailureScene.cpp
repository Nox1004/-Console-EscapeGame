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
	Utility::setColor(Utility::white, Utility::black);
	Utility::gotoxy(19, 10);
	cout << "탈출에";

	Utility::setColor(Utility::red, Utility::black);
	cout << " 실패"; 
	
	Utility::setColor(Utility::white, Utility::black);
	cout << "했습니다.\n";

	Utility::delay(2);

	int delay = 5;
	for (int i = delay; i > 0; i--) 
	{
		Utility::gotoxy(13, 12);
		cout << i <<"초 뒤 메인화면으로 넘어갑니다.";
		Utility::delay(1);
	}

	SceneMgr::instance()->changeScene(SceneMgr::Title);
}
