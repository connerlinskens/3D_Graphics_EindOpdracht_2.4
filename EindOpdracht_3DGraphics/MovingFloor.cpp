#include "MovingFloor.h"
#include "Components.h"

MovingFloor::MovingFloor(CollisionManager* colMan, glm::vec3 pos, glm::vec3 size, glm::vec4 color, Texture* texture, std::vector<glm::vec3> targets, float moveSpeed, std::string tag, float texTilesTopHor, float texTilesTopVer, float texTilesSides)
: Floor::Floor(colMan, pos, size, color, texture, tag, texTilesTopHor, texTilesTopVer, texTilesSides)
{
	this->addComponent(new FloorMoveComponent(targets, moveSpeed));
}

MovingFloor::~MovingFloor()
{
}
