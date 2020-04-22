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
	cout << "Ż�⿡ �����߽��ϴ�.\n";

	Utility::delay(1);

	cout << "1�� �� ����ȭ������ �Ѿ�ϴ�.";

	Utility::delay(1);

	SceneMgr::instance()->changeScene(SceneMgr::Title);
}
