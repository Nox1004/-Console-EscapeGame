#pragma once

#include "Scene.h"

//
// ���� ȭ���� ��Ÿ���� Ŭ����
//

class SuccessScene : public Scene
{
public:
	// Scene��(��) ���� ��ӵ�
	virtual void run() override;

private:
	void successDraw();
};