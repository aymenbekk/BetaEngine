#ifndef BLOCK_H
#define BLOCK_H

#include "vector"
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>
#include "../Renderer/VBO.h"

using namespace glm;
using namespace std;



enum BlockFace {
	Top,Bottom,Front,Back,Right,Left
};

namespace  Block {
	

	vector<Vertex> getBlockFace(BlockFace face);
};


#endif