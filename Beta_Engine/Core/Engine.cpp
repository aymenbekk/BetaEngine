#include "Engine.h"


Engine::Engine( Window& window ):window(window) {
	
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

}


void Engine::start(Renderer& renderer,vector<Entity* >& scenes){
	
	glEnable(GL_DEPTH_TEST);
	
	while (isRuning()) {

	
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		window.processInput();
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); 
		renderer.getCamera()->Inputs(window.get_GLFW_Window());
		for (Entity* root : scenes) {
			renderer.RenderScene(root);
		}
		window.swapBuffers();
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