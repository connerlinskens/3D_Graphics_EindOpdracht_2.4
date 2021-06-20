#pragma once
#include "MoveComponent.h"

class EnemyMoveComponent : public MoveComponent
{
public:
	EnemyMoveComponent(std::vector<glm::vec3> targetPositions, float movSpeed = 5.0f);
	~EnemyMoveComponent();

	virtual void update(float deltaTime) override;
};

