#include "CubeComponent.h"

CubeComponent::CubeComponent(glm::vec3 s, glm::vec4 color, Texture* tex)
{
	texture = tex;

	//bottom
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, -s.y, -s.z), glm::vec2(0, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, -s.y, -s.z), glm::vec2(1, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, -s.y, s.z), glm::vec2(1, 1), color));
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, -s.y, s.z), glm::vec2(0, 1), color));

	//top
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, s.y, -s.z), glm::vec2(0, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, s.y, -s.z), glm::vec2(1, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, s.y, s.z), glm::vec2(1, 1), color));
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, s.y, s.z), glm::vec2(0, 1), color));
							 
	//left					 
	verts.push_back(Vertex::PTC(glm::vec3(s.x, -s.y, -s.z), glm::vec2(0, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, s.y, -s.z), glm::vec2(1, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, s.y, s.z), glm::vec2(1, 1), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, -s.y, s.z), glm::vec2(0, 1), color));
							 
	//right					 
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, -s.y, -s.z), glm::vec2(0, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, s.y, -s.z), glm::vec2(1, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, s.y, s.z), glm::vec2(1, 1), color));
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, -s.y, s.z), glm::vec2(0, 1), color));
							 
	//back					 
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, -s.y, -s.z), glm::vec2(0, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, s.y, -s.z), glm::vec2(1, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, s.y, -s.z), glm::vec2(1, 1), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, -s.y, -s.z), glm::vec2(0, 1), color));
							 
	//front					 
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, -s.y, s.z), glm::vec2(0, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, s.y, s.z), glm::vec2(1, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, s.y, s.z), glm::vec2(1, 1), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, -s.y, s.z), glm::vec2(0, 1), color));
}

CubeComponent::~CubeComponent()
{
}

void CubeComponent::draw()
{
	if (texture)
		texture->bind();

	tigl::drawVertices(GL_QUADS, verts);
}
