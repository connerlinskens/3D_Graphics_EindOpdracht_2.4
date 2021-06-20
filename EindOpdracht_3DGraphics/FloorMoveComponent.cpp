#include "FloorMoveComponent.h"

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

	childRemoveTimer += deltaTime;
	if (childRemoveTimer > childRemoveTime) {
		for (auto& c : gameObject->getChildren())
			gameObject->removeChild(c);
		childRemoveTimer = 0.0f;
	}
}
