#pragma once

#include "Scene.h"
#include <vector>

//
// ���� ȭ���� ��Ÿ���� Ŭ����
// 

class GameScene : public Scene
{
public:
	GameScene();

private:
	// Scene��(��) ���� ��ӵ�
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