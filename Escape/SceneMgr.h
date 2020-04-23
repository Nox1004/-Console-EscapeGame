#pragma once

#include "Singleton.h"
#include "Scene.h"
#include <vector>

class SceneMgr : public Singleton<SceneMgr>
{
	friend class Singleton<SceneMgr>;

public:
	enum SceneName { Title = 0, Info, Game, Success, Failure };

public:
	void changeScene(SceneName scene);

	void run();

private:
	SceneMgr();
	~SceneMgr();

private:
	std::vector<Scene *> _scene;

	int _cntidx;
};