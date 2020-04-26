#include "SceneMgr.h"
#include "TitleScene.h"
#include "InfoScene.h"
#include "GameScene.h"
#include "SuccessScene.h"
#include "FailureScene.h"

SceneMgr::SceneMgr() : _cntidx{0}
{
	system("mode con cols=56 lines=24 | title 탈출게임");

	_scene.push_back(new TitleScene);
	_scene.push_back(new InfoScene);
	_scene.push_back(new GameScene);
	_scene.push_back(new SuccessScene);
	_scene.push_back(new FailureScene);

	CONSOLE_CURSOR_INFO consoleCursor;
	consoleCursor.bVisible = false;
	consoleCursor.dwSize = 1;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleCursor);
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
	// 작동
	_scene[_cntidx]->openScene();
}

void SceneMgr::changeScene(SceneName scene)
{
	// 이전 씬의 작동을 종료.
	_scene[_cntidx]->closeScene();

	_cntidx = static_cast<int>(scene);

	// 변경된 씬을 작동시작
	_scene[_cntidx]->openScene();
}