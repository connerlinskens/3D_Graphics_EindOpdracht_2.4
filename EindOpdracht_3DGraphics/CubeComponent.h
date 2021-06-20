#pragma once

#include "GeometryComponent.h"

class CubeComponent : public GeometryComponent
{

public:
	CubeComponent(glm::vec3 size, glm::vec4 color, Texture* tex, float texTilesTop = 1.0f, float texTilesSides = 1.0f);
	~CubeComponent();

	virtual void draw() override;
};

