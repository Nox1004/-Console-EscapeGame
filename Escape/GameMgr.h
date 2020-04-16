#pragma once

class GameMgr
{
public:
	static GameMgr& instance() {
		static GameMgr *instance = new GameMgr();

		return *instance;
	}

private:
	GameMgr();
};