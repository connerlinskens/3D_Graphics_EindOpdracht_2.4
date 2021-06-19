#pragma once
#include "Component.h"
#include <glm/glm.hpp>
#include <string>

class ColliderComponent : public Component
{
public:
	ColliderComponent(glm::vec3 colBounds, std::string colTag = "default");
	~ColliderComponent();

	bool debugDraw = true;
	glm::vec3 bounds;
	std::string tag;

	void draw();
};

