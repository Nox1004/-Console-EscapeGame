#pragma once

#include "Scene.h"

//
// ���� ȭ���� ��Ÿ���� Ŭ����
//

class InfoScene : public Scene
{
private:
	// Scene��(��) ���� ��ӵ�
	virtual void run() override;

	void explanationDraw();

	void checkInput();
};