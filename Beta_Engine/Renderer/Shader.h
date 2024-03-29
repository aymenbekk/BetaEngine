#ifndef SHADER_H
#define SHADER_H

#include "../../third_party/glad/include/glad/glad.h"
#include <GLFW/glfw3.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>
using namespace std;

string get_file_contents(const char* filename);

class Shader {

public:

	GLuint ID;

	Shader(const char* vertexFile, const char* fragmentFile);

	void Activate();

	//void Delete();

	//void setString();


	void compileErrors(unsigned int shader, const char* type);
};

#endif // !SHADER_H
