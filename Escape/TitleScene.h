#pragma once

#include "Scene.h"

class TitleScene : public Scene
{
public:
	TitleScene();

	void run() override;

private:
	void titleDraw();
	void menuDraw();

private:
	int _cntidx;
	int _x; // Ä¿¼­ xÁÂÇ¥
	int _y; // Ä¿¼­ yÁÂÇ¥
};