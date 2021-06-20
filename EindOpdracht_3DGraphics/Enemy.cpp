#include "Enemy.h"
#include "Components.h"

Enemy::Enemy(CollisionManager* colMan, glm::vec3 pos, ObjModel* model, glm::vec3 colBounds, std::vector<glm::vec3> targets, float moveSpeed, std::string tag)
{
	this->position = pos;
	this->scale = glm::vec3(0.008f);
	this->addComponent(new ModelComponent(model));
	this->addComponent(new ColliderComponent(colMan, colBounds, tag));
	this->addComponent(new EnemyMoveComponent(targets, moveSpeed));
}

Enemy::~Enemy()
{
}
