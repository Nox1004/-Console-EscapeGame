#pragma once

#include "Scene.h"
#include <vector>

//
// ���� ȭ���� ��Ÿ���� Ŭ����
// 

class GameScene : public Scene
{
public:
	GameScene() {}

	// Scene��(��) ���� ��ӵ�
	void run() override;

private:
	void startDraw() const;

	void nextDraw() const;

	void mapDraw() const;

	void moveInput();

	void playerDraw();
};