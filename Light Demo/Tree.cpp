#include "Tree.h"

#include <AssetManagers.h>
#include <SceneManager.h>
#include <d3dUtil.h>

Tree::Tree()
{
	this->pTree = new GraphicsObject_TextureAlpha(ModelManager::Get("Tree01"));
	this->pTree->SetTexture(TextureManager::Get("Tree01"));
	this->pTree->SetMaterial(Colors::Green, Colors::Green, Vect(1.0f, 1.0f, 1.0f));

	Matrix world = Matrix(SCALE, 0.25f, 0.25f, 0.25f) * Matrix(TRANS, 0.0f, -50.0f, 0.0f) * Matrix(ROT_Z, 3.14159f);

	this->pTree->SetWorld(world);

	this->pLight = new MOABEPointLight(Colors::Green);
	this->pLight->SetRange(100.0f);
	this->pLight->SetPosition(world.get(ROW_3));

	Drawable::RegisterToScene3D();
	Collidable::RegisterToScene();

	Collidable::SetCollidableGroup<Tree>();
	Collidable::SetAABBModel(this->pTree->GetModel());
	Collidable::UpdateCollisionData(world);
}

Tree::~Tree()
{
	delete this->pTree;
	delete this->pLight;
}

Tree::Tree(const char* const treeType, const float posX, const float posZ)
{
	this->pTree = new GraphicsObject_TextureAlpha(ModelManager::Get(treeType));
	this->pTree->SetTexture(TextureManager::Get(treeType));
	this->pTree->SetMaterial(0.4f * Colors::Green, 0.6f * Colors::Green, 0.4f * Vect(1.0f, 1.0f, 1.0f));

	Matrix world = Matrix(SCALE, 0.25f, 0.25f, 0.25f) * Matrix(TRANS, posX, -50.0f, posZ) * Matrix(ROT_Z, 3.14159f);

	this->pTree->SetWorld(world);

	this->pLight = new MOABEPointLight(Colors::Green);
	this->pLight->SetRange(100.0f);
	this->pLight->SetPosition(world.get(ROW_3));

	Drawable::RegisterToScene3D();
	Collidable::RegisterToScene();

	Collidable::SetCollidableGroup<Tree>();
	Collidable::SetAABBModel(this->pTree->GetModel());
	Collidable::UpdateCollisionData(world);
}

void Tree::ActivateLight() const
{
	this->pLight->RegisterLight();
}

void Tree::Draw3D()
{
	this->pTree->Render();
}

void Tree::SceneExit()
{
	this->pLight->DeregisterLight();
	Drawable::DeregisterFromScene3D();
	Collidable::DeregisterFromScene();
}

void Tree::Collision(SpaceFrigate* pFrigate)
{
	UNREFERENCED_PARAMETER(pFrigate);
	this->SubmitExit();
}
