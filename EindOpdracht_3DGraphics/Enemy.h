#pragma once
#include "GameObject.h"
#include "ObjModel.h"
#include "CollisionManager.h"
#include <vector>

class Enemy : public GameObject
{
public:
	Enemy(CollisionManager* colMan, glm::vec3 pos, ObjModel* model, glm::vec3 colBounds, std::vector<glm::vec3> targets, float moveSpeed, std::string tag = "enemy");
	~Enemy();
};

