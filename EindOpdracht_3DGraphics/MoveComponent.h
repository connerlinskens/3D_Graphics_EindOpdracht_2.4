#pragma once
#include "Component.h"
#include <glm/glm.hpp>
#include <vector>

class MoveComponent :  public Component
{
protected:
	float moveSpeed;
	std::vector<glm::vec3> targets;
	int currentTarget;
	bool flip;

	glm::vec3 directionToTarget(glm::vec3);
	float distanceToTarget(glm::vec3);

public:
	MoveComponent();
	~MoveComponent();
};

