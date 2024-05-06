#include "Block.h"


namespace Block {
	vector<Vertex> getBlockFace(BlockFace face) {

		vector<Vertex> vertices;
        if (face == BlockFace::Top) {
            vertices.push_back(Vertex{ glm::vec3(-0.5f,  0.5f, -0.5f),glm::vec3(0.0f,  1.0f,  0.0f),glm::vec2(0.0f, 0.0f) }); // 0
            vertices.push_back(Vertex{ glm::vec3(0.5f,  0.5f, -0.5f),glm::vec3(0.0f,  1.0f,  0.0f),glm::vec2(1.0f, 0.0f) });  // 1
            vertices.push_back(Vertex{ glm::vec3(0.5f,  0.5f,  0.5f),glm::vec3(0.0f,  1.0f,  0.0f),glm::vec2(1.0f, 1.0f) });  // 2
            vertices.push_back(Vertex{ glm::vec3(-0.5f,  0.5f, -0.5f),glm::vec3(0.0f,  1.0f,  0.0f),glm::vec2(0.0f, 0.0f) }); // 0
            vertices.push_back(Vertex{ glm::vec3(0.5f,  0.5f,  0.5f),glm::vec3(0.0f,  1.0f,  0.0f),glm::vec2(1.0f, 1.0f) });  // 2
            vertices.push_back(Vertex{ glm::vec3(-0.5f,  0.5f,  0.5f),glm::vec3(0.0f,  1.0f,  0.0f),glm::vec2(0.0f, 1.0f) }); // 5
        }
        else if (face == BlockFace::Bottom) {
            vertices.push_back(Vertex{ glm::vec3(-0.5f, -0.5f, -0.5f),glm::vec3(0.0f,  -1.0f,  0.0f),glm::vec2(0.0f, 0.0f) }); // 0
            vertices.push_back(Vertex{ glm::vec3(0.5f, -0.5f, -0.5f),glm::vec3(0.0f,  -1.0f,  0.0f),glm::vec2(1.0f, 0.0f) });  // 1
            vertices.push_back(Vertex{ glm::vec3(0.5f, -0.5f,  0.5f),glm::vec3(0.0f,  -1.0f,  0.0f),glm::vec2(1.0f, 1.0f) });  // 2
            vertices.push_back(Vertex{ glm::vec3(-0.5f, -0.5f, -0.5f),glm::vec3(0.0f,  -1.0f,  0.0f),glm::vec2(0.0f, 0.0f) }); // 0
            vertices.push_back(Vertex{ glm::vec3(0.5f, -0.5f,  0.5f),glm::vec3(0.0f,  -1.0f,  0.0f),glm::vec2(1.0f, 1.0f) });  // 2
            vertices.push_back(Vertex{ glm::vec3(-0.5f, -0.5f,  0.5f),glm::vec3(0.0f,  -1.0f,  0.0f),glm::vec2(0.0f, 1.0f) }); // 5
        }
        else if (face == BlockFace::Front) {
            vertices.push_back(Vertex{ glm::vec3(-0.5f, -0.5f,  0.5f),glm::vec3(0.0f,  0.0f,  1.0f),glm::vec2(0.0f, 0.0f) }); // 0
            vertices.push_back(Vertex{ glm::vec3(0.5f, -0.5f,  0.5f),glm::vec3(0.0f,  0.0f,  1.0f),glm::vec2(1.0f, 0.0f) });  // 1
            vertices.push_back(Vertex{ glm::vec3(0.5f,  0.5f,  0.5f),glm::vec3(0.0f,  0.0f,  1.0f),glm::vec2(1.0f, 1.0f) });  // 2
            vertices.push_back(Vertex{ glm::vec3(-0.5f, -0.5f,  0.5f),glm::vec3(0.0f,  0.0f,  1.0f),glm::vec2(0.0f, 0.0f) }); // 0
            vertices.push_back(Vertex{ glm::vec3(0.5f,  0.5f,  0.5f),glm::vec3(0.0f,  0.0f,  1.0f),glm::vec2(1.0f, 1.0f) });  // 2
            vertices.push_back(Vertex{ glm::vec3(-0.5f,  0.5f,  0.5f),glm::vec3(0.0f,  0.0f,  1.0f),glm::vec2(0.0f, 1.0f) }); // 5
        }
        else if (face == BlockFace::Back) {
            vertices.push_back(Vertex{ glm::vec3(-0.5f, -0.5f, -0.5f),glm::vec3(0.0f,  0.0f,  -1.0f),glm::vec2(0.0f, 0.0f) }); // 0
            vertices.push_back(Vertex{ glm::vec3(0.5f, -0.5f, -0.5f),glm::vec3(0.0f,  0.0f,  -1.0f),glm::vec2(1.0f, 0.0f) });  // 1
            vertices.push_back(Vertex{ glm::vec3(0.5f,  0.5f, -0.5f),glm::vec3(0.0f,  0.0f,  -1.0f),glm::vec2(1.0f, 1.0f) });  // 2
            vertices.push_back(Vertex{ glm::vec3(-0.5f, -0.5f, -0.5f),glm::vec3(0.0f,  0.0f,  -1.0f),glm::vec2(0.0f, 0.0f) }); // 0
            vertices.push_back(Vertex{ glm::vec3(0.5f,  0.5f, -0.5f),glm::vec3(0.0f,  0.0f,  -1.0f),glm::vec2(1.0f, 1.0f) });  // 2
            vertices.push_back(Vertex{ glm::vec3(-0.5f,  0.5f, -0.5f),glm::vec3(0.0f,  0.0f,  -1.0f),glm::vec2(0.0f, 1.0f) }); // 5
        }
        else if (face == BlockFace::Right) {
            vertices.push_back(Vertex{ glm::vec3(0.5f,  0.5f,  0.5f),glm::vec3(1.0f,  0.0f,  0.0f),glm::vec2(0.0f, 0.0f) }); // 0
            vertices.push_back(Vertex{ glm::vec3(0.5f,  0.5f, -0.5f),glm::vec3(1.0f,  0.0f,  0.0f),glm::vec2(1.0f, 0.0f) });  // 1
            vertices.push_back(Vertex{ glm::vec3(0.5f, -0.5f, -0.5f),glm::vec3(1.0f,  0.0f,  0.0f),glm::vec2(1.0f, 1.0f) });  // 2
            vertices.push_back(Vertex{ glm::vec3(0.5f,  0.5f,  0.5f),glm::vec3(1.0f,  0.0f,  0.0f),glm::vec2(0.0f, 0.0f) }); // 0
            vertices.push_back(Vertex{ glm::vec3(0.5f, -0.5f, -0.5f),glm::vec3(1.0f,  0.0f,  0.0f),glm::vec2(1.0f, 1.0f) });  // 2
            vertices.push_back(Vertex{ glm::vec3(0.5f, -0.5f,  0.5f),glm::vec3(1.0f,  0.0f,  0.0f),glm::vec2(0.0f, 1.0f) }); // 5
        }
        else {
            vertices.push_back(Vertex{ glm::vec3(-0.5f,  0.5f,  0.5f),glm::vec3(-1.0f,  0.0f,  0.0f),glm::vec2(0.0f, 0.0f) }); // 0
            vertices.push_back(Vertex{ glm::vec3(-0.5f,  0.5f, -0.5f),glm::vec3(-1.0f,  0.0f,  0.0f),glm::vec2(1.0f, 0.0f) });  // 1
            vertices.push_back(Vertex{ glm::vec3(-0.5f, -0.5f, -0.5f),glm::vec3(-1.0f,  0.0f,  0.0f),glm::vec2(1.0f, 1.0f) });  // 2
            vertices.push_back(Vertex{ glm::vec3(-0.5f,  0.5f,  0.5f),glm::vec3(-1.0f,  0.0f,  0.0f),glm::vec2(0.0f, 0.0f) }); // 0
            vertices.push_back(Vertex{ glm::vec3(-0.5f, -0.5f, -0.5f),glm::vec3(-1.0f,  0.0f,  0.0f),glm::vec2(1.0f, 1.0f) });  // 2
            vertices.push_back(Vertex{ glm::vec3(-0.5f, -0.5f,  0.5f),glm::vec3(-1.0f,  0.0f,  0.0f),glm::vec2(0.0f, 1.0f) }); // 5
        }

		return vertices;
	}

}
