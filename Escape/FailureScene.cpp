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
	cout << "Ż�⿡";

	Utility::setColor(Utility::red, Utility::black);
	cout << " ����"; 
	
	Utility::setColor(Utility::white, Utility::black);
	cout << "�߽��ϴ�.\n";

	Utility::delay(2);

	int delay = 5;
	for (int i = delay; i > 0; i--) 
	{
		Utility::gotoxy(13, 12);
		cout << i <<"�� �� ����ȭ������ �Ѿ�ϴ�.";
		Utility::delay(1);
	}

	SceneMgr::instance()->changeScene(SceneMgr::Title);
}
