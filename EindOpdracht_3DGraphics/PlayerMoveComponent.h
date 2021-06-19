#pragma once
#include "Component.h"
#include <GLFW/glfw3.h>

class PlayerMoveComponent : public Component
{
private:
	GLFWwindow* window;

	void move(float angle, float fac);

public:
	PlayerMoveComponent(GLFWwindow* wn);
	~PlayerMoveComponent();

	virtual void update(float deltaTime) override;

};

