#pragma once

#include "Scene.h"

//
// ���� ȭ���� ��Ÿ���� Ŭ����
//

class InfoScene : public Scene
{
public:
	InfoScene() { };
	~InfoScene() { cout << "InfoScene Scene �Ҹ�\n"; }

	void run() override;

private:
	void explanationDraw();

	void checkInput();
};