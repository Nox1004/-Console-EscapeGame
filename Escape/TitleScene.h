#pragma once

#include "Scene.h"

//
// 타이틀 화면을 나타내는 클래스
//

class TitleScene : public Scene
{
public:
	TitleScene();
	~TitleScene() { cout << "title Scene 소멸\n"; }

	void run() override;

private:
	void titleDraw();

	void menuDraw(int menuidx);

	void menuChoose();

	void menuChoice(int menuidx);

private:
	int _menuidx;
};
