#include "physicsEngine.h"




void PhysicsEngine::AddObject(const PhysicsObject& object)
{
	objects.push_back(object);
}

void PhysicsEngine::Simulate(float delta)
{
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		objects[i].Integrate(delta);
	}
}

void PhysicsEngine::HandleCollisions()
{
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		for (unsigned int j = i + 1; j < objects.size(); j++)
		{
			IntersectData intersectData =
				objects[i].GetCollider().Intersect(
					objects[j].GetCollider());

			if (intersectData.GetDoesIntersect())
			{
				vec3 direction = intersectData.GetDirection().Normalized();
				vec3 otherDirection = vec3(direction.Reflect(m_objects[i].GetVelocity().Normalized()));
				objects[i].SetVelocity(
					vec3(objects[i].GetVelocity().Reflect(otherDirection)));

				objects[j].SetVelocity(
					vec3(objects[j].GetVelocity().Reflect(direction)));
			}
		}
	}
}


void PhysicsEngine::start(float delta) {
	Simulate(delta);
	HandleCollisions();
}