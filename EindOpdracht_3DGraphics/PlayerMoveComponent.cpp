#include "PlayerMoveComponent.h"
#include <glm/gtc/matrix_transform.hpp>
#include "GameObject.h"

PlayerMoveComponent::PlayerMoveComponent(GLFWwindow* wn)
{
	window = wn;

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	if (glfwRawMouseMotionSupported())
		glfwSetInputMode(window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);

	onGround = false;
	gravity = -12.0f;
	jumpVelocity = 5.0f;
	yVelocity = gravity;
}

PlayerMoveComponent::~PlayerMoveComponent()
{
}

void PlayerMoveComponent::move(float angle, float fac)
{
	gameObject->position.x -= (float)cos(gameObject->rotation.y + glm::radians(angle)) * fac;
	gameObject->position.z -= (float)sin(gameObject->rotation.y + glm::radians(angle)) * fac;
}

void PlayerMoveComponent::update(float deltaTime)
{
	if (onGround) {
		if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
			onGround = false;
			yVelocity = jumpVelocity;
		}
	}


	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		move(0, 0.05f);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		move(180, 0.05f);
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		move(90, 0.05f);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		move(-90, 0.05f);

	gameObject->position.y += yVelocity * deltaTime;

	if (yVelocity > gravity)
		yVelocity += gravity * deltaTime;
}
