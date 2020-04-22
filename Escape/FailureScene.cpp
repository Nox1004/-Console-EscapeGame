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
	cout << "Ż�⿡ �����߽��ϴ�.\n";

	Utility::delay(1);

	cout << "1�� �� ����ȭ������ �Ѿ�ϴ�.";

	Utility::delay(1);

	SceneMgr::instance()->changeScene(SceneMgr::Title);
}
