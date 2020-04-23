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
	map.push_back("10100020100010000100020020001000100000000000000000000001");
	map.push_back("10122010101010110100020010101010100001111111100111111001");
	map.push_back("10000010102010110101000010100010100001000000000100000001");
	map.push_back("11111010101010110001000010122220100001001111111100111111");
	map.push_back("10000020001000112221220010110000000001000000000100111001");
	map.push_back("10111112011122110000000020110000000002000000000100000001");
	map.push_back("10000000000000110000000020111111111121110111111121111111");
	map.push_back("11111111111111110011111110111111111100000000000000000001");
	map.push_back("10000000000000000000000000111111111111111111111111111001");
	map.push_back("10111111111111111111111111110000000000000020000000002001");
	map.push_back("10200000000000000100000000010000000000000020000000000001");
	map.push_back("10100000000100000100000010011111111111100010000000000001");
	map.push_back("10100111010100000100000010010000000000100010000000000001");
	map.push_back("10122210000100000100000010010011111000100010022222222221");
	map.push_back("10100010111100000100000010010000001000100010000111000001");
	map.push_back("10101010000100000100000010010000001000100010000111000001");
	map.push_back("10101011110100000100000010011111101000100010000000000001");
	map.push_back("100010000001000000000000100000000010000000100000000000d1");
	map.push_back("11111111111111111111111111111111111111111111111111111111");

	_map.push_back(map);
	map.clear();
#pragma endregion

	// 함정위치 (1,3)
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

	_playerPos = make_pair(1, 1);
	_playerPrePos = make_pair(1, 1);
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