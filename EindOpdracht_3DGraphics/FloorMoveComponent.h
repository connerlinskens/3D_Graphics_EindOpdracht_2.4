#pragma once
#include "Component.h"
#include <glm/glm.hpp>
#include <vector>
#include "GameObject.h"

class FloorMoveComponent : public Component
{
private:
	float moveSpeed;
	std::vector<glm::vec3> targets;
	int currentTarget;

	bool flip;
	float childRemoveTime;
	float childRemoveTimer;

	glm::vec3 directionToTarget(glm::vec3);
	float distanceToTarget(glm::vec3);

public:
	FloorMoveComponent(std::vector<glm::vec3> targetPositions, float movSpeed = 5.0f);
	~FloorMoveComponent();

	virtual void update(float deltaTime) override;
};

