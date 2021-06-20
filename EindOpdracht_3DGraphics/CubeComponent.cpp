#include "CubeComponent.h"

CubeComponent::CubeComponent(glm::vec3 s, glm::vec4 color, Texture* tex, float texTilesTopHor, float texTilesTopVer, float texTilesSides)
{
	texture = tex;

	//bottom
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, -s.y, -s.z), glm::vec2(0, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, -s.y, -s.z), glm::vec2(texTilesTopVer, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, -s.y, s.z), glm::vec2(texTilesTopVer, texTilesTopHor), color));
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, -s.y, s.z), glm::vec2(0, texTilesTopHor), color));

	//top
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, s.y, -s.z), glm::vec2(0, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, s.y, -s.z), glm::vec2(texTilesTopVer, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, s.y, s.z), glm::vec2(texTilesTopVer, texTilesTopHor), color));
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, s.y, s.z), glm::vec2(0, texTilesTopHor), color));
							 
	//left					 
	verts.push_back(Vertex::PTC(glm::vec3(s.x, -s.y, -s.z), glm::vec2(0, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, s.y, -s.z), glm::vec2(texTilesSides, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, s.y, s.z), glm::vec2(texTilesSides, texTilesSides * texTilesTopHor), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, -s.y, s.z), glm::vec2(0, texTilesSides * texTilesTopHor), color));
							 
	//right					 
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, -s.y, -s.z), glm::vec2(0, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, s.y, -s.z), glm::vec2(texTilesSides, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, s.y, s.z), glm::vec2(texTilesSides, texTilesSides * texTilesTopHor), color));
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, -s.y, s.z), glm::vec2(0, texTilesSides * texTilesTopHor), color));
							 
	//back					 
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, -s.y, -s.z), glm::vec2(0, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, s.y, -s.z), glm::vec2(texTilesSides, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, s.y, -s.z), glm::vec2(texTilesSides, texTilesSides * texTilesTopHor), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, -s.y, -s.z), glm::vec2(0, texTilesSides * texTilesTopHor), color));
							 
	//front					 
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, -s.y, s.z), glm::vec2(0, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(-s.x, s.y, s.z), glm::vec2(texTilesSides, 0), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, s.y, s.z), glm::vec2(texTilesSides, texTilesSides * texTilesTopHor), color));
	verts.push_back(Vertex::PTC(glm::vec3(s.x, -s.y, s.z), glm::vec2(0, texTilesSides * texTilesTopHor), color));
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
