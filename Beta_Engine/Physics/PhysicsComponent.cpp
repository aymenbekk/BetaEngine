#include "PhysicsComponent.h"

PhysicsComponent::PhysicsComponent(const PhysicsComponent& other) :
	position(other.position),
	oldPosition(other.oldPosition),
	velocity(other.velocity),
	collider(other.collider)
{
	/*collider->AddReference();*/
}





void PhysicsComponent::Integrate(float delta)
{
	
	position += velocity * delta;
}


//LZM NACTIVER UPDATE SELF AND CHILDS MATENSACH
void PhysicsComponent::update() {
	
	if (collider->GetType() != Collider::PLANE)
	{
		transform->setPosition(position);
		collider->setCenter(position);
	};

}