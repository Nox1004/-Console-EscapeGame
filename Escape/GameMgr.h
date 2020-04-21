#pragma once

#include "Singleton.h"
#include "InputMgr.h"
#include <vector>
//
// "게임관리자 클래스"
// 플레이어 로직처리를 담당
//

class GameMgr : public Singleton<GameMgr>
{
	friend class Singleton<GameMgr>;

public:
	// GameScene에서 Map 정보를 얻을 수 있게 함수로 노출시켜준다.
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

	std::pair<int, int> _playerPos;		// 현재 위치값
	std::pair<int, int> _playerPrePos;	// 이전 위치값

	bool _isPlaying;

	int _cntidx;

	const int _rows;
	const int _cols;
};