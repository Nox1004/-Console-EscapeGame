#pragma once

#include "Scene.h"

//
// Ÿ��Ʋ ȭ���� ��Ÿ���� Ŭ����
//

class TitleScene : public Scene
{
public:
	TitleScene();
	~TitleScene() { cout << "title Scene �Ҹ�\n"; }

	void run() override;

private:
	void titleDraw();

	void menuDraw(int menuidx);

	void menuChoose();

	void menuChoice(int menuidx);

private:
	int _menuidx;
};
