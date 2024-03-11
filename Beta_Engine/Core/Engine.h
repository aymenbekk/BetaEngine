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


	Engine(vector<Entity*>& scenes,Window& window,Renderer& renderer, vector<pair<const char*, const char*>>& shadersPaths);
	

	void init();

	void start();

	


private :

	Renderer renderer;
	vector<Entity* > scenes;
	Window window;
	list<Shader*> shaders;
	vector<pair<const char*, const char*>> shadersPaths;
	bool isRuning();



};

#endif