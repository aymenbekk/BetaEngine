#include "./Components/ChunkMesh.h"
#include "Core/Engine.h"
#include "./Components/Sphere.h"
#include "./Physics/SphereCollider.h"
#include "./Physics/PlaneCollider.h"


int main() {

	glm::vec3 camPos = glm::vec3(0.0f, 6.0f, 20.0f);
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

	

	Engine engine(60,window);
	engine.init();
	Renderer renderer(camera, shadersPaths);
	

	//Creating meshes
	sphere sphere(1.0f, 20, 30);
	sphere.createSphere();
	vector<Texture> textures;
	////Mesh* cubeMesh = new Mesh(cubeVertices, indices, textures);
	Mesh* sphereMesh = new Mesh(sphere.vertices, sphere.indices, textures);
	Mesh* triangleMesh = new Mesh(triangle, indices2, textures);
	//Creating Entit.es
	const string tag1 = "sphere";
	const string tag2 = "chunk";
	size_t shaderIndex = 0;

	vec3 position = { 0.0f,-1.0f,0.0f };
	vec3 eulerRotation = { 0.0f,0.0f,0.0f };
	vec3 scale = { 1.0f,1.0f,1.0f };
	//position the cubeChild with +2 to the X of its parent and scale oof 75% of parent
	Transform* transform = new Transform(position,eulerRotation,scale);
	Transform* transformSpher = new Transform();
	ChunkMesh chunkMesh;
	Entity chunkEnt(tag2, shaderIndex, transform, &chunkMesh);
	Entity sphereEnt(tag1, shaderIndex, transformSpher, sphereMesh);
	Entity spherEnt2(tag1, shaderIndex, transformSpher, sphereMesh);
	Entity spherEnt3(tag1, shaderIndex, transformSpher, sphereMesh);

	//Creating the appropriate physics for each entity
	PhysicsEngine physicsEngine;
	SphereCollider* sColl = new SphereCollider(vec3(0.0f, 5.0f, 0.0f), 1.0f);
	PhysicsComponent sphereCompPhys(sColl, vec3(0.0f, -0.5f, 0.0f), sphereEnt.getTransform());

	SphereCollider* sColl2 = new SphereCollider(vec3(-5.0f, 5.0f, 0.0f), 1.0f);
	PhysicsComponent sphereCompPhys2(sColl2, vec3(0.5f, 0.0f, 0.0f), sphereEnt.getTransform());

	SphereCollider* sColl3 = new SphereCollider(vec3(-5.0f, 8.0f, 0.0f), 1.0f);
	PhysicsComponent sphereCompPhys3(sColl3, vec3(0.0f, -3.0f, 0.0f), sphereEnt.getTransform());

	PlaneCollider* pColl = new PlaneCollider(vec3(0.0f, 1.0f, 0.0f), 0.0f, chunkMesh.chunkBorders);
	PhysicsComponent planeCompPhyis(pColl, vec3(0.0f, 0.0f, 0.0f), transform);

	//physicsEngine.AddComponent(&sphereCompPhys);
	//physicsEngine.AddComponent(&sphereCompPhys2);
	/*physicsEngine.AddComponent(&sphereCompPhys3);*/
	physicsEngine.AddComponent(&planeCompPhyis);

	/*sphereEnt.AddComponent(&sphereCompPhys);*/
	//spherEnt2.AddComponent(&sphereCompPhys2);
	//spherEnt3.AddComponent(&sphereCompPhys3);
	chunkEnt.AddComponent(&planeCompPhyis);


	//Entity sun(tag3, shaderIndex, transform, cubeMesh);	
	/*Transform* transformEarth = new Transform(vec3(4.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.6f, 0.6f, 0.6f));*/
	/*Entity Cube( tag,shaderIndex, transformEarth, cubeMesh);*/
	//Transform* transformMoon = new Transform(vec3(2.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.75f, 0.75f, 0.75f));
	//Entity CubeChild(tag2, shaderIndex, transformMoon, cubeMesh);
	//Cube.AddChild(&CubeChild);
	//sun.AddChild(&Cube);
	/*Entity* triangleE=new Entity(tag,shaderIndex,transform,triangleMesh);*/
	/*sun.updateSelfAndChild();*/
	scenes.push_back(&chunkEnt);
	/*scenes.push_back(&sphereEnt);*/
	//scenes.push_back(&spherEnt2);
	//scenes.push_back(&spherEnt3);
	engine.start(renderer,scenes,physicsEngine);



	return 0;

}