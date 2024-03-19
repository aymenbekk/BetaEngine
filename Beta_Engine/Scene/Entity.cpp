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

void Entity::updateChilds() {

	for (auto&& child : childs) {
		if (child->parent) {
			child->getTransform()->setWorldMatrix(child->parent->transform->getWorldMatrix() * child->getTransform()->getLocalMatrix());
		}
		else {
			child->getTransform()->setWorldMatrix(transform->getLocalMatrix());
		}
		child->updateSelfAndChild();
	}

}


void Entity::update(Entity* entity) {
	for (auto&& component : entity->getComponents()) {
		component->update();
	}
}

void Entity::updateAll() {
	update(this);
	for (auto&& child : childs) {
		child->updateAll();
	}
}

