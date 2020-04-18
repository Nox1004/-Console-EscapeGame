#include "SceneMgr.h"
#include "TitleScene.h"
#include "InfoScene.h"

SceneMgr::SceneMgr() : _cntidx{0}
{
	system("mode con cols=56 lines=24 | title 테스트");

	_scene.push_back(new TitleScene);
	_scene.push_back(new InfoScene);
}

SceneMgr::~SceneMgr()
{
	while (_scene.size())
	{
		auto pScene = _scene[_scene.size() - 1];
		_scene.pop_back();

		delete pScene;
	}
}

void SceneMgr::run()
{
	run(_cntidx);
}

void SceneMgr::changeScene(SceneName scene)
{
	_cntidx = static_cast<int>(scene);

	// 변경된 화면작동
	_scene[_cntidx]->run();
}

void SceneMgr::run(int idx)
{
	_scene[idx]->run();
}