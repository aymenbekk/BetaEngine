#include "Core/Engine.h"

int main() {

	glm::vec3 camPos = glm::vec3(0.0f, 7.0f, 15.0f);
	Camera camera(camPos, 800, 800);
	Window window(800, 800, "Beta Engine", camera);
	Renderer renderer(camera);
	vector<pair<const char*, const char*>> shadersPaths;
	shadersPaths.push_back(make_pair("assets/shaders/shader.vert", "assets/shaders/shader.frag"));
	vector<Entity*> scenes;
	Engine engine(scenes,window,renderer,shadersPaths);
	engine.init();
	engine.start();



	return 0;

}