#pragma once
#include "Camera.h"

class DebugCamera : public Camera
{
private:
	void move(float angle, float fac);

public:
	DebugCamera(GLFWwindow*);
	~DebugCamera();

	virtual void update(GLFWwindow*) override;
};

