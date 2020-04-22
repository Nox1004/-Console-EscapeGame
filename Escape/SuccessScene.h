#pragma once

#include "Scene.h"

//
// 성공 화면을 나타내는 클래스
//

class SuccessScene : public Scene
{
public:
	// Scene을(를) 통해 상속됨
	virtual void run() override;

private:
	void successDraw();
};