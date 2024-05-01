#include "Engine.h"


Engine::Engine(double frameRate, Window* window ):frameTime(1.0/frameRate),window(window) {
	
}

void Engine::init() {
	int i = window->create();
	if (i == -1) {
		std::cout << "Failed to create GLFW window" << std::endl;
		return;
	}
	if (i == -2) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return;
	}



}


void Engine::start(Renderer& renderer,vector<Entity* >& scenes , PhysicsEngine& physicsEngine){
	
	
	double lastTime = glfwGetTime();
	double deltaTime = 0.0;
	int camWidth = renderer.getCamera()->width;
	int camHeight = renderer.getCamera()->height;

	glEnable(GL_DEPTH_TEST);
	
	while (isRuning()) {

	


		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		

		
		window->processInput();

		int width, height;
		glfwGetFramebufferSize(window->get_GLFW_Window(), &width, &height);

		if (camWidth != width)
			renderer.getCamera()->width = width;
		if (camHeight != height)
			renderer.getCamera()->height = height;

		renderer.getCamera()->Inputs(window->get_GLFW_Window());
		
		double mousePosX, mousePosY;
		glfwGetCursorPos(glfwGetCurrentContext(), &mousePosX, &mousePosY);
	/*	renderer.getCamera()->ProcessMouseMovement((float) mousePosX,(float) mousePosY,true);
		*/double currentTime = glfwGetTime();
		deltaTime += (currentTime - lastTime);
		lastTime = currentTime;

		/*physicsEngine.start((float)frameTime,deltaTime);*/
		deltaTime = 0.0; 
			
		for (Entity* root : scenes) {
			renderer.RenderScene(root);
		}
		window->swapBuffers();
		window->checkEvents();

	
	}

	window->Destroy();
}




bool Engine::isRuning() {
	if (window->shoudlClose()) {
		return false;
	}
	else {
		return true;
	}
}

