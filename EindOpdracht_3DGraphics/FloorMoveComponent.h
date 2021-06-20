#pragma once
#include "MoveComponent.h"
#include <glm/glm.hpp>
#include <vector>
#include "GameObject.h"

class FloorMoveComponent : public MoveComponent
{
private:
	float childRemoveTime;
	float childRemoveTimer;

public:
	FloorMoveComponent(std::vector<glm::vec3> targetPositions, float movSpeed = 5.0f);
	~FloorMoveComponent();

	virtual void update(float deltaTime) override;
};

