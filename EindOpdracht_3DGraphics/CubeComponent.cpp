#include "CubeComponent.h"

CubeComponent::CubeComponent(glm::vec3 s, glm::vec4 color)
{
	//bottom
	verts.push_back(Vertex::PC(glm::vec3(-s.x, -s.y, -s.z), color));
	verts.push_back(Vertex::PC(glm::vec3(s.x, -s.y, -s.z), color));
	verts.push_back(Vertex::PC(glm::vec3(s.x, -s.y, s.z), color));
	verts.push_back(Vertex::PC(glm::vec3(-s.x, -s.y, s.z), color));

	//top
	verts.push_back(Vertex::PC(glm::vec3(-s.x, s.y, -s.z), color));
	verts.push_back(Vertex::PC(glm::vec3(s.x, s.y, -s.z), color));
	verts.push_back(Vertex::PC(glm::vec3(s.x, s.y, s.z), color));
	verts.push_back(Vertex::PC(glm::vec3(-s.x, s.y, s.z), color));

	//left
	verts.push_back(Vertex::PC(glm::vec3(s.x, -s.y, -s.z), color));
	verts.push_back(Vertex::PC(glm::vec3(s.x, s.y, -s.z), color));
	verts.push_back(Vertex::PC(glm::vec3(s.x, s.y, s.z), color));
	verts.push_back(Vertex::PC(glm::vec3(s.x, -s.y, s.z), color));

	//right
	verts.push_back(Vertex::PC(glm::vec3(-s.x, -s.y, -s.z), color));
	verts.push_back(Vertex::PC(glm::vec3(-s.x, s.y, -s.z), color));
	verts.push_back(Vertex::PC(glm::vec3(-s.x, s.y, s.z), color));
	verts.push_back(Vertex::PC(glm::vec3(-s.x, -s.y, s.z), color));

	//back
	verts.push_back(Vertex::PC(glm::vec3(-s.x, -s.y, -s.z), color));
	verts.push_back(Vertex::PC(glm::vec3(-s.x, s.y, -s.z), color));
	verts.push_back(Vertex::PC(glm::vec3(s.x, s.y, -s.z), color));
	verts.push_back(Vertex::PC(glm::vec3(s.x, -s.y, -s.z), color));

	//front
	verts.push_back(Vertex::PC(glm::vec3(-s.x, -s.y, s.z), color));
	verts.push_back(Vertex::PC(glm::vec3(-s.x, s.y, s.z), color));
	verts.push_back(Vertex::PC(glm::vec3(s.x, s.y, s.z), color));
	verts.push_back(Vertex::PC(glm::vec3(s.x, -s.y, s.z), color));
}

CubeComponent::~CubeComponent()
{
}

void CubeComponent::draw()
{
	tigl::drawVertices(GL_QUADS, verts);
}
