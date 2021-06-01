#include "Camera.h"
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera()
{
}

Camera::~Camera()
{
}

void Camera::update(GLFWwindow*)
{
}

glm::mat4 Camera::getViewMatrix()
{
	glm::mat4 viewMatrix(1.0f);
	viewMatrix = glm::rotate(viewMatrix, rotation.x, glm::vec3(1, 0, 0));
	viewMatrix = glm::rotate(viewMatrix, rotation.y, glm::vec3(0, 1, 0));
	viewMatrix = glm::rotate(viewMatrix, rotation.z, glm::vec3(0, 0, 1));
	viewMatrix = glm::translate(viewMatrix, position);
	return viewMatrix;
}
