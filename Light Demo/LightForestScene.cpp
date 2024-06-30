#include "LightForestScene.h"

#include "Tree.h"

#include <MOABEDirectionalLight.h>

#include <Colors.h>
#include <SceneManager.h>

void LightForestScene::Initialize()
{
	this->DebugController.Initialize();

	this->pLight = new MOABEDirectionalLight(Colors::ForestGreen);
	this->pLight->SetDirectionalLightParams(Vect(0, -1, 0));
	this->pLight->RegisterLight();

	this->pPlane = new FlatPlaneTextured(1.0f, 1.0f, "Grass");
	this->pPlane->Initialize();

	this->pForest = new Forest(-2000.0f, -2000.0f, 2000.0f, 2000.0f);
	this->pForest->SpawnForest();

	this->pFrigate = new SpaceFrigate();
	this->pFrigate->Initialize();

	SetCollisionPair<SpaceFrigate, Tree>();
	
	SceneManager::GetCurrScene().SetDefaultCameraAsCurr();
}

void LightForestScene::SceneEnd()
{
	delete this->pLight;
	delete this->pPlane;
	delete this->pForest;
	delete this->pFrigate;
}
