#ifndef ENGINE_CLASS_H
#define ENGINE_CLASS_H

using namespace std;
#include <vector>
#include"../Beta.h"
#include "../Renderer/Renderer.h"
#include "../Scene/Entity.h"
#include "Window.h"
#include "../Physics/PhysicsEngine.h"


class Engine {

public :


	Engine(double frameRate,Window& window);
	

	void init();

	void start(Renderer& renderer, vector<Entity* >& scenes,PhysicsEngine& physicsEngine);

	


private :

	//Renderer renderer;
	//vector<Entity* > scenes;
	double frameTime;
	Window window;
	vector<Shader*> shaders;
	vector<pair<const char*, const char*>> shadersPaths;
	bool isRuning();



};

#endif