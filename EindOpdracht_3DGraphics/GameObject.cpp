#include "GameObject.h"
#include "Component.h"
#include "DrawComponent.h"
#include "ColliderComponent.h"
#include "tigl.h"
#include <glm/gtc/matrix_transform.hpp>

void GameObject::addComponent(Component* component)
{
	component->setGameObject(this);
	components.push_back(component);

	// Replace draw component if new component is a draw component
	DrawComponent* drawComp = dynamic_cast<DrawComponent*>(component);
	if (drawComp)
		drawComponent = drawComp;

	// Replace collider component if new component is a collider component
	ColliderComponent* colliderComp = dynamic_cast<ColliderComponent*>(component);
	if (colliderComp)
		colliderComponent = colliderComp;
}

std::list<Component*> GameObject::getComponents()
{
	return components;
}

void GameObject::update(float deltaTime)
{
	for (auto& c : components)
		c->update(deltaTime);
}

void GameObject::draw(const glm::mat4& parentMatrix)
{
	if (!drawComponent && !colliderComponent)
		return;

	glm::mat4 modelMatrix = parentMatrix;
	modelMatrix = glm::translate(modelMatrix, position);
	modelMatrix = glm::rotate(modelMatrix, rotation.x, glm::vec3(1, 0, 0));
	modelMatrix = glm::rotate(modelMatrix, rotation.y, glm::vec3(0, 1, 0));
	modelMatrix = glm::rotate(modelMatrix, rotation.z, glm::vec3(0, 0, 1));
	modelMatrix = glm::scale(modelMatrix, scale);

	tigl::shader->setModelMatrix(modelMatrix);

	if(drawComponent)
		drawComponent->draw();

	if(colliderComponent)
		if (colliderComponent->debugDraw)
			colliderComponent->draw();
}
