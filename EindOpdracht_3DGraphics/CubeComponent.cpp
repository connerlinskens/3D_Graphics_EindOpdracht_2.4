#include "CubeComponent.h"

CubeComponent::CubeComponent(glm::vec3 s, glm::vec4 color, Texture* tex, float texTilesTop, float texTilesSides)
{
	texture = tex;

	//bottom
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, -s.y, -s.z), glm::vec2(0, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, -s.y, -s.z), glm::vec2(texTilesTop, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, -s.y, s.z), glm::vec2(texTilesTop, texTilesTop), color));
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, -s.y, s.z), glm::vec2(0, texTilesTop), color));

	//top
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, s.y, -s.z), glm::vec2(0, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, s.y, -s.z), glm::vec2(texTilesTop, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, s.y, s.z), glm::vec2(texTilesTop, texTilesTop), color));
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, s.y, s.z), glm::vec2(0, texTilesTop), color));
							 
	//left					 
	verts.push_back(Vertex::PTC(glm::vec3(s.x, -s.y, -s.z), glm::vec2(0, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, s.y, -s.z), glm::vec2(texTilesSides, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, s.y, s.z), glm::vec2(texTilesSides, texTilesSides * texTilesTop), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, -s.y, s.z), glm::vec2(0, texTilesSides * texTilesTop), color));
							 
	//right					 
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, -s.y, -s.z), glm::vec2(0, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, s.y, -s.z), glm::vec2(texTilesSides, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, s.y, s.z), glm::vec2(texTilesSides, texTilesSides * texTilesTop), color));
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, -s.y, s.z), glm::vec2(0, texTilesSides * texTilesTop), color));
							 
	//back					 
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, -s.y, -s.z), glm::vec2(0, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, s.y, -s.z), glm::vec2(texTilesSides, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, s.y, -s.z), glm::vec2(texTilesSides, texTilesSides * texTilesTop), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, -s.y, -s.z), glm::vec2(0, texTilesSides * texTilesTop), color));
							 
	//front					 
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, -s.y, s.z), glm::vec2(0, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, s.y, s.z), glm::vec2(texTilesSides, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, s.y, s.z), glm::vec2(texTilesSides, texTilesSides * texTilesTop), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, -s.y, s.z), glm::vec2(0, texTilesSides * texTilesTop), color));
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
