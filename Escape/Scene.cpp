#include "Scene.h"

void Scene::openScene()
{
	_isActivating = true;

	run();
}

void Scene::closeScene()
{
	_isActivating = false;
}
