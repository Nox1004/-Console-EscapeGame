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

	Utility::setColor(Utility::lightgreen, Utility::black);
	Utility::gotoxy(18, 8);
	Utility::textSleep("야", 200); Utility::textSleep("호", 200); Utility::textSleep("!", 200);
	Utility::textSleep("! ", 400); Utility::textSleep("지", 200); Utility::textSleep("상", 200);
	Utility::textSleep("이", 200); Utility::textSleep("다", 200); Utility::textSleep("!", 200);
	Utility::textSleep("!", 200); Utility::textSleep("!", 200); Utility::textSleep("!", 200);
	
	Utility::setColor(Utility::white, Utility::black);
	Utility::gotoxy(2, 12);
	cout << "험난했던 지하미로를 모두 돌파해 탈출에";

	Utility::setColor(Utility::lightgreen, Utility::black);
	cout << " 성공";

	Utility::setColor(Utility::white, Utility::black);
	cout << "했습니다.";

	Utility::delay(2);

	int delay = 5;
	for (int i = delay; i > 0; i--)
	{
		Utility::gotoxy(13, 14);
		cout << i << "초 뒤 메인화면으로 넘어갑니다.";
		Utility::delay(1);
	}

	SceneMgr::instance()->changeScene(SceneMgr::Title);
}
