#ifndef SPACEFRIGATE_H
#define SPACEFRIGATE_H

#include <GameObject.h>

#include <PerspectiveCamera.h>
#include <GraphicsObject_TextureLight.h>

class Tree;

class SpaceFrigate : public GameObject
{
	static constexpr float MOVE_SPEED = 200.0f;
	static constexpr float ROT_ANGLE = 1.5f;

public:
	SpaceFrigate();
	SpaceFrigate(const SpaceFrigate& other) = default;
	SpaceFrigate& operator=(const SpaceFrigate& other) = default;
	SpaceFrigate(SpaceFrigate&& other) = default;
	SpaceFrigate& operator=(SpaceFrigate&& other) = default;
	~SpaceFrigate();

	void Initialize();

	virtual void Update() override;
	virtual void Draw3D() override;

	/// Seperate Key Pressed Input because camera switching should only be possible 
	/// when the space frigate is in the scene.
	virtual void KeyPressed(JAZUL_KEY key);

	void Collision(Tree* pTree);

private:
	PerspectiveCamera FrigateCam;

	Matrix RotTrans;

	GraphicsObject_TextureLight* pGO;
};

#endif // SPACEFRIGATE_H
