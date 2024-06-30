#ifndef CAMPFIRE_H
#define CAMPFIRE_H

#include <GameObject.h>
#include <MOABEPointLight.h>

#include <GraphicObject_Color.h>
#include <GraphicsObject_TextureLight.h>

class Campfire : public GameObject
{
public:
	Campfire();
	Campfire(const Campfire& other) = default;
	Campfire& operator=(const Campfire& other) = default;
	Campfire(Campfire&& other) = default;
	Campfire& operator=(Campfire&& other) = default;
	~Campfire();

	void Initialize();

	virtual void Draw3D() override;

private:
	MOABEPointLight FireLight;
	LightBehaviourCommand* pFireBehaviour;
	GraphicsObject_TextureLight* pTexGO;
	GraphicsObject_Color* pColGO;
};

#endif // CAMPFIRE_H
