#pragma once

#include "GeometryComponent.h"

class CubeComponent : public GeometryComponent
{

public:
	CubeComponent(glm::vec3 size, glm::vec4 color);
	~CubeComponent();

	virtual void draw() override;
};

