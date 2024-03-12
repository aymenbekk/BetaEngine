#ifndef ENGINE_CLASS_H
#define ENGINE_CLASS_H

using namespace std;
#include <vector>
#include"../Beta.h"
#include "../Renderer/Renderer.h"
#include "../Scene/Entity.h"
#include "Window.h"


class Engine {

public :


	Engine(Window& window);
	

	void init();

	void start(Renderer& renderer, vector<Entity* >& scenes);

	


private :

	//Renderer renderer;
	//vector<Entity* > scenes;
	Window window;
	vector<Shader*> shaders;
	vector<pair<const char*, const char*>> shadersPaths;
	bool isRuning();



};

#endif