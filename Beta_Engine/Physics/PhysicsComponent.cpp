#include "PhysicsComponent.h"

PhysicsComponent::PhysicsComponent(const PhysicsComponent& other) :
	position(other.m_position),
	oldPosition(other.m_oldPosition),
	velocity(other.m_velocity),
	collider(other.m_collider)
{
	/*collider->AddReference();*/
}





void PhysicsComponent::Integrate(float delta)
{
	position += velocity * delta;
}


//LZM NACTIVER UPDATE SELF AND CHILDS MATENSACH
void PhysicsComponent::UpdateEntityParent() {
	
	transform->setPosition(position);

}