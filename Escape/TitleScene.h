#pragma once

#include "Scene.h"

//
// Ÿ��Ʋ ȭ���� ��Ÿ���� Ŭ����
//

class TitleScene : public Scene
{
public:
	TitleScene();

private:	
	// Scene��(��) ���� ��ӵ�
	virtual void run() override;

	void titleDraw() const;

	void menuDraw(int menuidx);

	void menuChoose();

	void menuChoice(int menuidx) const;

private:
	int _menuidx;
};
