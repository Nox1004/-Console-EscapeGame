#include "GameMgr.h"

GameMgr::GameMgr() : _cntidx(0), _rows(20), _cols(56)
{
	// map ��-56 ��-20 ���� �����ϰ� �����Ѵ�.
	vector<string> map;

	// 0 - ������ �� �ִ� ����
	// 1 - ��						--> �������� �̵��Ұ� 
	// 2 - ������ �ʴ� ��			--> �������� �̵��Ұ�
	// 3 - ������ �ʴ� �߶� ����	--> ���� - 1 ������ġ���� �߶�
	// 4 - ������ �ʴ� ��ź ����	--> Ż�����
	// d - ������
#pragma region ù��° ��

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

#pragma region �ι�° ��
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
// �÷��̾ �̵��� �� �ִ� �������� �Ǻ��ϴ� �Լ�
// �̵��� �Ұ����ϸ� false�� ��ȯ. �����ϸ� true�� ��ȯ
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
// �÷��̾� �̵�ó��
// ���� ������ ȣ���ϰ� �ִ�.
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
// checkPlayerMoving���� ȣ���ϴ� �Լ�
// event ���� �� bool ���� ��������ش�.
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