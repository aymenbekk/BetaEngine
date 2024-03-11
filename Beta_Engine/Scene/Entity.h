#ifndef ENTITY_H
#define ENTITY_H


#include "string"
#include "../Components/Mesh.h"
#include "../Components/Transform.h"
using namespace std;


class Transform;

class Entity {

public:

	Entity(string& tag, GLuint shaderID, Transform* transfor);
	

	void AddComponent(Component* c);
	void AddChild(Entity* e);
	void updateSelfAndChild();

	Mesh* getMesh() { return mesh; };

	GLuint getShaderID() { return shaderID; };

	Transform* getTransform() { return transform; };

	vector <Entity*> childs;


private:
	//el attributes ndirhom pointers surtout ki ykono class bach ki nretrievihom mayetcopawch aya we noptimisi lespace 
	GLuint shaderID;
	string Tag;
	Transform* transform;
	Mesh* mesh;
	vector <Component* > components;

	Entity* parent = NULL;


};

#endif // !ENTITY.H




