#pragma once

#include "Scene.h"

class TitleScene : public Scene
{
public:
	TitleScene();
	~TitleScene() { cout << "TitleScene �Ҹ�\n"; }
	void run() override;

private:
	void titleDraw();
	void menuDraw();

private:
	int _cntidx;
	int _x; // Ŀ�� x��ǥ
	int _y; // Ŀ�� y��ǥ
};