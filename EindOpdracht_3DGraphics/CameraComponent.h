#pragma once
#include "Component.h"
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

class CameraComponent : public Component
{
private:
	GLFWwindow* window;
	float xRot;
	float maxXRot;

public:
	CameraComponent(GLFWwindow*);
	~CameraComponent();

	bool disabled;

	virtual void update(float deltaTime) override;

	glm::mat4 getViewMatrix();
	glm::mat4 getModelMatrix();
};

