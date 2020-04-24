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
	Utility::textSleep("��", 200); Utility::textSleep("ȣ", 200); Utility::textSleep("!", 200);
	Utility::textSleep("! ", 400); Utility::textSleep("��", 200); Utility::textSleep("��", 200);
	Utility::textSleep("��", 200); Utility::textSleep("��", 200); Utility::textSleep("!", 200);
	Utility::textSleep("!", 200); Utility::textSleep("!", 200); Utility::textSleep("!", 200);
	
	Utility::setColor(Utility::white, Utility::black);
	Utility::gotoxy(2, 12);
	cout << "�賭�ߴ� ���Ϲ̷θ� ��� ������ Ż�⿡";

	Utility::setColor(Utility::lightgreen, Utility::black);
	cout << " ����";

	Utility::setColor(Utility::white, Utility::black);
	cout << "�߽��ϴ�.";

	Utility::delay(2);

	int delay = 5;
	for (int i = delay; i > 0; i--)
	{
		Utility::gotoxy(13, 14);
		cout << i << "�� �� ����ȭ������ �Ѿ�ϴ�.";
		Utility::delay(1);
	}

	SceneMgr::instance()->changeScene(SceneMgr::Title);
}
