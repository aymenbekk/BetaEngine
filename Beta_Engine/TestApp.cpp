#include "Core/Engine.h"

int main() {

	glm::vec3 camPos = glm::vec3(0.0f, 2.0f, 10.0f);
	Camera camera(camPos, 800, 800);
	Window window(800, 800, "Beta Engine", camera);
	
	vector<pair<const char*, const char*>> shadersPaths;
	shadersPaths.push_back(make_pair("assets/shaders/shader.vert", "assets/shaders/shader.frag"));
	vector<Entity*> scenes;

	Transform* transform=new Transform();
	vector<Vertex> cubeVertices;
	cubeVertices.push_back(Vertex{ glm::vec3(0.5f,0.0f,-0.5f),glm::vec3(1.0f,1.0f,1.0f),glm::vec2() });
	cubeVertices.push_back(Vertex{ glm::vec3(0.5f,0.0f,0.5f),glm::vec3(1.0f,1.0f,1.0f),glm::vec2() });
	cubeVertices.push_back(Vertex{ glm::vec3(-0.5f,0.0f,0.5f),glm::vec3(1.0f,1.0f,1.0f),glm::vec2() });
	cubeVertices.push_back(Vertex{ glm::vec3(-0.5f,0.0f,-0.5f),glm::vec3(1.0f,1.0f,1.0f),glm::vec2() });
	cubeVertices.push_back(Vertex{ glm::vec3(0.5f,1.0f,-0.5f),glm::vec3(1.0f,1.0f,1.0f),glm::vec2() });
	cubeVertices.push_back(Vertex{ glm::vec3(0.5f,1.0f,0.5f),glm::vec3(1.0f,1.0f,1.0f),glm::vec2() });
	cubeVertices.push_back(Vertex{ glm::vec3(-0.5f,1.0f,0.5f),glm::vec3(1.0f,1.0f,1.0f),glm::vec2() });
	cubeVertices.push_back(Vertex{ glm::vec3(-0.5f,1.0f,-0.5f),glm::vec3(1.0f,1.0f,1.0f),glm::vec2() });

	vector<Vertex> triangle;
	triangle.push_back(Vertex{ glm::vec3(0.5f,0.5f,0.0f),glm::vec3(1.0f,1.0f,1.0f),glm::vec2() });
	triangle.push_back(Vertex{ glm::vec3(0.5f,-0.5f,0.0f),glm::vec3(1.0f,1.0f,1.0f),glm::vec2() });
	triangle.push_back(Vertex{ glm::vec3(-0.5f,0.5f,0.0f),glm::vec3(1.0f,1.0f,1.0f),glm::vec2() });

	vector<GLuint> indices = {
				0,1,2,
				0,2,3,
				4,5,6,
				4,6,7,
				1,2,6,
				1,5,6,
				0,4,7,
				0,3,7,
				1,0,4,
				1,5,4,
				2,3,7,
				2,6,7
	};
	vector <GLuint> indices2 = {
		0,1,2
	};
	vector<Texture> textures;
	Engine engine(window);
	engine.init();
	Renderer renderer(camera, shadersPaths);
	Mesh* cubeMesh = new Mesh(cubeVertices, indices, textures);
	Mesh* triangleMesh = new Mesh(triangle, indices2, textures);
	const string tag = "cube01";
	size_t shaderIndex = 0;
	Entity Cube( tag,shaderIndex, transform, cubeMesh);
	Entity* triangleE=new Entity(tag,shaderIndex,transform,triangleMesh);
	scenes.push_back(&Cube);
	engine.start(renderer,scenes);

	///nrodo el shaders le renderer negla3hom mel init ta3 el engine pcq el shaders 3andhom relation m3a el renderer mchi m3a el engine


	return 0;

}