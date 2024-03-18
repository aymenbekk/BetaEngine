#ifndef CHUNK_MESH_H
#define CHUNK_MESH_H

#include "Mesh.h"
#include "Block.h"

//namespace Chunk {
//	std::size_t Width = 16, Height = 16, Depth = 16;
//}

class ChunkMesh : public Mesh {

public:

	ChunkMesh();

	void Draw(Shader* shader, Camera& camera) override;



private:
	/*const bool blocks[Chunk::Width][Chunk::Height][Chunk::Depth];*/
	void updateVertices(int& x, int& y, int& z);
};

#endif // ! CHUNK_MESH_H

