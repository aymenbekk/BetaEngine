#ifndef VBO_H
#define VBO_H

#include "../../third_party/glad/include/glad/glad.h"
#include <../../third_party/glm/glm/glm.hpp>
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

	void BindToIndex(int index);

	void Unbind();

	void Delete();

};



#endif // !VBO_H
