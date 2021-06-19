#include "CollisionManager.h"
#include "GameObject.h"

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
	bool collided = false;

	GameObject* colliderGO = collider->getGameObject();
	glm::vec3 colliderBounds = collider->bounds;
	colliderBounds *= colliderGO->scale;

	for (auto& c : colliders) {
		if (c == collider)
			continue;

		GameObject* cGO = c->getGameObject();
		glm::vec3 cBounds = c->bounds;
		cBounds *= cGO->scale;

		//					a.minXYZ					<=				b.maxXYZ		&&				a.maxXYZ					>=			b.minXYZ					
		if ((colliderGO->position.x - colliderBounds.x <= cGO->position.x + cBounds.x && colliderGO->position.x + colliderBounds.x >= cGO->position.x - cBounds.x) &&
			(colliderGO->position.y - colliderBounds.y <= cGO->position.y + cBounds.y && colliderGO->position.y + colliderBounds.y >= cGO->position.y - cBounds.y) &&
			(colliderGO->position.z - colliderBounds.z <= cGO->position.z + cBounds.z && colliderGO->position.z + colliderBounds.z >= cGO->position.z - cBounds.z))
		{
			collided = true;
			collider->onCollision(c);
		}
	}
	return collided;
}
