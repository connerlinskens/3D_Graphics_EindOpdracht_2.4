#pragma once
#include "DrawComponent.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class GeometryComponent : public DrawComponent
{
protected:
	std::vector<Vertex> verts;
public:
	GeometryComponent();
	~GeometryComponent();
};

