#include "Campfire.h"

#include "LightFire.h"

#include <Colors.h>
#include <ModelManager.h>
#include <TextureManager.h>

Campfire::Campfire() :
	FireLight(),
	pTexGO(new GraphicsObject_TextureLight(ModelManager::Get("Campfire"))),
	pColGO(new GraphicsObject_Color(ModelManager::Get("Campfire")))
{
	static const Vect& Color1 = 0.5f * Colors::Yellow + 0.5f * Colors::Orange;
	static const Vect& Color2 = 0.5f * Colors::Yellow + 0.5f * Colors::Red;		// Blend Yellow and red

	this->pFireBehaviour = new LightFire(&this->FireLight, Color1, Color2, 2.0f);

	this->FireLight.SetPointLightParams(Vect(0.0f, 0.0f, 0.0f), Vect(0.0f, 0.0f, 0.001f), 100.0f);
	this->FireLight.SetAmbDifSpec(Color1, Color1, 0.5f * Color1);
	this->FireLight.SetBehaviour(this->pFireBehaviour);

	this->pTexGO->SetTexture(TextureManager::Get("Campfire"));
	this->pTexGO->SetMaterial(0.25f * Colors::Brown, 0.6f * Colors::Brown, 0.3f * Colors::White);
	this->pTexGO->SetWorld(Matrix(IDENTITY) * Matrix(SCALE, 0.5f, 0.5f, 0.5f));
	this->pTexGO->SetScale(0.5f);

	this->pColGO->SetColor(Colors::Red);
	this->pColGO->SetWorld(Matrix(IDENTITY) * Matrix(SCALE, 0.5f, 0.5f, 0.5f));
}

Campfire::~Campfire()
{
	delete this->pTexGO;
	delete this->pColGO;
}

void Campfire::Initialize()
{
	// Tell the scene to draw the campfire
	Drawable::RegisterToScene3D();
	this->FireLight.RegisterLight();
	this->pFireBehaviour->StartBehaviour();
}

void Campfire::Draw3D()
{
	this->pTexGO->Render();
	// 5this->pColGO->Render();
}
