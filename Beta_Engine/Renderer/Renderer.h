#ifndef RENDERER_H
#define RENDERER_h

#include <glad/glad.h>
#include <iostream>
#include <list>
#include "Shader.h"
#include "../Scene/Entity.h"
using namespace std;



class Renderer {

public:
	Renderer(Camera& camera);

	void RenderScene(Entity* root, list<Shader*>& shaders);

	void Renderer::Draw(Entity* e);

	Camera* getCamera() { return &camera; };

	
private:
	Camera camera;
	list<Shader*> shaders;
	Shader* Renderer::findShaderByID(GLuint ID);


};


#endif // !RENDERER.H
