#pragma once
#include "Component.h"
#include <glm/glm.hpp>
#include <string>

class CollisionManager;

class ColliderComponent : public Component
{
public:
	ColliderComponent(CollisionManager* colManager, glm::vec3 colBounds, std::string colTag = "default");
	~ColliderComponent();

	bool debugDraw = true;
	glm::vec3 bounds;
	std::string tag;
	void (*onCollision)(ColliderComponent* collider);

	void draw();
};

