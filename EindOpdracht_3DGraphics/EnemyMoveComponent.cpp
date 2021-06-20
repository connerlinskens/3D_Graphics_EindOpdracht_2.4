#include "EnemyMoveComponent.h"
#include "GameObject.h"

EnemyMoveComponent::EnemyMoveComponent(std::vector<glm::vec3> targetPositions, float movSpeed)
{
	moveSpeed = movSpeed;
	currentTarget = 0;
	flip = false;

	for (auto& t : targetPositions) {
		targets.push_back(t);
	}
}

EnemyMoveComponent::~EnemyMoveComponent()
{
}

void EnemyMoveComponent::lookAtTarget()
{
	float rotation = acos(glm::dot(glm::normalize(gameObject->rotation), directionToTarget(targets[currentTarget])));
	gameObject->rotation.y += glm::radians(rotation);
}

void EnemyMoveComponent::update(float deltaTime)
{
	if (distanceToTarget(targets[currentTarget]) > moveSpeed / 25.0f) {
		gameObject->position += directionToTarget(targets[currentTarget]) * moveSpeed * deltaTime;
	}
	else {
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

		//lookAtTarget();
	}
}
