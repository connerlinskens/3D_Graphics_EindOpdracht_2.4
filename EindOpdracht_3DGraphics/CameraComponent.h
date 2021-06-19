#pragma once
#include "Component.h"
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

class CameraComponent : public Component
{
private:
	GLFWwindow* window;
	float xRot;

public:
	CameraComponent(GLFWwindow*);
	~CameraComponent();

	virtual void update(float deltaTime) override;

	glm::mat4 getViewMatrix();
};
