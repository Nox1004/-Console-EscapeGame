#pragma once

#include "Singleton.h"
#include "InputMgr.h"
#include <vector>
//
// "���Ӱ����� Ŭ����"
// �÷��̾� ����ó���� ���
//

class GameMgr : public Singleton<GameMgr>
{
	friend class Singleton<GameMgr>;

public:
	// GameScene���� Map ������ ���� �� �ְ� �Լ��� ��������ش�.
	vector<string> getMap(int idx) const { return _map[idx]; }

	bool checkPlayerMoving(InputMgr::KeyInput key);
	void playerMove(InputMgr::KeyInput key);

	int getPlayerPosX() const { return _playerPos.second; }
	int getPlayerPosY() const { return _playerPos.first; }

	int getPlayerPrePosX() const { return _playerPrePos.second; }
	int getPlayerPrePosY() const { return _playerPrePos.first; }

	int getMaxRow() const { return _rows; }
	int getMaxCol() const { return _cols; }

private:
	GameMgr();
	~GameMgr() { }

private:
	std::vector<vector<string>> _map;

	std::pair<int, int> _playerPos;		// ���� ��ġ��
	std::pair<int, int> _playerPrePos;	// ���� ��ġ��

	bool _isPlaying;

	int _cntidx;

	const int _rows;
	const int _cols;
};