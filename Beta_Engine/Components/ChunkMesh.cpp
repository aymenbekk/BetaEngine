#include "ChunkMesh.h"




ChunkMesh::ChunkMesh() {

	for (int x = 0; x < 16; x++) {
		for (int y = 0; y < 16; y++) {
			for (int z = 0; z < 16; z++) {
				updateVertices(x, y, z);
			}
		}
	}

	VAO.Bind();

	VBO VBO(vertices);

	VAO.LinkAttrib(VBO, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
	VAO.LinkAttrib(VBO, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
	VAO.LinkAttrib(VBO, 2, 2, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));


	VAO.Unbind();
	VBO.Unbind();
}

void ChunkMesh::Draw(Shader* shader, Camera& camera) {
	shader->Activate();
	VAO.Bind();

	

	for (unsigned int i = 0; i < textures.size(); i++)
	{
		std::string myString = "texture";
		textures[i].texUnit(*shader, (myString + std::to_string(i + 1)).c_str(), i);
		glActiveTexture(textures[i].Unit);
		textures[i].Bind();
	}


	camera.Matrix(45.0f, 0.1f, 100.0f, *shader, "camMatrix");



	glDrawArrays(GL_TRIANGLES, 0,vertices.size());
}


//generate the bertices of  a block in a pos (x,y,z)
void ChunkMesh::updateVertices(int& x ,int& y,int& z) {

	vector<Vertex> FaceVertices;

	
	FaceVertices = Block::getBlockFace(BlockFace::Front);
	for (int i = 0; i < 6; i++) {
		vec3 pos = vec3(FaceVertices[i].position.x + (x - 8) / 2, FaceVertices[i].position.y + (y - 8) / 2, FaceVertices[i].position.z + (z - 8) / 2);
		vertices.push_back(Vertex{ pos, FaceVertices[i].color, FaceVertices[i].texUV });
		if (x==0 && y == 15 && z ==15) {
			cout << "max left front face" << endl;
			cout << "x : " << pos.x << "y : " << pos.y << "z : " << pos.z <<endl; //pushi i=5
		}
		if (x == 15 && y == 15 && z == 15) {
			cout << "max right front face" << endl;
			cout << "x : " << pos.x << "y : " << pos.y << "z : " << pos.z << endl; //pushi i=3
		}
	

	}
	FaceVertices = Block::getBlockFace(BlockFace::Back);
	for (int i = 0; i < 6; i++) {
		vec3 pos = vec3(FaceVertices[i].position.x + (x - 8) / 2, FaceVertices[i].position.y + (y - 8) / 2, FaceVertices[i].position.z + (z - 8) / 2);
		vertices.push_back(Vertex{ pos, FaceVertices[i].color, FaceVertices[i].texUV });
		if (x == 0 && y == 15 && z == 0) {
			cout << "max left back face" << endl;
			cout << "x : " << pos.x << "y : " << pos.y << "z : " << pos.z << endl; //pushi i=5
		}
		if (x == 15 && y == 15 && z == 0) {
			cout << "max right back face" << endl;
			cout << "x : " << pos.x << "y : " << pos.y << "z : " << pos.z << endl;//pushi i=3
		}

	}
	FaceVertices = Block::getBlockFace(BlockFace::Top);
	for (int i = 0; i < 6; i++) {
		vec3 pos = vec3(FaceVertices[i].position.x + (x - 8) / 2, FaceVertices[i].position.y + (y - 8) / 2, FaceVertices[i].position.z + (z - 8) / 2);
		vertices.push_back(Vertex{ pos, FaceVertices[i].color, FaceVertices[i].texUV });

	}

	FaceVertices = Block::getBlockFace(BlockFace::Bottom);
	for (int i = 0; i < 6; i++) {
		vec3 pos = vec3(FaceVertices[i].position.x + (x - 8) / 2, FaceVertices[i].position.y + (y - 8) / 2, FaceVertices[i].position.z + (z - 8) / 2);
		vertices.push_back(Vertex{ pos, FaceVertices[i].color, FaceVertices[i].texUV });

	}

	FaceVertices = Block::getBlockFace(BlockFace::Left);
	for (int i = 0; i < 6; i++) {
		vec3 pos = vec3(FaceVertices[i].position.x + (x - 8) / 2, FaceVertices[i].position.y + (y - 8) / 2, FaceVertices[i].position.z + (z - 8) / 2);
		vertices.push_back(Vertex{ pos, FaceVertices[i].color, FaceVertices[i].texUV });

	}


	FaceVertices = Block::getBlockFace(BlockFace::Right);
	for (int i = 0; i < 6; i++) {
		vec3 pos = vec3(FaceVertices[i].position.x + (x - 8) / 2, FaceVertices[i].position.y + (y - 8) / 2, FaceVertices[i].position.z + (z - 8) / 2);
		vertices.push_back(Vertex{ pos, FaceVertices[i].color, FaceVertices[i].texUV });
		

	}

}