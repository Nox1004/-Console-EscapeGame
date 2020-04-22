#include "GameMgr.h"

GameMgr::GameMgr() : _cntidx(0), _rows(20), _cols(56)
{
	// map 열-56 행-20 으로 생각하고 제작한다.
	vector<string> map;

	// 0 - 움직일 수 있는 공간
	// 1 - 벽						--> 이쪽으로 이동불가 
	// 2 - 보이지 않는 벽			--> 이쪽으로 이동불가
	// 3 - 보이지 않는 추락 함정	--> 층수 - 1 함정위치값에 추락
	// 4 - 보이지 않는 폭탄 함정	--> 탈출실패
	// d - 목적지
#pragma region 첫번째 층

	map.push_back("11111111111111111111111111111111111111111111111111111111");
	map.push_back("10010000000000000000000000000000000000000000000000000001");
	map.push_back("12410000000000000000000000000000000000000000000000000001");
	map.push_back("10000000000000000000000000000000000000000000000000000001");
	map.push_back("11100000000000000000000000000000000000000000000000000001");
	map.push_back("11110000000000000000000000000000000000000000000000000001");
	map.push_back("10000000000000000000000000000000000000000000000000000001");
	map.push_back("10000000000000000000000000000000000000000000000000000001");
	map.push_back("10000000000000000000000000000000000000000000000000000001");
	map.push_back("10000000000000000000000000000000000000000000000000000001");
	map.push_back("10000000000000000000000000000000000000000000000000000001");
	map.push_back("10000000000000000000000000000000000000000000000000000001");
	map.push_back("10000000000000000000000000000000000000000000000000000001");
	map.push_back("10000000000000000000000000000000000000000000000000000001");
	map.push_back("10000000000000000000000000000000000000000000000000000001");
	map.push_back("10000000000000000000000000000000000000000000000000000001");
	map.push_back("10000000000000000000000000000000000000000000000000000001");
	map.push_back("10000000000000000000000000000000000000000000000000000001");
	map.push_back("100000000000000000000000000000000000000000000000000000d1");
	map.push_back("11111111111111111111111111111111111111111111111111111111");

	_map.push_back(map);
	map.clear();
#pragma endregion

#pragma region 두번째 층
	map.push_back("11111111111111111111111111111111111111111111111111111111");
	map.push_back("1d010000000000000000000000000000000000000000000000000001");
	map.push_back("12010000000000000000000000000000000000000000000000000001");
	map.push_back("10003000000000000000000000000000000000000000000000000001");
	map.push_back("11100000000000000000000000000000000000000000000000000001");
	map.push_back("11110000000000000000000000000000000000000000000000000001");
	map.push_back("10000000000000000000000000000000000000000000000000000001");
	map.push_back("10000000000000000000000000000000000000000000000000000001");
	map.push_back("10000000000000000000000000000000000000000000000000000001");
	map.push_back("10000000000000000000000000000000000000000000000000000001");
	map.push_back("10000000000000000000000000000000000000000000000000000001");
	map.push_back("10000000000000000000000000000000000000000000000000000001");
	map.push_back("10000000000000000000000000000000000000000000000000000001");
	map.push_back("10000000000000000000000000000000000000000000000000000001");
	map.push_back("10000000000000000000000000000000000000000000000000000001");
	map.push_back("10000000000000000000000000000000000000000000000000000001");
	map.push_back("10000000000000000000000000000000000000000000000000000001");
	map.push_back("10000000000000000000000000000000000000000000000000021111");
	map.push_back("10000000000000000000000000000000000000000000000000000001");
	map.push_back("11111111111111111111111111111111111111111111111111111111");

	_map.push_back(map);
	map.clear();
#pragma endregion
}

void GameMgr::gameStart()
{
	_cntidx = 0;
	_playerEvent = None;

	_isPlaying = true;

	_playerPos = make_pair(1, 1);
	_playerPrePos = make_pair(1, 1);
}

void GameMgr::gameEnd()
{
	_isPlaying = false;
}

//
// 플레이어가 이동할 수 있는 공간인지 판별하는 함수
// 이동이 불가능하면 false를 반환. 가능하면 true를 반환
//
bool GameMgr::checkPlayerMoving(InputMgr::KeyInput key)
{
	bool result = false;

	switch (key)
	{
	case InputMgr::KeyInput::Left: 
		{
			auto ctemp = _map[_cntidx][getPlayerPosY()][getPlayerPosX()-1];
			
			checkNextEvent(&result, ctemp);
		}
		break;

	case InputMgr::KeyInput::Right:
		{
			auto ctemp = _map[_cntidx][getPlayerPosY()][getPlayerPosX()+1];
			
			checkNextEvent(&result, ctemp);
		}
		break;

	case InputMgr::KeyInput::Up:
		{
			auto ctemp = _map[_cntidx][getPlayerPosY() - 1][getPlayerPosX()];
			
			checkNextEvent(&result, ctemp);
		}
		break;

	case InputMgr::KeyInput::Down:
		{
			auto ctemp = _map[_cntidx][getPlayerPosY() + 1][getPlayerPosX()];
			
			checkNextEvent(&result, ctemp);
		}
		break;
	}

	return result;
}

//
// 플레이어 이동처리
// 게임 씬에서 호출하고 있다.
//
void GameMgr::playerMove(InputMgr::KeyInput key)
{
	_playerPrePos = _playerPos;

	switch (key)
	{
	case InputMgr::Up:
		_playerPos.first--;
		break;
	case InputMgr::Down:
		_playerPos.first++;
		break;
	case InputMgr::Left:
		_playerPos.second--;
		break;
	case InputMgr::Right:
		_playerPos.second++;
		break;
	}
}

//
// checkPlayerMoving에서 호출하는 함수
// event 설정 및 bool 값을 변경시켜준다.
// 
void GameMgr::checkNextEvent(bool *isMoving, char ch)
{
	if (ch == '0')
	{
		*isMoving = true;
		_playerEvent = None;
	}
	else if (ch == '2')
	{
		*isMoving = false;
		_playerEvent = InvisibleWall;
	}
	else if (ch == '3')
	{
		*isMoving = true;
		_playerEvent = FallTrap;
	}
	else if (ch == '4')
	{
		*isMoving = true;
		_playerEvent = BoomTrap;
	}
	else if (ch == 'd')
	{
		*isMoving = true;
		_playerEvent = NextFloor;
	}
}