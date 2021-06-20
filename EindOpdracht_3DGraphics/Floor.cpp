#include "Floor.h"
#include "Components.h"

Floor::Floor(CollisionManager* colMan, glm::vec3 pos, glm::vec3 size, glm::vec4 color, Texture* texture, std::string tag, float texTilesTop, float texTilesSides)
{
	this->position = pos;
	this->addComponent(new CubeComponent(size, color, texture, texTilesTop, texTilesSides));
	this->addComponent(new ColliderComponent(colMan, size, tag));
}

Floor::~Floor()
{
}
