#include "World.h"
#include "../Components/ChunkMesh.h"
//#include <boost/stacktrace.hpp>
#include <iomanip> /
#include <string>
#include <iostream>
#include <thread>

World::World(const string& tag, size_t shaderIndex, Transform* transfor) :Entity(tag, shaderIndex, transfor),Newvao() {

	

	this->soilText = new Texture("assets/soil.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	MPicker = new MousePicker();
	

	/*generateStaticTerrain();*/


	//vao = new VAO();
	//vao->Bind();
	//VBO VBO(worldVertices);

	//vao->LinkAttrib(VBO, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
	//vao->LinkAttrib(VBO, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
	//vao->LinkAttrib(VBO, 2, 2, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));


	//vao->Unbind();
	//VBO.Unbind();
	
	//Sets up the format, *without* a buffer object.


	//std::cout << "Before glVertexAttribFormat:\n" << boost::stacktrace::stacktrace() << std::endl;
	//glEnableVertexAttribArray(0);
	//glVertexAttribFormat(0, 3, GL_FLOAT, sizeof(Vertex), offsetof(Vertex,position));

	//glEnableVertexAttribArray(1);
	//glVertexAttribFormat(1, 3, GL_FLOAT, sizeof(Vertex), offsetof(Vertex, color));
	//
	//glEnableVertexAttribArray(2);
	//glVertexAttribFormat(2, 2, GL_FLOAT, sizeof(Vertex), offsetof(Vertex, texUV));



	////Sets up where the buffer object comes from
	//glVertexAttribBinding(0, 0);
	//Enable VAO

	

	//Done with VAO
	glBindVertexArray(0);

	//this->generateDrawCommands();

	//GLFWwindow* wind = this->window.get_GLFW_Window();
	//if (this->window.window != nullptr) {
	//	double mousePosX, mousePosY;
	//	glfwGetCursorPos(wind, &mousePosX, &mousePosY);

	//	std::cout << mousePosX << endl;
	//	std::cout << mousePosY << endl;
	//}
	//else {
	//	// Handle the case where window.window is null
	//	std::cerr << "Error: GLFW window pointer is null." << std::endl;
	//}



	
}


//void callDraw() {
//	glMultiDrawArraysIndirect(GL_TRIANGLES, NULL, 4, 0);
//}

void World::Draw(Camera& camera,Shader* shader) {
	

	shader->Activate();

	camera.Matrix(45.0f, 0.1f, 100.0f, *shader, "camMatrix");
	//glBindBuffer(GL_DRAW_INDIRECT_BUFFER, Id);
	//callDraw();


	MPicker->update(&camera);


	/*generateChunks(camera.Position, 2.0f);*/
	

	if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_Y) == GLFW_PRESS)
	{
		glm::vec3 placingPoint = MPicker->getPointOnRay(MPicker->getCurrentRay(), 2.0f, &camera);
		chunks[chunks.size()-3]->addBlock(placingPoint);

		std::cout << "placing point : " << placingPoint.x << "/" << placingPoint.y << "/" << placingPoint.z << endl;

	}
	
	
	generateChunks(camera.Position,1.0f);
	/*deleteChunks(camera.Position, 2.0f);*/
	
	std::string myString = "texture1";
	soilText->texUnit(*shader, myString.c_str(), 0);
	glActiveTexture(soilText->Unit);
	soilText->Bind();


	for (int i = 0; i < childs.size(); i++) {
		glUniformMatrix4fv(glGetUniformLocation(shader->ID, "model"), 1, GL_FALSE, glm::value_ptr(childs[i]->getTransform()->getWorldMatrix()));
		chunks[i]->getVAO().Bind();
		glDrawArrays(GL_TRIANGLES, 0, chunks[i]->vertices.size());
	}

	if (addedBlocks.size() != 0) {
		glUniformMatrix4fv(glGetUniformLocation(shader->ID, "model"), 1, GL_FALSE, glm::value_ptr(childs[childs.size()-1]->getTransform()->getWorldMatrix()));
		DrawNewBlocks();
	}
	
}




