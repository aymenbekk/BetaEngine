#ifndef PHYSICS_OBJECT_INCLUDED_H
#define PHYSICS_OBJECT_INCLUDED_H

#include "../Components/Component.h"
#include "../Math.h"
#include "./Collider.h"
#include "../Components/Transform.h"
using namespace glm;



class PhysicsComponent : public Component
{
public:


	//rani ngol nzid transform lel constructor ta3 el entity molate hade el component bach nakhdem bih fel fonction update li ba nzidha ta3 el physicsObjectComponent
	PhysicsComponent(Collider* collider, const vec3 velocity,Transform* transform) :
		position(collider->GetCenter()),
		oldPosition(collider->GetCenter()),
		velocity(velocity),
		collider(collider),
		transform(transform)
	{}

	PhysicsComponent(const PhysicsComponent& other);
	//void operator=(PhysicsObject other);
	/*virtual ~PhysicsObject();*/


	void Integrate(float delta);
	//update parent ENtity
	void update() override;

	inline const vec3 GetPosition() const { return position; }

	inline const vec3 GetVelocity() const { return velocity; }

	/**
	 * Returns a collider in the position of this object, updating the
	 * collider's position if necessary.
	 */
	inline  Collider& GetCollider()
	{
		
		vec3 translation = position - oldPosition;
	
		oldPosition = position;
		
		collider->Transform(translation);

		return *collider;
	}


	inline void SetVelocity( vec3 velocit) { velocity = velocit; }

	

private:
	
	vec3 position;
	vec3 oldPosition;
	vec3 velocity;
	Collider* collider;
	Transform* transform;//the transform of the entity that has this component
};

#endif