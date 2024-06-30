#ifndef CAMPFIRESCENE_H
#define CAMPFIRESCENE_H

#include <Scene.h>
#include <MOABEDirectionalLight.h>

#include "Tree.h"
#include "Campfire.h"
#include "Controller.h"

class CampfireScene : public Scene
{
public:
	CampfireScene() = default;
	CampfireScene(const CampfireScene& other) = default;
	CampfireScene& operator=(const CampfireScene& other) = default;
	CampfireScene(CampfireScene&& other) = default;
	CampfireScene& operator=(CampfireScene&& other) = default;
	~CampfireScene() = default;

	virtual void Initialize() override;
	virtual void SceneEnd() override;

private:
	Controller DebugController;

	MOABEDirectionalLight DayLight;
	MOABEDirectionalLight NightLight;
	Tree* pTree1;
	Tree* pTree2;
	Tree* pTree3;
	Tree* pTree4;
	Campfire* pCampFire;
};

#endif // CAMPFIRESCENE_H
