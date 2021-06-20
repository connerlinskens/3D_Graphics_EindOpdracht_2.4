#include "FloorMoveComponent.h"
#include <iostream>

FloorMoveComponent::FloorMoveComponent(std::vector<glm::vec3> targetPositions, float movSpeed)
{
	moveSpeed = movSpeed;
	currentTarget = 0;
	flip = false;
	childRemoveTime = 0.1f;
	childRemoveTimer = 0.0f;

	for (auto& t : targetPositions) {
		targets.push_back(t);
	}
}

void FloorMoveComponent::update(float deltaTime)
{
	if (distanceToTarget(targets[currentTarget]) > moveSpeed / 25.0f) {
		glm::vec3 translation = directionToTarget(targets[currentTarget]) * moveSpeed * deltaTime;
		gameObject->position += translation;
		for (auto& c : gameObject->getChildren()) {
			c->position += translation;
		}
	}
	else {
		for (auto& c : gameObject->getChildren()) {
			c->position += directionToTarget(targets[currentTarget]) * moveSpeed * deltaTime;;
		}
		gameObject->position = targets[currentTarget];

		if (!flip) {
			if (currentTarget + 1 < targets.size()) {
				currentTarget++;
			}
			else {
				currentTarget--;
				flip = true;
			}
		}
		else {
			if (currentTarget - 1 > -1) {
				currentTarget--;
			}
			else {
				currentTarget++;
				flip = false;
			}
		}
	}

	std::cout << childRemoveTimer << std::endl;
	childRemoveTimer += deltaTime;
	if (childRemoveTimer > childRemoveTime) {
		for (auto& c : gameObject->getChildren())
			gameObject->removeChild(c);
		childRemoveTimer = 0.0f;
	}
}

glm::vec3 FloorMoveComponent::directionToTarget(glm::vec3 target)
{
	// Calculate difference between position and target
	glm::vec3 diff = glm::vec3(
		target.x - gameObject->position.x,
		target.y - gameObject->position.y,
		target.z - gameObject->position.z
	);

	// Normalize result and return
	return glm::normalize(diff);
}

float FloorMoveComponent::distanceToTarget(glm::vec3 target)
{
	// Calculate difference between position and target 
	glm::vec3 diff = glm::vec3(
		gameObject->position.x - target.x,
		gameObject->position.y - target.y,
		gameObject->position.z - target.z
	);

	// Calculate the magnitude of the difference vector
	float distance = glm::sqrt(
		glm::pow(diff.x, 2.0f) +
		glm::pow(diff.y, 2.0f) +
		glm::pow(diff.z, 2.0f)
	);

	return distance;
}
