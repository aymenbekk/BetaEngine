#ifndef ENTITY_H
#define ENTITY_H


#include "string"
#include "../Components/Mesh.h"
#include "../Components/Transform.h"
using namespace std;


class Transform;

class Entity {

public:

	Entity(const string& tag, size_t shaderIndex, Transform* transfor);
	Entity();

	void AddComponent(Component* c);
	void AddChild(Entity* e);
	//this to update the world matrices
	void updateSelfAndChild();

	//this to executue the update function in each component for the complete scene
	void updateAll();
	//this to execute the update for each component of one entity of a scene
	void update(Entity* e);


	size_t getShaderIndex() { return shaderIndex; };

	Transform* getTransform() { return transform; };

	vector <Entity*> childs;

	string getTag() { return Tag; };

	Entity* getParent() { return parent; };

	void Entity::updateChilds();

	vector <Component* > getComponents() { return components; };

	virtual void Draw(Camera& camera, Shader* shader) ;
	

private:
	//el attributes ndirhom pointers surtout ki ykono class bach ki nretrievihom mayetcopawch aya we noptimisi lespace 
	size_t shaderIndex;
	string Tag;
	Transform* transform;
	vector <Component* > components;
	Entity* parent = NULL;


};

#endif // !ENTITY.H




