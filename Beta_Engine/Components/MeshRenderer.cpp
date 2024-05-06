#include "MeshRenderer.h"



MeshRenderer::MeshRenderer(Mesh* mesh):mesh(mesh) {


	VAO.Bind();

	VBO VBO(mesh->vertices);

	EBO EBO(mesh->indices);


	VAO.LinkAttrib(VBO, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
	VAO.LinkAttrib(VBO, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
	VAO.LinkAttrib(VBO, 2, 2, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));



	VAO.Unbind();
	VBO.Unbind();
	EBO.Unbind();
}

void MeshRenderer::Render(Shader* shader, Camera& camera)
{

	shader->Activate();
	VAO.Bind();



	for (unsigned int i = 0; i < mesh->textures.size(); i++)
	{
		std::string myString = "texture";
		mesh->textures[i].texUnit(*shader, (myString + std::to_string(i + 1)).c_str(), i);
		glActiveTexture(mesh->textures[i].Unit);
		mesh->textures[i].Bind();
	}


	camera.Matrix(45.0f, 0.1f, 100.0f, *shader, "camMatrix");



	glDrawElements(GL_TRIANGLES, mesh->indices.size(), GL_UNSIGNED_INT, 0);
}