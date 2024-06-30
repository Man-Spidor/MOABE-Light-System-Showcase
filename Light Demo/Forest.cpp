#include "Forest.h"
#include  "Tree.h"

Forest::~Forest()
{
	for (auto asset : this->forestAssets) {
		delete asset;
	}
}

Forest::Forest(const float _forestStartX, const float _forestStartZ, const float _forestEndX, const float _forestEndZ) :
	forestAssets(),
	forestStartX(_forestStartX),
	forestStartZ(_forestStartZ),
	forestEndX(_forestEndX),
	forestEndZ(_forestEndZ)
{
}

void Forest::SpawnForest()
{
	const float stepSize = 400.0f;

	for (float currSpawnPosX = this->forestStartX; currSpawnPosX < this->forestEndX; currSpawnPosX += stepSize) {
		for (float currSpawnPosZ = this->forestStartZ; currSpawnPosZ < this->forestEndZ; currSpawnPosZ += stepSize) {
			this->forestAssets.push_back(new Tree(this->privGetRandTree(), currSpawnPosX, currSpawnPosZ));
			this->forestAssets.back()->ActivateLight();
		}
	}
	Trace::out("Tree Count[%d]\n", this->forestAssets.size());
}

const char* const Forest::privGetRandTree()
{
	switch (rand() % 8) {
	case 0:
		return "Tree01";
	case 1:
		return "Tree02";
	case 2:
		return "Tree03";
	case 3:
		return "Tree04";
	case 4:
		return "Tree05";
	case 5:
		return "Tree05";
	case 6:
		return "Tree07";
	case 7:
		return "Tree08";
	default:
		Trace::out("What?\n");
		assert(0);
	}
	return nullptr;
}
