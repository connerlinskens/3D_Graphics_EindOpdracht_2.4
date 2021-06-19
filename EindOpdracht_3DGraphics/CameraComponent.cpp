#include "CameraComponent.h"
#include <glm/gtc/matrix_transform.hpp>
#include "GameObject.h"

CameraComponent::CameraComponent(GLFWwindow* wn)
{
	window = wn;
	xRot = 0;
}

CameraComponent::~CameraComponent()
{
}

void CameraComponent::update(float deltaTime)
{
	double x, y;
	glfwGetCursorPos(window, &x, &y);

	static double lastX = x;
	static double lastY = y;

	xRot -= (float)(lastY - y) / 100.0f;
	gameObject->rotation.y -= (float)(lastX - x) / 100.0f;

	lastX = x;
	lastY = y;
}

glm::mat4 CameraComponent::getViewMatrix()
{
	glm::mat4 viewMatrix(1.0f);
	viewMatrix = glm::rotate(viewMatrix, xRot, glm::vec3(1, 0, 0));
	viewMatrix = glm::rotate(viewMatrix, gameObject->rotation.y, glm::vec3(0, 1, 0));
	viewMatrix = glm::rotate(viewMatrix, gameObject->rotation.z, glm::vec3(0, 0, 1));
	viewMatrix = glm::translate(viewMatrix, gameObject->position * glm::vec3(-1));
	return viewMatrix;
}