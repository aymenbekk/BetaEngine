#ifndef CHUNK_MESH_H
#define CHUNK_MESH_H

#include "Mesh.h"
#include "Block.h"

//namespace Chunk {
//	std::size_t Width = 16, Height = 16, Depth = 16;
//}

class ChunkMesh : public Mesh {

public:
	vector<vec3> chunkBorders;

	ChunkMesh();

	void Draw(Shader* shader, Camera& camera) override;

	void update() override;

private:
	/*const bool blocks[Chunk::Width][Chunk::Height][Chunk::Depth];*/
	vec3 borderBL;
	vec3 borderBR;
	vec3 borderFL;
	vec3 borderFR;

    bool blocks[16][16][16];

	void updateVertices(int& x, int& y, int& z);


};

#endif // ! CHUNK_MESH_H

