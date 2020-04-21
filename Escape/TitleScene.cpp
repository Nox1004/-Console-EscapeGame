#include "TitleScene.h"
#include "SceneMgr.h"
#include "InputMgr.h"

TitleScene::TitleScene() : _menuidx{ 0 } { }

void TitleScene::run()
{
	Utility::clean();

	titleDraw();

	menuDraw(_menuidx);

	menuChoose();
}

void TitleScene::titleDraw()
{
	Utility::setColor(Utility::white, Utility::black);
	cout << "\n\n";
	cout << "        &&&&&   &&&    &&&    &    &&&&&   &&&&&  \n";
	cout << "        &      &      &      & &   &    &  &      \n";
	cout << "        &&&&   &&&&   &     &&&&&  &&&&&   &&&&   \n";
	cout << "        &          &  &     &   &  &       &      \n";
	cout << "        &&&&&  &&&&    &&&  &   &  &       &&&&&  \n";
	cout << "\n";
	Utility::setColor(Utility::yellow, Utility::black);
	cout << "	       &&&     &    &     &  &&&&&  \n";
	cout << "	      &       & &   &&   &&  &      \n";
	cout << "	      & &&&  &&&&&  & & & &  &&&&   \n";
	cout << "	      &   &  &   &  &  &  &  &      \n";
	cout << "	       &&&   &   &  &     &  &&&&&  \n";
	cout << "\n";
	Utility::setColor(Utility::white, Utility::black);
}

void TitleScene::menuDraw(int menuidx)
{
	// Ŀ����ġ ����
	setX(20);
	setY(15);

	if (menuidx == 0)
		Utility::setColor(Utility::lightgreen, Utility::black);
	else
		Utility::setColor(Utility::white, Utility::black);

	Utility::gotoxy(getX(), getY());
	cout << "  �� �� �� ��  ";



	if (menuidx == 1)
		Utility::setColor(Utility::lightgreen, Utility::black);
	else
		Utility::setColor(Utility::white, Utility::black);

	Utility::gotoxy(getX(), getY() + 1);
	cout << "  �� �� �� ��  ";



	if (menuidx == 2)
		Utility::setColor(Utility::lightgreen, Utility::black);
	else
		Utility::setColor(Utility::white, Utility::black);

	Utility::gotoxy(getX(), getY() + 2);
	cout << "     �� ��     \n";

	Utility::setColor(Utility::white, Utility::black);
}

void TitleScene::menuChoose()
{
	while (1)
	{
		int input = InputMgr::instance()->getControl();

		switch (input)
		{
		case InputMgr::Up:
			if (_menuidx != 0)
			{
				menuDraw(--_menuidx);
			}
			break;

		case InputMgr::Down:
			if (_menuidx != 2)
			{
				menuDraw(++_menuidx);
			}
			break;

		case InputMgr::Enter:
			menuChoice(_menuidx);
			break;
		}
	}
}

void TitleScene::menuChoice(int menuidx)
{
	if (menuidx == 0)
	{
		// ���ӽ���
		SceneMgr::instance()->changeScene(SceneMgr::Game);
	}
	else if (menuidx == 1)
	{
		// ���������� ��ȯ�ϱ�
		SceneMgr::instance()->changeScene(SceneMgr::Info);
	}
	else
	{
		// ����
		exit(0);
	}
}