#pragma once

#include "Scene.h"

//
// 타이틀 화면을 나타내는 클래스
//

class TitleScene : public Scene
{
public:
	TitleScene();

private:	
	// Scene을(를) 통해 상속됨
	virtual void run() override;

	void titleDraw() const;

	void menuDraw(int menuidx);

	void menuChoose();

	void menuChoice(int menuidx) const;

private:
	int _menuidx;
};
