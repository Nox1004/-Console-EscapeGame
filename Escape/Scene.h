#pragma once

#include "Utility.h"

class Scene
{
public:
	virtual void run() = 0;
	
	virtual ~Scene() { cout << "Scene �Ҹ�\n"; };
};