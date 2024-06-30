#ifndef TREE_H
#define TREE_H

#include <GameObject.h>
#include <MOABEPointLight.h>
#include <GraphicsObject_TextureAlpha.h>

class SpaceFrigate;

class Tree : public GameObject
{
public:
	Tree();
	Tree(const Tree& other) = default;
	Tree& operator=(const Tree& other) = default;
	Tree(Tree&& other) = default;
	Tree& operator=(Tree&& other) = default;
	~Tree();

	Tree(const char* const treeType, const float posX, const float posY);

	void ActivateLight() const;

	virtual void Draw3D() override;

	virtual void SceneExit() override;

	void Collision(SpaceFrigate* pFrigate);

private:
	MOABEPointLight* pLight;
	GraphicsObject_TextureAlpha* pTree;
};

#endif // TREE_Hx
