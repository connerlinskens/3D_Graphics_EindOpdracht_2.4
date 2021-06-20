#include "GeometryComponent.h"

GeometryComponent::GeometryComponent()
{
	texture = nullptr;
}

GeometryComponent::~GeometryComponent()
{
}

void GeometryComponent::draw()
{
	if (texture)
		texture->bind();
}
