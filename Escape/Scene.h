#pragma once

#include "Utility.h"

class Scene
{
public:
	virtual void run() = 0;

	virtual ~Scene() { cout << "Scene �Ҹ�\n"; };

protected:
	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }

	int getX() const { return _x; }
	int getY() const { return _y; }

private:
	int _x;
	int _y;
};
