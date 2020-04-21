#include "GameScene.h"
#include "GameMgr.h"
#include "InputMgr.h"

void GameScene::run()
{
	Utility::clean();

	startDraw();

	mapDraw();

	playerDraw();

	moveInput();
}

void GameScene::startDraw() const
{
}

void GameScene::nextDraw() const
{
	Utility::clean();
}

void GameScene::mapDraw() const
{
	std::vector<string> temp = GameMgr::instance()->getMap(0);

	for (int i = 0; i < temp.size(); i++)
	{
		for (int j = 0; j < temp[i].size(); j++)
		{
			// 벽
			if (temp[i][j] == '1')
			{
				Utility::setColor(Utility::brown, Utility::brown);
				cout << " ";
			}
			// 목적지
			else if (temp[i][j] == 'd')
			{
				Utility::setColor(Utility::lightred, Utility::lightred);
				cout << " ";
			}
			// 그 외 오브젝트들
			else
			{
				Utility::setColor(Utility::white, Utility::black);
				cout << temp[i][j];
			}
		}
		cout << '\n';
	}
}

void GameScene::moveInput()
{
	auto gameMgr = GameMgr::instance();

	while (1)
	{
		int value = InputMgr::instance()->getControl();
		auto input = static_cast<InputMgr::KeyInput>(value);

		if (gameMgr->checkPlayerMoving(input))
		{
			gameMgr->playerMove(input);
			playerDraw();
		}
	}
}

void GameScene::playerDraw()
{
	auto gameMgr = GameMgr::instance();

	Utility::setColor(Utility::black, Utility::black);
	Utility::gotoxy(gameMgr->getPlayerPrePosX(), gameMgr->getPlayerPrePosY());
	cout << " ";

	Utility::setColor(Utility::lightcyan, Utility::black);
	Utility::gotoxy(gameMgr->getPlayerPosX(), gameMgr->getPlayerPosY());
	cout << "@";
}