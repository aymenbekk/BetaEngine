#include "Block.h"


namespace Block {
	vector<Vertex> getBlockFace(BlockFace face) {

		vector<Vertex> vertices;
		if (face == BlockFace::Top) {
			vertices.push_back(Vertex{ glm::vec3(-0.5f,  0.5f, -0.5f),glm::vec3(0.0f,  1.0f,  0.0f),glm::vec2(0.0f, 1.0f) });
			vertices.push_back(Vertex{ glm::vec3(0.5f,  0.5f, -0.5f),glm::vec3(0.0f,  1.0f,  0.0f),glm::vec2(1.0f, 1.0f) });
			vertices.push_back(Vertex{ glm::vec3(0.5f,  0.5f,  0.5f),glm::vec3(0.0f,  1.0f,  0.0f),glm::vec2(1.0f, 0.0f) });
			vertices.push_back(Vertex{ glm::vec3(0.5f,  0.5f,  0.5f),glm::vec3(0.0f,  1.0f,  0.0f),glm::vec2(1.0f, 0.0f) });
			vertices.push_back(Vertex{ glm::vec3(-0.5f,  0.5f,  0.5f),glm::vec3(0.0f,  1.0f,  0.0f),glm::vec2(0.0f, 0.0f) });
			vertices.push_back(Vertex{ glm::vec3(-0.5f,  0.5f, -0.5f),glm::vec3(0.0f,  1.0f,  0.0f),glm::vec2(0.0f, 1.0f) });
		}
		else if (face == BlockFace::Bottom) {
			vertices.push_back(Vertex{ glm::vec3(-0.5f, -0.5f, -0.5f),glm::vec3(0.0f,  -1.0f,  0.0f),glm::vec2(0.0f, 1.0f) });
			vertices.push_back(Vertex{ glm::vec3(0.5f, -0.5f, -0.5f),glm::vec3(0.0f,  -1.0f,  0.0f),glm::vec2(1.0f, 1.0f) });
			vertices.push_back(Vertex{ glm::vec3(0.5f, -0.5f,  0.5f),glm::vec3(0.0f,  -1.0f,  0.0f),glm::vec2(1.0f, 0.0f) });
			vertices.push_back(Vertex{ glm::vec3(0.5f, -0.5f,  0.5f),glm::vec3(0.0f,  -1.0f,  0.0f),glm::vec2(1.0f, 0.0f) });
			vertices.push_back(Vertex{ glm::vec3(-0.5f, -0.5f,  0.5f),glm::vec3(0.0f,  -1.0f,  0.0f),glm::vec2(0.0f, 0.0f) });
			vertices.push_back(Vertex{ glm::vec3(-0.5f, -0.5f, -0.5f),glm::vec3(0.0f,  -1.0f,  0.0f),glm::vec2(0.0f, 1.0f) });
		}
		else if (face == BlockFace::Front) {
			vertices.push_back(Vertex{ glm::vec3(-0.5f, -0.5f,  0.5f),glm::vec3(0.0f,  0.0f,  1.0f),glm::vec2(0.0f, 1.0f) });
			vertices.push_back(Vertex{ glm::vec3(0.5f, -0.5f,  0.5f),glm::vec3(0.0f,  0.0f,  1.0f),glm::vec2(1.0f, 1.0f) });
			vertices.push_back(Vertex{ glm::vec3(0.5f,  0.5f,  0.5f),glm::vec3(0.0f,  0.0f,  1.0f),glm::vec2(1.0f, 0.0f) });
			vertices.push_back(Vertex{ glm::vec3(0.5f,  0.5f,  0.5f),glm::vec3(0.0f,  0.0f,  1.0f),glm::vec2(1.0f, 0.0f) });
			vertices.push_back(Vertex{ glm::vec3(-0.5f,  0.5f,  0.5f),glm::vec3(0.0f,  0.0f,  1.0f),glm::vec2(0.0f, 0.0f) });
			vertices.push_back(Vertex{ glm::vec3(-0.5f, -0.5f,  0.5f),glm::vec3(0.0f,  0.0f,  1.0f),glm::vec2(0.0f, 1.0f) });
		}
		else if (face == BlockFace::Back) {
			vertices.push_back(Vertex{ glm::vec3(-0.5f, -0.5f, -0.5f),glm::vec3(0.0f,  0.0f,  -1.0f),glm::vec2(0.0f, 1.0f) });
			vertices.push_back(Vertex{ glm::vec3(0.5f, -0.5f, -0.5f),glm::vec3(0.0f,  0.0f,  -1.0f),glm::vec2(1.0f, 1.0f) });
			vertices.push_back(Vertex{ glm::vec3(0.5f,  0.5f, -0.5f),glm::vec3(0.0f,  0.0f,  -1.0f),glm::vec2(1.0f, 0.0f) });
			vertices.push_back(Vertex{ glm::vec3(0.5f,  0.5f, -0.5f),glm::vec3(0.0f,  0.0f,  -1.0f),glm::vec2(1.0f, 0.0f) });
			vertices.push_back(Vertex{ glm::vec3(-0.5f,  0.5f, -0.5f),glm::vec3(0.0f,  0.0f,  -1.0f),glm::vec2(0.0f, 0.0f) });
			vertices.push_back(Vertex{ glm::vec3(-0.5f, -0.5f, -0.5f),glm::vec3(0.0f,  0.0f,  -1.0f),glm::vec2(0.0f, 1.0f) });
		}

		else if (face == BlockFace::Right) {
			vertices.push_back(Vertex{ glm::vec3(0.5f,  0.5f,  0.5f),glm::vec3(1.0f,  0.0f,  0.0f),glm::vec2(0.0f, 1.0f) });
			vertices.push_back(Vertex{ glm::vec3(0.5f,  0.5f, -0.5f),glm::vec3(1.0f,  0.0f,  0.0f),glm::vec2(1.0f, 1.0f) });
			vertices.push_back(Vertex{ glm::vec3(0.5f, -0.5f, -0.5f),glm::vec3(1.0f,  0.0f,  0.0f),glm::vec2(1.0f, 0.0f) });
			vertices.push_back(Vertex{ glm::vec3(0.5f, -0.5f, -0.5f),glm::vec3(1.0f,  0.0f,  0.0f),glm::vec2(1.0f, 0.0f) });
			vertices.push_back(Vertex{ glm::vec3(0.5f, -0.5f,  0.5f),glm::vec3(1.0f,  0.0f,  0.0f),glm::vec2(0.0f, 0.0f) });
			vertices.push_back(Vertex{ glm::vec3(0.5f,  0.5f,  0.5f),glm::vec3(1.0f,  0.0f,  0.0f),glm::vec2(0.0f, 1.0f) });
		}
		else {
			vertices.push_back(Vertex{ glm::vec3(-0.5f,  0.5f,  0.5f),glm::vec3(-1.0f,  0.0f,  0.0f),glm::vec2(0.0f, 1.0f) });
			vertices.push_back(Vertex{ glm::vec3(-0.5f,  0.5f, -0.5f),glm::vec3(-1.0f,  0.0f,  0.0f),glm::vec2(1.0f, 1.0f) });
			vertices.push_back(Vertex{ glm::vec3(-0.5f, -0.5f, -0.5f),glm::vec3(-1.0f,  0.0f,  0.0f),glm::vec2(1.0f, 0.0f) });
			vertices.push_back(Vertex{ glm::vec3(-0.5f, -0.5f, -0.5f),glm::vec3(-1.0f,  0.0f,  0.0f),glm::vec2(1.0f, 0.0f) });
			vertices.push_back(Vertex{ glm::vec3(-0.5f, -0.5f,  0.5f),glm::vec3(-1.0f,  0.0f,  0.0f),glm::vec2(0.0f, 0.0f) });
			vertices.push_back(Vertex{ glm::vec3(-0.5f,  0.5f,  0.5f),glm::vec3(-1.0f,  0.0f,  0.0f),glm::vec2(0.0f, 1.0f) });
		}

		return vertices;
	}

}
