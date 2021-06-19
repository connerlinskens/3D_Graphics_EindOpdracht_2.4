#include "ColliderComponent.h"
#include "tigl.h"
using tigl::Vertex;

ColliderComponent::ColliderComponent(glm::vec3 colBounds, std::string colTag)
{
	bounds = colBounds;
	tag = colTag;
}

ColliderComponent::~ColliderComponent()
{
}

void ColliderComponent::draw()
{
	glm::vec4 color = glm::vec4(0, 1, 0, 1);
	tigl::begin(GL_LINES);

	//bottom
	tigl::addVertex(Vertex::PC(glm::vec3(-bounds.x, -bounds.y, -bounds.z), color));
	tigl::addVertex(Vertex::PC(glm::vec3(bounds.x, -bounds.y, -bounds.z), color));
	tigl::addVertex(Vertex::PC(glm::vec3(bounds.x, -bounds.y, bounds.z), color));
	tigl::addVertex(Vertex::PC(glm::vec3(-bounds.x, -bounds.y, bounds.z), color));

	//top
	tigl::addVertex(Vertex::PC(glm::vec3(-bounds.x, bounds.y, -bounds.z), color));
	tigl::addVertex(Vertex::PC(glm::vec3(bounds.x, bounds.y, -bounds.z), color));
	tigl::addVertex(Vertex::PC(glm::vec3(bounds.x, bounds.y, bounds.z), color));
	tigl::addVertex(Vertex::PC(glm::vec3(-bounds.x, bounds.y, bounds.z), color));

	//left
	tigl::addVertex(Vertex::PC(glm::vec3(bounds.x, -bounds.y, -bounds.z), color));
	tigl::addVertex(Vertex::PC(glm::vec3(bounds.x, bounds.y, -bounds.z), color));
	tigl::addVertex(Vertex::PC(glm::vec3(bounds.x, bounds.y, bounds.z), color));
	tigl::addVertex(Vertex::PC(glm::vec3(bounds.x, -bounds.y, bounds.z), color));

	//right
	tigl::addVertex(Vertex::PC(glm::vec3(-bounds.x, -bounds.y, -bounds.z), color));
	tigl::addVertex(Vertex::PC(glm::vec3(-bounds.x, bounds.y, -bounds.z), color));
	tigl::addVertex(Vertex::PC(glm::vec3(-bounds.x, bounds.y, bounds.z), color));
	tigl::addVertex(Vertex::PC(glm::vec3(-bounds.x, -bounds.y, bounds.z), color));

	//back
	tigl::addVertex(Vertex::PC(glm::vec3(-bounds.x, -bounds.y, -bounds.z), color));
	tigl::addVertex(Vertex::PC(glm::vec3(-bounds.x, bounds.y, -bounds.z), color));
	tigl::addVertex(Vertex::PC(glm::vec3(bounds.x, bounds.y, -bounds.z), color));
	tigl::addVertex(Vertex::PC(glm::vec3(bounds.x, -bounds.y, -bounds.z), color));

	//front
	tigl::addVertex(Vertex::PC(glm::vec3(-bounds.x, -bounds.y, bounds.z), color));
	tigl::addVertex(Vertex::PC(glm::vec3(-bounds.x, bounds.y, bounds.z), color));
	tigl::addVertex(Vertex::PC(glm::vec3(bounds.x, bounds.y, bounds.z), color));
	tigl::addVertex(Vertex::PC(glm::vec3(bounds.x, -bounds.y, bounds.z), color));

	tigl::end();
}
