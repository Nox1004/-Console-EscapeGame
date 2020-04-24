#include "GameScene.h"
#include "GameMgr.h"
#include "SceneMgr.h"
#include "InputMgr.h"
#include <thread>

bool GameScene::_invisibleEventAct = false;

GameScene::GameScene() : _isActivatedEvent(false) { }

void GameScene::run()
{
	startDraw();

	Utility::clean();

	mapDraw(GameMgr::instance()->getidx());

	playerDraw();

	moveInput();
}

void GameScene::startDraw()
{
	_isActivatedEvent = true;

	_isActivatedEvent = false;
}

void GameScene::eventActivate()
{
	auto gameMgr = GameMgr::instance();
	auto eventT = gameMgr->getPlayerEvent();

	switch (eventT)
	{
	case GameMgr::InvisibleWall:
		{
			thread t1(invisibleWallEventDraw);

			t1.detach();
		}
		break;
	case GameMgr::FallTrap:
		{
			int cntFloor = gameMgr->getidx();

			fallTrapEventDraw();

			mapDraw(--cntFloor);

			playerDraw();
		}
		break;
	case GameMgr::BoomTrap:
		{
			boomTrapEventDraw();

			SceneMgr::instance()->changeScene(SceneMgr::Failure);
		}
		break;
	case GameMgr::NextFloor:
		{
			int cntFloor = gameMgr->getidx();

			// �̷� Ż�⿡ ����!
			if (cntFloor == gameMgr->getMapSize()-1)
			{
				SceneMgr::instance()->changeScene(SceneMgr::Success);
			}
			// ����������
			else
			{
				nextFloorEventDraw();

				mapDraw(++cntFloor);

				playerDraw();
			}
		}
		break;
	}
}

void GameScene::mapDraw(int idx) const
{
	Utility::clean();

	GameMgr::instance()->setIdx(idx);
	std::vector<string> temp = GameMgr::instance()->getMap(idx);

	for (int i = 0; i < temp.size(); i++)
	{
		for (int j = 0; j < temp[i].size(); j++)
		{
			// ��
			if (temp[i][j] == '1')
			{
				Utility::setColor(Utility::brown, Utility::brown);
				cout << " ";
			}
			// ������
			else if (temp[i][j] == 'd')
			{
				Utility::setColor(Utility::lightred, Utility::lightred);
				cout << " ";
			}
			// �� �� ������Ʈ��
			else
			{
				Utility::setColor(Utility::black, Utility::black);
				cout << temp[i][j];
			}
		}
		cout << '\n';
	}
}

void GameScene::moveInput()
{
	auto gameMgr = GameMgr::instance();

	while (getSceneState())
	{
		int value = InputMgr::instance()->getControl();

		if (!_isActivatedEvent) 
		{
			auto input = static_cast<InputMgr::KeyInput>(value);

			// �÷��̾ �̵��� �� �ִ��� �Ǻ�
			if (gameMgr->checkPlayerMoving(input))
			{
				// �÷��̾� ��ǥ�� ����
				gameMgr->playerMove(input);

				// �ܼ�â �÷��̾� �̵�
				playerMoveDraw();

				// event �۵�
				eventActivate();
			}
			else
			{
				// �÷��̾� �̺�Ʈ�� ������ �ʴ� ������ �浹�� ��, �۵�
				if (gameMgr->getPlayerEvent() 
					== GameMgr::EventType::InvisibleWall)
					eventActivate();
			}
		}
	}
}

void GameScene::playerDraw()
{
	auto gameMgr = GameMgr::instance();

	Utility::setColor(Utility::lightcyan, Utility::black);
	Utility::gotoxy(gameMgr->getPlayerPosX(), gameMgr->getPlayerPosY());
	cout << "@";
}

void GameScene::playerMoveDraw()
{
	auto gameMgr = GameMgr::instance();

	Utility::setColor(Utility::black, Utility::black);
	Utility::gotoxy(gameMgr->getPlayerPrePosX(), gameMgr->getPlayerPrePosY());
	cout << " ";

	playerDraw();
}

//
// ������ �ʴ� �� �̺�Ʈ �߻����� �� ȣ�� �Լ�
// �����带 �����ؼ� ����ϱ� ���ؼ� �����Լ��� ���� �� ������.
// 
void GameScene::invisibleWallEventDraw()
{
	if (!_invisibleEventAct)
	{
		_invisibleEventAct = true;
		Utility::gotoxy(13, 21);
		Utility::setColor(Utility::lightgreen, Utility::black);
		cout << " '����δ� �̵��� �� ����.. ' ";

		Utility::delay(0.85f, &_invisibleEventAct);

		Utility::gotoxy(13, 21);
		Utility::setColor(Utility::black, Utility::black);
		cout << " '����δ� �̵��� �� ����.. ' ";
	}
}

//
// ���������� �̵��� �� ��Ÿ���� �ؽ�Ʈ ����
//
void GameScene::nextFloorEventDraw()
{
	_isActivatedEvent = true;

	Utility::clean();
	Utility::setColor(Utility::lightgreen, Utility::black);
	Utility::gotoxy(17, 15);
	Utility::textSleep("��", 200); Utility::textSleep("��", 200); Utility::textSleep("!", 400);
	Utility::textSleep(" ��", 200); Utility::textSleep("��", 200); Utility::textSleep(" ��", 400);
	Utility::textSleep("��", 200); Utility::textSleep("��", 200); Utility::textSleep("!", 200);
	Utility::textSleep("!", 200); Utility::textSleep("!", 500);

	_isActivatedEvent = false;
}

//
// �߶��������� ��Ÿ���� �ؽ�Ʈ ����
//
void GameScene::fallTrapEventDraw()
{
	// �̺�Ʈ �۵��� true�� ��ȯ
	_isActivatedEvent = true;

	// ������� �����ϰ� �ִ� invisibleWallEventDraw �Լ��� �����Ű��
	_invisibleEventAct = false;
	Utility::delay(0.2f);

	Utility::gotoxy(19, 21);
	Utility::setColor(Utility::yellow, Utility::black);
	cout << "[�߶� ���� �۵�]";

	Utility::delay(2);
	Utility::clean();
	Utility::setColor(Utility::lightgreen, Utility::black);
	Utility::gotoxy(24, 15);
	Utility::textSleep("��", 100); Utility::textSleep("��", 100); Utility::textSleep("��", 100);
	Utility::textSleep("~", 100);

	// �̺�Ʈ �۵��� false�� ��ȯ
	_isActivatedEvent = false;
}

//
// ��ź�������� ��Ÿ���� �ؽ�Ʈ ����
//
void GameScene::boomTrapEventDraw()
{
	auto gameMgr = GameMgr::instance();

	// �̺�Ʈ �۵�
	_isActivatedEvent = true;
	
	_invisibleEventAct = false;
	Utility::delay(0.2f);

	Utility::gotoxy(19, 21);
	Utility::setColor(Utility::yellow, Utility::black);
	cout << "[��ź ���� �۵�]";

	Utility::delay(2);
	Utility::setColor(Utility::lightred, Utility::black);
	Utility::gotoxy(gameMgr->getPlayerPosX(), gameMgr->getPlayerPosY());
	cout << "*";

	Utility::delay(2);
}