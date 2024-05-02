#ifndef RENDERER_H
#define RENDERER_h

#include <glad/glad.h>
#include <iostream>
#include <list>
#include "Shader.h"
#include "../Scene/Entity.h"
using namespace std;

void printMat4(const glm::mat4& matrix);

class Renderer {

public:
	Renderer(Camera& camera, vector<pair<const char*, const char*>>& shadersPaths);

	void RenderScene(Entity* root);

	void Draw(Entity* e);

	void DrawWorld(Entity* root);

	Camera* getCamera() { return &camera; };

	vector<Shader*> getShaders() { return shaders; };
	
private:
	Camera camera;
	vector<Shader*> shaders;
	Shader* Renderer::findShaderByID(size_t Index);


};


#endif // !RENDERER.H
