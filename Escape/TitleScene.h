#pragma once

#include "Scene.h"

//
// 타이틀화면을 나타내는 클래스
//

class TitleScene : public Scene
{
public:
	TitleScene();
	~TitleScene() { cout << "TitleScene ¼Ò¸ê\n"; }
	
	void run() override;

private:
	void titleDraw();
	void menuDraw();
	void menuChoice();
	
private:
	int _cntidx;
};
