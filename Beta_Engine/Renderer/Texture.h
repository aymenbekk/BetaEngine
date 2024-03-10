#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include "../../third_party/stb/stb_image.h"
#include "Shader.h"

class Texture {

public:
	GLuint ID;
	GLenum type;
	GLenum Unit;
	Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);

	void texUnit(Shader& shader, const char* uniform, GLuint unit);

	void Bind();

	void Unbind();

	void Delete();
};




#endif // !TEXTURE_H
