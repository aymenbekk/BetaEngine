#include "Engine.h"


Engine::Engine(vector<Entity*>& scenes,Window& window):scenes(scenes),window(window) {
	
}

void Engine::init() {
	int i = window.create();
	if (i == -1) {
		std::cout << "Failed to create GLFW window" << std::endl;
		return;
	}
	if (i == -2) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return;
	}
	window.swapBuffers(0.07f, 0.13f, 0.17f, 1.0f);
}


void Engine::start(){

	while (isRuning()) {

		window.processInput();
		window.swapBuffers(0.07f, 0.13f, 0.17f, 1.0f);

		window.checkEvents();
	}

	window.Destroy();
}




bool Engine::isRuning() {
	if (window.shoudlClose()) {
		return false;
	}
	else {
		return true;
	}
}