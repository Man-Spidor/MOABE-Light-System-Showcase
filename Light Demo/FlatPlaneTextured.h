#ifndef FLATPLANETEXTURED_H
#define FLATPLANETEXTURED_H

#include "GameObject.h"
#include <GraphicsObject_TextureLight.h>

class FlatPlaneTextured : public GameObject
{
public:
	FlatPlaneTextured() = delete;
	FlatPlaneTextured(const FlatPlaneTextured& other) = default;
	FlatPlaneTextured& operator=(const FlatPlaneTextured& other) = default;
	FlatPlaneTextured(FlatPlaneTextured&& other) = default;
	FlatPlaneTextured& operator=(FlatPlaneTextured&& other) = default;
	~FlatPlaneTextured();

	FlatPlaneTextured(const float xScale, const float zScale, const char* const pTexture);

	void Initialize();

	virtual void Draw3D() override;

private:
	GraphicsObject_TextureLight* pModel;
};

#endif // FLATPLANETEXTURED_H
