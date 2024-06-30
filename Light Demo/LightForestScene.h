#ifndef LIGHTFORESTSCENE_H
#define LIGHTFORESTSCENE_H

#include <Scene.h>

#include "Forest.h"
#include "Controller.h"
#include "SpaceFrigate.h"
#include "FlatPlaneTextured.h"

class LightForestScene : public Scene
{
public:
	LightForestScene() = default;
	LightForestScene(const LightForestScene& other) = default;
	LightForestScene& operator=(const LightForestScene& other) = default;
	LightForestScene(LightForestScene&& other) = default;
	LightForestScene& operator=(LightForestScene&& other) = default;
	~LightForestScene() = default;

	virtual void Initialize() override;
	virtual void SceneEnd() override;

private:
	Controller DebugController;

	MOABEDirectionalLight* pLight;
	FlatPlaneTextured* pPlane;
	SpaceFrigate* pFrigate;
	Forest* pForest;
};

#endif // LIGHTFORESTSCENE_H
