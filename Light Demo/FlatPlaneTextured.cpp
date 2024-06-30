#include "FlatPlaneTextured.h"
#include <AssetManagers.h>
#include <SceneManager.h>
#include <Colors.h>

FlatPlaneTextured::~FlatPlaneTextured()
{
	delete this->pModel;
}

FlatPlaneTextured::FlatPlaneTextured(const float xScale, const float zScale, const char* const pTexture)
{
	this->pModel = new GraphicsObject_TextureLight(ModelManager::Get("Plane"));
	this->pModel->SetTexture(TextureManager::Get(pTexture));
	this->pModel->SetMaterial(Colors::Gray, Colors::Gray, Vect(1.0f, 1.0f, 1.0f));

	Matrix scale = Matrix(SCALE, xScale, 1.0f, zScale);
	Matrix world = Matrix(IDENTITY) * scale;
	this->pModel->SetWorld(world);
}

void FlatPlaneTextured::Initialize()
{
	Drawable::RegisterToScene3D();
}

void FlatPlaneTextured::Draw3D()
{
	this->pModel->Render();
}
