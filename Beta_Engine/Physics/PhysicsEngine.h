#ifndef PHYSICS_ENGINE_INCLUDED_H
#define PHYSICS_ENGINE_INCLUDED_H

#include "IntersectData.h"
#include "physicsComponent.h"
#include <iostream>
#include "../Math.h"
#include "vector"
using namespace glm;
using namespace std;

class PhysicsEngine
{
public:

	PhysicsEngine() {}

	void AddComponent( PhysicsComponent* component);

	void Simulate(float delta);
	void HandleCollisions(double deltaTime);
	void start(float delta, double deltaTime);
	
	inline  PhysicsComponent* GetComponent(unsigned int index)
	{
		return components[index];
	}
	inline unsigned int GetNumComponents() const
	{
		return (unsigned int)components.size();
	}

private:

	vector<PhysicsComponent*> components;
};

#endif