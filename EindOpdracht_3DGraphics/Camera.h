#pragma once
#include "GameObject.h"
#include <glm/glm.hpp>

struct GLFWwindow;

class Camera : public GameObject
{
public:
	Camera();
	~Camera();

	virtual void update(GLFWwindow*);
	glm::mat4 getViewMatrix();
};

