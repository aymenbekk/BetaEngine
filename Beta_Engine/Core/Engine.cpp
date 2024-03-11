#include "Engine.h"


Engine::Engine(vector<Entity*>& scenes, Window& window, Renderer& renderer, vector<pair<const char*, const char*>>& shadersPaths):scenes(scenes),window(window),renderer(renderer),shadersPaths(shadersPaths) {
	
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
	cout << "dkhalna" << endl;
	

	for (const auto& pair : shadersPaths) {

		cout << "first pair" << pair.first << "scond" << pair.second << endl;
		Shader shaderProgram(pair.first, pair.second);
		shaders.push_back(&shaderProgram);
	}

}


void Engine::start(){
	

	glEnable(GL_DEPTH_TEST);
	while (isRuning()) {

		window.processInput();
		window.swapBuffers(0.07f, 0.13f, 0.17f, 1.0f);

		renderer.getCamera()->Inputs(window.get_GLFW_Window());
		for (Entity* root : scenes) {
			renderer.RenderScene(root,shaders);
		}
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