#pragma once
#include "ColliderComponent.h"
#include <list>

class CollisionManager
{
private:
	std::list<ColliderComponent*> colliders;

public:
	CollisionManager();
	~CollisionManager();

	void addCollider(ColliderComponent* collider);

	bool isColliding(ColliderComponent* collider);
};

