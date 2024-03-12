#ifndef MESH_H
#define MESH_H


#include "vector"
#include "../Renderer/EBO.h"
#include "../Renderer/VAO.h"
#include "../Scene/Camera.h"
#include "../Renderer/Texture.h"
#include "Component.h"
using namespace std;


class Mesh : public Component
{
public:

	vector <Vertex> vertices;
	vector <GLuint> indices;
	vector <Texture> textures;

	VAO VAO;

	Mesh(vector <Vertex>& vertices, vector <GLuint>& indices, vector<Texture>& textures);
	~Mesh();

	void Draw(Shader* shader, Camera& camera);



};

#endif