#include "Mesh.h"


Mesh::Mesh(vector <Vertex>& vertices, vector <GLuint>& indices, vector<Texture>& textures):vertices(vertices),indices(indices),textures(textures) {

	Mesh::vertices = vertices;
	Mesh::indices = indices;
	Mesh::textures = textures;
	cout << "hihihi" << endl;

	VAO.Bind();

	VBO VBO(vertices);

	EBO EBO(indices);


	VAO.LinkAttrib(VBO, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
	VAO.LinkAttrib(VBO, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
	VAO.LinkAttrib(VBO, 2, 2, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));



	VAO.Unbind();
	VBO.Unbind();
	EBO.Unbind();
}
void Mesh::Draw(Shader* shader, Camera& camera)
{
	glm::vec3 surfacePos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::mat4 surfaceModel = glm::mat4(1.0f);
	surfaceModel = glm::translate(surfaceModel, surfacePos);
	// Bind shader to be able to access uniforms
	Shader shaderProgram("assets/shaders/shader.vert", "assets/shaders/shader.frag");
	glUseProgram(shader->ID);
	glUniformMatrix4fv(glGetUniformLocation(shader->ID, "model"), 1, GL_FALSE, glm::value_ptr(surfaceModel));
	VAO.Bind();
	


	for (unsigned int i = 0; i < textures.size(); i++)
	{
		std::string myString = "texture";
		textures[i].texUnit(shaderProgram, (myString + std::to_string(i + 1)).c_str(), i);
		glActiveTexture(textures[i].Unit);
		textures[i].Bind();
	}


	camera.Matrix(45.0f, 0.1f, 100.0f, shaderProgram, "camMatrix");


	cout << "item1 " << vertices[0].position.x << "y : " << vertices[1].position.x << endl;
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}