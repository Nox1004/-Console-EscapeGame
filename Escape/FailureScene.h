#pragma once

#include "Scene.h"

//
// ���� ȭ���� ��Ÿ���� Ŭ����
//

class FailureScene : public Scene
{
private:
	// Scene��(��) ���� ��ӵ�
	virtual void run() override;

	void failureDraw();
};