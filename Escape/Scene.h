#pragma once

#include "Utility.h"

class Scene
{
public:
	virtual void run() = 0;
	
	virtual ~Scene() { cout << "Scene ¼Ò¸ê\n"; };
	
protected:
	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }
	
private:
	int _x;
	int _y;
};
