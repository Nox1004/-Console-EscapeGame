#include "SceneMgr.h"
#include "TitleScene.h"
#include "InfoScene.h"
#include "GameScene.h"

SceneMgr::SceneMgr() : _cntidx{0}
{
	system("mode con cols=56 lines=24 | title �׽�Ʈ");

	_scene.push_back(new TitleScene);
	_scene.push_back(new InfoScene);
	_scene.push_back(new GameScene);

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
	run(_cntidx);
}

void SceneMgr::changeScene(SceneName scene)
{
	_cntidx = static_cast<int>(scene);

	// ����� ȭ�� �۵���Ű��
	_scene[_cntidx]->run();
}

void SceneMgr::run(int idx)
{
	_scene[idx]->run();
}