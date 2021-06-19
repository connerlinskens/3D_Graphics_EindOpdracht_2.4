#pragma once
#include "Component.h"
#include <GLFW/glfw3.h>

class PlayerMoveComponent : public Component
{
private:
	GLFWwindow* window;

	float gravity;
	float jumpVelocity;
	float yVelocity;

	void move(float angle, float fac);

public:
	PlayerMoveComponent(GLFWwindow* wn);
	~PlayerMoveComponent();

	bool onGround;

	virtual void update(float deltaTime) override;
};

