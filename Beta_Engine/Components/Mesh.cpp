#include "Mesh.h"


Mesh::Mesh(vector <Vertex>& vertices, vector <GLuint>& indices, vector<Texture>& textures):vertices(vertices),indices(indices),textures(textures) {

	//Mesh::vertices = vertices;
	//Mesh::indices = indices;
	//Mesh::textures = textures;
	

	//VAO.Bind();

	//VBO VBO(vertices);

	//EBO EBO(indices);


	//VAO.LinkAttrib(VBO, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
	//VAO.LinkAttrib(VBO, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
	//VAO.LinkAttrib(VBO, 2, 2, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));



	//VAO.Unbind();
	//VBO.Unbind();
	//EBO.Unbind();
}

Mesh::Mesh() {

}

//void Mesh::Draw(Shader* shader, Camera& camera)
//{
//	shader->Activate();
//	VAO.Bind();
//	
//
//
//	for (unsigned int i = 0; i < textures.size(); i++)
//	{
//		std::string myString = "texture";
//		textures[i].texUnit(*shader, (myString + std::to_string(i + 1)).c_str(), i);
//		glActiveTexture(textures[i].Unit);
//		textures[i].Bind();
//	}
//
//
//	camera.Matrix(45.0f, 0.1f, 100.0f, *shader, "camMatrix");
//
//
//
//	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
//}

//
//void Mesh::update() {
//
//}