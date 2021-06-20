#include "MoveComponent.h"
#include "GameObject.h"

MoveComponent::MoveComponent()
{
}

MoveComponent::~MoveComponent()
{
}

glm::vec3 MoveComponent::directionToTarget(glm::vec3 target)
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

float MoveComponent::distanceToTarget(glm::vec3 target)
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