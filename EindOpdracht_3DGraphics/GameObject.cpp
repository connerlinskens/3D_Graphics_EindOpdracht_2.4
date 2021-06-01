#include "GameObject.h"

void GameObject::setPosition(glm::vec3 pos)
{
	position = pos;
}

void GameObject::setRotation(glm::vec3 rot)
{
	rotation = glm::vec3(glm::radians(rot.x), glm::radians(rot.y), glm::radians(rot.z));
}