#include "TitleScene.h"
#include "SceneMgr.h"
#include "InputMgr.h"

TitleScene::TitleScene() : _cntidx{ 0 } { }

void TitleScene::run()
{
	Utility::clean();

	titleDraw();

	menuDraw(_cntidx);

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

void TitleScene::menuDraw(int cntidx)
{
	// Ŀ����ġ ����
	setX(20);
	setY(15);

	if (cntidx == 0)
		Utility::setColor(Utility::lightgreen, Utility::black);
	else
		Utility::setColor(Utility::white, Utility::black);

	Utility::gotoxy(getX(), getY());
	cout << "  �� �� �� ��  ";



	if (cntidx == 1)
		Utility::setColor(Utility::lightgreen, Utility::black);
	else
		Utility::setColor(Utility::white, Utility::black);

	Utility::gotoxy(getX(), getY() + 1);
	cout << "  �� �� �� ��  ";



	if (cntidx == 2)
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
			if (_cntidx != 0)
			{
				menuDraw(--_cntidx);
			}
			break;

		case InputMgr::Down:
			if (_cntidx != 2)
			{
				menuDraw(++_cntidx);
			}
			break;

		case InputMgr::Enter:
			menuChoice(_cntidx);
			break;
		}
	}
}

void TitleScene::menuChoice(int cntidx)
{
	if (_cntidx == 0)
	{
		// ���ӽ���
	}
	else if (_cntidx == 1)
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