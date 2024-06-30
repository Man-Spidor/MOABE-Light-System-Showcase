#ifndef FOREST_H
#define FOREST_H

#include <list>

class Tree;

class Forest
{
public:
	Forest() = delete;
	Forest(const Forest& other) = default;
	Forest& operator=(const Forest& other) = default;
	Forest(Forest&& other) = default;
	Forest& operator=(Forest&& other) = default;
	~Forest();

	Forest(const float _forestStartX, const float _forestStartZ, const float _forestEndX, const float _forestEndZ);

	void SpawnForest();

private:
	const char* const privGetRandTree();

	using SceneryAssets = std::list<Tree*>;
	SceneryAssets forestAssets;

	const float forestStartX;
	const float forestStartZ;
	const float forestEndX;
	const float forestEndZ;
};

#endif // FOREST_H
