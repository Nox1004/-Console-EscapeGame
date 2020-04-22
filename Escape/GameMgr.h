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
	enum EventType { None, InvisibleWall, FallTrap, BoomTrap, NextFloor };

public:
	void gameStart();
	void gameEnd();

	bool checkPlayerMoving(InputMgr::KeyInput key);
	void playerMove(InputMgr::KeyInput key);

	int getMapSize() const { return static_cast<int>(_map.size()); }
	int getidx() const { return _cntidx; }
	void setIdx(int idx) { _cntidx = idx; }

	// GameScene���� Map ������ ���� �� �ְ� �Լ��� ��������ش�.
	vector<string> getMap(int idx) const { return _map[idx]; }

	EventType getPlayerEvent() const { return _playerEvent; }

	int getPlayerPosX() const { return _playerPos.second; }
	int getPlayerPosY() const { return _playerPos.first; }

	int getPlayerPrePosX() const { return _playerPrePos.second; }
	int getPlayerPrePosY() const { return _playerPrePos.first; }

	int getMaxRow() const { return _rows; }
	int getMaxCol() const { return _cols; }

	bool getPlaying() const { return _isPlaying; }

private:
	GameMgr();
	~GameMgr() { }

	void checkNextEvent(bool* result, char ch);


private:
	std::vector<vector<string>> _map;

	EventType _playerEvent;

	std::pair<int, int> _playerPos;		// ���� ��ġ��
	std::pair<int, int> _playerPrePos;	// ���� ��ġ��

	bool _isPlaying;

	int _cntidx;

	const int _rows;
	const int _cols;
};