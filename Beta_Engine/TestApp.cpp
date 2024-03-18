#include "./Components/ChunkMesh.h"
#include "Core/Engine.h"



int main() {

	glm::vec3 camPos = glm::vec3(0.0f, 10.0f, 20.0f);
	Camera camera(camPos, 800, 800);
	Window window(800, 800, "Beta Engine", camera);
	
	vector<pair<const char*, const char*>> shadersPaths;
	shadersPaths.push_back(make_pair("assets/shaders/shader.vert", "assets/shaders/shader.frag"));
	vector<Entity*> scenes;

	
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
	const string tag2 = "cube02";
	const string tag3 = "sun";
	const string tag4 = "chunk";
	size_t shaderIndex = 0;
	
	//position the cubeChild with +2 to the X of its parent and scale oof 75% of parent
	Transform* transform = new Transform();
	ChunkMesh chunkMesh;
	Entity chunk(tag4, shaderIndex, transform,  &chunkMesh);
	Entity sun(tag3, shaderIndex, transform, cubeMesh);	
	Transform* transformEarth = new Transform(vec3(4.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.6f, 0.6f, 0.6f));
	Entity Cube( tag,shaderIndex, transformEarth, cubeMesh);
	Transform* transformMoon = new Transform(vec3(2.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.75f, 0.75f, 0.75f));
	Entity CubeChild(tag2, shaderIndex, transformMoon, cubeMesh);
	Cube.AddChild(&CubeChild);
	sun.AddChild(&Cube);
	/*Entity* triangleE=new Entity(tag,shaderIndex,transform,triangleMesh);*/
	sun.updateSelfAndChild();
	scenes.push_back(&chunk);
	engine.start(renderer,scenes);



	return 0;

}