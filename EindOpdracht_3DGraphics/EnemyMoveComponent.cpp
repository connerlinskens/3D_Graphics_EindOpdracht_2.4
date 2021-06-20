#include "EnemyMoveComponent.h"
#include "GameObject.h"
#include <iostream>

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
	//glm::vec3 diff = glm::vec3(
	//	targets[currentTarget].x - gameObject->position.x,
	//	targets[currentTarget].y - gameObject->position.y,
	//	targets[currentTarget].z - gameObject->position.z
	//);

	//float dot = glm::dot(gameObject->rotation, diff);
	//float rotation = acos(dot);
	//if(glm::cross(gameObject->rotation, diff).z > 0)
	//	gameObject->rotation.y -= rotation;
	//else
	//	gameObject->rotation.y += rotation;

	//std::cout << "diff: " << diff.x << " " << diff.y << " " << diff.z << std::endl;
	//std::cout << "GO: " << gameObject->rotation.x << " " << gameObject->rotation.y << " " << gameObject->rotation.z << std::endl;
	//std::cout << dot << "\t" << rotation << "\t" << glm::radians(rotation) << std::endl;
	//std::cout << glm::cross(gameObject->rotation, diff).x << " " << glm::cross(gameObject->rotation, diff).y << " " << glm::cross(gameObject->rotation, diff).z << std::endl;

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

		lookAtTarget();
	}
}
