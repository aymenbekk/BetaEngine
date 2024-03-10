#ifndef EBO_H
#define EBO_H

#include <glad/glad.h>
#include<vector>

using namespace std;

class EBO
{
public:

	GLuint ID;

	EBO(vector<GLuint>& indices);


	void Bind();

	void Unbind();

	void Delete();
};

#endif // !EBO_H