void World::generateDrawCommands() {
	/*DrawArraysCommand DrawCommands[4];


	for (unsigned int i = 0; i < childs.size(); i++) {
		DrawCommands[i].vertexCount = count_Vertices_per_Chunk[i];
		DrawCommands[i].instanceCount = 1;
		if (i == 0) {
			DrawCommands[i].firstIndex = 0;
		}
		else {
			DrawCommands[i].firstIndex = count_Vertices_per_Chunk[i-1];
		}
		DrawCommands[i].baseInstance = i;
		

	}*/


	//DrawArraysCommand drawCommands[] = {
	//  {3, 1, 0, 0},   // Draw the first triangle
	//  {3, 1, 3, 0}    // Draw the second triangle
	//};

	// Create and bind a buffer object for draw commands
	//GLuint drawBuffer;
	//glGenBuffers(1, &drawBuffer);
	//glBindBuffer(GL_DRAW_INDIRECT_BUFFER, drawBuffer);
	//glBufferData(GL_DRAW_INDIRECT_BUFFER, sizeof(drawCommands), drawCommands, GL_STATIC_DRAW);
	//
	//std::cout << "Creating Indirect buffer object..." << std::endl;


	//glGenBuffers(1, &Id);
	//glBindBuffer(GL_DRAW_INDIRECT_BUFFER, Id);
	//glBufferData(GL_DRAW_INDIRECT_BUFFER, sizeof(DrawCommands), DrawCommands, GL_STATIC_DRAW);
	//std::cout << "Indirect Buffer object created: " << Id << std::endl;

	////drwk necriyi array fih ga3 el world(model) matrices ta3 each chunk ndirhom fe dak el array nhoto fe VBO we 9ablo necriyi we nbindi VAO nzid ndir layout jdid fe shader nsemih translation (fe learn openGL tzid tefha)
	//glm::mat4* modelMatrices;
	//modelMatrices = new glm::mat4[childs.size()];
	//for (int i = 0; i < childs.size(); i++) {
	//	modelMatrices[i] = childs[i]->getTransform()->getWorldMatrix();
	//}

	//unsigned int buffer;
	//glGenBuffers(1, &buffer);
	//glBindBuffer(GL_ARRAY_BUFFER, buffer);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(modelMatrices), modelMatrices, GL_STATIC_DRAW);
	//VAO.Bind();
	//glEnableVertexAttribArray(3);
	//glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)0);
	//glEnableVertexAttribArray(4);
	//glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(glm::vec4)));
	//glEnableVertexAttribArray(5);
	//glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(2 * sizeof(glm::vec4)));
	//glEnableVertexAttribArray(6);
	//glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(3 * sizeof(glm::vec4)));

	//glVertexAttribDivisor(3, 1);
	//glVertexAttribDivisor(4, 1);
	//glVertexAttribDivisor(5, 1);
	//glVertexAttribDivisor(6, 1);
	//glBindVertexArray(0);

}




 void World::generateChunks(const glm::vec3& ccamPos, float range) {
	
	 std::cout << loadedChunks.size() << endl;
	 glm::vec3 min = ccamPos - glm::vec3(range);
	 glm::vec3 max = ccamPos + glm::vec3(range);
	 std::cout << "min : " << min.x << "/" << min.y << "/" << min.z << endl;
	 for (int x = min.x; x <= max.x; x +=1) {
			 for (int z = min.z; z <= max.z; z+=1) {
				 printf("CCCCCC");
				 glm::vec3 chunkPosition(x*16, 0.0f, z*16);
				 if (isChunkExist(chunkPosition) == false) {
					 load(chunkPosition);
				 }
			 }
	 }

	 printf("SIZE.\n" );
	 std::cout << loadedChunks.size() << endl;

 }

 void World::generateStaticTerrain() {
	 vec3 positionn = { 0.0f ,0.0f,0.0f };
	 vec3 eulerRotation = { 0.0f,0.0f,0.0f };
	 vec3 scale = { 1.0f,1.0f,1.0f };
	 Transform* transform = new Transform(positionn, eulerRotation, scale);


	 //size_t shaderIndex = 0;
	 for (int x = 0; x < 5; x++) {
		 for (int z = 0; z < 5; z++) {

			 
				 positionn = { (float)x * 16 ,0.0f,(float)z * 16 };
		

			 eulerRotation = { 0.0f,0.0f,0.0f };
			 scale = { 1.0f,1.0f,1.0f };
			 transform = new Transform(positionn, eulerRotation, scale);


			 const string tag2 = "chunk/" + std::to_string(x) + "/" + std::to_string(z);

			 printf("dkhalna .\n");
			 ChunkMesh* chunkMesh = new ChunkMesh();
			 chunks.push_back(chunkMesh);
			
			 this->AddChild(new Entity(tag2, 0, transform));


		 }
	 }
 }
 

 bool World::isChunkExist(const glm::vec3& position) {
	 for (int i = 0; i < loadedChunks.size(); i++) {
		 if (loadedChunks.at(i) == position)
		 {
			 printf("dkhalna.\n");
			 return true;
		 }
	 }
	 return false;
	
 }

 void World::load(glm::vec3 position) {

	 std::cout << "Position" << position.x << "/" << position.y << "/" << position.z << endl;
	 size_t shaderIndex = 0;
	 glm::vec3 eulerRotation = { 0.0f,0.0f,0.0f };
	 glm::vec3 scale = { 1.0f,1.0f,1.0f };
	 Transform* transform = new Transform(position, eulerRotation, scale);


	 const string tag2 = "chunk/" + std::to_string(position.x) + std::to_string(position.y) + "/" + std::to_string(position.z);
	 ChunkMesh* chunkMesh = new ChunkMesh();
	 chunks.push_back(chunkMesh);
	 this->AddChild(new Entity(tag2, shaderIndex, transform));

	 loadedChunks.push_back(position);
 }

 void World::deleteChunks(const glm::vec3& center, float range) {
	 for (int i = 0; i < loadedChunks.size(); i++) {
		 glm::vec3 chunkPosition = loadedChunks.at(i);
		 if (glm::distance(glm::vec3(chunkPosition.x,0,chunkPosition.z), center) > range) {
			 printf("deleted.\n");
			 std::cout << "distance : " << glm::distance(chunkPosition, center) << endl;
			 unload(chunkPosition);
			 loadedChunks.erase(loadedChunks.begin() + i);
			 
		 }
		
	 }
 }


 void World::unload(glm::vec3 position) {

	 const string tag = "chunk/" + std::to_string(position.x) + std::to_string(position.y) + "/" + std::to_string(position.z);
	 for (int i = 0; i < childs.size(); i++) {
		 if (childs[i]->getTag() == tag) {
			 childs.erase(childs.begin() + i);
			 chunks.erase(chunks.begin() + i);
			 break;
		 }
	 }


 }



 void World::addBlock(glm::vec3 position) {


	 vector<Vertex> FaceVertices;

	 printf("dkhalna .\n");
	 FaceVertices = Block::getBlockFace(BlockFace::Front);

	 for (int i = 0; i < 6; i++) {
		 vec3 pos = vec3(FaceVertices[i].position.x + (position.x), FaceVertices[i].position.y + (position.y), FaceVertices[i].position.z + (position.z));
		 addedBlocks.push_back(Vertex{ pos, FaceVertices[i].color, FaceVertices[i].texUV });
	 }

	 FaceVertices = Block::getBlockFace(BlockFace::Back);

	 for (int i = 0; i < 6; i++) {
		 vec3 pos = vec3(FaceVertices[i].position.x + (position.x), FaceVertices[i].position.y + (position.y), FaceVertices[i].position.z + (position.z));
		 addedBlocks.push_back(Vertex{ pos, FaceVertices[i].color, FaceVertices[i].texUV });

	 }

	 FaceVertices = Block::getBlockFace(BlockFace::Top);

	 for (int i = 0; i < 6; i++) {
		 vec3 pos = vec3(FaceVertices[i].position.x + (position.x), FaceVertices[i].position.y + (position.y), FaceVertices[i].position.z + (position.z));
		 addedBlocks.push_back(Vertex{ pos, FaceVertices[i].color, FaceVertices[i].texUV });

	 }

	 FaceVertices = Block::getBlockFace(BlockFace::Bottom);

	 for (int i = 0; i < 6; i++) {
		 vec3 pos = vec3(FaceVertices[i].position.x + (position.x), FaceVertices[i].position.y + (position.y), FaceVertices[i].position.z + (position.z));
		 addedBlocks.push_back(Vertex{ pos, FaceVertices[i].color, FaceVertices[i].texUV });

	 }

	 FaceVertices = Block::getBlockFace(BlockFace::Left);

	 for (int i = 0; i < 6; i++) {
		 vec3 pos = vec3(FaceVertices[i].position.x + (position.x), FaceVertices[i].position.y + (position.y), FaceVertices[i].position.z + (position.z));
		 addedBlocks.push_back(Vertex{ pos, FaceVertices[i].color, FaceVertices[i].texUV });

	 }


	 FaceVertices = Block::getBlockFace(BlockFace::Right);

	 for (int i = 0; i < 6; i++) {
		 vec3 pos = vec3(FaceVertices[i].position.x + (position.x), FaceVertices[i].position.y + (position.y), FaceVertices[i].position.z + (position.z));
		 addedBlocks.push_back(Vertex{ pos, FaceVertices[i].color, FaceVertices[i].texUV });

	 }
	
 }

 void World::DrawNewBlocks() {
	 Newvao.Bind();
	 VBO vbo(addedBlocks);

	 Newvao.LinkAttrib(vbo, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
	 Newvao.LinkAttrib(vbo, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
	 Newvao.LinkAttrib(vbo, 2, 2, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));

	 glDrawArrays(GL_TRIANGLES, 0, addedBlocks.size());

 }