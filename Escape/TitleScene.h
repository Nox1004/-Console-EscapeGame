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

	void menuDraw(int cntidx);

	void menuChoose();

	void menuChoice(int cntidx);

private:
	int _cntidx;
};
