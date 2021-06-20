#pragma once
#include "Floor.h"
#include <vector>

class MovingFloor : public Floor
{
public:
	MovingFloor(CollisionManager* colMan, glm::vec3 pos, glm::vec3 size, glm::vec4 color, Texture* texture, std::vector<glm::vec3> targets, float moveSpeed = 5.0f, std::string tag = "moving_floor", float texTilesTopHor = 1.0f, float texTilesTopVer = 1.0f, float texTilesSides = 1.0f);
	~MovingFloor();
};

