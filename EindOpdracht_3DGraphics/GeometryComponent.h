#pragma once
#include "DrawComponent.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>
#include "Texture.h"

class GeometryComponent : public DrawComponent
{
protected:
	std::vector<Vertex> verts;
	Texture* texture;

public:
	GeometryComponent();
	~GeometryComponent();

	virtual void draw() override;
};

