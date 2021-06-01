#pragma once
#include <glm/glm.hpp>

class GameObject
{
protected:
	glm::vec3 position = glm::vec3(0);
	glm::vec3 rotation = glm::vec3(0);

public:
	void setPosition(glm::vec3);
	void setRotation(glm::vec3);
};

