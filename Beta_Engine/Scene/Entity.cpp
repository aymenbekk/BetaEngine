#include "Entity.h"



Entity::Entity(const string& tag, size_t shaderIndex, Transform* transfor, Mesh* mesh):
	Tag(tag),
	shaderIndex(shaderIndex),
	transform(transfor),
	mesh(mesh)
{
}

void Entity::AddComponent(Component* c) {
	components.push_back(c);
}

void Entity::AddChild(Entity* e) {
	
	e->parent = this;
	childs.push_back(e);
}

void Entity::updateSelfAndChild() {
	if (parent) {
		transform->setWorldMatrix(parent->transform->getWorldMatrix() * transform->getLocalMatrix());
	}
	else {
		transform->setWorldMatrix(transform->getLocalMatrix());
	}
	for (auto&& child : childs) {
		child->updateSelfAndChild();
	}

}


