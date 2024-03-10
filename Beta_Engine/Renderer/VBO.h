#ifndef VBO_H
#define VBO_H

#include "glm/glm.hpp"
#include "../third_party/glad/include/glad/glad.h"
#include "vector"
using namespace glm;
using namespace std;

struct Vertex {

	vec3 position;
	vec3 color;
	vec2 texUV;
};

class VBO {

public:
	GLuint ID;

	VBO(vector<Vertex>& vertices);

	void Bind();

	void Unbind();

	void Delete();

};



#endif // !VBO_H
