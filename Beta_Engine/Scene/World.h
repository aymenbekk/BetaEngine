#ifndef WORLD_H
#define WORLD_H
#include "Entity.h"
#include "../Components/ChunkMesh.h"
#include "../Core/Window.h"
#include "../Utils/MousePicker.h"
#include <list>
struct DrawArraysCommand {
	GLuint vertexCount;
	GLuint instanceCount;
	GLuint firstIndex;
	GLuint baseInstance;
};

class World : public Entity
{
public:
	World(const string& tag, size_t shaderIndex, Transform* transfor) ;
	

	void addChunks(char* direction);

	void Draw(Camera& camera, Shader* shader)override;


	void generateChunks(const glm::vec3& center, float range);

	bool isChunkExist(const glm::vec3& position);

	void load(glm::vec3 position);


	void deleteChunks(const glm::vec3& center, float range);
	void unload(glm::vec3 position);
	void generateStaticTerrain();

	void DrawNewBlocks();
	void printMat4(const glm::mat4& matrix);

private:
	VAO Newvao;
	//Entity* root;//Entity=Chunk each Chunk has a transform
	vector<int> count_Vertices_per_Chunk;

	//containe the vertices of all the chunks
	vector<Vertex> worldVertices;

	vector<ChunkMesh*> chunks;

	void generateDrawCommands();

	

	MousePicker* MPicker;
	//GLuint Id;//drawIndirect buffer iD


	Texture* soilText;

	void addBlock(glm::vec3 placePoint);

	std::vector<glm::vec3> loadedChunks;

	
};




#endif // !WORLD_H
