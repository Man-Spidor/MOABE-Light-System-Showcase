#include "CampfireScene.h"

#include "LightDayNight.h"

#include <Colors.h>
#include <MOABEDirectionalLight.h>

#include <TextureManager.h>
#include <SkyboxObjectManager.h>
#include <TerrainObjectManager.h>

#include <SceneManager.h>

void CampfireScene::Initialize()
{
	this->DebugController.Initialize();

	// You Can Initialize Any Scene Assets Here
	this->pCampFire = new Campfire();
	this->pCampFire->Initialize();
	this->pTree1 = new Tree("Tree03", 0.0f, 100.0f);
	this->pTree2 = new Tree("Tree04", -75.0f, 50.0f);
	this->pTree3 = new Tree("Tree02", 100.0f, 100.0f);
	this->pTree4 = new Tree("Tree07", 175.0f, 50.0f);

	// Set the Ambient, Diffuse And Specular To Desired Colors
	// Can also comment this out to see default light color
	this->DayLight.SetAmbDifSpec(0.5f * Colors::OrangeRed, 0.5f * Colors::OrangeRed, 0.2f * Colors::Yellow);
	this->NightLight.SetAmbDifSpec(0.2f * Colors::MidnightBlue, 0.2f * Colors::MidnightBlue, 0.2f * Colors::White);
	
	// Set the behaviour to the desired behaviour
	// Note, there is no need to worry about cleanup, it is all done by the SceneLight
	this->DayLight.SetBehaviour(new LightDayNight(&this->DayLight, 5.0f));
	this->NightLight.SetBehaviour(new LightDayNight(&this->NightLight, 5.0f));
	
	// Make Sure To Redirect Your Light Wherever you want it
	this->DayLight.SetDirectionalLightParams(Vect(0.0f, -1.0f, 0.0f));
	this->NightLight.SetDirectionalLightParams(Vect(0.0f, 1.0f, 0.0f));

	// Finally Register your light to begin rendering it
	this->NightLight.RegisterLight();
	this->DayLight.RegisterLight();

	// Set The SkyBox as follows
	Scene::SetSkyBox(SkyboxObjectManager::Get("Sky"));
	
	// Set The Terrain as follows
	Scene::SetTerrain(TerrainObjectManager::Get("Terrain1"));
	
	// Need To Also Set the Following Parameters
	Scene::SetTerrainTexture(TextureManager::Get("Grass"));
	Scene::SetTerrainMaterial(0.2f * Colors::ForestGreen, 0.4f * Colors::ForestGreen, 0.7f * Vect(1, 1, 1));
	Scene::SetTerrainWorld(Matrix(IDENTITY));

	// This simply sets the Scene's God Cam as the Current Camera
	// And activates its controls
	// Uncomment to control camera
	// SceneManager::SwitchDebugMode();

	// Sets the Camera Position to a pretty angle
	Scene::SetCurrCameraPos(Vect(0.0f, 1.0f, 0.0f), Vect(80.0f, 50.0f, -150.0f), Vect(0.0f, 0.0f, 0.0f));
	Scene::UpdateCurrCamera();
}

void CampfireScene::SceneEnd()
{
	// Cleanup any scene assets here
	delete this->pCampFire;

	delete this->pTree1;
	delete this->pTree2;
	delete this->pTree3;
	delete this->pTree4;
}
