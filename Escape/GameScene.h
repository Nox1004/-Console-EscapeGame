#pragma once

#include "Scene.h"
#include <vector>

//
// 게임 화면을 나타내는 클래스
// 

class GameScene : public Scene
{
public:
	GameScene() {}

	// Scene을(를) 통해 상속됨
	void run() override;

private:
	void startDraw() const;

	void nextDraw() const;

	void mapDraw() const;

	void moveInput();

	void playerDraw();
};