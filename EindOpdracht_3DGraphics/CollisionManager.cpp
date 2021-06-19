#include "CollisionManager.h"

CollisionManager::CollisionManager()
{
}

CollisionManager::~CollisionManager()
{
}

void CollisionManager::addCollider(ColliderComponent* collider)
{
	colliders.push_back(collider);
}

bool CollisionManager::isColliding(ColliderComponent* collider)
{
	return false;
}
