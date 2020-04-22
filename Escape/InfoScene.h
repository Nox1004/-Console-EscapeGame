#pragma once

#include "Scene.h"

//
// 정보 화면을 나타내는 클래스
//

class InfoScene : public Scene
{
private:
	// Scene을(를) 통해 상속됨
	virtual void run() override;

	void explanationDraw();

	void checkInput();
};