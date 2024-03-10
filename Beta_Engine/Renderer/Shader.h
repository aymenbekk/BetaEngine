#ifndef SHADER_H
#define SHADER_H

#include "../Beta.h"
using namespace std;

string get_file_contents(const char* filename);

class Shader {

public:

	GLuint ID;

	Shader(const char* vertexFile, const char* fragmentFile);

	void Activate();

	//void Delete();

	//void setString();
private:

	void compileErrors(unsigned int shader, const char* type);
};

#endif // !SHADER_H
