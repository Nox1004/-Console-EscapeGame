#pragma once

#include "Utility.h"

class Scene
{
public:
	void openScene();
	void closeScene();

	virtual ~Scene() { };

protected:
	virtual void run() = 0;

	bool getSceneState() const { return _isActivating; }

private:
	bool _isActivating;
};
