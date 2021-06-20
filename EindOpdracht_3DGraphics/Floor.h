#pragma once
#include "GameObject.h"
#include "CollisionManager.h"
#include "Texture.h"

class Floor : public GameObject
{
public:
	Floor(CollisionManager* colMan, glm::vec3 pos, glm::vec3 size, glm::vec4 color, Texture* texture, std::string tag = "floor", float texTilesTop = 1.0f, float texTilesSides = 1.0f);
	~Floor();
};

