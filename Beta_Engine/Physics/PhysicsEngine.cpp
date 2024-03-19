#include "physicsEngine.h"




void PhysicsEngine::AddComponent( PhysicsComponent* component)
{
	components.push_back(component);
}

void PhysicsEngine::Simulate(float delta)
{
	for (unsigned int i = 0; i < components.size(); i++)
	{
		
		components[i]->Integrate(delta);
	}
}

void PhysicsEngine::HandleCollisions(double deltaTime)
{

	double collisionCheckInterval = 0.009;
	for (unsigned int i = 0; i < components.size(); i++)
	{
		for (unsigned int j = i + 1; j < components.size(); j++)
		{
			IntersectData intersectData =
				components[i]->GetCollider().Intersect(
					components[j]->GetCollider());

			if (intersectData.GetDoesIntersect() && deltaTime >= collisionCheckInterval)
			{	
					/*		if(components[i]->GetCollider().GetType() != Collider::PLANE)*/
				
					components[i]->SetVelocity(vec3(components[i]->GetVelocity().x * -1, components[i]->GetVelocity().y * -1, components[i]->GetVelocity().z * -1));

					//if (components[j]->GetCollider().GetType() != Collider::PLANE)
					components[j]->SetVelocity(vec3(components[j]->GetVelocity().x * -1, components[j]->GetVelocity().y * -1, components[j]->GetVelocity().z * -1));
				
			}
		}
	}
}


void PhysicsEngine::start(float delta,double deltaTime) {
	Simulate(delta);
	HandleCollisions(deltaTime);
}