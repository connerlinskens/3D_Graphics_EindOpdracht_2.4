#include "EnemyMoveComponent.h"
#include "GameObject.h"
#include <iostream>

EnemyMoveComponent::EnemyMoveComponent(std::vector<glm::vec3> targetPositions, float movSpeed, bool loopInstead)
{
	moveSpeed = movSpeed;
	currentTarget = 0;
	flip = false;
	loop = loopInstead;

	for (auto& t : targetPositions) {
		targets.push_back(t);
	}
}

EnemyMoveComponent::~EnemyMoveComponent()
{
}

void EnemyMoveComponent::lookAtTarget()
{
	if (gameObject->position.x < targets[currentTarget].x)
		gameObject->rotation.y = glm::radians(90.0f);
	else if (gameObject->position.x > targets[currentTarget].x)
		gameObject->rotation.y = glm::radians(270.0f);
	else if (gameObject->position.z < targets[currentTarget].z)
		gameObject->rotation.y = glm::radians(0.0f);
	else if(gameObject->position.z > targets[currentTarget].z)
		gameObject->rotation.y = glm::radians(180.0f);
}

void EnemyMoveComponent::update(float deltaTime)
{
	if (distanceToTarget(targets[currentTarget]) > moveSpeed / 25.0f) {
		gameObject->position += directionToTarget(targets[currentTarget]) * moveSpeed * deltaTime;
	}
	else {
		gameObject->position = targets[currentTarget];

		if (loop) {
			currentTarget = currentTarget + 1 >= targets.size() ? 0 : currentTarget + 1;
		}
		else {
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

		lookAtTarget();
	}
}
