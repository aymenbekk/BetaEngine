#ifndef ENTITY_H
#define ENTITY_H


#include "string"
#include "../Components/Mesh.h"
#include "../Components/Transform.h"
using namespace std;


class Transform;

class Entity {

public:

	Entity(const string& tag, size_t shaderIndex, Transform* transfor,Mesh* mesh);
	

	void AddComponent(Component* c);
	void AddChild(Entity* e);
	void updateSelfAndChild();

	Mesh* getMesh() { return mesh; };

	size_t getShaderIndex() { return shaderIndex; };

	Transform* getTransform() { return transform; };

	vector <Entity*> childs;


private:
	//el attributes ndirhom pointers surtout ki ykono class bach ki nretrievihom mayetcopawch aya we noptimisi lespace 
	size_t shaderIndex;
	string Tag;
	Transform* transform;
	Mesh* mesh;
	vector <Component* > components;

	Entity* parent = NULL;


};

#endif // !ENTITY.H




