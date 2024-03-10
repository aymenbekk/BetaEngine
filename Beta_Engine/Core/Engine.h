#ifndef ENGINE_CLASS_H
#define ENGINE_CLASS_H

using namespace std;
#include <vector>
#include"../Beta.h"
#include "../Scene/Entity.h"
#include "Window.h"

class Engine {

public :


	Engine(vector<Entity*>& scenes,Window& window);
	

	void init();

	void start();

	


private :

	vector<Entity* > scenes;
	Window window;
	bool isRuning();



};

#endif