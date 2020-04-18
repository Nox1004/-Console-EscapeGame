#pragma once

#include "Scene.h"

//
// 정보 화면을 나타내는 클래스
//

class InfoScene : public Scene
{
public:
	InfoScene() { };
	~InfoScene() { cout << "InfoScene Scene 소멸\n"; }

	void run() override;

private:
	void explanationDraw();

	void checkInput();
};