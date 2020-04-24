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

			// 미로 탈출에 성공!
			if (cntFloor == gameMgr->getMapSize()-1)
			{
				SceneMgr::instance()->changeScene(SceneMgr::Success);
			}
			// 다음층으로
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

			// 플레이어가 이동할 수 있는지 판별
			if (gameMgr->checkPlayerMoving(input))
			{
				// 플레이어 좌표값 변경
				gameMgr->playerMove(input);

				// 콘솔창 플레이어 이동
				playerMoveDraw();

				// event 작동
				eventActivate();
			}
			else
			{
				// 플레이어 이벤트가 보이지 않는 벽과의 충돌일 때, 작동
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
// 보이지 않는 벽 이벤트 발생했을 때 호출 함수
// 쓰레드를 병행해서 사용하기 위해서 정적함수로 선언 및 정의함.
// 
void GameScene::invisibleWallEventDraw()
{
	if (!_invisibleEventAct)
	{
		_invisibleEventAct = true;
		Utility::gotoxy(13, 21);
		Utility::setColor(Utility::lightgreen, Utility::black);
		cout << " '여기로는 이동할 수 없군.. ' ";

		Utility::delay(0.85f, &_invisibleEventAct);

		Utility::gotoxy(13, 21);
		Utility::setColor(Utility::black, Utility::black);
		cout << " '여기로는 이동할 수 없군.. ' ";
	}
}

//
// 다음층으로 이동할 때 나타나는 텍스트 연출
//
void GameScene::nextFloorEventDraw()
{
	_isActivatedEvent = true;

	Utility::clean();
	Utility::setColor(Utility::lightgreen, Utility::black);
	Utility::gotoxy(17, 15);
	Utility::textSleep("좋", 200); Utility::textSleep("아", 200); Utility::textSleep("!", 400);
	Utility::textSleep(" 다", 200); Utility::textSleep("음", 200); Utility::textSleep(" 층", 400);
	Utility::textSleep("으", 200); Utility::textSleep("로", 200); Utility::textSleep("!", 200);
	Utility::textSleep("!", 200); Utility::textSleep("!", 500);

	_isActivatedEvent = false;
}

//
// 추락함정으로 나타나는 텍스트 연출
//
void GameScene::fallTrapEventDraw()
{
	// 이벤트 작동을 true로 전환
	_isActivatedEvent = true;

	// 쓰레드로 동작하고 있는 invisibleWallEventDraw 함수를 종료시키기
	_invisibleEventAct = false;
	Utility::delay(0.2f);

	Utility::gotoxy(19, 21);
	Utility::setColor(Utility::yellow, Utility::black);
	cout << "[추락 함정 작동]";

	Utility::delay(2);
	Utility::clean();
	Utility::setColor(Utility::lightgreen, Utility::black);
	Utility::gotoxy(24, 15);
	Utility::textSleep("으", 100); Utility::textSleep("아", 100); Utility::textSleep("악", 100);
	Utility::textSleep("~", 100);

	// 이벤트 작동을 false로 전환
	_isActivatedEvent = false;
}

//
// 폭탄함정으로 나타나는 텍스트 연출
//
void GameScene::boomTrapEventDraw()
{
	auto gameMgr = GameMgr::instance();

	// 이벤트 작동
	_isActivatedEvent = true;
	
	_invisibleEventAct = false;
	Utility::delay(0.2f);

	Utility::gotoxy(19, 21);
	Utility::setColor(Utility::yellow, Utility::black);
	cout << "[폭탄 함정 작동]";

	Utility::delay(2);
	Utility::setColor(Utility::lightred, Utility::black);
	Utility::gotoxy(gameMgr->getPlayerPosX(), gameMgr->getPlayerPosY());
	cout << "*";

	Utility::delay(2);
}