#ifndef PHYSICS_ENGINE_INCLUDED_H
#define PHYSICS_ENGINE_INCLUDED_H

#include "physicsObject.h"
#include <vector>
#include "../Math.h"
using namespace glm;

class PhysicsEngine
{
public:

	PhysicsEngine() {}

	void AddObject(const PhysicsObject& object);

	void Simulate(float delta);
	void HandleCollisions();
	void start();
	
	inline const PhysicsObject& GetObject(unsigned int index) const
	{
		return objects[index];
	}
	inline unsigned int GetNumObjects() const
	{
		return (unsigned int)objects.size();
	}

private:

	std::vector<PhysicsObject> objects;
};

#endif