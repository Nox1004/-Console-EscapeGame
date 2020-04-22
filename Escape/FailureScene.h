#pragma once

#include "Scene.h"

//
// 실패 화면을 나타내는 클래스
//

class FailureScene : public Scene
{
private:
	// Scene을(를) 통해 상속됨
	virtual void run() override;

	void failureDraw();
};