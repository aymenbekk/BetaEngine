#include "ChunkMesh.h"




ChunkMesh::ChunkMesh():vao() {

	vector<vector<float>> noiseData;

	noiseData = Noise::generateNoise();

	float cellsheights[16][16];
	for (int y = 0; y < 16; y++) {
		for (int x = 0; x < 16; x++) {
			
			cellsheights[x][y] = trunc((noiseData[x][y] + 1)*7.5);
			if (cellsheights[x][y] == 0) {
				cellsheights[x][y] = 1;
			}
		
		
		}
	}

	
	
	for (int x = 0; x < 16; x++) {
			for (int z = 0; z < 16; z++) {
				for (int y = 0; y < cellsheights[x][z]; y++) {
					
					blocks[x][y][z] = true;
			}
		}
	}


	//aya we fel update vertices el faces nrigelhom 3la hssab el bool blocks lakan hda dak el cube a droite a block (blocks[x+1][y][z] = true ) donc mandiroloch face right ..etc
	for (int x = 0; x < 16; x++) {
		for (int z = 0; z < 16; z++) {
			for (int y = 0; y < cellsheights[x][z]; y++) {
				updateVertices(x, y, z);
			}
		}
	}

	chunkBorders.push_back(borderBL);
	chunkBorders.push_back(borderBR);
	chunkBorders.push_back(borderFL);
	chunkBorders.push_back(borderFR);

	//VAO.Bind();
	vao.Bind();
	VBO vbo(vertices);

	vao.LinkAttrib(vbo, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
	vao.LinkAttrib(vbo, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
	vao.LinkAttrib(vbo, 2, 2, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));


	vao.Unbind();
	vbo.Unbind();
}

void ChunkMesh::Draw(Shader* shader, Camera& camera) {
	/*shader->Activate();
	VAO.Bind();

	

	for (unsigned int i = 0; i < textures.size(); i++)
	{
		std::string myString = "texture";
		textures[i].texUnit(*shader, (myString + std::to_string(i + 1)).c_str(), i);
		glActiveTexture(textures[i].Unit);
		textures[i].Bind();
	}


	camera.Matrix(45.0f, 0.1f, 100.0f, *shader, "camMatrix");



	glDrawArrays(GL_TRIANGLES, 0,vertices.size());*/
}


//generate the bertices of  a block in a pos (x,y,z)
void ChunkMesh::updateVertices(int& x ,int& y,int& z) {

	vector<Vertex> FaceVertices;

	
	FaceVertices = Block::getBlockFace(BlockFace::Front);
	if (z == 15 || blocks[x][y][z + 1] != true)
		for (int i = 0; i < 6; i++) {
			vec3 pos = vec3(FaceVertices[i].position.x + (x - 8), FaceVertices[i].position.y + (y - 8), FaceVertices[i].position.z + (z - 8));
			vertices.push_back(Vertex{ pos, FaceVertices[i].color, FaceVertices[i].texUV });
			if (x == 0 && y == 15 && z == 15 && i == 5) {
				//cout << "max left front face" << endl;
				//cout << "x : " << pos.x << "y : " << pos.y << "z : " << pos.z <<endl; //pushi i=5
				/*chunkBorders.push_back(pos);*/
				borderFL = pos;

			}
			if (x == 15 && y == 15 && z == 15 && i == 3) {
				//cout << "max right front face" << endl;
				//cout << "x : " << pos.x << "y : " << pos.y << "z : " << pos.z << endl; //pushi i=3
				borderFR = pos;
			}

		}
	
	 FaceVertices = Block::getBlockFace(BlockFace::Back);
	 if (z == 0 || blocks[x][y][z - 1] != true)
		for (int i = 0; i < 6; i++) {
			vec3 pos = vec3(FaceVertices[i].position.x + (x - 8), FaceVertices[i].position.y + (y - 8), FaceVertices[i].position.z + (z - 8));
			vertices.push_back(Vertex{ pos, FaceVertices[i].color, FaceVertices[i].texUV });
			//if (x == 0 && y == 15 && z == 0 && i == 5) {
			//	cout << "max left back face" << endl;
			//	cout << "x : " << pos.x << "y : " << pos.y << "z : " << pos.z << endl; //pushi i=5

			//	borderBL = pos;
			//}
			//if (x == 15 && y == 15 && z == 0) {
			//	cout << "max right back face" << endl;
			//	cout << "x : " << pos.x << "y : " << pos.y << "z : " << pos.z << endl;//pushi i=3
			//	borderBR = pos;
			//}

		}
	
	FaceVertices = Block::getBlockFace(BlockFace::Top);
	if (y == 15 || blocks[x][y + 1][z] != true)
		for (int i = 0; i < 6; i++) {
			vec3 pos = vec3(FaceVertices[i].position.x + (x - 8), FaceVertices[i].position.y + (y - 8), FaceVertices[i].position.z + (z - 8));
			vertices.push_back(Vertex{ pos, FaceVertices[i].color, FaceVertices[i].texUV });

		}

	FaceVertices = Block::getBlockFace(BlockFace::Bottom);
	if (y == 0 || blocks[x][y - 1][z] != true)
		for (int i = 0; i < 6; i++) {
			vec3 pos = vec3(FaceVertices[i].position.x + (x - 8), FaceVertices[i].position.y + (y - 8), FaceVertices[i].position.z + (z - 8));
			vertices.push_back(Vertex{ pos, FaceVertices[i].color, FaceVertices[i].texUV });

		}

	FaceVertices = Block::getBlockFace(BlockFace::Left);
	if (x == 0 || blocks[x - 1][y][z] != true)
		for (int i = 0; i < 6; i++) {
			vec3 pos = vec3(FaceVertices[i].position.x + (x - 8), FaceVertices[i].position.y + (y - 8), FaceVertices[i].position.z + (z - 8));
			vertices.push_back(Vertex{ pos, FaceVertices[i].color, FaceVertices[i].texUV });

		}


	FaceVertices = Block::getBlockFace(BlockFace::Right);
	if (x == 15 || blocks[x + 1][y][z] != true)
		for (int i = 0; i < 6; i++) {
			vec3 pos = vec3(FaceVertices[i].position.x + (x - 8) , FaceVertices[i].position.y + (y - 8) , FaceVertices[i].position.z + (z - 8) );
			vertices.push_back(Vertex{ pos, FaceVertices[i].color, FaceVertices[i].texUV });

		}

}


void ChunkMesh::addBlock(glm::vec3 placePoint) {

	vector<Vertex> FaceVertices;

	printf("dkhalna .\n");
	FaceVertices = Block::getBlockFace(BlockFace::Front);

		for (int i = 0; i < 6; i++) {
			vec3 pos = vec3(FaceVertices[i].position.x + (placePoint.x ), FaceVertices[i].position.y + (placePoint.y ), FaceVertices[i].position.z + (placePoint.z ));
			vertices.push_back(Vertex{ pos, FaceVertices[i].color, FaceVertices[i].texUV });

		}

	FaceVertices = Block::getBlockFace(BlockFace::Back);

		for (int i = 0; i < 6; i++) {
			vec3 pos = vec3(FaceVertices[i].position.x + (placePoint.x), FaceVertices[i].position.y + (placePoint.y), FaceVertices[i].position.z + (placePoint.z));
			vertices.push_back(Vertex{ pos, FaceVertices[i].color, FaceVertices[i].texUV });

		}

	FaceVertices = Block::getBlockFace(BlockFace::Top);

		for (int i = 0; i < 6; i++) {
			vec3 pos = vec3(FaceVertices[i].position.x + (placePoint.x), FaceVertices[i].position.y + (placePoint.y), FaceVertices[i].position.z + (placePoint.z));
			vertices.push_back(Vertex{ pos, FaceVertices[i].color, FaceVertices[i].texUV });

		}

	FaceVertices = Block::getBlockFace(BlockFace::Bottom);

		for (int i = 0; i < 6; i++) {
			vec3 pos = vec3(FaceVertices[i].position.x + (placePoint.x), FaceVertices[i].position.y + (placePoint.y), FaceVertices[i].position.z + (placePoint.z));
			vertices.push_back(Vertex{ pos, FaceVertices[i].color, FaceVertices[i].texUV });

		}

	FaceVertices = Block::getBlockFace(BlockFace::Left);

		for (int i = 0; i < 6; i++) {
			vec3 pos = vec3(FaceVertices[i].position.x + (placePoint.x), FaceVertices[i].position.y + (placePoint.y), FaceVertices[i].position.z + (placePoint.z));
			vertices.push_back(Vertex{ pos, FaceVertices[i].color, FaceVertices[i].texUV });

		}


	FaceVertices = Block::getBlockFace(BlockFace::Right);
	
		for (int i = 0; i < 6; i++) {
			vec3 pos = vec3(FaceVertices[i].position.x + (placePoint.x), FaceVertices[i].position.y + (placePoint.y), FaceVertices[i].position.z + (placePoint.z));
			vertices.push_back(Vertex{ pos, FaceVertices[i].color, FaceVertices[i].texUV });

		}
		vao.Bind();
		VBO vbo(vertices);

		vao.LinkAttrib(vbo, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
		vao.LinkAttrib(vbo, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
		vao.LinkAttrib(vbo, 2, 2, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));


		vao.Unbind();
		vbo.Unbind();

};

//void ChunkMesh::update() {
//
//}