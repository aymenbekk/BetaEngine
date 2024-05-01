#ifndef  MESH_RENDERER_H
#define MESH_RENDERER_H
#include "Component.h"
#include "Mesh.h"

class MeshRenderer : public Component
{

public:

	MeshRenderer(Mesh* mesh) ;
	MeshRenderer();

	//void Render(Shader* shader, Camera& camera) override;
	VAO VAO;

private:
	Mesh* mesh;
};

#endif // ! MESH_RENDERER_H
