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
	cout << "                   [ �� �� �� �� �� ]\n";
	
	Utility::setColor(Utility::white, Utility::black);
	cout << "               ���Ͻǿ� ������ �� ���ΰ�..\n";
	cout << "               ���Ͻ��� Ż���Ϸ��� �ϴµ�\n";
	cout << "                 �� ���� �̷η� �Ǿ��־�\n";
	cout << "               Ż���� �������� ���� ������..\n";
	cout << "                          ����!\n";
	cout << "   ���ΰ��� �̷η� �� ���Ͻ��� Ż���� �� ���� ���ΰ�?\n\n";
	
	Utility::setColor(Utility::lightgreen, Utility::black);
	cout << "                      [ �� �� �� ]\n";
	
	Utility::setColor(Utility::white, Utility::black);
	cout << "           �̵� : ��, ��, ��, �� (Ű���� ����Ű)\n\n";

	Utility::setColor(Utility::lightgreen, Utility::black);
	cout << "                     [ �� �� �� �� ] \n";

	Utility::setColor(Utility::white, Utility::black);
	cout << "                1. ��\n";
	cout << "                2. ������ �ʴ� ��\n";
	cout << "                3. ������ �ʴ� �߶� ����\n";
	cout << "                4. ������ �ʴ� ��ź ����\n\n";

	Utility::setColor(Utility::lightgreen, Utility::black);
	cout << "                      [ �� �� �� ]\n";
	Utility::setColor(Utility::white, Utility::black);
	cout << "                        nox1004\n";
	cout << "         ��α� : https://nox1004.tistory.com/ \n\n";
	cout << "         ���͸� ������ Ÿ��Ʋȭ������ �̵��մϴ�.\n";
}

void InfoScene::checkInput()
{
	while (getSceneState())
	{
		int input = InputMgr::instance()->getControl();

		if (input == InputMgr::Enter)
		{
			// Ÿ��Ʋȭ������ �̵�
			SceneMgr::instance()->changeScene(SceneMgr::Title);
		}
	}
}