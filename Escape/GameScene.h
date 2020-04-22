#pragma once

#include "Scene.h"
#include <vector>

//
// 게임 화면을 나타내는 클래스
// 

class GameScene : public Scene
{
public:
	GameScene();

private:
	// Scene을(를) 통해 상속됨
	virtual void run() override;

	void startDraw();
	void eventActivate();
	void mapDraw(int idx) const;
	void playerDraw();

	void playerMoveDraw();

	void moveInput();

	static void invisibleWallEventDraw();
	void nextFloorEventDraw();
	void fallTrapEventDraw();
	void boomTrapEventDraw();

private:
	bool _isActivatedEvent;
};