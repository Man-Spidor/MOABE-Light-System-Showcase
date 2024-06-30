#include "LightDemoFunctions.h"

#include "CampfireScene.h"

#include <ModelManager.h>
#include <TextureManager.h>

#include <MOABE.h>
#include <SceneManager.h>
#include <TerrainObjectManager.h>
#include <SkyboxObjectManager.h>
#include <ShaderContextManager.h>
#include <SamplerManager.h>

void LightDemoFunctions::GameStart()
{
	// Game Window Device setup
	MOABE::SetWindowName("Light Demo");

	RECT rc;
	GetWindowRect(GetDesktopWindow(), &rc);
	MOABE::SetWidthHeight((rc.right - rc.left) / 2, (rc.bottom - rc.top) / 2);  // 1/4 of the screen

}

void LightDemoFunctions::GameEnd()
{
}

void LightDemoFunctions::LoadAllContent()
{
	// Store all the models, textures, and any other graphics related startups here 

	ModelManager::Load("Frigate", "space_frigate.azul");
	ModelManager::Load("Plane", 5000.0f, 15.0f, 15.0f);
	ModelManager::Load("Campfire", "campfire.azul");

	TextureManager::Load("Frigate", L"space_frigate.tga");
	TextureManager::Load("Campfire", L"campfire_tex1.tga");
	TextureManager::Load("Grass", L"grass.tga");
	TextureManager::Load("Sky", L"skybox_texture.tga");		// Remember to load the skybox texture before loading the skybox!

	TerrainObjectManager::Load("Terrain1", L"../Assets/Textures/HMtest.tga", 5000.0f, 75.0f, -10.0f, 15, 15);
	SkyboxObjectManager::Load("Sky", 3000.0f);

	// Trees
	ModelManager::Load("Tree01", "Scene Assets/tree01.azul");
	ModelManager::Load("Tree02", "Scene Assets/tree02.azul");
	ModelManager::Load("Tree03", "Scene Assets/tree03.azul");
	ModelManager::Load("Tree04", "Scene Assets/tree04.azul");
	ModelManager::Load("Tree05", "Scene Assets/tree05.azul");
	ModelManager::Load("Tree07", "Scene Assets/tree07.azul");
	ModelManager::Load("Tree08", "Scene Assets/tree08.azul");
	TextureManager::Load("Tree01", L"Scene Assets/tree01_fall.tga");
	TextureManager::Load("Tree02", L"Scene Assets/tree02_fall.tga");
	TextureManager::Load("Tree03", L"Scene Assets/tree03_fall.tga");
	TextureManager::Load("Tree04", L"Scene Assets/tree04_fall.tga");
	TextureManager::Load("Tree05", L"Scene Assets/tree05_fall.tga");
	TextureManager::Load("Tree06", L"Scene Assets/tree06_fall.tga");
	TextureManager::Load("Tree07", L"Scene Assets/tree07_fall.tga");
	TextureManager::Load("Tree08", L"Scene Assets/tree08_fall.tga");

	// Uncomment to enable ASync
	// MOABE::EnableAsync();

	// Need to specify the start scene
	SceneManager::SetStartScene(new CampfireScene);

	ShaderContextManager::SetFogData((float)UINT_MAX, (float)UINT_MAX, Vect(0.0f, 0.0f, 0.0f));

}
