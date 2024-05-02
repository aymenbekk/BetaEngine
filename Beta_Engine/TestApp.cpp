#include "./Components/ChunkMesh.h"
#include "Core/Engine.h"
#include "./Components/Sphere.h"
#include "./Physics/SphereCollider.h"
#include "./Physics/PlaneCollider.h"
#include "Scene/World.h"
#include "Components/MeshRenderer.h"

int main() {

	glm::vec3 camPos = glm::vec3(2.0f, 6.0f, 2.0f);
	Camera camera(camPos, 800, 800);
	Window* window=new Window(800, 800, "Beta Engine", &camera);
	
	vector<pair<const char*, const char*>> shadersPaths;
	shadersPaths.push_back(make_pair("assets/shaders/shader.vert", "assets/shaders/shader.frag"));
	shadersPaths.push_back(make_pair("assets/shaders/shader.vert", "assets/shaders/light.frag"));
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
	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	Renderer renderer(camera, shadersPaths);
	glUniform4f(glGetUniformLocation(renderer.getShaders().at(1)->ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	
	

	//Creating meshes
	sphere sphere(1.0f, 20, 30);
	sphere.createSphere();
	vector<Texture> textures;
	Mesh* sphereMesh = new Mesh(sphere.vertices, sphere.indices, textures);


	const string tag1 = "sphere";
	const string tag3 = "world";
	size_t shaderIndex = 0;
	size_t shaderIndex2 = 1;

	vec3 positionSpher = { 0.0f,12.0f,-25.0f };
	vec3 position = { -8.0f,0.0f,0.0f };
	vec3 eulerRotation = { 0.0f,0.0f,0.0f };
	vec3 scale = { 1.0f,1.0f,1.0f };
	renderer.getShaders().at(0)->Activate();
	glUniform4f(glGetUniformLocation(renderer.getShaders().at(0)->ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(renderer.getShaders().at(0)->ID, "lightPos"), positionSpher.x, positionSpher.y, positionSpher.z);
	glUniform3f(glGetUniformLocation(renderer.getShaders().at(0)->ID, "camPos"),camera.Position.x, camera.Position.y, camera.Position.z);
	////position the cubeChild with +2 to the X of its parent and scale oof 75% of parent
	Transform* transform = new Transform(position,eulerRotation,scale);
	Transform* transformSphere = new Transform(positionSpher, eulerRotation, scale);
	
	//ChunkMesh chunkMesh;
	//Entity chunkEnt(tag2, shaderIndex, transform, &chunkMesh);
	 Entity sphereEnt(tag1, shaderIndex2, transformSphere);
	 MeshRenderer* M_Renderer = new MeshRenderer(sphereMesh);
	//Entity spherEnt2(tag1, shaderIndex, transformSpher, sphereMesh);
	//Entity spherEnt3(tag1, shaderIndex, transformSpher, sphereMesh);

	 sphereEnt.AddComponent(M_Renderer);

	//ybanli lerreur kan puisque ki kont npassi el window hna kanet 9bel matetcriya 
	World world(tag3, shaderIndex, transform);


	//Creating the appropriate physics for each entity
	PhysicsEngine physicsEngine;
	//SphereCollider* sColl = new SphereCollider(vec3(0.0f, 5.0f, 0.0f), 1.0f);
	//PhysicsComponent sphereCompPhys(sColl, vec3(0.0f, -0.5f, 0.0f), sphereEnt.getTransform());

	//SphereCollider* sColl2 = new SphereCollider(vec3(-5.0f, 5.0f, 0.0f), 1.0f);
	//PhysicsComponent sphereCompPhys2(sColl2, vec3(0.5f, 0.0f, 0.0f), sphereEnt.getTransform());

	//SphereCollider* sColl3 = new SphereCollider(vec3(-5.0f, 8.0f, 0.0f), 1.0f);
	//PhysicsComponent sphereCompPhys3(sColl3, vec3(0.0f, -3.0f, 0.0f), sphereEnt.getTransform());

	//PlaneCollider* pColl = new PlaneCollider(vec3(0.0f, 1.0f, 0.0f), 0.0f, chunkMesh.chunkBorders);
	//PhysicsComponent planeCompPhyis(pColl, vec3(0.0f, 0.0f, 0.0f), transform);

	//physicsEngine.AddComponent(&sphereCompPhys);
	//physicsEngine.AddComponent(&sphereCompPhys2);
	/*physicsEngine.AddComponent(&sphereCompPhys3);*/
	//physicsEngine.AddComponent(&planeCompPhyis);

	/*sphereEnt.AddComponent(&sphereCompPhys);*/
	//spherEnt2.AddComponent(&sphereCompPhys2);
	//spherEnt3.AddComponent(&sphereCompPhys3);
	//chunkEnt.AddComponent(&planeCompPhyis);


	//Entity sun(tag3, shaderIndex, transform, cubeMesh);	
	/*Transform* transformEarth = new Transform(vec3(4.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.6f, 0.6f, 0.6f));*/
	/*Entity Cube( tag,shaderIndex, transformEarth, cubeMesh);*/
	//Transform* transformMoon = new Transform(vec3(2.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.75f, 0.75f, 0.75f));
	//Entity CubeChild(tag2, shaderIndex, transformMoon, cubeMesh);
	//Cube.AddChild(&CubeChild);
	//sun.AddChild(&Cube);
	/*Entity* triangleE=new Entity(tag,shaderIndex,transform,triangleMesh);*/
	/*sun.updateSelfAndChild();*/
	//scenes.push_back(&chunkEnt);
	/*scenes.push_back(&sphereEnt);*/
	//scenes.push_back(&spherEnt2);
	//scenes.push_back(&spherEnt3);

	scenes.push_back(&sphereEnt);
	scenes.push_back(&world);
	
	engine.start(renderer,scenes,physicsEngine);



	return 0;

}