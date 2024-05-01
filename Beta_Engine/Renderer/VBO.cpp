#include "VBO.h"


VBO::VBO(vector<Vertex>& vertices) {

	glGenBuffers(1,&ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(),GL_STATIC_DRAW);

}


void VBO::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::BindToIndex(int index) 
{
	glBindVertexBuffer(0, ID, 0, sizeof(Vertex));
}


void VBO::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}


void VBO::Delete()
{
	glDeleteBuffers(1, &ID);
}